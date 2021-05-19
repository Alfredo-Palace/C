#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#define FALSE 0
#define TRUE 1

int saca (int max, char *buf); //memoria dinamica

char primeraVocal (char *buf);

char primeraConsonante (char *buf);

int Primer_QuintoTotem (char *buf, char *curp);

int SegundoTotem (char *buf, char *curp);

int TercerTotem (char *buf, char *curp);

int CuartoTotem (int indice, char *curp);

int SextoTotem (char *curp); //homoclave aleatoria

	