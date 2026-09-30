/*
TRABAJO PRÁCTICO CUATRO - EJERCICIO 3.
Almacena 15 números en un vector y determina cuál
es el valor máximo ingresado y en qué posición se encuentra

Qué aprendimos:
	Nuevas bibliotecas: <cfloat> para usar FLT_MAX
*/


#include <iostream>
#include <cstdlib>
#include <limits>
#include <cfloat>


int main() {
	std::setlocale(LC_ALL, "");
    
    
	unsigned int const array_length = 15;
	// Aquí guardaremos el valor máximo
	// Lo inicializamos con el menor valor posible, usando el opuesto del mayor posible,
	// que se encuentra en la constante FLT_MAX  de la biblioteca cfloat
	float max_value = -FLT_MAX;
	// Un arreglo de elementos de punto flotante
	float my_array[array_length];
	
	
	// Cargamos los elementos del arreglo:
	std::cout << "Ingrese " << array_length << " números:\n";
	for (int i = 0; i < array_length; i++) {
		
		std::cout << "n" << i + 1 << " = ";
		if (!(std::cin >> my_array[i])) {
			std::cerr << "Número inválido. Intente nuevamente...\n";
			std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			i--;
			continue;
		}
		
		// Si el elemento recién cargado es mayor al récord guardado en max_value, actualizamos max_value
		if (my_array[i] > max_value) {
			max_value = my_array[i];
		}
		
		
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	
	
	// Informamos cuál fue el valor mayor
	std::cout << "\nEl valor máximo ingresado es " << max_value;
	
	// Luego volvemos a recorrer todo el arreglo para determinar en qué posición o posiciones está
	// Hacemos esto porque es posible que el valor máximo esté en más de una posición.
	std::cout << "\nSe encuentra en: ";
	for (int i = 0; i < array_length; i++) {
		if (my_array[i] ==  max_value) {
			std::cout << "n" << i + 1 << " ";
		}
	}
	
	
	return EXIT_SUCCESS;
}

