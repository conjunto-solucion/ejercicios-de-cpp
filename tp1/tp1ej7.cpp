/*
TRABAJO PRÁCTICO UNO - EJERCICIO 7.
Permite determinar el Área y volumen de un cilindro
dado su radio y altura.

Qué aprendimos:
	Definir constantes con #define
    Usar múltiples funciones personalizadas
	Mostrar directamente el valor de retorno de una función, sin almacenarlo
*/

#include <iostream>
#include <cstdlib>
#include <iomanip>

// Definimos una constante para el número pi, si no está definida:
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif



// Creamos dos funciones, para calcular el área y el volumen, respectivamente:

double area_of_cilinder(double radius, double height) {
	return 2 * radius * M_PI * (height + radius);
}
double volume_of_cilinder(double radius, double height) {
	return radius * radius * M_PI * height;
}



int main() {
	std::setlocale(LC_ALL, "");
	
	double height = 0.0;
	double radius = 0.0;
	
	
	std::cout << "Calculadora de volumen y superficie de un cilindro.\n";
	

	std::cout << "Radio del cilindro = ";
	if (!(std::cin >> radius) || radius <= 0) {
		std::cerr << "Error. El ancho debe ser un número positivo.";
		return EXIT_FAILURE;
	}
	
	std::cout << "Altura del cilindro = ";
	if (!(std::cin >> height) || height <= 0) {
		std::cerr << "Error. La altura debe ser un número positivo.";
		return EXIT_FAILURE;
	}
	
	// Escribimos el resultado de llamar a area_of_cilinder() en la consola:
	std::cout << "La superficie del cilindro es ";
	std::cout << std::fixed << std::setprecision(4) << area_of_cilinder(radius, height) << std::endl;
	
	// Escribimos el resultado de llamar a volume_of_cilinder() en la consola:
	std::cout << "El volumen del cilindro es ";
	std::cout << std::fixed << std::setprecision(4) << volume_of_cilinder(radius, height) << std::endl;	
	
	return EXIT_SUCCESS;
}
