/*
TRABAJO PRÁCTICO DOS - EJERCICIO 2.
Lee tres números, informa cuál es el mayor.
*/


#include <iostream>
#include <cstdlib>


int main() {
	std::setlocale(LC_ALL, "");
	float A = 0.0f, B = 0.0f, C = 0.0f;
	
	std::cout << "Ingresar tres números.\n";
	
	
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
	
	
	// Probamos las 7 posibilidades (la última por descarte)
	if (A > B && A > C) {
		std::cout << "El primer número (A) es el mayor.\n";
	}
	else if (B > C && B > A) {
		std::cout << "El segundo número (B) es el mayor.\n";
	}
	else if (C > A && C > B) {
		std::cout << "El tercer número (C) es el mayor.\n";
	}
	else if (A > C && A == B) {
		std::cout << "El primer y segundo número (A y B) son los mayores.\n";
	}
	else if (A == C && A > B) {
		std::cout << "El primer y tercer número (A y C) son los mayores.\n";
	}
	else if (B == C && B > A) {
		std::cout << "El segundo y tercer número (B y C) son los mayores.\n";
	}
	else {
		std::cout << "Los tres números son iguales.\n";
	}
	
	
	return EXIT_SUCCESS;
}
