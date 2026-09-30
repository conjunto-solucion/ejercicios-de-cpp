/*
TRABAJO PRÁCTICO DOS - EJERCICIO 12.
Simula una calculadora simple que lee 2 enteros y un caracter.
Operaciones: +, -, *, /, %.
*/


#include <iostream>
#include <cstdlib>


int main() {
	std::setlocale(LC_ALL, "");
	
	int A = 0, B = 0;
	float ANSWER = 0.0f;
	char OPERATION = '\0';
	
	
	std::cout << "Calculadora + - * / %\n";
	
	// Pedir el primer número
	std::cout << "A = ";
	if (!(std::cin >> A)) {
		std::cerr << "El operando debe ser un número entero.";
		return EXIT_FAILURE;
	}
	
	// Solicitar la operación
	std::cout << "Operación: ";
	std::cin >> OPERATION;
	
	
	// Pedir el segundo número
	std::cout << "B = ";
	if (!(std::cin >> B)) {
		std::cerr << "El operando debe ser un número entero.";
		return EXIT_FAILURE;
	}
	
	
	
	switch (OPERATION) {
		
		// Caso suma
		case '+':
			ANSWER = A + B;
			std::cout << "A + B = " << ANSWER;
			break;
			
		// Caso resta
		case '-':
			ANSWER = A - B;
			std::cout << "A - B = " << ANSWER;
			break;
		
		// Caso multiplicación
		case '*':
			ANSWER = A * B;
			std::cout << "A * B = " << ANSWER;
			break;
		
		// Caso división. Si el divisor es cero, salimos.
		case '/':
			if (B == 0) {
				std::cout << "Indefinido.";
				break;
			}
			ANSWER = (float)A / B;
			std::cout << "A / B = " << ANSWER;
			break;
		
		// Caso módulo
		case '%':
			if (B == 0) {
				std::cout << "Indefinido.";
				break;
			}
			ANSWER = A % B;
			std::cout << "Para A / B el resto es " << ANSWER;
			break;
		
		// Si el caracter ingresado no es ninguna operación
		default:
			std::cerr << "Operación inválida.";
	}
	
	return EXIT_SUCCESS;
}
