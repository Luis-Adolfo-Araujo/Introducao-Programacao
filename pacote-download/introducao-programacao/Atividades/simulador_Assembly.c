#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int ADD(char input[30]);
int MOV(char input[30]);
int VERIFY(char input[30]);
int A = 0, B = 0, C = 0, D = 0;
int MEMORY[26] = {};
char CONSTANTE[5] = {}, ENDERECO_MEMORIA[5] = {};
char instruction[30] = {};

int main() {
    int temp, i = 0, ascii_character, buffer;
    char stop[5] = "HLT\n";

    printf("------------------Simulador Assembly-----------------\n");
    
    while (1) {
        
        //updates 
        printf("\nBanco de Registradores: A: %d | B: %d | C: %d | D: %d\n", A, B, C, D);
        printf("Memória de Dados:");
        for (int i = 0; i < 26; i++) {
            printf(" %d", MEMORY[i]);
        }

        //Define constante e endereço de memoria pra zero, assim podemos receber novos comandos
        ENDERECO_MEMORIA[0] = '\0';
        CONSTANTE[0] = '\0';

        //input
        printf("\nInstrução: ");
        fgets(instruction, sizeof instruction, stdin);

        //verifica se o usuario quer continuar o programa
        int temp = strcasecmp(instruction, stop);
        if (temp == 0) {
            break;
        }
        
        for (int i = 0; i < strlen(instruction); i++) {
            
            //Verifica se é endereço de memória e salva no vetor ENDERECO_MEMORIA
            if (instruction[i] == '[') {
                if(instruction[i+2] == ']'){
                    strncat(ENDERECO_MEMORIA, &instruction[i+1],1);
                }
                else {
                    strncat(ENDERECO_MEMORIA, &instruction[i+1],1);
                    strncat(ENDERECO_MEMORIA, &instruction[i+2],1);
                }
            } 

            //Verifica se o ith caracter é uma constante e armazena no vetor CONSTANTE
            if (isdigit(instruction[i]) != 0){
                if (instruction[i - 1] == '['){
                    continue;
                }
                if (instruction[i + 1] == ']'){
                    continue;
                }
                strncat(CONSTANTE, &instruction[i], 1);
            }
        }

        MOV(instruction);
        continue;
    }
}


int MOV(char input[30]) {
int ascii_character, ascii_character_2, buffer;

    for (int i = 0; i < strlen(input); i++) {
        // Verifica se vetor nao esta vazio, indicando que input pede endereço de memoria
        if (ENDERECO_MEMORIA[0] != '\0') {  
            ascii_character = input[8];
            ascii_character = toupper(ascii_character);

            ascii_character_2 = input[9];
            ascii_character_2 = toupper(ascii_character_2);
                
            //verifica se a primeira instrução foi endereço de memória
            if (input[4] == '[') {

                //se houver letra trata-se de { ENDEREÇO DE MEMORIA - REGISTRADOR }
                if ( isalpha(ascii_character_2)!= 0 || isalpha(ascii_character) != 0){
                    
                    if (ascii_character == 65 || ascii_character_2 == 65) {
                        MEMORY[atoi(&ENDERECO_MEMORIA)] = A;
                        return 0;
                    }

                    if (ascii_character == 66 || ascii_character_2 == 66) {
                        MEMORY[atoi(&ENDERECO_MEMORIA)] = B;
                        return 0;
                    }

                    if (ascii_character == 67 || ascii_character_2 == 67) {
                        MEMORY[atoi(&ENDERECO_MEMORIA)] = C;
                        return 0;
                    }

                    if (ascii_character == 68 || ascii_character_2 == 68) {
                        MEMORY[atoi(&ENDERECO_MEMORIA)] = D;
                        return 0;
                    }
                }

                //se não, trata-se de { ENDEREÇO DE MEMORIA - CONSTANTE }
                else { 
                    MEMORY[atoi(&ENDERECO_MEMORIA)] = atoi(&CONSTANTE);
                    return 0;
                }   
            }

            // Se é endereço de memoria, mas como segunda instrução { REGISTRADOR - ENDEREÇO DE MEMORIA }
            else if (input[6] == '['){
                ascii_character = input[4];
                ascii_character = toupper(ascii_character);

                if (ascii_character == 65) {
                    A = MEMORY[atoi(&ENDERECO_MEMORIA)];
                    return 0;
                }

                if (ascii_character == 66) {
                    B = MEMORY[atoi(&ENDERECO_MEMORIA)];
                    return 0;
                }

                if (ascii_character == 67) {
                    C = MEMORY[atoi(&ENDERECO_MEMORIA)];
                    return 0;
                }

                if (ascii_character == 68) {
                    D = MEMORY[atoi(&ENDERECO_MEMORIA)];
                    return 0;
                }
            }
        }

        //  { REGISTRADOR - CONSTANTE } -- > MOV & ADD
        if (CONSTANTE != '\0' && isdigit(input[6]) != 0) {
            ascii_character = toupper(input[4]);

            if (ascii_character == 65) {
                if (toupper(input[2]) == 'D'){
                    A += atoi(&CONSTANTE);
                    return 0;
                }
                A = atoi(&CONSTANTE);
                return 0;
            }

            if (ascii_character == 66) {
                if (toupper(input[2]) == 'D'){
                    B += atoi(&CONSTANTE);
                    return 0;
                }
                B = atoi(&CONSTANTE);
                return 0;
            }

            if (ascii_character == 67) {
                if (toupper(input[2]) == 'D'){
                    C += atoi(&CONSTANTE);
                    return 0;
                }
                C = atoi(&CONSTANTE);
                return 0;
            }

            if (ascii_character == 68) {
                if (input[2] == 'D'){
                    D += atoi(&CONSTANTE);
                    return 0;
                }
                D = atoi(&CONSTANTE);
                return 0;
            }
        }

        // {REGISTRADOR - REGISTRADOR } MOV & ADD
        if (isalpha(input[6]) != 0){
            ascii_character = toupper(input[6]);
            ascii_character_2 = toupper(input[4]);

            if (ascii_character == 65){
                if (ascii_character_2 == 66){
                    if (toupper(input[2]) == 'D') {
                        B += A;
                        return 0;
                    }
                    B = A;
                    return 0;
                }

                if (ascii_character_2 == 67){
                    if (toupper(input[2]) == 'D') {
                        C += A;
                        return 0;
                    }
                    C = A;
                    return 0;
                }

                if (ascii_character_2 == 68){
                    if (toupper(input[2]) == 'D') {
                        D += A;
                        return 0;
                    }
                    D = A;
                    return 0;
                }
            }

            if (ascii_character == 66){
                    
                if (ascii_character_2 == 65){
                    if (toupper(input[2]) == 'D') {
                        A += B;
                        return 0;
                    }
                    A = B;
                    return 0;
                }

                if (ascii_character_2 == 67){
                    if (toupper(input[2]) == 'D') {
                        C += B;
                        return 0;
                    }
                    C = B;
                    return 0;
                }

                if (ascii_character_2 == 68){
                    if (toupper(input[2]) == 'D') {
                        D += B;
                        return 0;
                    }
                    D = B;
                    return 0;
                }
            }

            if (ascii_character == 67){
                    
                if (ascii_character_2 == 65){
                    if (toupper(input[2]) == 'D') {
                        A += C;
                        return 0;
                    }
                    A = C;
                    return 0;
                }

                if (ascii_character_2 == 66){
                    if (toupper(input[2]) == 'D') {
                        B += C;
                        return 0;
                    }
                    B = C;
                    return 0;
                }

                if (ascii_character_2 == 68){
                    if (toupper(input[2]) == 'D') {
                        D += C;
                        return 0;
                    }
                    D = C;
                    return 0;
                }
            }
                
            if (ascii_character == 68){
                    
                if (ascii_character_2 == 65){
                    if (toupper(input[2]) == 'D') {
                        A += D;
                        return 0;
                    }
                    A = D;
                    return 0;
                }

                if (ascii_character_2 == 66){
                    if (toupper(input[2]) == 'D') {
                        B += D;
                        return 0;
                    }
                    B = D;
                    return 0;
                }

                if (ascii_character_2 == 67){
                    if (toupper(input[2]) == 'D') {
                        C += D;
                        return 0;
                    }
                    C = D;
                    return 0;
                }
            }
        }
    }
    return 0;
}
