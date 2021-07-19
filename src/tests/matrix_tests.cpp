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

TEST(matrix_tests, multiply_scalar) {
	std::vector<std::vector<double>> data = {{1, 2, 3, 4, 5, 6}};
	std::vector<std::vector<double>> ans = {{2, 4, 6, 8, 10, 12}};

	Matrix mat(data);
	mat.multiply(2);
	std::vector<std::vector<double>> multiplied = mat.contains();
	EXPECT_EQ(multiplied, ans);
}

TEST(matrix_tests, multiply_vector) {
	std::vector<std::vector<double>> data = {{1, 1}, {2, 2}, {3, 3}};
	Matrix mat(data);

	std::vector<double> vec1 = {2, 3};
	std::vector<double> vec2 = {1, 2, 3};

	EXPECT_THROW(mat.multiply(vec1), std::invalid_argument);

	mat.multiply(vec2);
	std::vector<std::vector<double>> multiplied = mat.contains();
	std::vector<std::vector<double>> ans = {{14}, {14}};
	EXPECT_EQ(multiplied, ans);
}

TEST(matrix_tests, reassign) {
	Matrix mat(8, 4);

	std::vector<double> input1 = {1, 2, 3};
	std::vector<double> input2 = {4, 5, 6};
	std::vector<std::vector<double>> input = {input1, input2};
	mat.reassign(input);
	EXPECT_EQ(mat.rowCount(), 3);
	EXPECT_EQ(mat.columnCount(), 2);

	std::vector<double> input3 = {4, 5};
	std::vector<std::vector<double>> input_to_fail = {input2, input3};
	EXPECT_THROW(Matrix mat(input_to_fail), std::invalid_argument);
}

TEST(matrix_tests, matrix_types) {
	Matrix mat1(1, 5);
	EXPECT_TRUE(mat1.isVector());
	EXPECT_FALSE(mat1.isSquare());

	Matrix mat2;
	EXPECT_TRUE(mat2.isVector());
	EXPECT_TRUE(mat2.isSquare());

	Matrix mat3(6, 6);
	EXPECT_FALSE(mat3.isVector());
	EXPECT_TRUE(mat3.isSquare());

	std::vector<std::vector<double>> input1 = {{1, 2, 3}, {4, 5, 6}};
	Matrix mat4(input1);
	EXPECT_FALSE(mat4.isVector());
	EXPECT_FALSE(mat4.isSquare());

	std::vector<std::vector<double>> input2 = {{1, 2, 3}};
	Matrix mat5(input2);
	EXPECT_TRUE(mat5.isVector());
	EXPECT_FALSE(mat5.isSquare());

	std::vector<std::vector<double>> input3 = {{1, 2}, {2, 1}};
	Matrix mat6(input3);
	EXPECT_FALSE(mat6.isVector());
	EXPECT_TRUE(mat6.isSquare());
}