/*
TRABAJO PRÁCTICO TRES - EJERCICIO 4.
Muestra los números impares entre el 1 y el 100.
*/


#include <iostream>
#include <cstdlib>


int main() {
	std::setlocale(LC_ALL, "");
	std::cout << "Números impares del 1 al 100:\n";
	
	// Al comienzo i = 1, luego 1 + 2 = 3, luego 3 + 2 = 5... mientras i < 100
	for (int i = 1; i < 100; i+=2) {
		std::cout << i << " ";
	}
	
	return EXIT_SUCCESS;
}
