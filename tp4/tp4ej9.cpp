/*
TRABAJO PRÁCTICO CUATRO - EJERCICIO 9.
Permite ingresar valores enteros en una matriz de
orden 3 x 3 y luego la imprime en formato de tabla (filas y columnas).

Qué aprendimos:
	Bibliotecas nuevas: <vector> para facilitar la creación de vectores
	Definir una estructura con struct
	Crear una matriz
	Un método para acceder a los valores de una matriz almacenada en forma de vector: m[i * columnas + j]

Preguntas y respuestas:

	¿Por qué usamos un struct?
	Para agrupar los datos de la matriz en un sólo tipo de dato, de modo que sea más fácil pasarlos a una función,
	y devolverlo como valor de retorno en un función
	
	¿Por qué usamos un vector de la biblioteca <vector> en lugar de un arreglo bidimensional clásico?
	Porque los vectores de <vector> tienen métodos últiles, como size(), que nos devuelve la cantidad de elementos.
	En versiones más recientes de C++, como C++23, tenemos otras formas más elegantes de resolver estos problemas,
	por ejemplo, usando std::mdspan.
	Pero en este proyecto nos limitamos a usar una versión antigua: C++98.

	¿Por qué usamos un vector unidimensional en lugar de usar una estructura como: int a[3][4]?
	Por dos motivos:
	UNO:
		Al declarar una función donde uno de sus parámetros es una matriz, nos exigirán que la cantidad de columnas esté definida.
		No podemos hacer esto: void function(int matrix[][]).
		Esto dará un error, porque dejamos vacía la cantidad de columnas. Pero tampoco podemos asumir las dimensiones de la matriz.
		Guardar todo en una estructura de una dimensión nos evita tener que pasar la cantidad de filas y columnas.
		Imaginen que estamos cortando todas las filas de una tabla y colocandolas una al lado de otra.
	DOS:
		Para evitar tener que usar memoria dinámica manual. Con matrices clásicas debemos ser cautelosos en dónde
		asignamos la memoria (¡y cuánta memoria!), y recordar siempre liberar la memoria con la instrucción delete[]

*/


#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <limits>


// Esta es una estructura de datos personalizada.
// Permite agrupar distintos campos en un mismo tipo de dato.
struct Matrix {
    unsigned int rows;		// guardará la cantidad de filas
    unsigned int columns;	// guardará la cantidad de columnas
    std::vector<int> data;	// guardará los datos de la matriz, colocados secuencialmente en solo vector
};



Matrix read_matrix(unsigned int rows, unsigned int columns);
void print_matrix(const Matrix m);





int main() {
	std::setlocale(LC_ALL, "");
    
    // Definimos el orden de nuestra matriz cuadrada
	unsigned const int matrix_order = 3;
	
	
	// Solicitamos los elementos. Si es de orden n, tiene n² elementos
	std::cout << "Ingrese " << matrix_order * matrix_order << " números enteros:\n";
	// Declaramos una nueva matriz
	Matrix M;
	// Le cargamos valores a la matriz usando nuestr función read_matrix
	M = read_matrix(matrix_order, matrix_order);
	
	
	
	// Mostramos la matriz en consola usando la función print_matrix
	std::cout << "\nMatriz:\n";
	print_matrix(M);
	
	
	
	return EXIT_SUCCESS;
}



/**
 * @brief Lee los elementos de una matriz desde la consola
 * 
 * Esta función inicializa una estructura Matrix con las dimensiones dadas
 * y solicita al usuario que ingrese cada uno de los valores, validando
 * que la entrada sea correcta.
 * 
 * @param rows Número de filas que tendrá la matriz.
 * @param columns Número de columnas que tendrá la matriz.
 * @return Matrix Objeto Matrix con las dimensiones y los datos ya cargados.
 */
Matrix read_matrix(unsigned int rows, unsigned int columns) {
	
	// Crear y configurar la estructura de la matriz
    Matrix m;
    m.rows = rows;
    m.columns = columns;
    // Reservamos memoria para el total de elementos
    m.data.resize(rows * columns);
	
	// Recorremos desde 0 hasta el último elemento.
	// Para conocer el último elemento, usamos la función size() del vector data
	for (unsigned int i = 0; i < m.data.size(); i++) {
    	if (!(std::cin >> m.data[i])) {
			std::cerr << "Número inválido. Intente nuevamente:\n";
			i--;		
		}
		std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    
    // Devolvemos la matriz, ahora con datos cargados
    return m;
}



/**
 * @brief Imprime una matriz en la consola con un formato tabular.
 * @param m Objeto Matrix que se desea imprimir. Pasado por referencia para ahorrar memoria.
 */
void print_matrix(const Matrix &m) {
	
	// Recorre las filas de la matriz
    for (unsigned int i = 0; i < m.rows; i++) {
    	
    	// Para cada fila, recorre las columnas
        for (unsigned int j = 0; j < m.columns; j++) {
        	
        	/*
			Imprime el dato de la celda con longitud 8 y con 2 decimales.
        	Se usa la notación:
				m[i * m.columns + j], que significa "fila i, columna j"
        	En otros programas verán otra notación que utiliza dos pares de corchetes:
				m[i][j]
        	Esa notación no nos sirve a nosotros, porque guardamos los datos en un vector (estructura unidimensional)
        	*/
            std::cout << std::setw(8) << std::setprecision(2) << m.data[i * m.columns + j];
        }
        
        
        std::cout << std::endl;
    }
}
