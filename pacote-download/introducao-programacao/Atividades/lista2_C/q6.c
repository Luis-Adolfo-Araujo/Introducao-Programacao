#include <stdio.h>
#include <math.h>

int main(void) {
  int i = 0;
  char input[13], password[13] = "lemonysnicket";

  printf("Digite a senha: ");
  scanf("%s", input); 
  
  while (i < 12) {

    if (input[i] == password[i]){
      i++;
    } else{
      printf("Senha incorreta\n");
      return 1;
    }
  }

  printf("Senha correta");
  return 0;
}