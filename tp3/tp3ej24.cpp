/*
TRABAJO PRÁCTICO TRES - EJERCICIO 24.
Permite ingresar para los N alumnos de una universidad:
	SEXO (‘M’ o ‘F’), edad y carrera ( ‘A’,’B’,’C’).
Imprimie la carrera con menor promedio de edad de sus alumnos que son varones.

Qué aprendimos:
	Bibliotecas nuevas: <cctype> para usar toupper()
	Saltar a la siguiente vuelta dentro de una estructura repetitiva con continue
*/


#include <iostream>
#include <cstdlib>
#include <cctype>
#include <limits>



int main() {
	std::setlocale(LC_ALL, "");
	
	// No guardaremos los datos de todos los alumnos, sólo del alumno que estamos cargando actualmente
	char course, sex;
	int age;
	
	// Aquí guardamos la cantidad de alumnos, total y de cada curso
	unsigned int n_total_students = 0;
	unsigned int n_course_A_students = 0;
	unsigned int n_course_B_students = 0;
	unsigned int n_course_C_students = 0;
	
	// Aquí guardaremos las sumatorias de edades
	unsigned int sum_of_ages_of_course_A_students = 0;
	unsigned int sum_of_ages_of_course_B_students = 0;
	unsigned int sum_of_ages_of_course_C_students = 0;
	
	// Aquí guardaremos los promedios de edades
	float average_age_of_course_A_students;
	float average_age_of_course_B_students;
	float average_age_of_course_C_students;
	
	
	// Le preguntamos de antemano la cantidad total de alumnos.
	// Esto nos evita tener que estar preguntando "¿desea continuar?" a cada rato
	std::cout << "Ingrese la cantidad total de alumnos: ";
	if (!(std::cin >> n_total_students) || n_total_students <= 0) {
		std::cerr << "Valor inválido. Finalizando...";
		return EXIT_FAILURE;
	}
	
	
	// Iteramos para cargar los datos de cada alumno
	for (int i = 0; i < n_total_students; i++) {
		
		
		std::cout << "\nDatos del alumno n° " << i+1 << "\n";
		
		// Preguntar la carrera
		std::cout << "Carrera: ";
		std::cin >> course;
		course = std::toupper(course); // pasamos el caracter a mayúsculas antes de comparar
		// Si no es una carrera válida, debemos volver a solicitar los datos del mismo alumno.
		if (!(course == 'A' || course == 'B' || course == 'C')) {
			std::cerr << "Error. Los valores permitidos son A, B y C. Intente nuevamente...\n";
			i--;
			continue;
		}
		
		
		// Preguntar el sexo. Usamos el mismo proceso de verificación que usamos para la carrera.
		std::cout << "Sexo: ";
		std::cin >> sex;
		sex = std::toupper(sex);
		if (!(sex == 'F' || sex == 'M')) {
			std::cerr << "Error. Los valores permitidos son F y M. Intente nuevamente...\n";
			i--;
			continue;
		}
		
		
		// Preguntamos la edad y nos aseguramos que no sea negativa
		std::cout << "Edad: ";
		if (!(std::cin >> age) || age < 0) {
			std::cerr << "Edad inválida. Intente nuevamente...\n";
			i--;
			std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		
		
		if (sex == 'M') {
			
			switch (course) {
				
				// Varones de la carrera A
				case 'A':
					n_course_A_students++;
					sum_of_ages_of_course_A_students += age;
					break;
					
				// Varones de la carrera B
				case 'B':
					n_course_B_students++;
					sum_of_ages_of_course_B_students += age;
					break;
				
				// Varones de la carrera C
				case 'C':
					n_course_C_students++;
					sum_of_ages_of_course_C_students += age;
					break;
			}
		}
	}

	std::cout << "\n\n";
	
	// Calculamos la media si y sólo si se registraron alumnos varones en la carrera A
	if (n_course_A_students > 0) {
		average_age_of_course_A_students = (float)sum_of_ages_of_course_A_students / n_course_A_students;
		std::cout << "Media de edad de varones de la carrera A: " << average_age_of_course_A_students << std::endl;
	}
	
	
	// Calculamos la media si y sólo si se registraron alumnos varones en la carrera B
	if (n_course_B_students > 0) {
		average_age_of_course_B_students = (float)sum_of_ages_of_course_B_students / n_course_B_students;
		std::cout << "Media de edad de varones de la carrera B: " << average_age_of_course_B_students << std::endl;
	}
	
	
	// Calculamos la media si y sólo si se registraron alumnos varones en la carrera C
	if (n_course_C_students > 0) {
		average_age_of_course_C_students = (float)sum_of_ages_of_course_C_students / n_course_C_students;
		std::cout << "Media de edad de varones de la carrera C: " << average_age_of_course_C_students << std::endl;
	}	
	
	
	
	
	if (n_course_A_students==0 && n_course_B_students==0 && n_course_C_students==0) {
		std::cout << "¡Ups! No hay alumnos varones en ninguna carrera.\n";
	}
	
	else {
		std::cout << "\nLa carrera con menor promedio de edad de varones es:\n";
	}
	
	
	
	
	// Determinamos la carrera con menor promedio de edad de los varones
	if  (n_course_A_students > 0 &&
		(average_age_of_course_A_students <= average_age_of_course_B_students || n_course_B_students==0) &&
		(average_age_of_course_A_students <= average_age_of_course_C_students || n_course_C_students==0)
	) {
		std::cout << "La carrera A.\n";
	}
	
	if  (n_course_B_students > 0 &&
		(average_age_of_course_B_students <= average_age_of_course_A_students || n_course_A_students==0) &&
		(average_age_of_course_B_students <= average_age_of_course_C_students || n_course_C_students==0)
	) {
		std::cout << "La carrera B.\n";
	}
	
	if  (n_course_C_students > 0 &&
		(average_age_of_course_C_students <= average_age_of_course_A_students || n_course_A_students==0) &&
		(average_age_of_course_C_students <= average_age_of_course_B_students || n_course_B_students==0)
	) {
		std::cout << "La carrera C.\n";
	}

	return EXIT_SUCCESS;
}
