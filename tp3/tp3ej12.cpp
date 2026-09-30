/*
TRABAJO PRÁCTICO TRES - EJERCICIO 12.
Muestra los números primos entre 1 y 100.
*/


#include <iostream>
#include <cstdlib>
#define UPPER_LIMIT 100


// El prototipo de nuestra función para determinar si un número es primo o no
bool is_prime(int n);


int main() {
	std::setlocale(LC_ALL, "");
	
	
	std::cout << "Números primos entre 1 y " << UPPER_LIMIT << ":\n";
	
	
	// Mostramos el primer número primo, y el ÚNICO número primo par:
	std::cout << 2 << "\n";
	
	
	// Aquí guardaremos la cantidad de primos a medida que los vamos contando:
	// Esto no es necesario hacerlo
	int prime_count = 1;
	
	
	// Todos los demás primos son impares.
	// Por lo tanto empezaremos a comprobar a partir del 3, saltando de 2 en 2. Así: 3, 5, 7,... hasta UPPER_LIMIT
	for (int n = 3; n <= UPPER_LIMIT; n += 2) {
		
		// Preguntamos si el número es primo;
		// de ser así, aumentamos el contador y mostramos el número
		if (is_prime(n)) {
			prime_count++;
			std::cout << n << "\n";
		}
	}
	
	
	// Un extra (que no pide el enunciado): informar la cantidad
	std::cout << "Cantidad de primos en el intervalo [ 1, " << UPPER_LIMIT << " ] = " << prime_count;
	return EXIT_SUCCESS;
}


/*
Esta función recibe un número y devuelve si es primo (true) o no lo es (false)
Definición de número primo: número natural mayor que 1 que solo tiene dos divisores positivos
Por tanto, para decidir si un número es primo, debemos intentar encontrar al menos un divisor distinto de 1 y de n
*/
bool is_prime(int n) {
	
	// Antes que nada, descartamos los negativos, el 1, y los pares mayores que 2
	if (n <= 1 || n != 2 && n % 2 == 0) {
		return false;
	}
	
	
	// Preguntamos si n es 2 o 3.
	if (n <= 3) {
		return true;	// Si da verdadero: es primo y terminamos
	}
	// Si da falso: aún no sabemos si es primo. Debemos comprobar si tiene algún divisor (distinto de 1 y de n)
	
	
	
	/*
	A partir de este punto sabemos que: n es un número impar mayor que 3
	De esto podemos deducir que:
	los posibles divisores de n están en el intervalo [3, raíz cuadrada de n]
	
	Vamos a probar si es divisible por 3, luego por 5, luego por 7, y así hasta llegar a la raíz cuadrada de n
	Para evitar usar sqrt(), elevamos al cuadrado ambos lados de la desigualdad, así:
	divisor <= sqrt(n)    pasa a ser      divisor²  <= n
	*/
	
	for (int divisor = 3; divisor*divisor <= n; divisor += 2) {
		
		// Si es divisible por divisor, significa que NO ES primo
		if (n % divisor == 0) {
			return false;	// y terminamos inmediatamente. No seguimos preguntando
		}
	}
	
	
	// Si no logramos encontrar ningún divisor, significa que el número es primo:
	return true;
}
