/**
 * @file tps.cpp
 * @author Juan Andrés Dos Santos.
 * @version 2026
 * @brief Proporciona un menú para los trabajos prácticos 1 a 4 de Diagramación y Método.
 * Permite seleccionar un trabajo práctico, seleccionar un ejercicio del mismo,
 * y luego ver su código fuente en notepad o ejecutarlo.
 * 
 * Creado con Dev-C++ 5.11
 * Programado con C++ 98
 * Guardado con la codificación Windows 1252.
 */
 

#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <limits>
#include <windows.h>


void ejercicio(int tp, int n);
void tp1();
void tp2();
void tp3();
void tp4();
void presione_enter_para_continuar();




int main() {
	std::setlocale(LC_ALL, "");
	std::cout << "TRABAJOS PRÁCTICOS DE DIAGRAMACIÓN Y MÉTODO\n";
	std::cout << "___________________________________________\n";
	
	
	while (true) {
		
		system("color f");
		
		std::cout << "\nElija el trabajo práctico:\n";
		std::cout << "1\tentrada, procesamiento y salida de datos.\n";
		std::cout << "2\testructuras selectivas.\n";
		std::cout << "3\testructuras repetitivas.\n";
		std::cout << "4\tarreglos.\n";
		std::cout << "0\tSALIR\n\n";
		
		
		int num = -1;
		if (!(std::cin >> num) || num > 4 || num < 0) {
			std::cout << "\nFuera de rango...\n";
			return EXIT_FAILURE;
		}
		
		
		switch (num) {
			case 1: system("cls"); tp1(); break;
			case 2: system("cls"); tp2(); break;
			case 3: system("cls"); tp3(); break;
			case 4: system("cls"); tp4(); break;
			
			default:
				std::cout << "\nFin...\n";
				return EXIT_SUCCESS;
		}
		
		
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		system("cls");
	}
	
	return EXIT_SUCCESS;
}



void presione_enter_para_continuar() {
	std::cout << "\n\nPresione enter para continuar...\n";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.get();
	system("cls");
}



void ejercicio(int trabajo_n, int ejercicio_n) {	
	
	std::cout << "--------------------------\n";
	std::cout << "1\tver código fuente.\n";
	std::cout << "2\tejecutar.\n";
	std::cout << "0\tCANCELAR.\n";
	
	
	std::ostringstream tp, ej;
    tp << trabajo_n;
    ej << ejercicio_n;
	
	std::string comando_1 = "notepad .\\tp" + tp.str() + "\\tp" + tp.str() + "ej" + ej.str() + ".cpp";
	std::string comando_2 = ".\\tp" + tp.str() + "\\tp" + tp.str() + "ej" + ej.str() + ".exe";

	int operacion = 0;
	if (!(std::cin >> operacion)) {
		operacion = 0;
	}
	
	switch (operacion) {
		case 1:
			system(comando_1.c_str());
			break;
		case 2:
			system("cls");
			system(comando_2.c_str());
			break;
		default:
			return;
	}
}



void tp1() {
	system("color a");
	std::cout << "TRABAJO PRÁCTICO UNO\n";
	std::cout << "____________________\n";
	
	
	while (true) {
		std::cout << "Elija un ejercicio:\n";
		std::cout << "1\tsumar dos números.\n";
		std::cout << "2\tcalcular la hipotenusa de un triángulo.\n";
		std::cout << "3\tpedir 2 números y mostrar suma, resta, producto y cociente.\n";
		std::cout << "4\tpasar segundos a horas, minutos y segundos.\n";
		std::cout << "5\tcalcular media de tres precios.\n";
		std::cout << "6\tcalcular volumen de un prisma recto.\n";
		std::cout << "7\tcalcular área y volumen de un cilindro.\n";
		std::cout << "8\tconvertir millas marinas a metros.\n";
		std::cout << "9\tconvertir centímetros a pulgadas.\n";
		std::cout << "10\tconvertir ARS a dólares y reales.\n";
		std::cout << "11\tcalcula el precio de la nafta dados los galones. 1 gal = 3,785L y  1L cuesta $35,2.\n";
		std::cout << "0\tSALIR\n\n";
		
		int ej = 0;
		if (!(std::cin >> ej) || ej > 11 || ej < 1) {
			return;
		}
		
		ejercicio(1, ej);
		presione_enter_para_continuar();
	}
}


void tp2() {
	system("color b");
	std::cout << "TRABAJO PRÁCTICO DOS\n";
	std::cout << "____________________\n";
	
	
	while (true) {
		std::cout << "\nElija un ejercicio:\n";
		std::cout << "1\tdeterminar el mayor de dos números.\n";
		std::cout << "2\tdeterminar el mayor de tres números.\n";
		std::cout << "3\tdeterminar si una letra es vocal o consonante.\n";
		std::cout << "4\tinformar primo o no primo dado un número del 1 al 9.\n";
		std::cout << "5\tmostrar el día de la semana dado un número.\n";
		std::cout << "6\tdeterminar si un número ingresado es par o impar.\n";
		std::cout << "7\tmostrar masculino ('M') o femenino ('F').\n";
		std::cout << "8\tdeterminar aprobado o desaprobado dadas 3 notas\n";
		std::cout << "9\tcalcular la edad de una persona.\n";
		std::cout << "10\tleer 3 números e identificar el central.\n";
		std::cout << "11\tresolver una ecuación cuadrática.\n";
		std::cout << "12\tsimular una calculadora simple.\n";
		std::cout << "0\tSALIR\n\n";
		
		int ej = -1;
		if (!(std::cin >> ej) || ej > 12 || ej < 1) {
			return;
		}
		ejercicio(2, ej);
		presione_enter_para_continuar();
	}
}



void tp3() {
	system("color 6");
	std::cout << "TRABAJO PRÁCTICO TRES\n";
	std::cout << "_____________________\n";
	
	
	while (true) {
		std::cout << "\nElija un ejercicio:\n";
		std::cout << "1\timprimir los números del 1 al 100.\n";
		std::cout << "2\timprimir los números del 100 al 1.\n";
		std::cout << "3\tmostrar los números pares del 1 al 100.\n";
		std::cout << "4\tmostrar los números impares del 1 al 100.\n";
		std::cout << "5\tmostrar la suma de los enteros del 1 al 100.\n";
		std::cout << "6\tmostrar la suma de los pares del 1 al 100 y cuántos hay.\n";
		std::cout << "7\tdeterminar la media de una lista indefinida de positivos. Finalizar cuando se ingresa un negativo.\n";
		std::cout << "8\tcontar los pares del 1 al 50.\n";
		std::cout << "9\tcontar los números en un intervalo cerrado dados los extremos.\n";
		std::cout << "10\tcalcular la cantidad de pares e impares en un intervalo cerrado.\n";
		std::cout << "11\tcalcular el factorial de un número ingresado.\n";
		std::cout << "12\timprimir los números primos entre el 1 y el 100.\n";
		std::cout << "13\tsolicita un número y muestra en pantalla su cantidad en asterisco(s).\n";
		std::cout << "14\tsolicita un número entre 0 y 10 y muestra su tabla de multiplicar.\n";
		std::cout << "15\tcalcular la media de N números. Se dejan de solicitar números cuando se lee un 0.\n";
		std::cout << "16\tcalcula la suma de los cuadrados de los 100 primeros números enteros positivos.\n";
		std::cout << "17\tescribe los primeros 25 dígitos de la sucesión de Fibonacci.\n";
		std::cout << "18\tdetermina cuántos dígitos tiene un número entero ingresado.\n";
		std::cout << "19\tlee un entero y dice cuál es su dígito mayor.\n";
		std::cout << "20\tmuestra todos los números primos de 3 dígitos.\n";
		std::cout << "21\timprime 1 una vez, 2 dos veces, 3 tres veces,... N N veces.\n";
		std::cout << "22\tlee N enteros, calcula la suma y el promedio de los pares y de los impares, y cuál promedio es mayor.\n";
		std::cout << "23\tcargar planilla de notas y decir qué alumnos aprobaron (10 alumnos, con 4 notas cada uno).\n";
		std::cout << "24\tcargar los datos de N alumnos. Imprimir la carrera con menor promedio de edad de sus alumnos varones.\n";
		std::cout << "0\tSALIR\n\n";
		
		int ej = -1;
		if (!(std::cin >> ej) || ej > 24 || ej < 1) {
			return;
		}
		ejercicio(3, ej);
		presione_enter_para_continuar();
	}
}



void tp4() {
	system("color e");
	std::cout << "TRABAJO PRÁCTICO CUATRO\n";
	std::cout << "_______________________\n";
	
	
	while (true) {
		std::cout << "\nElija un ejercicio:\n";
		std::cout << "1\tcargar un arreglo e imprimirlo en reversa.\n";
		std::cout << "2\tcargar un arreglo y calcular el promedio.\n";
		std::cout << "3\tcargar un arreglo y determinar el máximo.\n";
		std::cout << "4\tcontar pares, impares y ceros de un arreglo.\n";
		std::cout << "5\tcargar un arreglo y mostrarlo multiplicado por 2.\n";
		std::cout << "6\tbuscar un valor N en un arreglo ingresado.\n";
		std::cout << "7\tcargar edades y nombres de alumnos en arreglos paralelos. Determinar el alumno mayor.\n";
		std::cout << "8\tcargar un arreglo y mostrarlo ordenado.\n";
		std::cout << "9\tcargar una matriz y mostrarla en forma de tabla.\n";
		std::cout << "10\tpide una matriz y calcula la suma de su diagonal principal.\n";
		std::cout << "11\tcarga una matriz de 3x4 y muestra la suma de cada fila por separado.\n";
		std::cout << "12\tdetermina si una matriz cuadrada ingresada es una matriz identidad.\n";
		std::cout << "13\tcarga 3 notas por cada uno de los 5 alumnos. Luego muestra el promedio de cada uno.\n";
		std::cout << "14\tpermite sumar dos matrices de 3x3.\n";
		std::cout << "0\tSALIR\n\n";
		
		int ej = -1;
		if (!(std::cin >> ej) || ej > 14 || ej < 1) {
			return;
		}
		ejercicio(4, ej);
		presione_enter_para_continuar();
	}
}
