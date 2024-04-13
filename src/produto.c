#include "../include/produto.h"

struct produto {
    char nome[50];
    char marca[50];
    float preco;
    int quantEstoque;
    struct setor *prox;
};

Produto *adicionarProd(Produto *lista_prod, Produto produto){
    Produto *novo_prod = (Produto*)malloc(sizeof(Produto));
    if(novo_prod == NULL){
        printf("Erro na alocacao da memoria! \n");
        exit(1);
    }
    strcpy(novo_prod->nome, produto.nome);
    strcpy(novo_prod->marca, produto.marca);
    novo_prod->preco = produto.preco;

    novo_prod->prox = NULL;


    if (lista_prod == NULL || strcmp(novo_prod->nome, produto.nome) > 0) {
        novo_prod->prox = lista_prod;
        return novo_prod;
    }

    Produto *ant = NULL;
    Produto *aux = lista_prod;

    while (aux != NULL && strcmp(aux->nome, produto.nome) < 0) {
        ant = aux;
        aux = aux->prox;
    }
    ant->prox = novo_prod;
    novo_prod->prox = aux;

    return lista_prod;
}

Produto *criaProd(void){
    return NULL;
}

Produto *editaProd(Produto *produto, char *nome, char *marca, float preco){
    
}

Produto *removeProd(Produto *produto, char *nome, char marca, float preco){
    Produto *ant = NULL;
    Produto *aux = produto;

    while(aux != NULL){
        if(strcmp(aux->nome, nome)== 0 &&
           strcmp(aux->marca, marca)== 0 &&
           (aux->preco, preco)== 0){
            if(ant == NULL){
                produto = aux->prox;
            }
            else{
                ant->prox = aux->prox;
            }
            free(aux);
            return produto;
           }
        ant = aux;
        aux = aux->prox;
    }
    printf("Produto nao encontrado!\n");
    return produto;
}

void lista_prod(Produto *lista_prod){
    Produto *aux = lista_prod;
    int encontrado = 0;

    if(aux == NULL){
        printf("Ainda nao foi adicionado nenhum produto! \n");
    }
    else {
        cabecalho("==========================", "Lista de Produtos");
        while(aux != NULL){
            cabecalho("==========================", "Produto");

            printf("Nome: %s\n", aux->nome);
            printf("Marca: %s\n", aux->marca);
            printf("Preco: %f\n", aux->preco);

            aux = aux->prox;
        }
    }
}