#ifndef MATHSML_MATRIX_H
#define MATHML_MATRIX_H

#include <utility>
#include <vector>

class Matrix
{
    private:
        int m_numrows;
        int m_numcols; 
        //std::vector<std::vector<int>> array;

    public:
        // constructors
		Matrix();
        Matrix(int numrows, int numcols);

		// setters 


        // getters
        int rowCount() { return m_numrows; };
        int columnCount() { return m_numcols; };
        std::pair<int, int> shape();
};

#endif //MATHSML_MATRIX_H