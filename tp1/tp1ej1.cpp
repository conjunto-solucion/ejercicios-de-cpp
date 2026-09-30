/*
TRABAJO PRÁCTICO UNO - EJERCICIO 1.
Permite sumar dos números leídos por teclado y escribir el
resultado en pantalla.

Qué aprendimos:
    Importar bibliotecas con #include
    Bibliotecas nuevas: iostream, cstdlib
    Declarar la función principal main()
    Agregar soporte para acentos y ñ con setlocale()
    Declarar variables y asignarle un valor
    Leer valores con cin >>
    Escribir valores con cout << o con cerr <<
    Usar la estructura selectiva simple "if"
    Escribir el valor de retorno de una función
*/

#include <iostream>
#include <cstdlib>


int main() {
    
    // Configura el idioma del sistema para permitir acentos y caracteres especiales (como la 'Ñ')
    std::setlocale(LC_ALL, "");
    
    // Declaramos dos variables de tipo decimal (float) inicializadas en 0.0 para guardar los números
    float A = 0.0f, B = 0.0f;
    
    
    
    // Solicitamos al usuario que ingrese el valor de A en la consola
    std::cout << "A = ";
    
    // Leemos el valor ingresado. Si cin devuelve un error,
	// por ejemplo, si el usuario escribe letras en vez de números, is_valid_input será falso
	bool is_valid_input = std::cin >> A;
	
	// Podemos usar esto último para decidir si aceptar el valor o no. Si no es válido, mostraremos un error
    if (!is_valid_input) {
        std::cerr << "Fuera de rango o entrada inválida."; // Mostramos un mensaje de error por la salida de errores
        return EXIT_FAILURE; // Terminamos el programa inmediatamente indicando que hubo un fallo
    }
    
    
    // Solicitamos al usuario que ingrese el valor de B
    std::cout << "B = ";
    // Hacemos la misma validación de seguridad para la variable B
    if (!(std::cin >> B)) {
        std::cerr << "Fuera de rango o entrada inválida.";
        return EXIT_FAILURE;
    }
    
    // Realizamos la suma de A + B y mostramos el resultado directamente en pantalla
    std::cout << "A + B = " << A + B;
    
    // Indicamos que el programa finalizó con éxito
    return EXIT_SUCCESS;
}
