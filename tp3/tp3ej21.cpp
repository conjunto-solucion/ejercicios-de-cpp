/*
TRABAJO PRÁCTICO TRES - EJERCICIO 21.
Imprime el número 1, una vez; el 2, dos veces; el 3, tres veces;
y así sucesivamente hasta llegar a un número n ingresado por teclado.
*/

#include <iostream>
#include <cstdlib>


int main() {
	std::setlocale(LC_ALL, "");
	
	// Definimos un límite hasta el cual realizar la operación
	int limit;
	
	// Solicitamos dicho límite al usuario
	// Decidimos arbitrariamente hacer que el valor máximo sea 500. Para valores muy grandes tarda mucho en ejecutarse
	std::cout << "Ingrese un número positivo del 1 al 500:\n";
	if (!(std::cin >> limit) || limit < 1 || limit > 500) {
		std::cerr << "Fuera de rango.";
		return EXIT_FAILURE;
	}
	
	
	// Recorremos desde 1 hasta el límite.
	// Usamos short para guardar números enteros pequeños (hasta aproximadamente 32.000).
	// Investiguen cuándo conviene usar short y cuándo int ¿qué otras formas de guardar números hay?
	for (short n = 1; n <= limit; n++) {
		
		// Por cada número n, repetimos n cantidad de veces
		for (short i = 0; i < n; i++) {
			std::cout << n << " "; // mostramos el número n
		}
		
		// Escribimos un salto de línea
		std::cout << std::endl;
	}
	
	
	return EXIT_SUCCESS;
}
