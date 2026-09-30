/*
TRABAJO PRÁCTICO UNO - EJERCICIO 4.
Expresa en horas y minutos un valor de tiempo ingresado
en segundos por teclado.

Qué aprendimos:
    Obtener el resto de una división con %
	Usar el operador ternario de condición:
		condición ? valor por verdadero : valor por falso
*/



#include <iostream>
#include <cstdlib>


int main() {
	std::setlocale(LC_ALL, "");		
	int hours, minutes, seconds = 0;
	
	
	// Pedimos el tiempo en segundos, y verificamos que sea válido
	std::cout << "Tiempo en segundos = ";
	if (!(std::cin >> seconds) || seconds < 0) {
		std::cerr << "Fuera de rango.\n";
		return EXIT_FAILURE;
	}
	
	// Convertirmos a horas
	hours = seconds / 3600;
	// Los segundos restantes, convertimos a segundos
	minutes = seconds % 3600 / 60;
	// Obtenemos los segundos restantes (que no llegan a ser ni 1 minuto)
	seconds = seconds % 3600 % 60;
	
	// Mostramos las conversiones
	// Usamos el operador ? para sabes si debemos usar plural o singular
	// hours != 1? "s ":" "  ---> Si no es 1, agregar "s" (plural), de otro modo, agregar "" (singular)
	std::cout << "Equivale a " << hours   << " hora"   << (hours != 1? "s ":" ");
	std::cout << minutes << " minuto" << (minutes != 1? "s ":" ");
	std::cout << seconds << " segundo" << (seconds != 1? "s":"");
	
	return EXIT_SUCCESS;
}
