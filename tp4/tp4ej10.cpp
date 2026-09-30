/*
TRABAJO PRÁCTICO CUATRO - EJERCICIO 10.
Lee una matriz de 4 x 4 de números enteros
y calcula e informa la suma de los elementos de su diagonal principal.

Qué aprendimos:
	Recorrer la diagonal principal de una matriz cuadrada
*/



#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <limits>


struct Matrix {
    unsigned int rows;
    unsigned int columns;
    std::vector<int> data;
};

Matrix read_matrix(unsigned int rows, unsigned int columns);
void print_matrix(const Matrix m);
int trace(Matrix M);




int main() {
	std::setlocale(LC_ALL, "");
    
    // Orden de nuestra matriz:
	unsigned const int matrix_order = 4;
	
	// Solicitar y leer los elementos:
	std::cout << "Ingrese " << matrix_order * matrix_order << " números enteros:\n";
	Matrix M = read_matrix(matrix_order, matrix_order);
	
	
	// Mostrar la matriz:
	std::cout << "\nMatriz:\n";
	print_matrix(M);
	
	// Calcular y mostrar la traza:
	std::cout << "\nTraza = " << trace(M);
	
	
	
	return EXIT_SUCCESS;
}


// Función que lee una matriz y la devuelve
// Ir al ejercicio 9 para ver la documentación y explicación
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



// Imprime una matriz en la consola
void print_matrix(const Matrix m) {
    for (unsigned int i = 0; i < m.rows; i++) {
        for (unsigned int j = 0; j < m.columns; j++) {
            std::cout << std::setw(8) << std::setprecision(2) << m.data[i * m.columns + j];
        }
        std::cout << std::endl;
    }
}



/**
 * @brief Calcula la traza de una matriz cuadrada
 * 
 * La traza es la suma de los elementos de la diagonal principal
 * 
 * @param Matrix M la matriz cuadrada
 * @return int La suma de los elementos de la diagonal principal
 */
int trace(Matrix M) {
	
	// Si no es una matriz cuadrada, no hay nada para calcular
	if (M.columns != M.rows || M.columns == 0) {
		return 0;
	}
	
	// Inicializamos la sumatoria en 0
	int trace = 0;
	// Recorremos todos los elementos de la diagonal
	// Los elementos de la diagonal se caracterizan por tener el mismo índice de fila y de columna
	for (unsigned int i = 0; i < M.rows; i++) {
        trace += M.data[i * M.rows + i];
    }
    
    // Devolvemos la sumatoria
    return trace;
}
