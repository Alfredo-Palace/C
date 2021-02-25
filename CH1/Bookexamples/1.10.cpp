#include <stdio.h>
int main() {
  float x = 1.199;
  int y = 18;
  while (x <= y) {
    x = x / 2;
    y = y * x;
  }
  printf("%.2f, %d\n", x, y);
}
