#include <stdio.h>
#include <stdlib.h>		/* for atof() */
#define MAXOP	100		/* max size of operand or operator */
#define NUMERO	'0'		/* signal that a number was found */
#define SIGNO	'1' /* signal that an operator was found */
#define OPERADORMATH	'2'	/* signal that a math operator was found */
#define VARIABLE		'3'	/* signal that a variable was found */

int getop(char []);
void push(double);
double pop(void);
void dup(void);
void clear(void);