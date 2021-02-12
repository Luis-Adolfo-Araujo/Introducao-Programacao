#include <stdio.h>
#include <math.h>

int main(void) {
  float height, weight, imc;

  printf("Enter the height: ");
  scanf("%f", &height);

  printf("Enter the weight: ");
  scanf("%f", &weight);

  imc = weight / (height * height);

  if (imc < 18.5) {
    printf("Slightness");
    return 0;
  }

  if(imc > 18.5 && imc < 24.9){
    printf("Normal");
    return 0;
  }

  if(imc > 25.0 && imc < 29.9){
    printf("overweight");
    return 0;
  }

  if(imc < 30.0 && imc < 39.9){
    printf("Obesity");
    return 0;
  }

  printf("Serious obesity");
  return 0;
}