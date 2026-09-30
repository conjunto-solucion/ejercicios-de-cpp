/*
TRABAJO PRÁCTICO DOS - EJERCICIO 4.
Lee un entero entre el 1 y 9.
Devuelve si se trata de un número primo.
*/



#include <iostream>
#include <cstdlib>



int main() {
	std::setlocale(LC_ALL, "");
	int N = 0;
	
	
	// Leemos un número. Verificamos que esté en [1, 9]
	std::cout << "Ingrese un número del 1 al 9: ";
	if (!(std::cin >> N) || N < 1 || N > 9) {
		std::cerr << "Fuera de rango.";
		return EXIT_FAILURE;
	}
	
	// Lo comparamos con todos los números primos en ese rango
	if (N == 2 || N == 3 || N == 5 || N == 7) {
		std::cout << "Es un número primo.";
	}
	else {
		std::cout << "No es un número primo";
	}
	
	
	return EXIT_SUCCESS;
}
