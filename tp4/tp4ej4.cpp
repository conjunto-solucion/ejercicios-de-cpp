/*
TRABAJO PRÁCTICO CUATRO - EJERCICIO 4.
Solicita la carga de un vector de 20 números y cuenta
cuántos valores son pares, cuántos impares y cuántos ceros.
*/


#include <iostream>
#include <cstdlib>
#include <limits>


int main() {
	std::setlocale(LC_ALL, "");
    
	unsigned int const array_length = 20;
	int my_array[array_length];
	unsigned int odd_count = 0, even_count = 0, zero_count = 0;
	
	
	std::cout << "Ingrese " << array_length << " números enteros:\n";
	
	
	// Cargamos todos los elementos:
	for (int i = 0; i < array_length; i++) {
		
		std::cout << "n" << i + 1 << " = ";
		if (!(std::cin >> my_array[i])) {
			std::cerr << "Número inválido. Intente nuevamente...\n";
			std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			i--;
			continue;
		}
		
		// Si el número recién ingresado es par, aumentar el contador de pares
		if (my_array[i] % 2 == 0) {
			even_count++;
		}
		// de otro modo, aumentar el contador de impares
		else {
			odd_count++;
		}
		
		// Si el número es 0, aumentar el contador de ceros
		if (my_array[i] == 0) {
			zero_count++;
		}
		
		
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	
	
	// Informar los contadores:
	std::cout << "\nCantidad de pares: " << even_count;
	std::cout << "\nCantidad de impares: " << odd_count;
	std::cout << "\nCantidad de ceros: " << zero_count;
	
	
	
	
	return EXIT_SUCCESS;
}

