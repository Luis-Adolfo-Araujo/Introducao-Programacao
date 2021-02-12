#include <stdio.h>

int main(void) {

  int number1, number2, number3;

  printf("enter the 1st number: ");
  scanf("%d", &number1);

  printf("enter the 2nd number: ");
  scanf("%d", &number2);

  printf("enter the 3rd number: ");
  scanf("%d", &number3);

  if (number1 > number2 && number1 > number3) {
    printf("the greater number is %d\n", number1);
  }
  
  else if (number2 > number1 && number2 > number3) {
    printf("the greater number is %d\n", number2);
  } else {
      printf("the greater number is %d\n", number3);
  }

}