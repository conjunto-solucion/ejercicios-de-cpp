/*
TRABAJO PRÁCTICO TRES - EJERCICIO 11.
Calcula el factorial de un número.
Qué aprendimos:
	Nuevas bibliotecas: stdexcept para usar out_of_range
	Usar variables de tipo long (o long long)
	Lanzar una excepción con la sentencia throw
*/


#include <iostream>
#include <cstdlib>
#include <stdexcept>
using std::out_of_range;


// Función que calcula el factorial de un número.
// Devuelve un entero grande (long)
unsigned long long factorial(int n) {
	
	// Pregunta si es un número negativo.
	// En ese caso, lanza un error de tipo out_of_range (fuera de rango)
	if (n < 0) {
		throw out_of_range("No existe el factorial de un número negativo.");
	}
	
	// Delcaramos una variable de tipo long
	unsigned long long result = 1;
	
	// Calculamos el factorial
	// 1era vuelta: 1*1... 2da vuelta: 1*2... 3ra vuelta: 2*3... 4ta vuelta : 6*4...
	for (int factor = 1; factor <= n; factor++) {
		result *= factor; // esto es lo mismo que decir result = result * factor
	}
	
	return result;
}



int main() {
	std::setlocale(LC_ALL, "");
	
	
	int n = 0;
	std::cout << "Ingrese un número natural: ";
	
	// Solicitar un número y validar que sea natural
	if (!(std::cin >> n) || n < 0) {
		std::cerr << "Error. No es un número natural.";
		return EXIT_FAILURE;
	}
	
	
	if (n > 65) {
		std::cerr << "¡Demasiado grande! El valor máximo permitido es 65.";
		return EXIT_FAILURE;
	}
	
	// Informar usando nuestra función que definimos al principio
	std::cout << n << "! = " << factorial(n);
	
	
	return EXIT_SUCCESS;
}
