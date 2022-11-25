#include <gtest/gtest.h>
#include "../src/matrix.h"

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

	// a scalar
	Matrix mat1(1, 1);
	EXPECT_EQ(mat1.rowCount(), 1);
	EXPECT_EQ(mat1.columnCount(), 1);
}

TEST(matrix_tests, dataConstructor) {
	std::vector<double> input1 = {1, 2, 3};
	std::vector<double> input2 = {4, 5, 6};
	std::vector<std::vector<double>> input = {input1, input2};
	Matrix mat(&input);
	EXPECT_EQ(mat.rowCount(), 3);
	EXPECT_EQ(mat.columnCount(), 2);

	std::vector<double> input3 = {4, 5};
	std::vector<std::vector<double>> input_to_fail = {input2, input3};
	EXPECT_THROW(Matrix mat1(&input_to_fail), std::invalid_argument);

	std::vector<double> input4 = {1};
	std::vector<std::vector<double>> scalar = {input4};
	Matrix mat2(&scalar);
	EXPECT_EQ(mat2.rowCount(), 1);
	EXPECT_EQ(mat2.columnCount(), 1);
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
	Matrix mat2(&data);
	int cols2 = mat2.contains().size();
	EXPECT_EQ(cols2, 2);
	int rows2 = mat2.contains()[0].size();
	EXPECT_EQ(rows2, 3);
}

TEST(matrix_tests, contains_contents) {
	std::vector<std::vector<double>> data = {{1, 2, 3, 4, 5, 6}};
	Matrix mat(&data);
	std::vector<std::vector<double>> ans = mat.contains();
	EXPECT_EQ(data, ans);
}

TEST(matrix_tests, multiply_scalar) {
	std::vector<std::vector<double>> data = {{1, 2, 3, 4, 5, 6}};
	std::vector<std::vector<double>> ans = {{2, 4, 6, 8, 10, 12}};

	Matrix mat(&data);
	mat.multiply(2);
	std::vector<std::vector<double>> multiplied = mat.contains();
	EXPECT_EQ(multiplied, ans);
}

TEST(matrix_tests, multiply_vector) {
	std::vector<std::vector<double>> data = {{1, 1}, {2, 2}, {3, 3}};
	Matrix mat(&data);

	std::vector<double> vec1 = {2, 3};
	std::vector<double> vec2 = {1, 2, 3};

	EXPECT_THROW(mat.multiply(&vec1), std::invalid_argument);

	mat.multiply(&vec2);
	std::vector<std::vector<double>> multiplied = mat.contains();
	std::vector<std::vector<double>> ans = {{14}, {14}};
	EXPECT_EQ(multiplied, ans);
}

TEST(matrix_tests, reassign) {
	Matrix mat(8, 4);

	std::vector<double> input1 = {1, 2, 3};
	std::vector<double> input2 = {4, 5, 6};
	std::vector<std::vector<double>> input = {input1, input2};
	mat.reassign(&input);
	EXPECT_EQ(mat.rowCount(), 3);
	EXPECT_EQ(mat.columnCount(), 2);

	std::vector<double> input3 = {4, 5};
	std::vector<std::vector<double>> input_to_fail = {input2, input3};
	EXPECT_THROW(Matrix mat(&input_to_fail), std::invalid_argument);
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
	Matrix mat4(&input1);
	EXPECT_FALSE(mat4.isVector());
	EXPECT_FALSE(mat4.isSquare());

	std::vector<std::vector<double>> input2 = {{1, 2, 3}};
	Matrix mat5(&input2);
	EXPECT_TRUE(mat5.isVector());
	EXPECT_FALSE(mat5.isSquare());

	std::vector<std::vector<double>> input3 = {{1, 2}, {2, 1}};
	Matrix mat6(&input3);
	EXPECT_FALSE(mat6.isVector());
	EXPECT_TRUE(mat6.isSquare());
}

TEST(matrix_tests, vector_types) {
	std::string none = "NONE";
	std::string row = "ROW";
	std::string column = "COLUMN";

	Matrix mat1(1, 5);
	EXPECT_EQ(mat1.vectorType(), column);

	Matrix mat2(100, 1);
	EXPECT_EQ(mat2.vectorType(), row);

	Matrix mat3(500, 400);
	EXPECT_EQ(mat3.vectorType(), none);

	// a scalar
	Matrix mat4;
	EXPECT_EQ(mat4.vectorType(), column);
	Matrix mat5(1, 1);
	EXPECT_EQ(mat5.vectorType(), column);

	std::vector<std::vector<double>> input1 = {{1, 2, 3}, {4, 5, 6}};
	Matrix mat6(&input1);
	EXPECT_EQ(mat6.vectorType(), none);
}

TEST(matrix_tests, transpose) {
	std::vector<std::vector<double>> data = {{1, 2, 3}, {4, 5, 6}};
	Matrix t1(&data);
	Matrix t2(&data);
	t2.transpose();
	EXPECT_EQ(t1.contains()[1][2], t2.contains()[2][1]);
	EXPECT_EQ(t1.contains()[0][1], t2.contains()[1][0]);
	EXPECT_EQ(t1.columnCount(), 2);
	EXPECT_EQ(t1.rowCount(), 3);
	EXPECT_EQ(t2.columnCount(), 3);
	EXPECT_EQ(t2.rowCount(), 2);

	// twice transposing should return original
	Matrix t3 = t2;
	t3.transpose();
	EXPECT_EQ(t1.contains(), t3.contains());
}

TEST(matrix_tests, getElement) {
	std::vector<std::vector<double>> data = {{1, 2, 3}, {4, 5, 6}};
	Matrix t1(&data);
	Matrix t2(&data);
	t2.transpose();
	
	EXPECT_EQ(t1.getElement(2, 0), 3);
	EXPECT_EQ(t2.getElement(1, 0), 4);
	EXPECT_EQ(t2.getElement(1, 2), 6);
}

TEST(matrix_tests, addition) {
	std::vector<std::vector<double>> data1 = {{1, 2, 3}, {4, 5, 6}};
	Matrix mat1(&data1);

	std::vector<std::vector<double>> data2 = {{0, -2, -3}, {-4, -4, -6}};
	Matrix mat2(&data2);
	
	Matrix result = mat1 + mat2;

	std::vector<std::vector<double>> ans = {{1, 0, 0}, {0, 1, 0}};
	EXPECT_EQ(result.contains(), ans);

	Matrix vec(3, 1);
	EXPECT_THROW(vec + mat1, std::invalid_argument);
}

TEST(matrix_tests, subtraction) {
	std::vector<std::vector<double>> data1 = {{1, 2, 3}, {4, 5, 6}};
	Matrix mat1(&data1);

	std::vector<std::vector<double>> data2 = {{100, 100, 100}, {0, 0, 0}};
	Matrix mat2(&data2);
	
	Matrix result = mat2 - mat1;

	std::vector<std::vector<double>> ans = {{99, 98, 97}, {-4, -5, -6}};
	EXPECT_EQ(result.contains(), ans);

	Matrix vec(3, 1);
	EXPECT_THROW(vec - mat1, std::invalid_argument);
}

TEST(matrix_tests, dotProduct) {
	std::vector<double> valid_vec = {5, 5, 4};
	std::vector<double> invalid_vec = {5, 5, 4, 8};

	std::vector<std::vector<double>> data1 = {{1, 2, 3}};
	Matrix mat1(&data1);

	EXPECT_EQ(mat1.dotProduct(&valid_vec), 27);
	EXPECT_THROW(mat1.dotProduct(&invalid_vec), std::invalid_argument);

	std::vector<std::vector<double>> data2 = {{1}, {2}, {3}};
	Matrix mat2(&data2);

	EXPECT_EQ(mat2.dotProduct(&valid_vec), 27);
	EXPECT_THROW(mat1.dotProduct(&invalid_vec), std::invalid_argument);
}