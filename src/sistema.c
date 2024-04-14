#include "../include/sistema.h"

int contem_apenas_letras( char *str){
    for(int index = 0; str[index] != '\0'; index ++){
        if(isalpha(str[index]) && str[index] != ' '){
            printf("Por favor digite apenas letras! \n");
            return 0;
        }
    }
}

float lerFloat() {
    char input[100];

    printf("Digite um número decimal: ");
    fgets(input, sizeof(input), stdin);

    float numero = atof(input);

    return numero;
}

void upper_string(char *str) {
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        str[i] = toupper(str[i]);
    }
}

void cabecalho(){
    system("cls");
    printf("------------------------------------------\n");
    printf("LOJA DE PRODUTOS DE LIMPEZA\n");
    printf("------------------------------------------\n");
}
