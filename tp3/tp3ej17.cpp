/*
TRABAJO PRÁCTICO TRES - EJERCICIO 17.
Escribe los primeros 25 dígitos de la sucesión de Fibonacci.

Nuevas bibliotecas:
	<utility>, para usar swap, que nos permite rápidamente intercambiar los valores de dos variables
*/


#include <iostream>
#include <cstdlib>
#include <utility>
#define UPPER_LIMIT 25


int main() {
	std::setlocale(LC_ALL, "");
	
	// Estas variables representan el número que mostraremos y el siguiente en la sucesión
	unsigned int fibo = 0, next = 1; 
	
	
	std::cout << "Sucesión de Fibonacci hasta el elemento " << UPPER_LIMIT << std::endl;
	
	
	for (int i = 0; i < UPPER_LIMIT; i++) {
		
		// Mostramos el número
		std::cout << fibo << std::endl;
		
		// Intercambiamos los valores de fibo y next: si eran 0 y 1, ahora son 1 y 0
		std::swap(fibo, next);
		
		// Y modificamos el valor de next
		next = next + fibo;
	}
		
	return EXIT_SUCCESS;
}
