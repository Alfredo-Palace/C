#include <stdio.h> //Bibliotecas
#include <math.h>
#define K 11   //"K" numero de primos que desees
#define TRUE 1 //Definiendo constantes
#define FALSE 0
#define START 0
#define SPACES 7
#define DIGITS 6

void primos (int P);  //Funcion de numeros primos

//Funcion main principal
int main () {
primos (K); //Resultado del filtro
return 1;
}

//Condiciones del filtro (binario & primo)

//Funcion convertir a numero binario
void binario (int b)
{
    int i = START;
    int base [SPACES] = {START};   //Converion manual de decimal a binario
    while (b != 0){
        base [i] = b%2;
        b /= 2;
    i=i+1;
    }
    for (int p=DIGITS;p>=0;--p) //invierte el orden de impresion
    {
        printf ("%01d", base [p]); //formato de impresion
    }
    printf ("\n"); //impresion de salto de linea
}

//Funcion checar si es un nº primo
void primos (int k)
{
    int count = TRUE;
    int root;
    int i;
    int eresprimoono;
    int c = 1;
    int ignore = TRUE;
    while (count <= k) {
        root = sqrt (c); //funcion para sacar la raiz
        eresprimoono = TRUE;
        for (i=2; i<= root; i= i+1){
         if (c%i==0) {
          eresprimoono = FALSE; //si no es primo flag = 1 y no se cumple la condicion asi que no lo imprime
           ignore = TRUE;
         }

        }
    if (eresprimoono == TRUE) {
            binario (c);
    count = count + 1;
    }
    c = c+1;

}
}

//Me gustaria agradecer a mis compañeros Angel Raul Soria, Cracklitos and Abner Z, por su ayuda a saber como orientar mi codigo
//igual agradezco a este video que se los pongo aqui: https://www.youtube.com/watch?v=RFVJHeDL9LA&t=608s, https://www.youtube.com/watch?v=w2k_8K9bveE

