/*
TRABAJO PRÁCTICO UNO - EJERCICIO 8.
Lee el valor correspondiente a una distancia en millas
marinas y las escribe en pantalla expresadas en metros.

NOTA:
El enunciado usa la equivalencia 1 nm = 1609.34 m.
Esta en realidad es la equivalencia de millas terrestres.
Decidí usar la equivalencia real (1 nm = 1852 m)
para no quitarle veracidad al programa.
*/


#include <iostream>
#include <cstdlib>
#include <iomanip>



// No es bueno tener números como 1852 en el código sin un contexto de su significado.
// Por eso se usa una constante, para darle un nombre:
#define NAUTICAL_MILES_TO_METERS 1852



int main() {
	std::setlocale(LC_ALL, "");
	double nautical_miles = 0.0;
	
	std::cout << "Conversión de millas marinas a metros.\n";
	std::cout << "Millas marinas = ";
	
	if (!(std::cin >> nautical_miles) || nautical_miles < 0) {
		std::cerr << "La medida debe ser un número real no negativo.";
		return EXIT_FAILURE;
	}
	
	
	std::cout << std::fixed << std::setprecision(2) << nautical_miles;
	std::cout << " nm equivale a ";
	std::cout << std::fixed << std::setprecision(2) << nautical_miles * NAUTICAL_MILES_TO_METERS;
	std::cout << " m\n";
	
	return EXIT_SUCCESS;
}
