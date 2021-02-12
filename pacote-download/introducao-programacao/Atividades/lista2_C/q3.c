#include <stdio.h>

int main(void) {
  float sideA, sideB, sideC;

  printf("Enter value of Side A: ");
  scanf("%f", &sideA);

  printf("Enter value of Side B: ");
  scanf("%f", &sideB);

  printf("Enter value of Side C: ");
  scanf("%f", &sideC);

  if (sideA == sideB && sideA == sideC) {
    printf("Equilateral triangle");
    return 0;
  }

  if(sideA != sideB && sideA == sideC) {
    printf("Isosceles triangle");
    return 0;  
  }

  if(sideB == sideA && sideB != sideC) {
    printf("Isosceles triangle");
    return 0;
  }

  printf("Scalene triangle");
  return 0;
}