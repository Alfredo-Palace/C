#include <stdio.h>
/* copia la entrada a la salida; la. versi�n */
int main()
{
int c;
c = getchar( );
while ((c = EOF)) {
putchar(c);
c = getchar( );
}
}
