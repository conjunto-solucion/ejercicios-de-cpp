/*
TRABAJO PRÁCTICO TRES - EJERCICIO 10.
Solicita dos extremos y calcula la cantidad de números pares e impares comprendidos.
Incluye los extremos.
*/


#include <iostream>
#include <cstdlib>



int main() {
	std::setlocale(LC_ALL, "");
	
	int upper_limit = 0, lower_limit = 0;
	
	// Solicita el límite inferior
	std::cout << "Límite inferior = ";
	if (!(std::cin >> lower_limit)) {
		std::cerr << "Error. El límite debe ser un número entero.";
		return EXIT_FAILURE;
	}
	
	// Solicita el límite superior
	std::cout << "Límite superior = ";
	if (!(std::cin >> upper_limit)) {
		std::cerr << "Error. El límite debe ser un número entero.";
		return EXIT_FAILURE;
	}
	
	
	// Verifica que el límite superior sea mayor al inferior
	if (lower_limit >= upper_limit) {
		std::cerr << "El límite superior debe ser mayor al inferior.";
		return EXIT_FAILURE;
	}
	
	
	// Calculamos la cantidad de enteros en el intervalo
	const int count = upper_limit - lower_limit + 1;
	// Luego dividimos por 2 para repartir entre pares e impares
	int n_even = count / 2;
	int n_odd = n_even;
	
	
	// Si la cantidad de números total es impar, significa que:
	// O hay +1 par, o hay +1 impar
	if (count % 2 != 0) {
		
		// Si el primer número es par, faltó contar 1 par
		if (lower_limit % 2 == 0) {
			n_even++;
		}
		
		// Si el primer número es impar, faltó contar 1 impar
		else {
			n_odd++;
		}
	}
	
	// Informamos la cantidad de pares e impares. Uso el truco de verificar singular o plural con el operador ?
	std::cout << "En el intervalo [ " << lower_limit << ", " << upper_limit << " ]\n";
	std::cout << "Hay " << n_even << " número" << (n_even == 1? " par.\n"   : "s pares.\n");
	std::cout << "Hay " << n_odd  << " número" << (n_odd  == 1? " impar.\n" : "s impares.\n");
	
	return EXIT_SUCCESS;
}
