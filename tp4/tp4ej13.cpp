/*
TRABAJO PRÁCTICO CUATRO - EJERCICIO 13.
Simula el registro de notas de un curso:
dada una matriz de 5 x 3 (5 alumnos y 3 notas por alumno),
calcula y muestra el promedio de notas obtenido por cada alumno.


*/


#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <limits>


struct Matrix {
    unsigned int rows;
    unsigned int columns;
    std::vector<float> data;
};



int main() {
	std::setlocale(LC_ALL, "");
	std::cout << "PLANILLA DE NOTAS\n*****************\n";
	
	
	// Definimos el número de alumnos (filas) y de notas (columnas)
	unsigned const int number_of_students = 5, grades_per_student = 3;
	
	// Creamos una matriz con las dimensiones indicadas
	Matrix grades;
	grades.rows = number_of_students;
	grades.columns = grades_per_student;
	grades.data.resize(number_of_students * grades_per_student);
	
	
	// Usaremos esta variable auxiliar para solicitar una nota.
	// Sólo cargaremos el dato en la matriz después de asegurarnos que es una nota válida.
	float grade = 0.0f;
	
	
	// Recorremos las filas (los alumnos)
	for (unsigned int i = 0; i < number_of_students; i++) {
		std::cout << "Alumno " << i + 1 << ":\n";
		
		
		// Recorremos las columnas (las notas por cada alumno)
		for(unsigned int j = 0; j < grades_per_student; j++) {
			
			// Solicitamos y validamos una nota:
			std::cout << "\tnota " << j + 1 << " = ";
			if (!(std::cin >> grade) || grade < 1 || grade > 10) {
				std::cerr << "La nota debe ser un número del 1 al 10.\n";
				j--;		
			}
			
			// Si no hubo problemas, cargamos dicha nota en la matriz
			else {
				grades.data[i * grades_per_student + j] = grade;
			}
			
			
			// Limpiamos el estado de error y el búfer
			std::cin.clear();
        	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
	
	
	
	// Volvemos a recorrer la matriz, ahora ya cargada con todos los datos,
	// para calcular los promedios
	for (unsigned int i = 0; i < grades.rows; i++) {
		
		float sum = 0; // Aquí guardamos las sumatorias de calificaciones
		
		
		// Mostramos todas las calificaciones del alumno, y las sumamos
		std::cout << "Alumno " << i + 1 << ":\t";
		for(unsigned int j = 0; j < grades.columns; j++) {
			sum += grades.data[i * grades.columns + j];
			std::cout << std::setw(8) << std::fixed << std::setprecision(2) << grades.data[i * grades.columns + j];
		}
		
		// Luego calculamos y mostramos el promedio
		std::cout << "\tpromedio = " << sum / grades.columns;
		// Imprimos un salto de línea antes de mostrar el siguiente alumno:
		std::cout << "\n";
	}
	
	
	return EXIT_SUCCESS;
}

