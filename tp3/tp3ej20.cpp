/*
TRABAJO PRÁCTICO TRES - EJERCICIO 20.
Muestra todos los números primos de 3 dígitos.
*/


#include <iostream>
#include <cstdlib>


// Protitipo de la función que permite preguntar si un número es primo o no
bool is_prime(int n);


int main() {
	std::setlocale(LC_ALL, "");
	
	// Inicializamos el contador de números primos
	int prime_count = 0;
	
	
	std::cout << "Números primos de tres dígitos:\n";
	
	
	// Recorremos todos los impares de 3 dígitos
	for (int n = 101; n <= 999; n += 2) {
		
		// Por cada uno preguntamos si es primo
		if (is_prime(n)) {
			
			prime_count++;					// De ser así, aumentamos el contador
			std::cout << n << "; ";	// Y mostramos el número
		}
	}
	
	// Extra: informamos también la cantidad de primos encontrados
	std::cout << "\nCantidad total de primos: " << prime_count;
		
		
		
	return EXIT_SUCCESS;
}


// Devuelve si n es primo o no
// Es exactamente la misma función que apareció y expliqué en el ejercicio 12
bool is_prime(int n) {

	if (n <= 1 || n != 2 && n % 2 == 0) {
		return false;
	}
	if (n <= 3) {
		return true;
	}
	
	for (int divisor = 3; divisor*divisor <= n; divisor += 2) {
		if (n % divisor == 0) {
			return false;
		}
	}

	return true;
}
