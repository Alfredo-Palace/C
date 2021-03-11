#include <stdio.h> // Stablish the library
#include <ctype.h> // isdigit: Identify if the character is a number
#define TRUE 1
#define FALSE 0   //Stablish my constants to simplify the procees of redaction
#define INICIO 0
#define FINAL 2
#define NOES 1
#define SIES 0

int main() {
  int c;
  int numeros = NOES;
  int parentesis = TRUE;     // Assigning values to the variables
  int comillas = FALSE;

  do{    //using the loop do while
      switch(c){
      case '[':  case '(': case '{': case '<': //Begining of the parenthesis
          parentesis=FALSE;
          putchar(c);
          break;

      case ']': case ')': case '}': case '>': //ending of the parenthesis
          parentesis=TRUE;
          putchar(c);
          break;

      case '\"': case '\'': case '/':    //using a counter to identifiy the quotes
          putchar(c);
          comillas++;
          break;

      default:  //if the above is not true, do this

        if(c!='.'&&c!=':'&&c!='\?'&&c!='!'&&c!='-'&&c!=';'&&c!='_'&&c!='`'&&c!='¿'&&c!='¡'&&c!='*'){   //Lets eliminate the punctuation 
            if (parentesis==FALSE||comillas==TRUE){
            putchar (c);
            }

            else{
                if (comillas==FINAL){
                    comillas=INICIO;
                }
                if (isdigit(c)){//Here we identify if the character is a number
                    numeros = numeros + 1; 
                }
                else{
                  numeros=INICIO;
                }
                if (numeros==NOES){ //If the number is not in a parentesis printf X
                    putchar('X');
                }
                if (numeros==SIES){ //If the number is in a parentesis printf the original input
                    putchar(c);
                }
                }
        }

        }
    } while ((c = getchar()) != EOF); //do all of the above while the cycle is running 
    return 90;
  }
//I would like to thak my mates Angel Raul Chavez, Cracklitos and Hector Mtz for open my panorama to simplify my ideas about how to do my code, you are amazing bros :)
