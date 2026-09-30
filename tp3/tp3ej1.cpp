/*
TRABAJO PRÁCTICO TRES - EJERCICIO 1.
Muestra los números enteros del 1 al 100.

Qué aprendimos:
	Usar la estructura repetitiva for
*/



#include <iostream>
#include <cstdlib>


int main() {
	std::setlocale(LC_ALL, "");
	
	std::cout << "Números del 1 al 100:\n";
	
	// Esto es un bucle REPETIR. Tiene tres partes en el encabezado.
	// 		1: Primero definimos la variable de control (centinela o iterador).
	//		2: Luego definimos la condición. El bloque se ejecutará mientras esta sea verdadera.
	//		3: Por último definimos el incremento o decremento de la variable de control. En este caso, i++ significa "i = i + 1"
	for (int i = 1; i <= 100; i++) {
		
		// Imprimir la variable de control
		std::cout << i << " ";
	}
	
	return EXIT_SUCCESS;
}
