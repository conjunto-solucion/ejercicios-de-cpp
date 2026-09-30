/*
TRABAJO PRÁCTICO DOS - EJERCICIO 10.
Dados tres números ingresados, identifica el número central.
*/


#include <iostream>
#include <cstdlib>


int main() {
	std::setlocale(LC_ALL, "");
	
	float A = 0.0f, B = 0.0f, C = 0.0f;
	std::cout << "Ingrese tres números.\n";
	
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
	
	// Leemos el tercer número
	std::cout << "C = ";
	if (!(std::cin >> C)) {
		std::cerr << "Error al leer el número.";
		return EXIT_FAILURE;
	}
	
	
	// Probar las 4 posibilidades:
	if (B>A && A>C || C>A && A>B) {
		std::cout << "El número central es A = " << A;
	}
	
	else if (A>B && B>C || C>B && B>A) {
		std::cout << "El número central es B = " << B;
	}
	
	else if (A>C && C>B || B>C && C>A) {
		std::cout << "El número central es C = " << C;
	}
	
	// La última es por descarte:
	else {
		std::cout << "No hay un número central.";
	}
	
	return EXIT_SUCCESS;
}
