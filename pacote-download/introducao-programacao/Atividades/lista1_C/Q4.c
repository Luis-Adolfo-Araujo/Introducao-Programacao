#include <stdio.h>
#include <math.h> 

int main() {
  int a, b, c;
  float x1, x2, x, delta;
  
  printf("Digite o valor de a: ");
  scanf("%d", &a);

  printf("Digite o valor de b: ");
  scanf("%d", &b);

  printf("Digite o valor de c: ");
  scanf("%d", &c);

  //calculando o valor de delta
  delta = (b * b) - (4 * a * c);
  
  if (delta < 0){
    printf("Sem resultados reais possíveis.");
    return 1;
  }

  if (delta == 0){
    x = -(b) / (2 * a);
    printf("Os valores de x1 e x2 são iguais. X = %f", x);
  }
  else {
    delta = sqrt(delta);

    //Calculando x1
    x1 = -(b) + delta;
    x1 = x1 / 2 * a;

    //Calculando x2
    x2 = -(b) - delta;
    x2 = x2 / 2 * a;
    printf("X1 = %f | X2 = %f", x1, x2);
  }

  return 0;
}