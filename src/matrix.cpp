#include <iostream>
#include <utility>
#include <stdexcept>
#include <vector>

#include "matrix.h"

// constructors and destructors
Matrix::Matrix() // default constructor creates a scalar
{
	m_numcols = 1;
	m_numrows = 1;
	// resize array to have a number of elements equal to the number of columns
	// each of these elements is another vector of size number of rows 
	m_array.resize(m_numcols, std::vector<double>(m_numrows));
}

Matrix::Matrix(const int numrows, const int numcols)
{
    m_numrows = numrows;
    m_numcols = numcols;
	m_array.resize(m_numcols, std::vector<double>(m_numrows));

	m_square = m_numrows == m_numcols;
	m_vector = m_numrows == 1 | m_numcols == 1;
}

Matrix::Matrix(const std::vector<std::vector<double>>* array) 
{
	m_array = *array;
	m_numcols = m_array.size();
	m_numrows = m_array[0].size();

	m_square = m_numrows == m_numcols;
	m_vector = m_numrows == 1 | m_numcols == 1;

	for (int column = 1; column < m_numcols; column++)
	{
		if (m_array[column].size() != m_numrows) 
		{
			throw std::invalid_argument("All rows must be of equal length");
		}
	}
}

// getters
const std::pair<int, int> Matrix::shape() 
{
    const std::pair<int, int> xy(m_numrows, m_numcols);
    return xy;
}

const std::vector<std::vector<double>> Matrix::contains()
{
	return m_array;
}

// setters
void Matrix::reassign(const std::vector<std::vector<double>>* mat)
{
	m_array = *mat;
	m_numcols = m_array.size();
	m_numrows = m_array[0].size();

	for (int column = 1; column < m_numcols; column++)
	{
		if (m_array[column].size() != m_numrows) 
		{
			throw std::invalid_argument("All rows must be of equal length");
		}
	}
}

// printing
void Matrix::print()
{
	for (auto vec: m_array) {
		for (auto i: vec) {
			std::cout << i << ' ';
		}
		std::cout << '\n';
	}
}

// basic operations  
void Matrix::multiply(double value) 
{
	for( auto &vec: m_array )
	{
		for (auto &i: vec) {
			i *= value;
		}
	}
}

// input assumed to be a pointer to a column vector 
void Matrix::multiply(std::vector<double>* vec) 
{
	// check that dimensions allow for multiplication 
	if ((*vec).size() != m_numcols) {
		throw std::invalid_argument("Length of vector b must be equal to the number of columns in the matrix A to perform Ab");
	}

	// matrix to store the results 
	std::vector<std::vector<double>> ans;
	ans.resize(m_numrows, std::vector<double>(1));

	for (int i = 0; i < m_numrows; i++) {
		double sum = 0;
		for (int j = 0; j < (*vec).size(); j++) {
			sum += (*vec)[j] * m_array[j][i];
		}
  		ans[i][0] = sum;
	}

	this->reassign(&ans);
}

void Matrix::dotProduct(std::vector<double>* vec) 
{

}

//void Matrix::multiply(Matrix* mat)
//{
//	if (mat.rowCount() != m_numcols) {
//		throw std::invalid_argument("Number of rows in matrix B must be equal to the number of columns in the matrix A to perform AB");
//	}

//	std::vector<std::vector<double>> ans;
//	ans.resize(mat.columnCount(), std::vector<double>(m_numrows));

	// matrix multiplication is the inner product  
//	for (int row = 0; row < m_numrows; row++) {
//		for (int col = 0; col < m_numcols; col++) {
//			std::inner_product(m_array[row], m_array[row] + m_numcols, m_array[col], 0);
//		}
//	}
//}
