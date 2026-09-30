/*
TRABAJO PRÁCTICO DOS - EJERCICIO 8.
Calcula el promedio de tres calificaciones ingresadas,
e informa si el alumno aprobó (con nota igual o superior a 4).
*/


#include <iostream>
#include <cstdlib>
#include <iomanip>


int main() {
	std::setlocale(LC_ALL, "");
	
	// Declaramos variables para las tres notas
	float grade_1 = 0.0f, grade_2 = 0.0f, grade_3 = 0.0f;
	
	// Y una variable para el promedio
	float average = 0.0f;
	
	
	std::cout << "Ingrese tres calificaciones del alumno:\n";
	
	// Pedimos la nota 1
	std::cout << "Calificación 1: ";
	if (!(std::cin >> grade_1) || grade_1 < 0 || grade_1 > 10) {
		std::cerr << "Fuera de rango.\n";
		return EXIT_FAILURE;
	}
	
	// Pedimos la nota 2
	std::cout << "Calificación 2: ";
	if (!(std::cin >> grade_2) || grade_2 < 0 || grade_2 > 10) {
		std::cerr << "Fuera de rango.\n";
		return EXIT_FAILURE;
	}
	
	// Pedimos la nota 3
	std::cout << "Calificación 3: ";
	if (!(std::cin >> grade_3) || grade_3 < 0 || grade_3 > 10) {
		std::cerr << "Fuera de rango.\n";
		return EXIT_FAILURE;
	}
	
	
	// Calculamos el promedio
	average = (grade_1 + grade_2 + grade_3) / 3;
	
	// Mostramos el promedio con 2 cifras decimales
	std::cout << "El promedio es: ";
	std::cout << std::fixed << std::setprecision(2) << average << std::endl;
	
	// Usamos el operador ? para decidir si mostrar aprobado o desaprobado
	std::cout << ((average >= 4)? "Alumno aprobado" : "Alumno desaprobado");
	
	
	return EXIT_SUCCESS;
}
