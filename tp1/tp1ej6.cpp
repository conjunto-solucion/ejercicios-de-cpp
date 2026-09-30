/*
TRABAJO PRÁCTICO UNO - EJERCICIO 6.
Permite calcular el volumen de un prisma recto.
*/

#include <iostream>
#include <cstdlib>
#include <iomanip>



int main() {
	std::setlocale(LC_ALL, "");	
	
	double height = 0;
	double length = 0;
	double width = 0;
	
	std::cout << "Calculadora de volumen de un prisma recto.\n";
	
	
	std::cout << "Ancho = ";
	if (!(std::cin >> width) || width <= 0) {
		std::cerr << "Error. El ancho debe ser un número positivo.";
		return EXIT_FAILURE;
	}
	
	std::cout << "Alto = ";
	if (!(std::cin >> height) || height <= 0) {
		std::cerr << "Error. El alto debe ser un número positivo.";
		return EXIT_FAILURE;
	}
	
	std::cout << "Largo = ";
	if (!(std::cin >> length) || length <= 0) {
		std::cerr << "Error. El largo debe ser un número positivo.";
		return EXIT_FAILURE;
	}
	
	
	const double volume = height * length * width;
	std::cout << "El volumen del prisma es: ";
	std::cout << std::fixed << std::setprecision(4) << volume;
	
	
	return EXIT_SUCCESS;
}
