/*
TRABAJO PRÁCTICO DOS - EJERCICIO 6.
Dado un número ingresado por teclado, escribe si es par o impar.
*/


#include <iostream>
#include <cstdlib>


int main() {
	std::setlocale(LC_ALL, "");
	int num = 0;
	
	// Leemos un número entero
	std::cout << "Ingrese un número entero: ";	
	if (!(std::cin >> num)) {
		std::cerr << "Inválido.";
		return EXIT_FAILURE;
	}
	
	
	// Usamos el operador ? para decidir qué mensaje mostrar
	// Condición: num % 2 == 0 (el resto de num/2 es 0)
	std::cout << (num % 2 == 0 ? "Es par." : "Es impar.");
	
	
	return EXIT_SUCCESS;
}
