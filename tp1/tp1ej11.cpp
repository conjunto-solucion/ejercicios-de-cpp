/*
TRABAJO PRÁCTICO UNO - EJERCICIO 11.
Calcula el precio de la gasolina en pesos, dado un volumen en galones.
Cada galón tiene 3,785 Litros. El precio del litro es de 35,20 pesos
*/

#include <iostream>
#include <cstdlib>
#include <iomanip>

#define PRICE_OF_FUEL_IN_ARS 35.2
#define GALLONS_TO_LITERS 3.785


int main () {
	std::setlocale(LC_ALL, "");
	float gallons = 0.0f;
	
	std::cout << "Ingrese el volumen de combustible en galones\n";
	
	if (!(std::cin >> gallons) || gallons < 0) {
		std::cerr << "Error. El volumen debe ser un número real no negativo.\n";
		return EXIT_FAILURE;
	}
	
	
	const float volume_in_liters = gallons * GALLONS_TO_LITERS;
	const float price_in_ARS = volume_in_liters * PRICE_OF_FUEL_IN_ARS;
	std::cout << "El precio es ARS ";
	std::cout << std::fixed << std::setprecision(2) << price_in_ARS;
	
	return EXIT_SUCCESS;
}
