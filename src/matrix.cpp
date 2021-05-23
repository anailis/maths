#include <utility>
#include <vector>

#include "matrix.h"

// constructors and destructors
Matrix::Matrix() // default constructor creates a scalar
{
	m_numcols = 1;
	m_numrows = 1;
}

Matrix::Matrix(int numrows, int numcols)
{
    m_numrows = numrows;
    m_numcols = numcols;
}

// getters
std::pair<int, int> Matrix::shape() 
{
    std::pair<int, int> xy(m_numrows, m_numcols);
    return xy;
}

// printing

// basic operations  