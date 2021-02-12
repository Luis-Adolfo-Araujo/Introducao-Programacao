#include <stdio.h>
#include <stdlib.h>


int main()
{
  int option;
  float celsius, fahrenheit;

  printf(" 1) Celsius - fahrenheit\n 2) Fahrenheit - Celsius\n Digite uma das opções acima: ");
  scanf("%d", &option);

  if (option > 2 || option < 1){
    printf("Digite uma opção válida\n");
    return 1;
  }

  if (option == 1) {
    printf("Digite a temperatura em Celsius: ");
    scanf("%f", &celsius);
    fahrenheit = (celsius * 9/5) + 32;
    printf("Equivale a %.2f", fahrenheit); 
    return 0;
  }
  
  printf("Digite a temperatura em Fahrenheit: ");
  scanf("%f", &fahrenheit);
  celsius = (fahrenheit - 32) * 5/9;
  printf("Equivale a %.2f", celsius);
  return 0;
}