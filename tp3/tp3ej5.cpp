/*
TRABAJO PRÁCTICO TRES - EJERCICIO 5.
Muestra la suma de los números del 1 al 100.
*/


#include <iostream>
#include <cstdlib>

// Puedes probar a cambiar este límite para ver como cambia el resultado
#define UPPER_LIMIT 100


int main() {
	std::setlocale(LC_ALL, "");
	
	// Aquí usamos la constante simbólica que definimos más arriba
	std::cout << "La suma de los enteros del 1 al " << UPPER_LIMIT << " es ";
	
	
	// Usamos la fórmula de sumatoria de una progresión aritmética.
	// La fórmula nos dice la sumatoria hasta el elemento N es:
	// N * (N + 1) / 2	Esto nos permite sumar los número del 1 al 100
	std::cout << UPPER_LIMIT * (UPPER_LIMIT + 1) / 2 << "\n";
	
	
	return EXIT_SUCCESS;
}
