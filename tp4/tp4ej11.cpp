/*
TRABAJO PRÁCTICO CUATRO - EJERCICIO 11.
Carga una matriz de 3 x 4
y muestra la suma acumulada de cada una de sus filas por separado

Qué aprendimos:
	Sumar las filas de una matriz
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
int row_sum(Matrix M, unsigned int row);
Matrix read_matrix(unsigned int rows, unsigned int columns);
void print_matrix(const Matrix m);





int main() {
	std::setlocale(LC_ALL, "");
	
	std::cout << "Calculadora de las sumatorias de las filas de una matriz.\n";
    
    // Definimos la cantidad de filas y de columnas de la matriz
	unsigned const int rows = 3, columns = 4;
	
	// Solicitamos los elementos y los leemos con read_matrix()
	std::cout << "Ingrese " << rows*columns << " números enteros:\n";
	Matrix M = read_matrix(rows, columns);
	
	// Mostramos la matriz recién cargada
	std::cout << "\nMatriz:\n";
	print_matrix(M);
	std::cout << std::endl;
	
	// Por cada fila, imprimimos su sumatoria usando la función row_sum
	for (unsigned int i = 0; i < M.rows; i++) {
		std::cout << "Sumatoria de fila " << i + 1 << " = " << row_sum(M, i) << std::endl;
	}
	
	
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
 * @brief Calcula la sumatoria de los elementos de una fila de una matriz
 * 
 * @param Matrix M la matriz de números enteros
 * @param int row La fila de la cual queremos saber su sumatoria
 * @return int La suma de los elementos de la fila indicada
 */
int row_sum(Matrix M, unsigned int row) {
	// Inicializamos la sumatoria en 0
	int sum = 0;
	
	// Recorremos todas las columnas en la fila row
	for(unsigned int j = 0; j < M.columns; j++) {
		// Por cada celda, sumamos su valor a sum
		sum += M.data[row * M.columns + j];
	}
	
	// Devolvemos la sumatoria
	return sum;
}
