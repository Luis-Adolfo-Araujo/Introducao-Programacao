#include <stdio.h>
#include <math.h> 

int main() {
  int days, hours, min, sec;
  
  
  printf("Digite a quantidade de dias:  ");
  scanf("%d", &days);
  
  printf("Digite a quantidade de horas:  ");
  scanf("%d", &hours);

  printf("Digite a quantidade de minutos:  ");
  scanf("%d", &min);

  days *= 86400;
  hours *= 3600;
  min *= 60;

  sec = (days + hours + min);
  printf("O valor em segundos é %d", sec);
  return 0;
}