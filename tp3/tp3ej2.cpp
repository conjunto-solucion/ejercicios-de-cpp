/*
TRABAJO PRÁCTICO TRES - EJERCICIO 2.
Muestra los números enteros del 100 al 1.

Qué aprendimos:
	Usar la estrucrura for un un decremento (i--)
*/


#include <iostream>
#include <cstdlib>


int main() {
	std::setlocale(LC_ALL, "");
	
	std::cout << "Números del 100 al 1:\n";
	
	// Inicializamos i como 100, y le restamos 1 al final de cada vuelta
	for (int i = 100; i >= 1; i--) {
		std::cout << i << " ";
	}

	return EXIT_SUCCESS;
}
