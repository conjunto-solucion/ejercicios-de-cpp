/*
TRABAJO PRÁCTICO UNO - EJERCICIO 5.
Proporciona el precio medio de un producto a partir del
precio en tres establecimientos distintos.

Qué aprendimos:
    Bibliotecas nuevas: iomanip (manipulación de entrada/salida)
	La sentencia using, para indicar que usaremos un namesapace
	Crear funciones personalizadas para evitar tener que repetir el código
	Escribir el prototipo de la función
	Escribir la documentación de una función con comentarios
	Tipo de dato: booleano (verdadero o falso)
	Tipo de dato: cadena de caracteres (std::string)
*/

#include <iostream>
#include <iomanip>
#include <cstdlib>

// Podemos usar esta sentencia para poder decir string, en lugar de std::string
// Nos ahorramos tener que escribir std:: cada vez
using std::string;


// Este es el prototipo de la función read_price
// Escribir esto aquí nos permite definir la función al final, después de main:

/**
* Muestra el texto `prompt` por consola
* Luego lee un valor por consola e intenta guardarlo en `price`.
* Si el valor es inválido, escribe un mensaje de error en consola.
* @param price la variable float donde se guardará la entrada de usuario.
* @param prompt el mensaje que se muestra antes de pedir el valor al usuario.
* @returns si se leyó el precio correctamente o no.
*/
bool read_price(float &price, string prompt);



int main() {
	std::setlocale(LC_ALL, "");	
	
	float price_1 = 0.0f,
	price_2 = 0.0f,
	price_3 = 0.0f;

	string product_name;
	

	std::cout << "Calculadora de precio medio.\n";



	std::cout << "Nombre del producto: ";
	if (!(std::cin >> product_name) ||  product_name.length() < 1 || product_name.length() > 50) {
		std::cerr << "El nombre del producto debe contener entre 1 y 50 caracteres.\n";
		return EXIT_FAILURE;
	}
	

	// Llamamos a la función para leer el precio
	// Si alguna de ellas retorna false, significa que hubo un error, y se termina el programa
	if (!read_price(price_1, "Precio 1 = ") ||
		!read_price(price_2, "Precio 2 = ") ||
		!read_price(price_3, "Precio 3 = ")) {
		return EXIT_FAILURE;
	}
	
	// Calcular el promedio
	const float average_price = (price_1 + price_2 + price_3) / 3;

	// Informamos el precio medio
	// Notar como decimos \" para indicar que literalmente queremos que
	// imprima las comillas, en lugar de cerrar nuestro string
	std::cout << "El precio medio de \"" << product_name << "\" es: $";

	// Usamos fixed para decir que no queremos que use notación científica
	// Y usamos setprecision para indicarle la cantidad de cifras decimales a mostrar
	std::cout << std::fixed << std::setprecision(2) << average_price;
	return EXIT_SUCCESS;
}



bool read_price(float &price, string prompt) {
	
	std::cout << prompt;
	
	if (!(std::cin >> price) || price <= 0) {
		std::cerr << "El precio debe ser un número positivo.\n";
		return false;
	}

	return true;
}
