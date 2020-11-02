/**
 * @file imagen.h
 * @brief Fichero de cabecera del TDA Imagen
 *
 */

#ifndef IMAGEN
#define IMAGEN

typedef unsigned char byte; /**< tipo base de cada pixel */

/**
  *  @brief T.D.A. Imagen
  *
  * Una instancia del tipo de datos abstracto Imagen es una matriz de
  * datos unisigned char compuesta por dos valores enteros que representan,
  * respectivamente, filas y columnas de la matriz. Lo representamos
  *
  * imagen[filas][columnas]
  *
  * Un ejemplo de su uso:
  * @include usoImagen.cpp
  *
  * @author Adrián Acosa Sánchez y Alejandro Rodger Marín
  * @date Octubre 2020
  */

class Imagen{

private:

/**
  * @page repConjunto Rep del TDA Imagen
  *
  * @section invConjunto Invariante de la representación
  *
  * El invariante es \e rep.byte[i][j]>=0 && rep.byte[i][j]<=255
  *
  * @section faConjunto Función de abstracción
  *
  * Un objeto válido @e rep del TDA Imagen representa al valor
  *
  * imagen[filas][columnas]
  *
  */

	int filas; /**< filas */
	int cols; /**< columnas */
	byte **img; /**< imagen */

public:

/**
 * Funcion: Imagen(int filas, int cols)
 * Tarea: Crear una imagen en memoria con "filas" filas y "cols" columnas.
 * Reserva memoria para alojar la imagen de "filas" x "cols" pixeles.
 * Recibe: int filas, Número de filas de la imagen.
 * int cols, Número de columnas de la imagen.
 * Devuelve: imagen, la imagen creada.
 * Comentarios:
 * 1. Operación de tipo constructor.
 * 2. La imagen creada contiene "filas" filas y "cols" columnas.
 * 3. La imagen creada no esta inicializada.
 */

/**
 * @brief Constructor por defecto de la clase. Crea la imagen vacía
 */
	Imagen();

/**
 * @brief Constructor de copia de la clase. Crea la imagen a partir de otra
 * @param otra imagen a copiar
 * @pre otra existe
 */
	Imagen(const Imagen & otra);

/**
 * @brief Constructor con dos argumentos de la clase. Crea la imagen especificando 
 * sus filas y columnas
 * @param f filas
 * @param c columnas
 * @pre f y c son mayores que 0
 * @post La imagen creada contiene f filas y c columnas
 * @post La imagen creada contiene valores "basura" (no está inicializada)
 */
	Imagen(int f, int c);

/**
 * @brief Destructor de la clase. Libera los recursos ocupados por la imagen
 * @post La imagen destruida no puede volver a usarse, salvo que se vuelva a
 * realizar sobre ella otra operación Imagen()
 */
	~Imagen();


/**
 * @brief Consultor del número de filas. Calcular el número de filas de la imagen
 * @return Número de filas de la imagen
 * @post La imagen no se modifica
 */
	int num_filas() const;

/**
 * @brief Consultor del número de columnas. Calcular el número de columnas de la imagen
 * @return Número de columnas de la imagen
 * @post La imagen no se modifica
 */
	int num_columnas() const;

/**
 * @brief Asignar un valor a un punto de la imagen. Asignar el valor de luminosidad
 * a la casilla (f,c) de la imagen
 * @param f fila
 * @param c columna
 * @param valor valor de luminosidad
 * @pre 0 <= f < num_filas() 
 * @pre 0 <= c < num_columnas()
 * @pre 0 <= valor < 255
 * @post La imagen se modifica. Concretamente, se cambia el valor de la casilla
 * (f,c) de la imagen por el especificado con valor. Los restantes puntos no se modifican
 */
	void asigna_pixel (int f, int c, unsigned char valor);

/**
 * @brief Consultor del valor de un punto de la imagen. Consultar el valor de luminosidad
 * de la casilla (f,c) de la imagen
 * @param f fila
 * @param c columna
 * @pre 0 <= f < num_filas() 
 * @pre 0 <= c < num_columnas()
 * @return El valor de luminosidad de la casilla (f,c) de la imagen, que está en
 * el conjunto {0,1,....,255}
 * @post La imagen se modifica. Concretamente, se cambia el valor de la casilla
 * (f,c) de la imagen por el especificado con valor. Los restantes puntos no se modifican
 */
	byte valor_pixel (int f, int c) const;

/**
 * @brief Umbralizar una imagen usando una escala de grises. Si el valor del píxel está 
 * comprendido dentro del umbral, se mantiene su valor. Si no, se vuelve blanco.
 * @param fichE nombre del fichero de entrada
 * @param fichS nombre del fichero de salida
 * @param T_1 umbral inferior
 * @param T_2 umbral superior
 * @pre T_1 es menor que T_2. fichE existe.
 * @post La imagen queda umbralizada en el fichero de salida.
 */
  void umbraliza (const char * fichE, const char * fichS, unsigned char T_1, unsigned char T_2);

/**
 * @brief Realizar zoom de una porción de la imagen. Se realiza mediante un simple
 * procedimiento de interpolación.
 * @param fichE nombre del fichero de entrada
 * @param fichS nombre del fichero resultado
 * @param x_1 coordenada x superior izquierda.
 * @param y_1 coordenada y superior izquierda.
 * @param x_2 coordenada x inferior derecha.
 * @param y_2 coordenada y inferior derecha.
 * @pre Ha de ser un trozo cuadrado.
 * @post La imagen resultante se almacena en el fichero de salida.
 */
  void zoom (const char * fichE, const char * fichS, int x_1, int y_1, int x_2, int y_2);

/**
 * @brief Aumento de contraste de una imagen mediante una transformación lineal
 * @param fichE nombre del fichero de entrada
 * @param fichS nombre del fichero resultado
 * @param min extremo inferior del nuevo rango de la imagen
 * @param max extremo superior del nuevo rango de la imagen
 * @pre 'min' ha de ser menor que 'max'
 * @post La imagen con nuevo contraste se almacena en el fichero de salida.
 */
  void contrasteTL (const char* fichE, const char* fichS, byte min, byte max);

/**
 * @brief Transición progresiva de una imagen a otra
 * @param fich_orig fichero con la imagen de origen
 * @param fich_rdo fichero con la imagen final
 * @param fich_intermedios ficheros intermedios (máximo 256)
 * @pre Las dos imagenes tienen que tener el mismo tamaño.
 * @post Las imagenes resultantes se almacenan en los ficheros intermedios.
 */
  void morphing(const char* fich_orig, const char* fich_rdo, const char* fich_intermedios);

/**
 * @brief Asignar una imagen a otra imagen. Copia profunda de una imagen en la implícita
 * @param otra imagen
 * @pre imagen existe 
 * @return La imagen copiada
 * @post La imagen se modifica. Cambia todos sus valores por los de la otra imagen
 */
	Imagen & operator = (const Imagen & otra);

private:

/**
 * @brief Liberador de memoria de la clase. Libera los recursos ocupados por la imagen
 * @post La imagen destruida no puede volver a usarse, salvo que se vuelva a
 * realizar sobre ella otra operación Imagen()
 */
	void liberar();

/**
 * @brief Reservador de memoria de la clase. Reserva los recursos necesarios para la imagen
 * @param f filas
 * @param c columnas
 * @post La imagen queda reservada con f filas y c columnas
 */
	void reservar(int f, int c);

/**
 * @brief Copiador de la clase. Copia los recursos de otra imagen a la implícita
 * @param f filas
 * @pre La imagen tiene suficiente memoria reservada
 * @post La imagen queda reservada con f filas y c columnas
 */
	void copiar(const Imagen & otra);

/**
 * @brief Convierte una imagen de vector a matriz
 * @param datos vector de byte que contiene una imagen
 * @pre img tiene el suficiente espacio para almacenar 'datos'
 * @post La imagen es convertida de vector a matriz
 */
void vector2matriz(byte* datos);

/**
 * @brief Convierte una imagen de matriz a vector
 * @return Devuelve un vector de byte
 * @post El vector devuelto es la forma vectorial de la matriz img de datos byte
 */
byte* matriz2vector();


};

#endif