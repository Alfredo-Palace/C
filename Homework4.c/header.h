#include <stdio.h>
#include <stdlib.h>		/* for atof() */
#define MAXOP	100		/* max size of operand or operator */
#define NUMERO	'0'		/* señal de que se encontro un numero*/
#define SIGNO	'1' /* señal de que se encontro un signo */
#define OPERADORMATH	'2'	/* señal de que se encontro un operador matematico */
#define VARIABLE		'3'	/* señal de que se encontro una variable */

int getop(char []);
void push(double);
double pop(void);
void dup(void);
void clear(void);
