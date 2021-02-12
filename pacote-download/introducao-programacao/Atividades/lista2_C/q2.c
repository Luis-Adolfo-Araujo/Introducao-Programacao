#include <stdio.h>

int main(void) {
  int number;

  printf("Enter a number: ");
  scanf("%d", &number);

  if (number % 2 == 0) {
    printf("Number is even");
    return 0;
  }
  
  printf("number is odd");
  return 0;
}