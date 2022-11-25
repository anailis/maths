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
        const int rowCount() const { return m_numrows; };
        const int columnCount() const { return m_numcols; };
		const double getElement(int row, int column) const;
        const std::pair<int, int> shape() const;
		const std::vector<std::vector<double>> contains() const;
		const bool isVector() { return m_vector; };
		const bool isSquare() { return m_square; };
		const std::string vectorType();

		// setters
		void reassign(const std::vector<std::vector<double>>* mat);

		// printing
		void print();

		// basic operations
		friend Matrix operator+(const Matrix& a, const Matrix& b);
		friend Matrix operator-(const Matrix& a, const Matrix& b);
		void multiply(double value);
		void multiply(std::vector<double>* vec);
		void multiply(Matrix* mat);
		
		Matrix transpose() const;

		double dotProduct(std::vector<double>* vec) const;
};

#endif //MATHSML_MATRIX_H