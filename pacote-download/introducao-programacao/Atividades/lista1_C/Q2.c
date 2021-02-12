#include <stdio.h>
#include <math.h> 

int main() {
  int Xa, Ya, Xb, Yb;
  float distance;
  
  //Lê as coordenadas do Ponto A
  printf("Digite o valor das coordenadas do ponto A(Xa, Ya):\n");
  
  printf("Xa:\t");
  scanf("%d", &Xa);
  
  printf("Ya:\t");
  scanf("%d", &Ya);
  
  //Lê as coordenadas do ponto B
  printf("Digite o valor das coordenadas do ponto B(Xb, Yb):\n");
  
  printf("Xb:\t");
  scanf("%d", &Xb);
  
  printf("Yb:\t");
  scanf("%d", &Yb);

  //Determina a distância entre os pontos
  Xb = Xb - Xa;
  Yb = Yb - Ya;

  Xb = pow(Xb, 2);
  Yb = pow(Yb, 2);
  
  distance = sqrt((Xb + Yb));

  printf("A distância entre os pontos é %f", distance);

  return 0;
}