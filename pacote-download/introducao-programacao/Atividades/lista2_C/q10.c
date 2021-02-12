#include <stdio.h>
#include <stdlib.h>


int main()
{
  int option, num1, num2, result;

  printf("--- Calculadora --- \n");
  printf("1) Soma\n");
  printf("2) Subtração\n");
  printf("3) Multiplicação\n");
  printf("4) Divisão\n");
  printf("Escolha uma operação: ");
  scanf("%d", &option);

  if (option > 4 || option < 1) {
    printf("Digite um valor válido.\n");
    return 1;
  }

  if (option == 1) {
    printf("Digite o primeiro número: ");
    scanf("%d", &num1);
    printf("Digite o segundo número: ");
    scanf("%d", &num2);

    result = num1 + num2;
    printf("O resultado é: %d\n", result);
    return 0;
  }

  if (option == 2) {
    printf("Digite o primeiro número: ");
    scanf("%d", &num1);
    printf("Digite o segundo número: ");
    scanf("%d", &num2);

    result = num1 - num2;
    printf("O resultado é: %d\n", result);
    return 0;
  }

  if (option == 3) {
    printf("Digite o primeiro número: ");
    scanf("%d", &num1);
    printf("Digite o segundo número: ");
    scanf("%d", &num2);

    result = num1 * num2;
    printf("O resultado é: %d\n", result);
    return 0;
  }

  if (option == 4) {
    printf("Digite o primeiro número: ");
    scanf("%d", &num1);
    printf("Digite o segundo número: ");
    scanf("%d", &num2);

    result = num1 / num2;
    printf("O resultado é: %d\n", result);
    return 0;
  }
}