/*
TRABAJO PRÁCTICO TRES - EJERCICIO 23.
Solicita 4 notas por cada alumno del curso 7mo 'A', en total son 10 alumnos.
Informa qué alumnos aprobaron, considerando que se aprueba únicamente si
las cuatro notas son individualmente superiores a 6.

Qué aprendimos:
	Bibliotecas nuevas: <limits> para usar numeric_limits<streamsize>::max()
	Leer una línea completa de texto por consola, incluyendo los espacios
	Limpiar el búfer de entrada por consola y el estado de error
*/


#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <limits>

using std::numeric_limits;
using std::streamsize;


int main() {
	SetConsoleCP(1252);
	SetConsoleOutputCP(1252);
	
	// Este ejercicio lo solucionaremos SIN usar arreglos.
	// En el trabajo práctico 4 aprenderemos otra forma de implementar la solución
	
	
	// Guarda la cantidad de alumnos cargados
	int number_of_students = 0;
	// Guarda el nombre del alumno
	std::string name;
	// La calificación del alumno;
	float grade;
	// Cantidad de calificaciones
	const unsigned int number_of_grades = 4;
	
	
	std::cout << "Planilla de calificaciones:\n";
	
	
	// Vamos del 0 al 9 para cargar las notas de 10 alumnos:
	for (int i = 0; i < 10; i++) {
		
		// Solicitamos el nombre del alumno
		std::cout << "Nombre del alumno " << i + 1 << ": ";
		// Usamos getline, en lugar de cin que venimos usando hasta ahora,
		// porque debemos tener en cuenta que los nombres pueden tener espacios.
		// Con cin NO podemos guardar todo el string en un variable inlcuyendo los espacios
		std::getline(std::cin, name);
		
		
		// Solicitamos las calificaciones del alumno actual
		std::cout << "Calificaciones de " << name << ":\n";
		
		// Bandera para indicar si el alumno aprobó o no
		bool passed = true;
		
		for (int j = 0; j < number_of_grades; j++) {
			
			// Solicitamos una calificación
			std::cout << "Nota " << j + 1 << ": ";
			if (!(std::cin >> grade) || grade < 0 || grade > 10) {
				// Si es una nota inválida, borramos la entrada y solicitamos nuevamente
				// Para ello, disminuimos nuestro iterador i, y saltamos a la siguiente vuelta con continue
				
				
				std::cout << "Inválido. Debe ser un número del 0 al 10. Intente nuevamente...\n";
				// Usamo esta instrucción para restaurar el estado de error
				std::cin.clear(); 
				// Usamos esta instrucción para limpiar el búfer de lectura, para dejarlo como nuevo en la siguiente vuelta
            	std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
            	
				j--;
				continue;
			}
			
			// Si la nota es menor a 6, actualizamos la bandera passed a falso
			if (grade <= 6) {
				passed = false;
			}
			
			std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		
		// Cuando se temrinaron de cargar las notas, informamos si aprobó o no
		std::cout << "Alumno " << name <<  (passed? " aprobado.\n" : " desaprobado.\n");
	}


	return EXIT_SUCCESS;
}
