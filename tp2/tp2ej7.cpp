/*
TRABAJO PRÁCTICO DOS - EJERCICIO 7.
Dado un caracter M o F ingresado,
escribe masculino o femenino.

Qué aprendimos:
	Usar variables de tipo caracter (char)
	Pasar un caracter a mayúsculas
*/


#include <iostream>
#include <cstdlib>
#include <cctype>


int main() {
	std::setlocale(LC_ALL, "");
	
	// Declaramos una variable de tipo caracter.
	// Inicializamos con un caracter vacío ('\0')
	char sex = '\0';
	
	// Pedimos el caracter
	std::cout << "Ingrese F o M: ";
	std::cin >> sex;
	
	// Convertimos el caracter a mayúsculas
	sex = static_cast<char>(std::toupper(sex));
	
	// Usamos selección múltiple para elegir el mensaje.
	switch (sex) {
		case 'M': std::cout << "Masculino."; break;
		case 'F': std::cout << "Femenino."; break;
		default: std::cout << "Inválido.";
	}
	
	return EXIT_SUCCESS;
}
