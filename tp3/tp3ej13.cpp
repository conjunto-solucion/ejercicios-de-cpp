/*
TRABAJO PRÁCTICO TRES - EJERCICIO 13.
Solicita un número y muestra en pantalla su cantidad en asterisco(s).
*/


#include <iostream>
#include <cstdlib>



int main() {
	std::setlocale(LC_ALL, "");
	
	int number_of_asterisks = 0;
	
	
	// Solicitar la cantidad de asteriscos
	std::cout << "Ingrese un número entero positivo. Se mostrará esa cantidad en asteriscos: ";
	if (!(std::cin >> number_of_asterisks) || number_of_asterisks < 1) {
		std::cerr << "Error. El número debe ser entero positivo.";
		return EXIT_FAILURE;
	}
	
	// Imprimir * y luego restar 1, hasta que no queden más asteriscos para imprimir
	while (number_of_asterisks > 0) {
		std::cout << "*";
		number_of_asterisks--;
	}
		
	return EXIT_SUCCESS;
}
