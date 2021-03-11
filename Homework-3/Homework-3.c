#include <stdio.h>
#include <ctype.h>
#define TRUE 1
#define FALSE 0
#define INICIO 0
#define FINAL 2
#define NOES 1
#define SIES 0

int main() {
  int c;
  int numeros = NOES;
  int parentesis = TRUE;
  int comillas = FALSE;

  do{
      switch(c){
      case '[':  case '(': case '{': case '<':
          parentesis=FALSE;
          putchar(c);
          break;

      case ']': case ')': case '}': case '>':
          parentesis=TRUE;
          putchar(c);
          break;

      case '\"': case '\'': case '/':
          putchar(c);
          comillas++;
          break;

      default:

        if(c!='.'&&c!=':'&&c!='\?'&&c!='!'&&c!='-'&&c!=';'&&c!='_'&&c!='`'&&c!='¿'&&c!='¡'&&c!='*'){
            if (parentesis==FALSE||comillas==TRUE){
            putchar (c);
            }

            else{
                if (comillas==FINAL){
                    comillas=INICIO;
                }
                if (isdigit(c)){
                    numeros = numeros + 1;
                }
                else{
                  numeros=INICIO;
                }
                if (numeros==NOES){
                    putchar('X');
                }
                if (numeros==SIES){
                    putchar(c);
                }
                }
        }

        }
    } while ((c = getchar()) != EOF);
    return 90;
  }
