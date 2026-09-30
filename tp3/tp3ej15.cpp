/*
TRABAJO PRÁCTICO TRES - EJERCICIO 15.
Calcula la media de X números.
Se dejarán de solicitar números en el momento que se introduzca el número cero.
*/


#include <iostream>
#include <cstdlib>


int main() {
	std::setlocale(LC_ALL, "");
	
	float input = 0.0f, sum = 0.0f, average = 0.0f;
	unsigned int count = 0;
	
	std::cout << "Ingrese números para calcular la media. Para terminar, ingrese un 0.\n";
	
	// Usamos la estructura do-while para que el bloque se ejecute al menos una vez antes de evualuar la condición
	do {
		
		
		// Solicitamos un número
		std::cout << "n" << count + 1 << " = ";
		if (!(std::cin >> input)) {
			std::cerr << "Inválido. Terminando el programa...\n";
			break;
		}
		
		// Si es distinto de 0, lo tenemos en cuenta para calcular la media
		if (input != 0) {	// Notar que aquí hay una condición duplicada (input != 0 aparece 2 veces)
			sum += input;	// Existen formas de evitar eso,
			count++;			// pero por ahora lo haremos así para ilustrar el funcionamiento de do-while
		}
	}
	
	while (input != 0); // Si el input fue 0, no vuelve a ejectuar el bloque
	
	
	// Si no se ingresaron números distintos de 0, mostramos un mensaje de error
	if (count == 0) {
		std::cerr << "No se ha ingresado ningún número distinto de 0.";
	}
	
	// De otro modo, mostramos la cantidad y el promedio
	else {
		average = sum / count;
		std::cout << "\nTamaño: " << count;
		std::cout << "\nPromedio: " << average;	
	}
	
		
	return EXIT_SUCCESS;
}
