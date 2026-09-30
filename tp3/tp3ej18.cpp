/*
TRABAJO PRÁCTICO TRES - EJERCICIO 18.
Determina cuántos dígitos tiene un número entero ingresado por teclado.

Qué aprendimos:
	Determinar el valor absoluto de un número
*/


#include <iostream>
#include <cstdlib>
#include <cmath>


int main() {
	std::setlocale(LC_ALL, "");
	
	int n = 0;
	unsigned int number_of_digits = 1; 
	
	// Solicitar un número entero
	std::cout << "Ingrese un número entero:\n";
	if (!(std::cin >> n)) {
		std::cerr << "Inválido.";
		return EXIT_FAILURE;
	}
	
	// Nos aseguramos de tener el valor absoluto del número
	n = std::abs(n);
	
	
	// Ya sabemos que tiene por lo menos 1 dígito
	// Por lo tanto, le sacamos uno dividiendo entre 10. Si era 345, ahora será 34
	n = n / 10;
	
	
	// Si es mayor a 0, significa que todavía le quedan más dígitos para contar...
	while (n > 0) {
		
		// ...Por eso le sumamos uno a la cantidad
		number_of_digits++;
		
		// Y nos deshacemos de dicho dígito, porque ya lo contamos
		n = n / 10;
	}
	
	
	// Por último, informamos la cantidad de dígitos
	std::cout << "El número tiene " << number_of_digits << " dígito" << (number_of_digits > 1? "s enteros":" entero");
		
	return EXIT_SUCCESS;
}
