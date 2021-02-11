# include <stdio.h>
/* imprime la tabla Fahrenheit-Celsius
para fahr = 0, 20, ..., 300; versión de punto flotante */
int main()
{
float fahr, celsius;
int lower, upper, step;
lower = 0; /* límite superior de la tabla de temperaturas */
upper = 300; /* límite superior */
step = 20; /* tamaño del incremento */
fahr = lower;
while (fahr <= upper) {
celsius = (5.0/9.0) * (fahr-32.0);
printf ("%3.1fF\t=\t%6.2fC\n", fahr, celsius);
fahr = fahr + step;
}
return 0;
}
