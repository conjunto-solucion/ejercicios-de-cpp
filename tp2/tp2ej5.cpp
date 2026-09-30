/*
TRABAJO PRÁCTICO DOS - EJERCICIO 5.
Dado un número ingresado por teclado,
escribe el día de la semana que corresponda.

Qué aprendimos:
	Usar la estructura de selección múltiple (switch)
*/


#include <iostream>
#include <cstdlib>


int main() {
	std::setlocale(LC_ALL, "");
	int day = 0;
	
	
	// Leemos un número entero
	std::cout << "Elija un número del 1 al 7: ";
	std::cin >> day;
	
	// Lo comparamos con distintos valores enteros:
	switch (day) {
		
		// 7 valores a comparar:
		case 1: std::cout << "Domingo."; 	break; // Si coincide con 1, terminará el bloque donde aparezca break
		case 2: std::cout << "Lunes."; 		break;
		case 3: std::cout << "Martes."; 	break;
		case 4: std::cout << "Miércoles."; 	break;
		case 5: std::cout << "Jueves."; 	break;
		case 6: std::cout << "Viernes."; 	break;
		case 7: std::cout << "Sábado."; 	break;
		
		// Si no es 1, 2, 3, 4, 5, 6 ni 7: realizamos el caso predeterminado:
		default:
			std::cerr << "Fuera de rango.";
			return EXIT_FAILURE;
	}
	
	
	return EXIT_SUCCESS;
}
