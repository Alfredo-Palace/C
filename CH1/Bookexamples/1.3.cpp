#include <stdio.h> // para printf
#define LOWER 0 // ahora con constantes
#define HIGHER 300
#define STEP 20

int main() {
  float fahr; // menos variables

  for (fahr = LOWER; fahr <= HIGHER; fahr = fahr + STEP) { 
    printf("%3.1fF\t=\t%6.2fC\n", fahr, 5.0 * (fahr - 32) / 9.0);
  }
  return 0;
}
