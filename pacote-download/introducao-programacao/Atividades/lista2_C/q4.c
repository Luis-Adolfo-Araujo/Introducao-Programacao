#include <stdio.h>
#include <math.h>

int main(void) {
  float va1, va2, greater, average, minor;

  printf("enter your 'va1' score: ");
  scanf("%f", &va1);

  printf("enter your 'va2' score: ");
  scanf("%f", &va2);

  //verify the greater number to divide correctly
  if (va1 > va2) {
    greater = va1;
    minor = va2;
  } else {
    greater = va2;
    minor = va1;
  }
  //take the average
  average = (greater + minor) / 2;

  if (average >= 7.0) {
    printf("You got approved with %.2f", average);
  } 
  else {
    average = 14 - average;
    printf("You need a %.2f on 'va3' to get approved", average);
  } 

  return 0;
}