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
	TDynamicVector<int> v(10);
	for (int i = 0; i < v.size(); i++) {
		v[i] = i;
	}
	TDynamicVector<int> v1(v);
	for (int i = 0; i < v.size(); i++) {
		EXPECT_EQ(v[i], v1[i]);
	}
}

TEST(TDynamicVector, copied_vector_has_its_own_memory)
{
	TDynamicVector<int> v(5);
	for (int i = 0; i < v.size(); i++) {
		v[i] = i;
	}
	TDynamicVector<int> v1(v);
	v1[0] = -2;
	EXPECT_NE(v1[0], v[0]);
	for (int i = 1; i < v.size(); i++) {
		EXPECT_EQ(v1[i], v[i]);
	}
}

TEST(TDynamicVector, can_get_size)
{
  TDynamicVector<int> v(4);

  EXPECT_EQ(4, v.size());
}

TEST(TDynamicVector, can_set_and_get_element)
{
  TDynamicVector<int> v(4);
  v[0] = 4;

  EXPECT_EQ(4, v[0]);
}

TEST(TDynamicVector, throws_when_set_element_with_negative_index)
{
	TDynamicVector<int> v(2);
	ASSERT_ANY_THROW(v.at(-1));
}

TEST(TDynamicVector, throws_when_set_element_with_too_large_index)
{
	TDynamicVector<int> v(2);
	ASSERT_ANY_THROW(v.at(3));
}

TEST(TDynamicVector, can_assign_vector_to_itself)
{
	TDynamicVector<int>v(2);
	ASSERT_NO_THROW(v = v);
}

TEST(TDynamicVector, can_assign_vectors_of_equal_size)
{
	TDynamicVector<int> v1(5);
	TDynamicVector<int> v2(5);
	for (int i = 0; i < v1.size(); i++) {
		v1[i] = i;
	}
	v2 = v1;
	for (int i = 0; i < v1.size(); i++) {
		EXPECT_EQ(v1[i], v2[i]);
	}
}

TEST(TDynamicVector, assign_operator_change_vector_size)
{
	TDynamicVector<int> v1(2);
	TDynamicVector<int> v2(4);
	int old_size = v1.size();
	v1 = v2;
	int new_size = v1.size();
	EXPECT_NE(old_size, new_size);
}

TEST(TDynamicVector, can_assign_vectors_of_different_size)
{
	TDynamicVector<int> v1(2);
	TDynamicVector<int> v2(4);
	ASSERT_NO_THROW(v1 = v2);
}

TEST(TDynamicVector, compare_equal_vectors_return_true)
{
	TDynamicVector<int> v1(4);
	TDynamicVector<int> v2(4);
	for (int i = 0; i < v1.size(); i++) {
		v1[i] = i;
		v2[i] = i;
	}
	EXPECT_EQ(v1 == v2, true);
}

TEST(TDynamicVector, compare_vector_with_itself_return_true)
{
	TDynamicVector<int> v(4);
	EXPECT_EQ(v == v, true);
}

TEST(TDynamicVector, vectors_with_different_size_are_not_equal)
{
	TDynamicVector<int> v1(4);
	TDynamicVector<int> v2(5);
	EXPECT_EQ(v1 != v2, true);
}

TEST(TDynamicVector, can_add_scalar_to_vector)
{
	TDynamicVector<int> v1(4);
	TDynamicVector<int> v2(4);
	v1[0] = 1; v1[1] = 8; v1[2] = 12; v1[3] = 5;
	v2 = v1 + 5;
	EXPECT_EQ(v2[0], 6);
	EXPECT_EQ(v2[1], 13);
	EXPECT_EQ(v2[2], 17);
	EXPECT_EQ(v2[3], 10);
}

TEST(TDynamicVector, can_subtract_scalar_from_vector)
{
	TDynamicVector<int> v1(4);
	TDynamicVector<int> v2(4);
	v1[0] = 1; v1[1] = 8; v1[2] = 12; v1[3] = 5;
	v2 = v1 - 4;
	EXPECT_EQ(v2[0], -3);
	EXPECT_EQ(v2[1], 4);
	EXPECT_EQ(v2[2], 8);
	EXPECT_EQ(v2[3], 1);
}

TEST(TDynamicVector, can_multiply_scalar_by_vector)
{
	TDynamicVector<int> v1(4);
	TDynamicVector<int> v2(4);
	v1[0] = 1; v1[1] = 8; v1[2] = 12; v1[3] = 5;
	v2 = v1 * 6;
	EXPECT_EQ(v2[0], 6);
	EXPECT_EQ(v2[1], 48);
	EXPECT_EQ(v2[2], 72);
	EXPECT_EQ(v2[3], 30);
}

TEST(TDynamicVector, can_add_vectors_with_equal_size)
{
	TDynamicVector<int> v1(4);
	TDynamicVector<int> v2(4);
	TDynamicVector<int> v3(4);
	v1[0] = 1; v1[1] = 8; v1[2] = 12; v1[3] = 5;
	v2[0] = 5; v2[1] = 3; v2[2] = 9; v2[3] = 12;
	v3 = v1 + v2;
	EXPECT_EQ(v3[0], 6);
	EXPECT_EQ(v3[1], 11);
	EXPECT_EQ(v3[2], 21);
	EXPECT_EQ(v3[3], 17);
}

TEST(TDynamicVector, cant_add_vectors_with_not_equal_size)
{
	TDynamicVector<int> v1(5);
	TDynamicVector<int> v2(4);
	ASSERT_ANY_THROW(v1 + v2);
}

TEST(TDynamicVector, can_subtract_vectors_with_equal_size)
{
	TDynamicVector<int> v1(4);
	TDynamicVector<int> v2(4);
	TDynamicVector<int> v3(4);
	v1[0] = 1; v1[1] = 8; v1[2] = 12; v1[3] = 5;
	v2[0] = 5; v2[1] = 3; v2[2] = 9; v2[3] = 12;
	v3 = v1 - v2;
	EXPECT_EQ(v3[0], -4);
	EXPECT_EQ(v3[1], 5);
	EXPECT_EQ(v3[2], 3);
	EXPECT_EQ(v3[3], -7);
}

TEST(TDynamicVector, cant_subtract_vectors_with_not_equal_size)
{
	TDynamicVector<int> v1(5);
	TDynamicVector<int> v2(4);
	ASSERT_ANY_THROW(v1 - v2);
}

TEST(TDynamicVector, can_multiply_vectors_with_equal_size)
{
	TDynamicVector<int> v1(4);
	TDynamicVector<int> v2(4);
	v1[0] = 1; v1[1] = 8; v1[2] = 12; v1[3] = 5;
	v2[0] = 5; v2[1] = 3; v2[2] = 9; v2[3] = 12;
	int tmp = v1 * v2;
	EXPECT_EQ(tmp, 197);
}

TEST(TDynamicVector, cant_multiply_vectors_with_not_equal_size)
{
	TDynamicVector<int> v1(5);
	TDynamicVector<int> v2(4);
	ASSERT_ANY_THROW(int scalar = v1 * v2);
}

