/*
TRABAJO PRÁCTICO CUATRO - EJERCICIO 2.
Permite cargar un vector de N elementos enteros,
calcula la suma de todos sus valores e informe el promedio general

Qué aprendimos:
	Declarar un arreglo cuya longitud fue definida por el usuario
*/


#include <iostream>
#include <cstdlib>
#include <limits>


int main() {
	std::setlocale(LC_ALL, "");
    
    // Dejamos la cantidad de elementos indefinida por ahora
	unsigned int array_length;
	// Aquí guardaremos la suma de los elementos
	int sum = 0;


	// Ahora le pedimos al usuario que defina array_length
	std::cout << "Elija la cantidad de elementos del arreglo: ";
	if (!(std::cin >> array_length) || array_length <= 0) {
		std::cerr << "La cantidad de elementos debe ser un número positivo.";
		return EXIT_FAILURE;
	}
	
	// Ya sabemos la longitud. Ahora sí podemos definir el arreglo
	int my_array[array_length];
	
	
	// Leemos todas las posiciones de 0 en adelante
	std::cout << "Ingrese " << array_length << (array_length == 1? " número entero:\n": " números enteros:\n");
	for (int i = 0; i < array_length; i++) {
		
		std::cout << "n" << i + 1 << " = ";
		if (!(std::cin >> my_array[i])) {
			// Volvemos a preguntar si la lectura fue inválida
			std::cerr << "Número inválido. Intente nuevamente...\n";
			std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			i--;
			continue;
		}
		
		// Agregamos el número leído a la sumatoria
		sum += my_array[i];
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	
	
	// Mostramos la sumatoria y la media
	std::cout << "\nSUMA TOTAL = " << sum;
	std::cout << "\nMEDIA = " << (float)sum / array_length; // escribir (float) nos asegura que el resultado debe ser del tipo float
	
	
	return EXIT_SUCCESS;
}

