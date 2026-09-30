/*
TRABAJO PRÁCTICO UNO - EJERCICIO 3.
Solicita por teclado dos números enteros y muestra su
suma, resta, multiplicación, división.

Qué aprendimos:
    Variables de tipo entero: int
	Operaciones aritméticas
*/


#include <iostream>
#include <cstdlib>


int main() {
	std::setlocale(LC_ALL, "");	
	int A = 0, B = 0;
	
	std::cout << "Ingrese valores enteros.\n";


	std::cout << "A = ";
	if (!(std::cin >> A)) {
		std::cerr << "Fuera de rango.\n";
		return EXIT_FAILURE;
	}


	std::cout << "B = ";
	if (!(std::cin >> B)) {
		std::cerr << "Fuera de rango.\n";
		return EXIT_FAILURE;
	}
	
	
	std::cout << "A + B = " << A + B << std::endl;
	std::cout << "A - B = " << A - B << std::endl;
	std::cout << "A x B = " << A * B << std::endl;
	// Realizamos una validación para impedir que se divida entre 0
	if (B != 0) {
		std::cout << "A / B = " << (float)A / B << std::endl;		
	}
	
	return EXIT_SUCCESS;
}
