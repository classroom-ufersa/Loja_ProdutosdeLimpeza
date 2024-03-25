#include <stdio.h>
#include <stdlib.h>
#include "setor.h"
#include "lista.c"


typedef struct setor{
    char nome[50];
    char descrição[100];
    char produto[50]
}Setor;

Setor *cria_setor(char nome, char descrição, char produto){
    Setor* setor = (Setor*)malloc(sizeof(Setor*));

    if (setor == NULL){
        printf("ERRO NA ALOCAÇÃO DE MEMÓRIA!!!\n");
        exit(1);
    }



    printf("Informe o nome do setor que deseja cadastrar:\n");
    scanf("%s\n", setor->nome);
}