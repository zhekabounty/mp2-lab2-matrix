#include "tmatrix.h"

#include <gtest.h>

TEST(TDynamicMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TDynamicMatrix<int> m(5));
}

TEST(TDynamicMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TDynamicMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TDynamicMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TDynamicMatrix<int> m(-5));
}

TEST(TDynamicMatrix, can_create_copied_matrix)
{
  TDynamicMatrix<int> m(5);

  ASSERT_NO_THROW(TDynamicMatrix<int> m1(m));
}

TEST(TDynamicMatrix, copied_matrix_is_equal_to_source_one)
{
	TDynamicMatrix<int> m(5);
	for (int i = 0; i < m.size(); i++) {
		for (int j = 0; j < m.size(); j++) {
			m[i][j] = i + j;
		}
	}
	TDynamicMatrix<int> m1(m);
	for (int i = 0; i < m.size(); i++) {
		for (int j = 0; j < m.size(); j++) {
			EXPECT_EQ(m[i][j], m1[i][j]);
		}
	}
}

TEST(TDynamicMatrix, copied_matrix_has_its_own_memory)
{
	TDynamicMatrix<int> m(5);
	for (int i = 0; i < m.size(); i++) {
		for (int j = 0; j < m.size(); j++) {
			m[i][j] = i + j;
		}
	}
	TDynamicMatrix<int> m1(m);
	m[0][0] = -4;
	for (int i = 0; i < m.size(); i++) {
		for (int j = 0; j < m.size(); j++) {
			if((i == j) && (i == 0))
				EXPECT_NE(m[i][j], m1[i][j]);
			else
				EXPECT_EQ(m[i][j], m1[i][j]);
		}
	}
}

TEST(TDynamicMatrix, can_get_size)
{
	TDynamicMatrix<int> m(4);
	EXPECT_EQ(4, m.size());
}

TEST(TDynamicMatrix, can_set_and_get_element)
{
	TDynamicMatrix<int> m(4);
	m[0][0] = 4;
	EXPECT_EQ(4, m[0][0]);
}

TEST(TDynamicMatrix, throws_when_set_element_with_negative_index)
{
	TDynamicMatrix<int> m(2);
	ASSERT_ANY_THROW(m.at(1).at(-2));
	ASSERT_ANY_THROW(m.at(-2).at(1));
}

TEST(TDynamicMatrix, throws_when_set_element_with_too_large_index)
{
	TDynamicMatrix<int> m(2);
	ASSERT_ANY_THROW(m.at(3).at(1));
	ASSERT_ANY_THROW(m.at(1).at(3));
}

TEST(TDynamicMatrix, can_assign_matrix_to_itself)
{
	TDynamicMatrix<int> m(2);
	ASSERT_NO_THROW(m = m);
}

TEST(TDynamicMatrix, can_assign_matrices_of_equal_size)
{
	TDynamicMatrix<int> m1(5);
	for (int i = 0; i < m1.size(); i++) {
		for (int j = 0; j < m1.size(); j++) {
			m1[i][j] = i + j;
		}
	}
	TDynamicMatrix<int> m2(5);
	m2 = m1;
	for (int i = 0; i < m1.size(); i++) {
		for (int j = 0; j < m1.size(); j++) {
			EXPECT_EQ(m1[i][j], m2[i][j]);
		}
	}
}

TEST(TDynamicMatrix, assign_operator_change_matrix_size)
{
	TDynamicMatrix<int> m1(2);
	TDynamicMatrix<int> m2(4);
	int old_size = m1.size();
	m1 = m2;
	int new_size = m1.size();
	EXPECT_NE(old_size, new_size);
}

TEST(TDynamicMatrix, can_assign_matrices_of_different_size)
{
	TDynamicMatrix<int> m1(2);
	TDynamicMatrix<int> m2(4);
	ASSERT_NO_THROW(m1 = m2);
}

TEST(TDynamicMatrix, compare_equal_matrices_return_true)
{
	TDynamicMatrix<int> m1(5);
	TDynamicMatrix<int> m2(5);
	for (int i = 0; i < m1.size(); i++) {
		for (int j = 0; j < m1.size(); j++) {
			m1[i][j] = i + j;
			m2[i][j] = i + j;
		}
	}
	EXPECT_EQ(m1 == m2, true);
}

TEST(TDynamicMatrix, compare_matrix_with_itself_return_true)
{
	TDynamicMatrix<int> m(5);
	EXPECT_EQ(m == m, true);
}

TEST(TDynamicMatrix, matrices_with_different_size_are_not_equal)
{
	TDynamicMatrix<int> m1(4);
	TDynamicMatrix<int> m2(5);
	EXPECT_EQ(m1 == m2, false);
}

TEST(TDynamicMatrix, can_add_matrices_with_equal_size)
{
	TDynamicMatrix<int> m1(2);
	m1[0][0] = 4;	m1[0][1] = 2;
	m1[1][0] = 9;	m1[1][1] = 0;

	TDynamicMatrix<int> m2(2);
	m2[0][0] = 3;	m2[0][1] = 1;
	m2[1][0] = -3;	m2[1][1] = 4;

	TDynamicMatrix<int> m3(2);
	m3 = m1 + m2;

	EXPECT_EQ(m3[0][0], 7);	EXPECT_EQ(m3[0][1], 3);
	EXPECT_EQ(m3[1][0], 6); EXPECT_EQ(m3[1][1], 4);
}

TEST(TDynamicMatrix, cant_add_matrices_with_not_equal_size)
{
	TDynamicMatrix<int> m1(5);
	TDynamicMatrix<int> m2(4);
	ASSERT_ANY_THROW(m1 + m2);
}

TEST(TDynamicMatrix, can_subtract_matrices_with_equal_size)
{
	TDynamicMatrix<int> m1(2);
	m1[0][0] = 4;	m1[0][1] = 2;
	m1[1][0] = 9;	m1[1][1] = 0;

	TDynamicMatrix<int> m2(2);
	m2[0][0] = 3;	m2[0][1] = 1;
	m2[1][0] = -3;	m2[1][1] = 4;

	TDynamicMatrix<int> m3(2);
	m3 = m1 - m2;

	EXPECT_EQ(m3[0][0], 1);	EXPECT_EQ(m3[0][1], 1);
	EXPECT_EQ(m3[1][0], 12); EXPECT_EQ(m3[1][1], -4);
	
}

TEST(TDynamicMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TDynamicMatrix<int> m1(5);
	TDynamicMatrix<int> m2(4);
	ASSERT_ANY_THROW(m1 - m2);
}

TEST(TDynamicMatrix, can_multiply_matrixes_with_equal_size)
{
	TDynamicMatrix<int> m1(3);
	m1[0][0] = 1;	m1[0][1] = 4;	m1[0][2] = 3;
	m1[1][0] = 2;	m1[1][1] = 1;	m1[1][2] = 5;
	m1[2][0] = 3;	m1[2][1] = 2;	m1[2][2] = 1;

	TDynamicMatrix<int> m2(3);
	m2[0][0] = 5;	m2[0][1] = 2;	m2[0][2] = 1;
	m2[1][0] = 4;	m2[1][1] = 3;	m2[1][2] = 2;
	m2[2][0] = 2;	m2[2][1] = 1;	m2[2][2] = 6;

	TDynamicMatrix<int> m3(3);
	m3 = m1 * m2;

	EXPECT_EQ(m3[0][0], 27);	EXPECT_EQ(m3[0][1], 17);	EXPECT_EQ(m3[0][2], 27);
	EXPECT_EQ(m3[1][0], 24);	EXPECT_EQ(m3[1][1], 12);	EXPECT_EQ(m3[1][2], 34);
	EXPECT_EQ(m3[2][0], 25);	EXPECT_EQ(m3[2][1], 13);	EXPECT_EQ(m3[2][2], 13);
}

TEST(TDynamicMatrix, cant_multiply_matrixes_with_not_equal_size)
{
	TDynamicMatrix<int> m1(5);
	TDynamicMatrix<int> m2(4);
	ASSERT_ANY_THROW(m1 * m2);
}

