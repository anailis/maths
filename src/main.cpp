#include <iostream>

#include "matrix.h"

int main() 
{
    std::vector<std::vector<double>> data = {{1, 2, 3}, {4, 5, 6}};
	std::vector<std::vector<double>>* pointer = &data;
	for (int i = 0; i < 3; i++) {
		std::cout << (*pointer)[1][i] << '\n';
	}
	Matrix mat(&data);
	mat.multiply(2);
	mat.print();

    return 0;
};