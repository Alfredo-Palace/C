#include <stdio.h> //printf, scanf 
#include <string.h> // strstr
#include <stdlib.h> // malloc & free
#include <ctype.h> // isspace & tolower
#define MAX 80
#define FALSO 0
#define VERDADERO 1
typedef struct nodoCadena
{
    char username[MAX];
    char password[MAX];
    // Las ramas
    struct nodoCadena *leftChild;
    struct nodoCadena *rightChild;
} usuario;

