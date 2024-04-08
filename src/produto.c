#include "../include/produto.h"

struct produto {
    char nome[50];
    char marca[50];
    float preco;
    int quantEstoque;
    struct setor *prox;
};

Produto *adicionarProd(Produto *produto, char *nome, char *marca, float preco){
    Produto *novo_prod = (Produto*)malloc(sizeof(Produto));
    if(novo_prod == NULL){
        printf("Erro na alocacao da memoria! \n");
        exit(1);
    }
    strcpy(novo_prod->nome, nome);
    strcpy(novo_prod->marca, marca);
    novo_prod->preco = preco;
    novo_prod->prox = produto;
    return novo_prod;
}

Produto *criaProd(void){
    return NULL;
}

Produto *removeProd(Produto *produto, char *nome, char marca, float preco){
    Produto *ant = NULL;
    Produto *atual = produto;

    while(atual != NULL){
        if(strcmp(atual->nome, nome)== 0 &&
           strcmp(atual->marca, marca)== 0 &&
           (atual->preco, preco)== 0){
            if(ant == NULL){
                produto = atual->prox;
            }
            else{
                ant->prox = atual->prox;
            }
            free(atual);
            return produto;
           }
        ant = atual;
        atual = atual->prox;
    }
    printf("Produto nao encontrado!\n");
    return produto;
}

Produto *editaProd(Produto *produto, char *nome, char *marca, float preco){
    
}