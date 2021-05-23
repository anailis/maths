#include <gtest/gtest.h>
#include "../matrix.h"

TEST(matrix_tests, defaultConstructor) {
	Matrix mat;
	EXPECT_EQ(mat.rowCount(), 1);
	EXPECT_EQ(mat.columnCount(), 1);
	EXPECT_NE(mat.rowCount(), 3);
	EXPECT_NE(mat.columnCount(), 2);
}

TEST(matrix_tests, dimensionConstructor) {
	Matrix mat(5, 4);
	EXPECT_EQ(mat.rowCount(), 5);
	EXPECT_EQ(mat.columnCount(), 4);
}

TEST(matrix_tests, rowCount) {
	Matrix mat(5, 4);
	EXPECT_EQ(mat.rowCount(), 5);
}

TEST(matrix_tests, columnCount) {
	Matrix mat(5, 4);
	EXPECT_EQ(mat.columnCount(), 4);
}

TEST(matrix_tests, shape) {
	Matrix mat(5, 4);
	std::pair<int, int> ans;
	ans.first = 5;
	ans.second = 4;
	EXPECT_EQ(mat.shape(), ans);
}

TEST(matrix_tests, contains) {
	Matrix mat(5, 4);
	int cols = mat.contains().size();
	EXPECT_EQ(cols, 4);
	int rows = mat.contains()[0].size();
	EXPECT_EQ(rows, 5);
}