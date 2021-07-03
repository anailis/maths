#ifndef MATHSML_MATRIX_H
#define MATHML_MATRIX_H

#include <utility>
#include <vector>

class Matrix
{
    private:
        int m_numrows{ 1 };
        int m_numcols{ 1 }; 
        std::vector<std::vector<int>> m_array;

    public:
        // constructors
		Matrix();
        Matrix(const int numrows, const int numcols);
		Matrix(const std::vector<std::vector<int>> array);

		// setters 


        // getters
        const int rowCount() { return m_numrows; };
        const int columnCount() { return m_numcols; };
        const std::pair<int, int> shape();
		const std::vector<std::vector<int>> contains();

		// printing
		void print();
};

#endif //MATHSML_MATRIX_H