#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cabecalho();

int main(){
    char op;
    cabecalho();
    printf("----------MENU----------\n");
    printf("[1] Adicionar produto \n");
    printf("[2] Remover produto \n");
    printf("[3] Editar produto \n");
    printf("[4] Adicionar novo setor\n");
    printf("[5] Remover setor existente\n");
    printf("[6] Listar setores existentes\n");
    printf("[7] Buscar produto \n");
    printf("[8] Sair \n");
    printf("-------------------------\n");
}

void cabecalho(){
    system("cls");
    printf("------------------------------------------\n");
    printf("LOJA DE PRODUTOS DE LIMPEZA\n");
    printf("------------------------------------------\n");
}

