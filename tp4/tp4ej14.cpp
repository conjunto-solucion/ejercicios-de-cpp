/*
TRABAJO PRÁCTICO CUATRO - EJERCICIO 14.
Permite ingresar valores en dos matrices de 3 x 3 (A y B),
genera una tercera matriz C resultante de la suma de A + B, y la muestre por pantalla.

Qué aprendimos:
	Sumar dos matrices
*/



#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <limits>
#include <vector>


struct Matrix {
    unsigned int rows;
    unsigned int columns;
    std::vector<float> data;
};

Matrix add_matrices(Matrix A, Matrix B);
void print_matrix(const Matrix m);
Matrix read_matrix(unsigned int rows, unsigned int columns);




int main() {
	std::setlocale(LC_ALL, "");
	std::cout << "Sumador de matrices\n";
	
	// Definimos el orden de la matriz
	unsigned int const order = 3;
	
	// Leer la primera matriz
	std::cout << "Ingrese " << order * order << " números reales para A:\n";
	Matrix A = read_matrix(order, order);
	
	
	// Leer la segunda matriz
	std::cout << "Ingrese " << order * order << " números reales para B:\n";
	Matrix B = read_matrix(order, order);
	
	
	// Creamos la matriz suma C:
	Matrix C = add_matrices(A, B);
	
	
	// Mostramos la matriz A y la matriz B
	std::cout << "A =\n";
	print_matrix(A);
	std::cout << "B =\n";
	print_matrix(B);
	
	
	// Mostramos la matriz C
	std::cout << "\nA + B =\n";
	print_matrix(C);
	
	
	
	return EXIT_SUCCESS;
}




Matrix read_matrix(unsigned int rows, unsigned int columns) {
    Matrix m;
    m.rows = rows;
    m.columns = columns;
    m.data.resize(rows * columns);

	for (unsigned int i = 0; i < m.data.size(); i++) {
    	if (!(std::cin >> m.data[i])) {
			std::cerr << "Número inválido. Intente nuevamente:\n";
			i--;		
		}
		std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return m;
}

void print_matrix(const Matrix m) {
    for (unsigned int i = 0; i < m.rows; i++) {
        for (unsigned int j = 0; j < m.columns; j++) {
            std::cout << std::setw(8) << std::setprecision(2) << m.data[i * m.columns + j];
        }
        std::cout << std::endl;
    }
}


/**
 * @brief Suma dos matrices y devuelve la matriz resultante
 * @param Matrix A la primera matriz cuadrada
 * @param Matrix B la segunda matriz cuadrada, del mismo orden que A
 * @return Matrix la matriz suma. Si no se pudo sumar, devuelve una matriz vacía
 */
Matrix add_matrices(Matrix A, Matrix B) {
	
	// Si no tienen las mismas dimensiones, no se puede realizar la suma
	if (A.columns != B.columns || A.rows != B.rows) {
		return Matrix();
	}
	
	// Declaramos la matriz suma, con las mismas dimensiones que A y B
	Matrix SUM;
    SUM.rows = A.rows;
    SUM.columns = A.columns;
    SUM.data.resize(A.rows * A.columns);

	// Recorremos SUM, asignandole la suma de los elementos correspondientes de A y B
    for (unsigned int i = 0; i < SUM.data.size(); i++) {
        SUM.data[i] = A.data[i] + B.data[i];
    }
    
    // Retornamos la suma
	return SUM;
}

