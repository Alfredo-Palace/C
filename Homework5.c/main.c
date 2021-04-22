//Este programa fue hecho en su totalidad en el compilador en linea GDB asi que te recomiendo probarlo ahi. 
// Para testearlo tienes que colocar todo el codigo del archivo main.c en la pestaña principal para luego abrir una nueva pestaña o documento y colocarle el nombre de "header.h", y colocar todo el codigo del archivo header.h del otro archivo de la misma carpeta.
// Sino sigues estas indicaciones probablemente el programa no se compilara. Cualquier duda mandame mensaje en discordsito :)

#include "header.h"
//-----------------TEORIA DEL JUEGO------------------------//
// Indica los contadores correctos a las demás celdas
int ContadoresCeldas(int fila, int columna, char cuadricula[NFILAS][NCOLUMNAS]) {
  int contador = 0, filaInicial, filaFinal, columnaInicial, columnaFinal;
  if (fila <= 0) {
    filaInicial = FALSO;
  } else {
    filaInicial = fila - 1;
  }

  if (fila + 1 >= NFILAS) {
    filaFinal = NFILAS - 1;
  } else {
    filaFinal = fila + 1;
  }

  if (columna <= 0) {
    columnaInicial = FALSO;
  } else {
    columnaInicial = columna - 1;
  }
  if (columna + 1 >= NCOLUMNAS) {
    columnaFinal = NCOLUMNAS - 1;
  } else {
    columnaFinal = columna + 1;
  }
  int a;
  for (a = filaInicial; a <= filaFinal; a++) {
    int b;
    for (b = columnaInicial; b <= columnaFinal; b++) {
      if (cuadricula[a][b] == BOMBA) {
        contador++;
      }
    }
  }
  return contador;
}

// Devolver un número aleatorio entre minimo y maximo (incluyendolos)
int ValorAleatorio(int minimo, int maximo) {
  return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
}
// Rellena el tablero de espacios sin descubrir
void inicio(char cuadricula[NFILAS][NCOLUMNAS]) {
  int b;
  for (b = 0; b < NFILAS; b++) {
    int a;
    for (a = 0; a < NCOLUMNAS; a++) {
      cuadricula[b][a] = ESPACIO_MISTERIOSO;
    }
  }
}

// Coloca una bomba 
void Bombardeo(int fila, int columna, char cuadricula[NFILAS][NCOLUMNAS]) {
  cuadricula[fila][columna] = BOMBA;
}

// Coloca bombas aleatoriamente
void BombardeoAleatorio(char cuadricula[NFILAS][NCOLUMNAS]) {
  int b;
  for (b = 0; b < NBOMBAS; b++) {
    int fila = ValorAleatorio(0, NFILAS - 1);
    int columna = ValorAleatorio(0, NCOLUMNAS - 1);
    Bombardeo(fila, columna, cuadricula);
  }
}

//-----------------------FORMATO DE CUADRICULA-------------------------------//
void Encabezado() {
  printf("    ");
  int b;
  for (b = 0; b < NCOLUMNAS; b++) {
    printf("  %d ", b + 1);
    if (b + 1 == NCOLUMNAS) {
      printf(" ");
    }
  }
  printf("\n");
}

char enteroAcaracter(int numero) {  
  return numero + '0';
}

void imprimirCuadricula(char cuadricula[NFILAS][NCOLUMNAS], int MostrarBombas) {
  Encabezado();
  char letra = 'A';
  int b;
  for (b = 0; b < NFILAS; b++) {
    int a;
    printf("  %c ", letra); // Imprimir la letra de la fila
    letra++;
    for (a = 0; a < NCOLUMNAS; a++) {
      // Ocultar las bombas
      char verdaderaLetra = ESPACIO_MISTERIOSO;
      char letraActual = cuadricula[b][a];
      if (letraActual == BOMBA) {
        verdaderaLetra = ESPACIO_MISTERIOSO;
      } else if (letraActual == ESPACIO_DESCUBIERTO) {
        // Mostrar bombas si ya perdio o gano
        int BombasCercanas = ContadoresCeldas(b, a, cuadricula);
        verdaderaLetra = enteroAcaracter(BombasCercanas);
      }
      if (letraActual == BOMBA && MostrarBombas) {
        verdaderaLetra = BOMBA;
      }
      printf("  %c ", verdaderaLetra);
      if (a + 1 == NCOLUMNAS) {
        printf(" ");
      }
    }
    printf("\n");
  }
}

//Armando los encabezados verticales y horizontales de la cuadricula
int abrirCasilla(char filaLetra, int columna, char cuadricula[NFILAS][NCOLUMNAS]) {
  filaLetra = toupper(filaLetra);   // Convertir a mayúscula
  columna--; // Restamos 1 porque usamos la columna como índice
  int fila = filaLetra - 'A'; // Convertir la letra a índice
  assert(columna < NCOLUMNAS && columna >= 0);
  assert(fila < NFILAS && fila >= 0);
  
  if (cuadricula[fila][columna] == BOMBA) {
    return ERROR_BOMBA_ENCONTRADA;
  }
  if (cuadricula[fila][columna] == ESPACIO_DESCUBIERTO) {
    return ERROR_ESPACIO_ENCONTRADO;
  }
  // Si no hay error se muestra la celda
  cuadricula[fila][columna] = ESPACIO_DESCUBIERTO;
  return TODO_OK;
}

// Para saber si el usuario ganó
int TodasAbiertas(char cuadricula[NFILAS][NCOLUMNAS]) {
  int b;
  for (b = 0; b < NFILAS; b++) {
    int a;
    for (a = 0; a < NCOLUMNAS; a++) {
      char actual = cuadricula[b][a];
      if (actual == ESPACIO_MISTERIOSO) {
        return 0;
      }
    }
  }
  return 1;
}

//-------------------MECANISMO DEL JUEGO------------------------//
int main() {
  printf("         ** BUSCAMINAS **\n\nINSTRUCCIONES:\n-> Escribe las coordenadas de acuerdo a si te pide una columna o fila\n-> Recuerda que en buscaminas el juego se acaba si encuentras una X (Mina)\n-> Las celdas que encuentres y que no sean minas te daran pistas de la ubicacion del resto de minas\n-> El juego se acaba cuando encuentras una mina o hallaste todas las celdas vacias\n-> Al perder o ganar se te mostrara la ubicacion de las minas\n\n ");
  
  char cuadricula[NFILAS][NCOLUMNAS];
  int ChecarBombas = FALSO; //Bandera
  srand(getpid());
  inicio(cuadricula);
  BombardeoAleatorio(cuadricula);
  // Ciclo infinito se rompe cuando se caba el juego y muestra las bombas
  while (1) {
      printf ("           Tablero de Juego\n");
    imprimirCuadricula(cuadricula, ChecarBombas);
    if (ChecarBombas) {
      break;
    }
    int columna; 
    char fila;
    printf("Ingresa el numero de la columna (y): ");
    scanf("%d", &columna);
        printf("Ingresa la letra de la fila (x): ");
    scanf(" %c", &fila);
    int status = abrirCasilla(fila, columna, cuadricula);
    if (TodasAbiertas(cuadricula)) {
      printf("---------ERES UN CAPO  B)-------\n");
      ChecarBombas = VERDADERO;
    } else if (status == ERROR_ESPACIO_ENCONTRADO) {
      printf("Ya has abierto esta casilla\n");
    } else if (status == ERROR_BOMBA_ENCONTRADA) {
      printf("-----------PERDISTE NOOO :(------------\n");
      ChecarBombas = VERDADERO;
    }
  }
  return 0;
}


//Este codigo fue hecho con la ayuda del canal de youtube de Luis Cabrera Benito, el libro de programacion en c de Kernighan, y la c-refcard
