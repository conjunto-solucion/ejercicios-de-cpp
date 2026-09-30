/*
TRABAJO PRÁCTICO TRES - EJERCICIO 6.
Muestra la suma de los números pares del 1 al 100.
Informa cuántos hay.

Qué aprendimos:
	Declarar constantes con const
*/


#include <iostream>
#include <cstdlib>
#define N 100


int main() {
	std::setlocale(LC_ALL, "");
	
	// Calculamos la suma usando la fórmula de la sumatoria de una progresión aritmética.
	// Pero dividimo el límite N entre 2 para considerar sólo la mitad (sólo los pares)
	// Aquí usamos la sentencia const para decir que SUM no cambiará su valor inicial
	const unsigned int SUM = (N / 2)  *  ((N / 2) + 1);
	
	// La cantidad de pares siempre será N / 2, sabiendo que el primer número es siempre 1
	std::cout << "La cantidad de pares del 1 al " << N << " es: " << N / 2 << "\n";
	
	// Mostramos la sumatoria
	std::cout << "La suma es " << SUM;
	
	return EXIT_SUCCESS;
}
