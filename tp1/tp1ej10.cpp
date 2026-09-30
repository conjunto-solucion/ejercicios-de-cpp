/*
TRABAJO PRÁCTICO UNO - EJERCICIO 10.
Solicita un monto expresado en pesos 
y devuelve el valor expresado en:
	Pesos.
	Dólares.
	Reales.
*/

#include <iostream>
#include <cstdlib>
#include <iomanip>

#define USD_TO_ARS_FACTOR 1366
#define BRL_TO_ARS_FACTOR 274.42


int main() {
	std::setlocale(LC_ALL, "");
	float ARS;
	
	std::cout << "Ingrese el monto en pesos: ";
	if (!(std::cin >> ARS) || ARS < 0) {
		std::cerr << "El monto debe ser un número real no negativo.";
		return EXIT_FAILURE;
	}
	
	std::cout << "ARS: " << std::fixed << std::setprecision(2) << ARS << std::endl;
	std::cout << "USD: " << std::fixed << std::setprecision(2) << ARS / USD_TO_ARS_FACTOR << std::endl;
	std::cout << "BRL: " << std::fixed << std::setprecision(2) << ARS / BRL_TO_ARS_FACTOR << std::endl;
	
	return EXIT_SUCCESS;
}
