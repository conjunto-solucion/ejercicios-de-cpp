/*
TRABAJO PRÁCTICO TRES - EJERCICIO 19.
Lee un entero y dice cuál es su dígito mayor.
*/


#include <iostream>
#include <cstdlib>
#include <cmath>


int main() {
	std::setlocale(LC_ALL, "");
	
	int n = 0;
	unsigned int current_digit;
	unsigned int max_digit = 0; // comenzamos asumiendo que el récord de dígito mayor es el menor posible: 0
	
	
	// Solicitar un número entero
	std::cout << "Ingrese un número entero: ";
	if (!(std::cin >> n)) {
		std::cerr << "Inválido.";
		return EXIT_FAILURE;
	}
	
	// Obtener su valor absoluto
	n = std::abs(n);
	
	
	// Mientras tenga dígitos
	while (n > 0) {
		
		// Obtener un dígito. Si n es 187, obtenemos el 7
		current_digit = n % 10;
		
		// Si el dígito obtenido es mayor al récord, actualizamos el récord
		if (current_digit > max_digit) {
			max_digit = current_digit;
		}
		
		// Nos deshacemos del dígito que acabamos de procesar. Si n es 187, quedará como 18
		n = n / 10;
	}
	
	
	std::cout << "El dígito entero mayor es " << max_digit;
		
	return EXIT_SUCCESS;
}
