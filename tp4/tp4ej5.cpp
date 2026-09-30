/*
TRABAJO PRÁCTICO CUATRO - EJERCICIO 5.
Lee 10 números enteros en un vector A,
genera un vector B con los mismos valores pero multiplicados por 2,
y muestra ambos vectores por pantalla.

Qué aprendimos:
	Usar múltiples arreglos de la misma longitud
*/


#include <iostream>
#include <cstdlib>
#include <limits>


int main() {
	std::setlocale(LC_ALL, "");
	
	
	unsigned int const array_length = 10;
	// Creamos dos arreglos del mismo tamaño:
	int A[array_length];
	int B[array_length];
	
	
	
	std::cout << "Ingrese " << array_length << " números enteros:\n";
	// Cargamos los valores en el arreglo A
	for (int i = 0; i < array_length; i++) {
		
		
		// Solicitamos un número. Si es inválido, lo volvemos a solicitar
		std::cout << "n" << i + 1 << " = ";
		if (!(std::cin >> A[i])) {
			std::cerr << "Número inválido. Intente nuevamente...\n";
			std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			i--;
			continue;
		}
	
	
	
		// Tomamos el número que acabamos de leer, lo multiplicamos por 2, y
		// guardamos el resultado en el arreglo B, en la misma posición
		B[i] = A[i] * 2;
		
		// Limpiamos el búfer
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	
	
	
	// Mostramos el arreglo A de principio a fin
	std::cout << "\nVector original:\n";
	for (int i = 0; i < array_length; i++) {
		std::cout << A[i] << " ";
	}
	
	// Mostramos el arreglo B de principio a fin
	std::cout << "\nVector multiplicado por 2:\n";
	for (int i = 0; i < array_length; i++) {
		std::cout << B[i] << " ";
	}
	
	
	
	return EXIT_SUCCESS;
}
