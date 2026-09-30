/*
TRABAJO PRÁCTICO CUATRO - EJERCICIO 1.
Lee 10 números enteros, los almacene en un vector y
luego los muestra en el orden inverso al que fueron ingresados

Qué aprendimos:
	Definir arreglos unidimensionales, cargar y leer sus elementos
	Recorrer un arreglo en sentido normal y en reversa
*/



#include <iostream>
#include <cstdlib>
#include <limits>



int main() {
	std::setlocale(LC_ALL, "");
	
	/*
	Usaremos arreglos para resolver el ejercicio.
	Un arreglo es una estructura de datos con las siguientes características:
		Es una colección de elementos del mismo tipo. No puede guardar múltiples tipos de datos en la misma variable.
		Tiene una longitud N determinada. En el momento de crearlo, se debe especificar la cantidad de elementos que guardará.
		Los elementos se almacenan en un único bloque contiguo de memoria
		Los elementos están enumerados del 0 en adelante, hasta N - 1, así: [0] [1] [2]... [N-1]
	*/
	
	
	// En esta constante definimos el tamaño del arreglo. Esta no se puede modificar una vez que se define.
    unsigned int const SIZE_OF_ARRAY = 10;
	// Así es como definimos un arreglo que guardará tantos enteros como indica SIZE_OF_ARRAY
	// Los números enteros podrán ser accedidos con la notación my_array[0], my_array[1], ..., my_array[9]
	int my_array[SIZE_OF_ARRAY];
	
	
	// Solicitamos la cantidad de elementos indicada en SIZE_OF_ARRAY
	std::cout << "Ingrese " << SIZE_OF_ARRAY << " números enteros:\n";
	for (int i = 0; i < SIZE_OF_ARRAY; i++) {
		
		std::cout << "n" << i + 1 << " = ";
			
		// Leemos un entero a la vez.
		// La primera vez se leerá my_array[0], luego my_array[1], luego my_array[2], ..., my_array[9]
		if (!(std::cin >> my_array[i])) {
			
			// Si hubo un error, usamos el mismo truco que ya explicamos para volver a solicitar el mismo número
			std::cerr << "Número inválido. Intente nuevamente...\n";
			std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			i--;
			continue;
		}
		
		// Limpiamos el búfer por si quedaron caracteres sobrantes que no se leyeron
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	
	
	// Recorremos el arreglo desde N - 1 hasta 0 (en sentido inverso).
	// La primera vez se escribirá my_array[9], luego my_array[8], luego my_array[7], ..., my_array[0]
	std::cout << "\nValores en el orden inverso:\n";
	for (int i = SIZE_OF_ARRAY - 1; i >= 0; i--) {
		std::cout << my_array[i] << " ";
	}
	
	return EXIT_SUCCESS;
}

