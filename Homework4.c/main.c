
#include "header.h"

/* reverse Polish Calculator */
int main()
{
	int type;
	double op2, op1;
	char s[MAXOP];
	double variables[52] = {0.0};
	char var;
    printf("    BIENVENIDO A LA CALCULADORAAAA INVERSA POLACA \n\n Al ser una calculadora con estas caracteristicas la notacion sera la siguiente:\n -> Las operaciones son asi (1 2 + -> 1+2)\n -> Para asignar valor a una variable escribe algo asi:  Numero Letra = (EJ: 4 B = -> B = 4) \n -> Para asignar un valor forzado a una variable escribe al asi: Numero Letra := (EJ: 4 B := -> B := 4)\n\n *preferible si usas mayusculas pq me cuesta entender procesar minusculas jejeje perdon :( \n \n !!!!!! IMPORTANTE: RESPETA EL ESPACIADO ('12+' NO es lo mismo que '1 2 +'), y PRESIONA LA TECLA ENTER DESPUES DE CADA ESCRITURA\n\n INFORMACION QUE CURA: Si no te acuerdas del valor de una variable que ya estableciste escribe esto para que te la arroje:\n -> Numero ? (EJ: B ?) \n\n Si quieres cerrar el programa presiona ctrl C\n enjoy it :)\n\n");

	while ((type = getop(s)) != EOF){

		switch(type) {
			case NUMERO:
				push(atof(s));
				break;
			case SIGNO:
				switch(s[0]) {
					case '+':
					push(pop() + pop());
					break;
				case '*':
					push(pop() * pop());
					break;
				case '-':
					op2 = pop();
					push(pop() - op2);
					break;
				case '/':
					op2 = pop();
					if(op2 != 0.0)
						push(pop() / op2);
					else
						printf("error: divisor de cero\n");
					break;
				case '%':
					op2 = pop();
					if(op2 != 0.0)
						push((int)pop() % (int)op2);
					else
						printf("error: divisor de cero\n");
					break;
				case '=':
					pop();
					push(variables[var - 'A'] = pop());
					break;
				case  '?':
					push(variables[var - 'A']);
					break;
				case ':'&&'=':
					pop();
					push(variables[var - 'A'] = pop());
					break;
				}
				break;

			case OPERADORMATH:{
					push(atof(s));;
				}
				break;
			case  VARIABLE:
				var = s[0];
				push(variables[var - 'A']);
				break;
			case '\n':
				dup();
				printf("\t%.8g\n", pop());
				break;
			default:
				printf("error: no se que andas diciendo jajaja %s\n", s) ;
				break;
		        }
		}

	}


#define MAXVAL	100		/* maximum depth of value stack */

int sp = 0;				/* next free stack position */
double val[MAXVAL];		/* value stack */

/* push: push f onto value stack */
void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: ta todo lleno, no lo puedo pushear %g\n", f);
}
/* pop: pop and return top value from stack */
double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else {
		printf("error: lo que pusiste no tiene valor numerico\n");
		
	}
	return 0.0;
}

#include <ctype.h>

int getch(void);
void ungetch(int);

/* getop: get next operator or numeric operand */
int getop(char s[])
{
	int i, c, op, sign = 0;

	while((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';

	if(c == '\n')
		return c;

	i = 0;

	/* collect all the characters */
	while(isalnum(s[++i] = c = getch()) || c == '.')
		;

	s[i] = '\0';
	if(c != EOF)
		ungetch(c);

	/* determine if it is a NUMBER, an OPERATOR, or a
	 * MATH_OPER */
	if(i == 1 && !isalnum(s[0]))
			return SIGNO;
	else if(i == 1 && isupper(s[0]))
		return VARIABLE;
	else if(i > 1 &&  isalpha(s[0]))
		return OPERADORMATH;
	else
		return NUMERO;

}

#define BUFSIZE	100

char buf[BUFSIZE];		/* buffer for ungetch */
int bufp = 0;			/* next free position in buf */

int getch(void)			/* get a (possibly pushed back) character */
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)		/* push character back on input */
{
	if (bufp >= BUFSIZE)
		printf("ungetch: Mucho texto mijo\n");
	else
		buf[bufp++] = c;
}

