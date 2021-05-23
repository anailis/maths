#include <utility>
#include <vector>

#include "matrix.h"

// constructors and destructors
Matrix::Matrix() // default constructor creates a scalar
{
	m_numcols = 1;
	m_numrows = 1;
	m_array.resize(m_numcols, std::vector<int *>(m_numrows));
}

Matrix::Matrix(const int numrows, const int numcols)
{
    m_numrows = numrows;
    m_numcols = numcols;
	m_array.resize(m_numcols, std::vector<int *>(m_numrows));
}

// getters
const std::pair<int, int> Matrix::shape() 
{
    const std::pair<int, int> xy(m_numrows, m_numcols);
    return xy;
}

const std::vector<std::vector<int *>> Matrix::contains()
{
	return m_array;
}

// printing

// basic operations  