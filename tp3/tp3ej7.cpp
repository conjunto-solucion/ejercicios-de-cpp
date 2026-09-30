/*
TRABAJO PRÁCTICO TRES - EJERCICIO 7.
Muestra la media de una lista indefinida de números positivos.
Finaliza cuando se ingresa un número negativo.

Qué aprendimos:
	Usar estructuras repetitivas MIENTRAS (while)
*/



#include <iostream>
#include <cstdlib>


int main() {
	std::setlocale(LC_ALL, "");
	
	// La cantidad de números que se guardan. Siempre es un número positivo, por eso usamos unsigned
	unsigned int n = 0;
	
	// En estas tres variables guardaremos el número ingresado y la sumatoria, respectivamente
	int input_number = 0, sum = 0;
	
	
	std::cout << "Ingrese números positivos. Se calculará el promedio. No se contarán los ceros.\n";
	std::cout << "Para finalizar, ingrese un número negativo.\n";
	
	
	// Este es una estructura MIENTRAS. En su encabezado tiene una condición.
	// Ejecutará el bloque de código siempre que se cumpla input_number >= 0.
	// Notar que la primera vez será verdadero, porque la inicializamos con 0
	while (input_number >= 0) {
		
		// Pedir un número entero
		if (!(std::cin >> input_number)) {
			std::cerr << "Entrada inválida. Finalizando...\n";
			break;
		}
		
		// Agregar a la sumatoria sólo si el número es positivo
		if (input_number > 0) {
			sum += input_number;
			n++;
		}
	}
	
	// Calculamos y mostramos el promedio sólo si se cargó al menos un valor
	if (n > 0) {
		std::cout << "Tamaño = " << n;
		std::cout << "\nMedia = " << (float)sum / n;
	}
	
	else {
		std::cout << "No se ha ingresado ningún número positivo.";
	}
	
	return EXIT_SUCCESS;
}
