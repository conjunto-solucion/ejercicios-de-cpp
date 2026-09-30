/*
TRABAJO PRÁCTICO CUATRO - EJERCICIO 6.
Solicita N números enteros en un vector y luego pide ingresar un número X para buscarlo.
Informar si el número X se encuentra dentro del vector y en qué índice está

Qué aprendimos:
	Buscar un valor dentro de un arreglo
*/


#include <iostream>
#include <cstdlib>
#include <limits>


int main() {
	std::setlocale(LC_ALL, "");
	
	// El valor que el usuario desea buscar
	int search_value;
	// Una bandera que usaremos para saber si lo encontramos
	bool value_was_found = false;
	
	
	
	// Preguntamos la longitud del arreglo
	std::cout << "Elija la cantidad de elementos del vector: ";
	unsigned int array_size;
	if (!(std::cin >> array_size) || array_size <= 0) {
		std::cerr << "La cantidad de elementos debe ser un número positivo.";
		return EXIT_FAILURE;
	}
	int my_array[array_size];
	
	
	// Leemos los valores para rellenar el arreglo
	std::cout << "Ingrese " << array_size << " números enteros:\n";
	for (int i = 0; i < array_size; i++) {
		
		// Pedimos un número entero. Si hubo un error, lo volvemos a solicitar.
		std::cout << "n" << i + 1 << " = ";
		if (!(std::cin >> my_array[i])) {
			std::cerr << "Número inválido. Intente nuevamente...\n";
			std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			i--;
			continue;
		}
		
		// Limpiamos el búfer
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	
	
	
	// Preguntamos qué valor hay que buscar
	std::cout << "\nIngrese un valor para buscar: ";
	if (!(std::cin >> search_value)) {
		std::cerr << "Número inválido.";
		return EXIT_FAILURE;
	}
	
	
	// Recorremos el arreglo de principio a fin para buscar el valor
	for (int i = 0; i < array_size; i++) {
		
		// Si el valor actual coincide con el buscado, informamos la posición actual
		if (search_value == my_array[i]) {
			std::cout << "Se encontró el valor en la posición n" << i + 1 << "\n";
			value_was_found = true; // También actualizamos la bandera para indicar que sí se encontró el valor
		}
	}
	
	
	// Si la bandera quedó con su valor inicial (false), significa que no se encontró el valor en ninguna posición
	if (!value_was_found) {
		std::cout << "\nNo se encontró el valor buscado.\n";
	}
	
	
	return EXIT_SUCCESS;
}

