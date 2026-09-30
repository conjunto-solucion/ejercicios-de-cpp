/*
TRABAJO PRÁCTICO DOS - EJERCICIO 1.
Lee dos números, informa cuál es el mayor.

Qué aprendimos:
	Usar estructuras si-sino-si (if... else if...)
*/


#include <iostream>
#include <cstdlib>


int main() {
	std::setlocale(LC_ALL, "");
	float A = 0.0f, B = 0.0f;
	
	std::cout << "Ingrese dos números.\n";
	
	// Leemos el primer número
	std::cout << "A = ";
	if (!(std::cin >> A)) {
		std::cerr << "Error al leer el número.";
		return EXIT_FAILURE;
	}
	
	// Leemos el segundo número
	std::cout << "B = ";
	if (!(std::cin >> B)) {
		std::cerr << "Error al leer el número.";
		return EXIT_FAILURE;
	}
	
	
	// Preguntamos por las 3 posibilidades (la 3ra por descarte)
	if (A > B) {
		std::cout << "El primer número (A) es mayor.";
	}
	else if (A < B) {
		std::cout << "El segundo número (B) es mayor.";
	}
	else {
		std::cout << "Los números son iguales.";
	}
	
	
	return EXIT_SUCCESS;
	
}
