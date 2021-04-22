#include <stdio.h>  
#include <ctype.h>   // para toupper-----> toma un carácter y devuelve su versión en mayúscula
#include <stdlib.h>  // para rand-------> obtener números aleatorios entre el minimo y el maximo valor
#include <assert.h>  // para assert-----> comprobar suposiciones en el programa
#include <unistd.h>  // para getpid-----> devuelve el identificador de proceso del proceso actual

//-----Variables---//
#define FALSO 0
#define VERDADERO 1

//---Modificacion para dificultad----//
#define NCOLUMNAS 9
#define NFILAS 9
#define NBOMBAS 3

//------Estetica del juego----//
#define ESPACIO_MISTERIOSO '#'
#define ESPACIO_DESCUBIERTO ' '
#define BOMBA 'X'

//-----Errorres que pueden ocurrir en el juego-----//
#define ERROR_BOMBA_ENCONTRADA 1
#define ERROR_ESPACIO_ENCONTRADO 2
#define TODO_OK 3

//ADEVERTENCIA
 /*
  - No puede haber más filas que letras del abecedario, porque solo se imprime hasta la Z.
  - No puede haber más de 9 columnas porque ya no se imprimiría bien por el acomodo de los espacios.
  - Por el bien del programa te recomiendo como maximo utilizar una cuadricula de 9x9.
  - Al colocar las minas se puede colocar una mina sobre otra mina asi que a veces se imprimen menos.
*/

