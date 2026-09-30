/*
TRABAJO PRÁCTICO CUATRO - EJERCICIO 8.
Lee 10 números dentro de un vector y luego ordena
sus elementos de menor a mayor para mostrarlos ordenados.

Qué aprendimos:
	Implementar el algoritmo de selección y de burbuja para ordenar arreglos
*/


#include <iostream>
#include <cstdlib>
#include <utility>
#include <limits>




// Ordena un arreglo de menor a mayor usando el algoritmo de selección
// El arreglo se declara como float v[] (que es lo mismo que float *v)
void sort_array(float v[], unsigned int length) {
	
	
	// Si no hay al menos 2 elementos, no es posible ordenar nada, así que salimos
	if (length < 2) return;
	
	
	/*
	Recorremos el arreglo desde el elemento 0 hasta el penúltimo elemento
	la variable start representa el inicio de la parte desordenada del arreglo:
		Comienza con 0, porque asumimos que todo está desordenado.
		Y termina con el penúltimo... ¿por qué no termina con el último?
		Porque no tendría sentido decir que 1 elemento está desordenado por sí solo (hacen falta 2 como mínimo)
	*/
	for (unsigned int start = 0; start < length - 1; start++) {
		
		// Debemos encontrar el menor valor desde start en adelante (ahora sí, hasta el último)
		// Guardamos la posición de dicho valor
		// Comenzamos asumiendo que el menor valor está en start
		unsigned int min_index = start;
		
		
		// Ahora recorremos el arreglo comenzando por start + 1
		// No comenzamos por start, porque no tendría sentido comparar v[start] con sí mismo
		for (unsigned int i = start + 1; i < length; i++) {
			
			// Si el valor en la posición actual
			if (v[i] < v[min_index]) {
				min_index = i;
			}
		}
		
		// Aquí ya sabemos el índice del menor elemento (por lo menos la primera instancia del menor valor)
		// Entonces reemplazamos el valor del inicio (v[start]) con el valor menor (v[min_index])
		std::swap(v[start], v[min_index]);
	}
	
	
	/*
	¿Por qué no retornamos nada?
	Porque los arreglos son pasados como un puntero a la primera posición
	Como estamos manipulando las mismas direcciones de memoria, lo que hagamos en la función
	afectará a la variable fuera de la función
	*/
}






// Ordena un arreglo de menor a mayor usando el método de la burbuja.
// NO usaremos esta función en este ejercicio. La dejo aquí como ejemplo.
void bubble_sort_array(float v[], unsigned int length) {
	
	
	if (length < 2) return;
	
	// Una bandera que indica si se intercambiaron elementos o no
	bool swapped;
    
    
    // Recorremos el arreglo a lo sumo (length - 1) veces.
	// ...con suerte no hará falta recorrer tantas veces.
    for (unsigned int pass_count = 0; pass_count < length - 1; pass_count++) {
        
        
        // Es el inicio, todavía no intercambiamos nada, así que swapped comienza como falso
		swapped = false;
        
        /*
		Nuestro objetivo es ordenar los elementos de dos en dos
        De modo que el elemento mayor subirá lentamente hasta el final (...como una burbuja)
        Una vez que pasamos por todo el arreglo una vez, ya sabemos que el último elemento está en la posición correcta
        Por lo tanto, disminuimos el final para dejar de tenerlo en cuenta
        */
        for (unsigned int i = 0; i < length - pass_count - 1; i++) {
            
            
            // Ordenamos el elemento actual con el siguiente de menor a mayor
            // Si el actual es mayor al siguiente, debemos intercambiarlos:
			if (v[i] > v[i + 1]) {
                
				std::swap(v[i], v[i + 1]); // Intercambiar el actual con el siguiente
                swapped = true; // Avisar que ya realizamos por lo menos un intercambio
            }
            
        }
        
        
        // Si recorrimos todo el arreglo sin necesitar hacer ningún intercambio,
        // significa que el arreglo ya está ordenado, así que salimos:
        if (!swapped) {
            return;
        }
    }
}





int main() {
	std::setlocale(LC_ALL, "");
    
	unsigned const int array_length = 10;
	float my_array[array_length];
	
	
	// Cargamos los 10 elementos:
	std::cout << "Ingrese " << array_length << " números:\n";
	for (int i = 0; i < array_length; i++) {
		
		std::cout << "n" << i + 1 << " = ";
		if (!(std::cin >> my_array[i])) {
			std::cerr << "Número inválido. Intente nuevamente...\n";
			std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			i--;
		}
		
	}
	
	
	// Ordenamos el arreglo usando nuestra función.
	// Nota: cambiar sort_array por bubble_sort_array para comprobar que el resultado es el mismo.
	sort_array(my_array, array_length);
	
	
	// Y lo mostramos
	std::cout << "\nVector ordenado:\n";
	for (unsigned int i = 0; i < array_length; i++) {
		std::cout << my_array[i] << "  ";
	}
	
	
	return EXIT_SUCCESS;
}

