/*
TRABAJO PRÁCTICO TRES - EJERCICIO 9.
Solicita dos extremos y calcula la cantidad de números comprendidos.
Incluye los extremos.
*/


#include <iostream>
#include <cstdlib>



int main() {
	std::setlocale(LC_ALL, "");
	
	// Definimos el límite inferior y superior como variables enteras
	int upper_limit = 0, lower_limit = 0;
	
	// Solicitamos el límite inferior
	std::cout << "Límite inferior = ";
	if (!(std::cin >> lower_limit)) {
		std::cerr << "Error. El límite debe ser un número entero.";
		return EXIT_FAILURE;
	}
	
	// Solicitamos el límite superior
	std::cout << "Límite superior = ";
	if (!(std::cin >> upper_limit)) {
		std::cerr << "Error. El límite debe ser un número entero.";
		return EXIT_FAILURE;
	}
	
	
	// Verificamos que el límite superior sea mayor al inferior
	if (lower_limit >= upper_limit) {
		std::cerr << "El límite superior debe ser mayor al inferior.";
		return EXIT_FAILURE;
	}
	
	// La cantidad de números en un intervalo [a, b] (donde a y b son enteros) es b - a + 1
	// ¿Por qué se le suma 1?
	// Porque b - a es la distancia para llegar de un punto a otro, y +1 es el punto inicial
	const int count = upper_limit - lower_limit + 1;
	
	
	std::cout << "Hay " << count << " números enteros en el intervalo [ " << lower_limit << ", " << upper_limit << " ]";
	
	
	return EXIT_SUCCESS;
}
