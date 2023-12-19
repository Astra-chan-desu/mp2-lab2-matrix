#include "tmatrix.h"

#include <gtest.h>

TEST(TDynamicVector, can_create_vector_with_positive_length)
{
	ASSERT_NO_THROW(TDynamicVector<int> v(5));
}

TEST(TDynamicVector, cant_create_too_large_vector)
{
	ASSERT_ANY_THROW(TDynamicVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TDynamicVector, throws_when_create_vector_with_negative_length)
{
	ASSERT_ANY_THROW(TDynamicVector<int> v(-5));
}

TEST(TDynamicVector, can_create_copied_vector)
{
	TDynamicVector<int> v(10);

	ASSERT_NO_THROW(TDynamicVector<int> v1(v));
}

TEST(TDynamicVector, copied_vector_is_equal_to_source_one)
{
	TDynamicVector<int> v(4);
	ASSERT_NO_THROW(TDynamicVector<int> g(v));
}

TEST(TDynamicVector, can_get_size)
{
	TDynamicVector<int> v(4);

	EXPECT_EQ(4, v.size());
}

//TEST(TDynamicVector, can_set_and_get_element)
//{
//  TDynamicVector<int> v(4);
//  v[0] = 4;
//
//  EXPECT_EQ(4, v[0]);
//}

TEST(TDynamicVector, throws_when_set_element_with_negative_index)
{
	TDynamicVector<int> v(6);
	ASSERT_ANY_THROW(v.at(-5));
}

TEST(TDynamicVector, throws_when_set_element_with_too_large_index)
{
	TDynamicVector<int> v(4);
	ASSERT_ANY_THROW(v.at(99));
}

TEST(TDynamicVector, throws_when_sum_different_size)
{
	TDynamicVector<int> v(4);
	TDynamicVector<int> g(10);
	ASSERT_ANY_THROW(v + g);
}

TEST(TDynamicVector, throws_when_minus_different_size)
{
	TDynamicVector<int> v(4);
	TDynamicVector<int> g(10);
	ASSERT_ANY_THROW(v - g);
}

TEST(TDynamicVector, copied_vector_has_its_own_memory)
{
	int* arr1 = new int[3] { 1, 2, 3 };
	TDynamicVector<int> v1(arr1, 3), v3(std::move(v1));
	EXPECT_NE(&v1, &v3);
}

TEST(TDynamicVector, compare_equal_vectors_return_true)
{
	int* arr1 = new int[3] { 1, 2, 3 };
	int* arr3 = new int[3] { 1, 2, 3 };
	TDynamicVector<int> v1(arr1, 3), v3(arr3, 3);
	EXPECT_EQ(v1, v3);

	delete[] arr1;
	delete[] arr3;
}

TEST(TDynamicVector, can_multiply_scalar_by_vector)
{
	int* arr1 = new int[3] { 1, 2, 3 };
	int* arr3 = new int[3] { 3, 6, 9 };
	TDynamicVector<int> v1(arr1, 3), v3(arr3, 3);
	EXPECT_EQ(v3, v1 * 3);

	delete[] arr1;
	delete[] arr3;
}

