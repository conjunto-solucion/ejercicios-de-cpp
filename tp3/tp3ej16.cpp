/*
TRABAJO PRÁCTICO TRES - EJERCICIO 16.
Calcula la suma de los cuadrados de los 100 primeros números enteros positivos.
Es decir: 1² + 2² + 3² + ... + 100²
*/


#include <iostream>
#include <cstdlib>
#define UPPER_LIMIT 100


int main() {
	std::setlocale(LC_ALL, "");
	
	// Comenzamos en 0...
	unsigned int sum_of_squares = 0;
	
	// ...Y vamos sumandole los cuadrados a partir de 1²
	for (unsigned int n = 1; n <= UPPER_LIMIT; n++) {
		sum_of_squares += n * n;
	}
	
	// Mostramos el resultado
	std::cout << "Suma de los cuadrados de los primeros " << UPPER_LIMIT << " enteros positivos =\n";
	std::cout << sum;
	
	
	return EXIT_SUCCESS;
}
