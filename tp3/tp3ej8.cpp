/*
TRABAJO PRÁCTICO TRES - EJERCICIO 8.
Cuenta los números pares entre el 1 y el 50.
*/


#include <iostream>
#include <cstdlib>
#define UPPER_LIMIT 50


int main() {
	std::setlocale(LC_ALL, "");
	
	
	unsigned int even_count = 0;
	
	// Empezamos en 2 y saltamos de 2 en 2
	for (int i = 2; i <= UPPER_LIMIT; i += 2) {
		even_count++;
	}
	
	std::cout << "Hay " << even_count << " números pares entre 1 y " << UPPER_LIMIT;
	
	
	
	return EXIT_SUCCESS;
}
