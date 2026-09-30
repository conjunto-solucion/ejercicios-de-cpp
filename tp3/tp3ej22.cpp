/*
TRABAJO PRÁCTICO TRES - EJERCICIO 22.
Lee N números enteros e informa por separado:
	la suma y el promedio de los números pares,
	la suma y el promedio de los números impares,
	cuál de los 2 grupos tiene el promedio mayor.
*/


#include <iostream>
#include <cstdlib>


int main() {
	std::setlocale(LC_ALL, "");
	
	// Declaramos la variable en la cual guardaremos los números ingresados
	int input_number;
	
	// Aquí guardaremos la cantidad total, la cantidad de pares y la cantiadd de impares
	int n_total = 0, n_even = 0, n_odd = 0;
	
	// Y en estas cuatro, las sumas y promedios
	int sum_of_evens = 0, sum_of_odds = 0;
	float avg_of_evens, avg_of_odds;
	
	
	// Preguntamos al usuario la cantidad total de números
	std::cout << "¿Cuántos números quiere ingresar? ";
	if (!(std::cin >> n_total) || n_total <= 0 || n_total > 1000) {
		std::cerr << "Fuera de rango. Debe ser un número del 1 al 1000.";
		return EXIT_FAILURE;
	}	
	
	
	std::cout << "Ingrese los números a continuación:\n";
	// Solicitamos la cantidad indicada de números
	for (int i = n_total; i > 0; i--) {
		
		// Leemos el número
		if (!(std::cin >> input_number)) {
			std::cerr << "Error. Número inválido. Finalizando...\n";
			break;	
		}
		
		// Si es par
		if (input_number % 2 == 0) {
			sum_of_evens += input_number;	// lo agregamos a la sumatoria de pares
			n_even++;						// sumamos el contador de pares
		}
		// De otro modo (es impar)
		else {
			sum_of_odds += input_number;	// lo agregamos a la sumatoria de impares
			n_odd++;						// sumamos el contador de impares
		}
	}
	
	
	// Informamos todo:
	
	// De los número pares...
	std::cout << "\nCantidad total = " << n_total << "\n";
	std::cout << "\nCantidad de números pares = " << n_even << "\n";
	std::cout << "Suma de números pares = " << sum_of_evens << "\n";
	if (n_even > 0) {	// Nos aseguramos de que hubo pares para calcular el promedio de pares
		avg_of_evens = (float)sum_of_evens / n_even;
		std::cout << "Media de números pares = " << avg_of_evens << "\n";
	}
	// De los número impares...
	std::cout << "\nCantidad de números impares = " << n_odd << "\n";
	std::cout << "Suma de números impares = " << sum_of_odds << "\n";
	if (n_odd > 0) {
		avg_of_odds = (float)sum_of_odds / n_odd;
		std::cout << "Media de números impares = " << avg_of_odds << "\n";
	}
	
	
	// Determinamos cuál promedio es mayor sólo si se cargaron tanto pares como impares
	// Si hubiesen sólo pares, el promedio de impares sería indeterminado, de modo que no tendría sentido intentar compararlo 
	if (n_even > 0 && n_odd > 0) {
		if (avg_of_evens > avg_of_odds) {
			std::cout << "\nEl promedio de pares es mayor.\n";
		}
		else {
			std::cout << "\nEl promedio de impares es mayor\n";
		}
	}
	
	
	return EXIT_SUCCESS;
}
