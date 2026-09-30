/*
TRABAJO PRÁCTICO UNO - EJERCICIO 2.
Calcula la hipotenusa de un triángulo rectángulo,
conociendo sus dos catetos (el usuario los ingresa).

Qué aprendimos:
    Bibliotecas nuevas: cmath
	Caracter de salto de línea \n
    Variables de tipo double ¿Qué diferencia hay entre float y double?
	Realizar una validación con if ()
*/


#include <iostream>
#include <cstdlib>
#include <cmath>


int main() {
	std::setlocale(LC_ALL, "");
	double leg_1 = 0.0f, leg_2 = 0.0f;
	
	std::cout << "Calculadora de hipotenusa.\n";
	std::cout << "Ingrese las medidas de los catetos:\n";
	

	// Realizamos una validación: si el cateto ingresado no es un número
	// o no es positivo, terminar el programa
	std::cout << "Cateto 1 = ";
	if (!(std::cin >> leg_1) || leg_1 <= 0) {
		std::cerr << "Fuera de rango.\n";
		return EXIT_FAILURE;
	}

	// Hacemos lo mismo para el cateto 2
	std::cout << "Cateto 2 = ";
	if (!(std::cin >> leg_2) || leg_2 <= 0) {
		std::cerr << "Fuera de rango.\n";
		return EXIT_FAILURE;
	}
	
	// Usamos la función hypot() para calcular la hipotenusa. Se encuentra en la biblioteca cmath
	std::cout << "Hipotenusa = " << hypot(leg_1, leg_2);


	return EXIT_SUCCESS;
}
