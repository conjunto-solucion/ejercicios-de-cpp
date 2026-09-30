/*
TRABAJO PRÁCTICO DOS - EJERCICIO 3.
Dada una letra ingresada por teclado,
devuelve si se trata de una vocal o una consonante.

Qué aprendimos:
	Biblioteca nueva: windows.h para usar SetConsoleCP y SetConsoleOutputCP
	Usar funciones booleanas
	Usar las equivalencias numéricas de los caracteres
	Usar variables de texto ingresadas por el usuario (sin espacios, por ahora)
*/


#include <iostream>
#include <cstdlib>
#include <windows.h>


// Una función que nos dirá si un string c es vocal (true) o no (false)
bool is_vowel(std::string c) {
	
	// El valor de retorno es directamente lo que dé la condición
	return (
		c == "a" || c == "e" || c == "i" || c == "o" || c == "u" ||
		c == "á" || c == "é" || c == "í" || c == "ó" || c == "ú" || c == "ü" ||
		c == "A" || c == "E" || c == "I" || c == "O" || c == "U" ||
		c == "Á" || c == "É" || c == "Í" || c == "Ó" || c == "Ú" || c == "Ü"
		
	);
}



// Una función que nos dirá si un string c es consonante española o no
bool is_consonant(std::string c) {
	
	// Preguntamos por la ñ primero, porque su longitud es igual a 2
	if (c == "ñ" || c == "Ñ") {
		return true;
	}
	
	// Nos aseguramos de que es una letra y no es vocal
	if (c.length() == 1 && !is_vowel(c)) {
		
		// Aprovechamos el hecho de que cada letra tiene un código numérico, de modo que 'b' > 'a'.
		// Si el código de c está entre 'b' y 'z', significa que es una consonante
		if (c[0] >= 'b' && c[0] <= 'z' || c[0] >= 'B' && c[0] <= 'Z') {
			return true;
		}
	}
	
	// Si llegó hasta acá, significa que NO es consonante
	return false;
}



int main() {
	
	// Aquí no basta usar setlocale():
	// Usamos estas dos funciones para que nos permita leer correctamente
	// cadenas con acentos y eñe ingresadas por el usuario
	SetConsoleCP(1252);
	SetConsoleOutputCP(1252);
	
	
	// Podríamos declarar esta variable como tipo char...
	// Pero eso nos impediría ingresar, por ejemplo, la Á (con acento)
	std::string letter = "";
	
	// Leemos la letra
	std::cout << "Ingresar una letra: ";
	std::cin >> letter;
		
	
	// Preguntamos si es vocal o consonante, usando nuestras funciones
	if (is_vowel(letter)) {
		std::cout << "Es una vocal.";
	}
	
	else if (is_consonant(letter)) {
		std::cout << "Es una consonante.";
	}
	
	// Por descarte, no es ni uno ni otro
	else {
		std::cout << "No es una vocal ni consonante.";
	}
	
	
	return EXIT_SUCCESS;
}
