/*
TRABAJO PRÁCTICO DOS - EJERCICIO 11.
Resuelve una ecuación cuadrática (ax² + bx + c = 0).
*/


#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>


int main() {
	std::setlocale(LC_ALL, "");
	
	// Declaramos los coeficientes
	double A = 0.0, B = 0.0, C = 0.0;
	
	// Aquí guardaremos las soluciones (una ecuación cuadrática SIEMPRE tiene dos soluciones)
	double X1 = 0.0, X2 = 0.0;
	
	
	std::cout << "Calculadora de ecuaciones cuadráticas.\n";
	std::cout << "Ingrese el valor de los coeficientes.\n";
	
	std::cout << "A = ";
	if (!(std::cin >> A) || A == 0) {
		std::cerr << "El coeficiente principal debe ser un número real distinto de 0.";
		return EXIT_FAILURE;
	}
	std::cout << "B = ";
	if (!(std::cin >> B)) {
		std::cerr << "El coeficiente debe ser un número real.";
		return EXIT_FAILURE;
	}
	std::cout << "C = ";
	if (!(std::cin >> C)) {
		std::cerr << "El coeficiente debe ser un número real.";
		return EXIT_FAILURE;
	}
	
	
	const double discriminant = pow(B, 2) - 4 * A * C;
	std::cout << "Solución = { ";
	if (discriminant == 0) {
		
		if (B == 0) {
			B = -B;
		}
		
		X1 = -B / (2.0 * A);
		std::cout << X1 << ", " << X1 << " }";
	}
	
	
	else if (discriminant > 0) {
		X1 = (-B + sqrt(discriminant))/ 2 * A;
		X2 = (-B - sqrt(discriminant))/ 2 * A;
		std::cout << X1 << ", " << X2 << " }";
	}
	else {
		const double real_part = -B / 2 * A;
		const double imaginary_part = sqrt(-discriminant) / 2 * A;
		std::cout << real_part << " + " << imaginary_part << "i, ";
		std::cout << real_part << " - " << imaginary_part << "i }";
	}
	
	return EXIT_SUCCESS;
}
