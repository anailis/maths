#ifndef MATHSML_MATRIX_H
#define MATHML_MATRIX_H

#include <utility>
#include <vector>

class Matrix
{
    private:
		enum vectorTypes {
			NONE,
			COLUMN,
			ROW
		};

        int m_numrows{ 1 };
        int m_numcols{ 1 }; 
		bool m_vector{ true };
		bool m_square{ true };
		vectorTypes m_vectortype{ NONE };
        std::vector<std::vector<double>> m_array;

    public:
        // constructors
		Matrix();
        Matrix(const int numrows, const int numcols);
		Matrix(const std::vector<std::vector<double>>* array);

        // getters
        const int rowCount() { return m_numrows; };
        const int columnCount() { return m_numcols; };
        const std::pair<int, int> shape();
		const std::vector<std::vector<double>> contains();
		const bool isVector() { return m_vector; };
		const bool isSquare() { return m_square; };
		const std::string vectorType();

		// setters
		void reassign(const std::vector<std::vector<double>>* mat);

		// printing
		void print();

		// basic operations
		void multiply(double value);
		void multiply(std::vector<double>* vec);
		void multiply(Matrix* mat);
		
		void dotProduct(std::vector<double>* vec);
};

#endif //MATHSML_MATRIX_H