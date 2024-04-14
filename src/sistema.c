#include "../include/sistema.h"

int contem_apenas_letras( char *str){
    for(int index = 0; str[index] != '\0'; index ++){
        if(isalpha(str[index]) && str[index] != ' '){
            printf("Por favor digite apenas letras! \n");
            return 0;
        }
    }
}

int contem_apenas_numeros(char *str) {

    for (int index = 0; str[index] != '\0'; index++) {
        if (isalpha(str[index]) && str[index]) {
            printf("só aceita numero!!!!\n");
            return 0;
        }
    }
    return 1;
}

void cabecalho(){
    system("cls");
    printf("------------------------------------------\n");
    printf("LOJA DE PRODUTOS DE LIMPEZA\n");
    printf("------------------------------------------\n");
}


