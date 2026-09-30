/*
TRABAJO PRÁCTICO CUATRO - EJERCICIO 7.
Almacene los nombres y las edades de 10 alumnos en dos vectores paralelos,
e imprime el nombre del alumno con mayor edad.
*/



#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <limits>


int main() {
	SetConsoleCP(1252);
	SetConsoleOutputCP(1252);
    
	
	unsigned const int array_length = 10;
	std::string names[array_length];
	int ages [array_length];
	
	// Aquí guardaremos el récord de edad. Comienza en 0, que es la menor edad posible
	int max_age = 0;
	
	
	
	// Leemos los nombres y las edades de los alumnos
	std::cout << "Planilla de edades de los alumnos:";
	for (int i = 0; i < array_length; i++) {
		
		
		// Leer el nombre. Usamos getline para leer espacios también.
		std::cout << "\nNombre: ";
		std::getline(std::cin, names[i]);
		
		
		// Leemos la edad. Si es inválida, preguntamos nuevamente.
		std::cout << "Edad: ";
		if (!(std::cin >> ages[i]) || ages[i] < 0) {
			std::cerr << "Edad inválida. Intente nuevamente...\n";
			std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			i--;
			continue;
		}
		
		
		// Si la edad que se acaba de leer supera el récord, actualizamos el récord
		if (ages[i] > max_age) {
			max_age = ages[i];
		}
		
		
		// Limpiamos el búfer
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	
	
	
	// Decimos cuál fue la edad mayor registrada
	std::cout << "\nLos alumnos con mayor edad " << "(" << max_age << " años) son:\n";
	
	
	// Volvemos a recorrer el arreglo de edades para determinar qué alumnos coinciden con el récord
	for (int i = 0; i < array_length; i++) {
		
		// Si la edad del alumno i coincide con la edad máxima
		if (max_age == ages[i]) {
			// Decimos el nombre de dicho alumno
			std::cout << names[i] << std::endl;	
		}
	}
	
	
	
	return EXIT_SUCCESS;
}
