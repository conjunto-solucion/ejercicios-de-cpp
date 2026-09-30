/*
TRABAJO PRÁCTICO CUATRO - EJERCICIO 12.
Determina si una matriz cuadrada de N x N ingresada
por el usuario es una matriz identidad.
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
bool is_identity_matrix(Matrix m);





int main() {
	std::setlocale(LC_ALL, "");
	
	// Leemos el orden de la matriz
	int order = 0;
	std::cout << "Elija el orden de la matriz: ";
	if (!(std::cin >> order) || order <= 0) {
		std::cerr << "Error. El orden de la matriz debe ser un entero positivo.";
		return EXIT_FAILURE;
	}

	// Leemos los elementos de la matriz
	std::cout << "Ingrese " << order*order << " números enteros:\n";	
	Matrix M = read_matrix(order, order);
	
	
	// Mostramos la matriz recién cargada
	print_matrix(M);
	
	
	// Usamos nuestra función is_identity_matrix() para decidir qué mensaje mostrar
	if (is_identity_matrix(M)) {
		
		std::cout << "\nMatriz identidad.";
	}
	
	else {
		
		std::cout << "\nNo es una matriz identidad.";
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
 * @brief Determina si una matriz cuadrada es una matriz identidad
 * @param Matrix M la matriz de números enteros
 * @return bool Si se trata de una matriz identidad o no
 */
bool is_identity_matrix(Matrix m) {
	
	// Si no es cuadrada, no es identidad
	if (m.columns != m.rows) {
		return false;
	}
	
	// Guardamos el orden en m, ahora que sabemos que es cuadrada
	unsigned int const n = m.rows;
	
	// Recorremos TODOS los elementos
	// Si el elemento está en la diagonal principal, debería ser 1
	// Si el elemento no está en la diagonal principal, debería ser 0
	// Si en algún momento no se cumplen estas dos condiciones, inmediatamente sabemos que no es identidad
	for (unsigned int i = 0; i < n; i++) {
		for(unsigned int j = 0; j < n; j++) {
			
			// Verificamos ambas condiciones de una sola vez
			if (j == i && m.data[i * n + j] != 1
			 || j != i && m.data[i * n + j] != 0) {
				
				return false; // Significa que no es identidad
			}
		}
	}
	
	// Si llegó hasta aquí, pasó todas las pruebas y es una matriz identidad
	return true;
}

