#include "../include/sistema.h"

int contem_apenas_letras( char *str){
    for(int index = 0; str[index] != '\0'; index ++){
        if(isalpha(str[index]) && str[index] != ' '){
            printf("Por favor digite apenas letras! \n");
            return 0;
        }
    }
    return 1;
}

int numeroInteiro(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

int numero_decimal(char *str) {
    int ponto_ou_virgula = 0; 
    if (!isdigit(str[0])){
        return 0;
    }
    if (!isdigit(str[strlen(str) - 1])){
        return 0;
    }
    for (int i = 0; str[i] != '\0'; i++) {

        if (!(str[i] >= '0' && str[i] <= '9')) {
            if(str[i] == ','){
                ponto_ou_virgula++;
                if (ponto_ou_virgula > 1){
                    return 0;
                }
            }
            else{
                return 0;
            }
        }
    }
    return 1;
}

int contem_apenas_numeros(char *str) {

    for (int index = 0; str[index] != '\0'; index++) {
        if (isalpha(str[index]) && str[index]) {
            printf("só aceita numero!!!!!!!!\n");
            return 0;
        }
    }
    return 1;
}

void formata_nome(char *str) {
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        if (i==0){
            str[0] = toupper(str[0]);
        }
        else{
            if (str[i - 1] == ' ') {
                str[i] = toupper(str[i]);
            } 
            else {
                str[i] = tolower(str[i]);
            }
        }
    }
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