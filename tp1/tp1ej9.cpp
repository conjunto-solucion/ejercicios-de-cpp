/*
TRABAJO PRÁCTICO UNO - EJERCICIO 9.
Tras introducir una medida expresada en centímetros la
convierte en pulgadas (1 pulgada = 2,54 centímetros).
*/

#include <iostream>
#include <cstdlib>
#include <iomanip>

#define INCHES_TO_CM 2.54

int main() {
	setlocale(LC_ALL, "");
	double centimeters = 0.0;
	
	
	std::cout << "Conversión de centímetros a pulgadas.\n";
	std::cout << "Centímetros: ";
	
	if (!(std::cin >> centimeters) || centimeters < 0) {
		std::cerr << "La medida debe ser un número real no negativo.";
		return EXIT_FAILURE;
	}
	
	
	std::cout << std::fixed << std::setprecision(2) << centimeters;
	std::cout << " cm equivale a ";
	std::cout << std::fixed << std::setprecision(2) << centimeters / INCHES_TO_CM;
	std::cout << "''\n";
	
	return EXIT_SUCCESS;
}
