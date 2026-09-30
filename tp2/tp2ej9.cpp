/*
TRABAJO PRÁCTICO DOS - EJERCICIO 9.
Pregunta la fecha de nacimiento de una persona.
Informa su edad actual y si es mayor de edad (más de 18 años).

Qué aprendimos:
    Bibliotecas nuevas: ctime
    Declarar punteros con *
    	Un puntero es una variable que almacena una dirección de memoria.
    	Por ejemplo, int* a almacena la dirección de memoria de un entero
    	Si un puntero tiene almacenado NULL, significa que no apunta a nada
    Acceder a la dirección de memoria de una variable con &
    	Si int a es nuestra variable, &a es la dirección de memoria de la misma.
    Mencionamos la existencia de estructuras (struct), pero aún no declaramos una personalizada
*/


#include <iostream>
#include <ctime>
#include <cstdlib>


// Esta función nos devuelve el año actual como un entero
// En esta función usamos un concepto un poquito avanzado, que son los punteros y direcciones de memoria
int get_current_year() {
	
	// Creamos una variable tipo time_t llamada my_time
	// Inicializamos con time(), pasando un puntero nulo
	std::time_t my_time = std::time(NULL);
	
	// Crea un puntero tipo tm: guarda la dirección de memoria de una variable tipo tm
	// Le llamamos now
	// Lo inicializamos con localtime(), pasando la dirección de memoria de my_time
	std::tm* now = std::localtime(&my_time);
	
	
	/*
	La variable now que acabamos de crear nos permite acceder a la fecha
	Usamos la flechita (->) para acceder a un miembro de la estructura a la cual apunta el puntero now
	Una estructura contiene múltiples datos, y debemos ejegir a cuál de ellos acceder
	Debemos sumarle 1900 para obtener el año real
	*/
	return now->tm_year + 1900;
}

// Devuelve el mes actual como entero
int get_current_month() {
	std::time_t t 	= std::time(NULL);
	std::tm* now 	= std::localtime(&t);
	
	return now->tm_mon + 1;
}

// Devuelve el  día actual como entero
int get_current_day() {
	std::time_t t 	= std::time(NULL);
	std::tm* now 	= std::localtime(&t);
	
	return now->tm_mday;
}



int main() {
	
	std::setlocale(LC_ALL, "");
	
	// Variables para año, mes y día:
	int y = 0, m = 0, d = 0;
	
	// Variable para almacenar la edad.
	// Como está declarada como unsigned, significa que no puede almacenar negativos.
	// Si intentamos almacenar un número negativo, se interpretará como positivo y dará valores muy altos (buscar: complemento a 2)
	// Por eso mismo, las variables y m d NO deberían ser unsigned
	unsigned int age = 0;
	
	// Recuperamos la fecha actual con las funciones del principio
	unsigned int const current_year 	= get_current_year();
	unsigned int const current_month 	= get_current_month();
	unsigned int const current_day 		= get_current_day();

	
	std::cout << "Ingrese su fecha de nacimiento.\n";
	
	// Pedir el año de nacimiento
	std::cout << "Año: ";
	if (!(std::cin >> y) || y < 1 || y > current_year) {
		std::cerr << "Fuera de rango.";
		return EXIT_FAILURE;
	}
	
	// Pedir el mes de nacimiento
	std::cout << "Mes: ";
	if (!(std::cin >> m) || m < 1 || m > 12) {
		std::cerr << "Fuera de rango.";
		return EXIT_FAILURE;
	}
	
	// Pedir el mes de nacimiento
	std::cout << "Día: ";
	if (!(std::cin >> d) || d < 1 || d > 31) {
		std::cerr << "Fuera de rango.";
		return EXIT_FAILURE;
	}
	
	// Determinar si la fecha ingresada está en el futuro
	if (current_year < y ||
		current_year == y && current_month < m ||
		current_year == y && current_month == m && current_day < d) {
			
		std::cerr << "La fecha de nacimiento no puede ser futura.";
		return EXIT_FAILURE;
	}
	
	// Calcular la edad
	age = current_year - y;
	
	// Restarle 1 año si es que aún no llegó su cumpleaños
	if (current_month < m || current_month == m && current_day < d) {
		age--;
	}
	
	
	// Decimos la fecha actual, la edad y si es mayor de edad
	std::cout << "La fecha actual es: " << current_day << "/" << current_month << "/" << current_year << ".\n";
	std::cout << "Su edad es: " << age << ".\n";
	// Notar que la consigna especifica que debe tener MÁS de 18 para ser mayor de edad
	std::cout << (age > 18? "Mayor de edad.":"Menor de edad.");
	
	return EXIT_SUCCESS;
}
