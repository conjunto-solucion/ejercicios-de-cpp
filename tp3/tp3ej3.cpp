/*
TRABAJO PRÁCTICO TRES - EJERCICIO 3.
Muestra los números pares entre el 1 y el 100.

Qué aprendimos:
	Usar el for con un incremento personalizado ( i += 2 )
*/


#include <iostream>
#include <cstdlib>


int main() {
	std::setlocale(LC_ALL, "");
	
	std::cout << "Números pares del 1 al 100:\n";
	
	// Aquí i += 2 es una forma abreviada de escribir i = i + 2
	// Significa que se sumará 2 a la variable i al final de cada iteración
	for (int i = 2; i <= 100; i+=2) {
		std::cout << i << " ";
	}
	
	return EXIT_SUCCESS;
}
