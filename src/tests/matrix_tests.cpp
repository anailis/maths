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

TEST(matrix_tests, dataConstructor) {
	std::vector<double> input1 = {1, 2, 3};
	std::vector<double> input2 = {4, 5, 6};
	std::vector<std::vector<double>> input = {input1, input2};
	Matrix mat(input);
	EXPECT_EQ(mat.rowCount(), 3);
	EXPECT_EQ(mat.columnCount(), 2);

	std::vector<double> input3 = {4, 5};
	std::vector<std::vector<double>> input_to_fail = {input2, input3};
	EXPECT_THROW(Matrix mat(input_to_fail), std::invalid_argument);
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

TEST(matrix_tests, contains_size) {
	Matrix mat(5, 4);
	int cols = mat.contains().size();
	EXPECT_EQ(cols, 4);
	int rows = mat.contains()[0].size();
	EXPECT_EQ(rows, 5);

	std::vector<std::vector<double>> data = {{1, 2, 3}, {4, 5, 6}};
	Matrix mat2(data);
	int cols2 = mat2.contains().size();
	EXPECT_EQ(cols2, 2);
	int rows2 = mat2.contains()[0].size();
	EXPECT_EQ(rows2, 3);
}

TEST(matrix_tests, contains_contents) {
	std::vector<std::vector<double>> data = {{1, 2, 3, 4, 5, 6}};
	Matrix mat(data);
	std::vector<std::vector<double>> ans = mat.contains();
	EXPECT_EQ(data, ans);
}