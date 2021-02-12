#include <stdio.h>
#include <math.h>

int main(void) {
  int number;

  printf("Enter a number from 1 to 7: ");
  scanf("%d", &number);

  if (number == 1) {
    printf("Sunday\n");
  }

  if (number == 2) {
    printf("Monday\n");
  }

  if (number == 3) {
    printf("tuesday\n");
  }

  if (number == 4) {
    printf("wednesday\n");
  }

  if (number == 5) {
    printf("Thursday\n");
  }

  if (number == 6) {
    printf("Friday\n");
  }

  if (number == 7) {
    printf("Saturday\n");
  }

  if (number < 1 || number > 7) {
    printf("Invalid number\n");
  }
  return 0;
}