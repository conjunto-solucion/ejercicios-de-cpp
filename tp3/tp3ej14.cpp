/*
TRABAJO PRÁCTICO TRES - EJERCICIO 14.
Solicita un número entre 0 y 10 y devuelve la tabla de multiplicar de dicho número.
*/


#include <iostream>
#include <cstdlib>



int main() {
	std::setlocale(LC_ALL, "");
	
	int n = 0;
	
	std::cout << "TABLA DE MULTIPLICAR\n";
	std::cout << "Ingrese un número entero del 1 al 9: ";
	
	// Solicitar el número y validar que se encuentre en (0, 10)
	if (!(std::cin >> n) || n < 1 || n > 9) {
		std::cerr << "Fuera de rango.";
		return EXIT_FAILURE;
	}
	
	// Incrementar el factor desde 0 hasta 10 y mostrar el producto
	for (int factor = 0; factor <= 10; factor++) {
		std::cout << n << "×" << factor << " = " << n * factor << std::endl;
	}
	
		
	return EXIT_SUCCESS;
}
