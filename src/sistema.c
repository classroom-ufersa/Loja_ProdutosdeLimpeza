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
    char input[100]; // buffer para armazenar a entrada do usuário

    // Ler a entrada do usuário como uma string
    printf("Digite um número decimal: ");
    fgets(input, sizeof(input), stdin);

    // Converter a string para um float usando strtod() ou atof()
    float numero = atof(input);

    return numero;
}
void cabecalho(){
    system("cls");
    printf("------------------------------------------\n");
    printf("LOJA DE PRODUTOS DE LIMPEZA\n");
    printf("------------------------------------------\n");
}
