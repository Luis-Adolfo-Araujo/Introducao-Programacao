#include <stdio.h>

int main() {
  int a, b, soma;
  
  printf("Digite o valor de A:\t");
  scanf("%d", &a);
  printf("Digite o valor de B:\t");
  scanf("%d", &b);

  soma = a + b;
  printf("O valor da soma é %d", soma);

  return 0;
}