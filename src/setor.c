#include "../include/setor.h"
#include "../include/produto.h"

struct setor {
    char nome[50];
    char descricao[100];
    ListaProduto *produtos;
};

struct listaSetor{
    Setor setor;
    struct listaSetor *prox;
};

void CriaSetor(ListaSetor **lista){
    *lista = NULL;
}

void NovoSetor(ListaSetor **lista){
    //variaveis auxiliares
    ListaSetor *novoSetor = (ListaSetor*)malloc(sizeof(ListaSetor));
    ListaSetor *aux = NULL;

    //pegando setor
    printf("Digite o nome do setor:\n");
    scanf("%s\n", novoSetor->setor.nome);

    printf("Digite a descricao do setor: \n ");
    scanf("%s\n", novoSetor->setor.descricao);

    //procurando o setor
    if(*lista == NULL){
        *lista = novoSetor;
        novoSetor->prox = NULL;
        printf("Setor adicionado com sucesso!\n");
    } else{
        aux = *lista;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = novoSetor;
        novoSetor->prox = NULL;
        printf("Setor adicionado com sucesso!\n");
    }

}

void RemoveSetor(ListaSetor **lista){
    //variaveis auxiliares
    ListaSetor *aux = *lista;
    ListaSetor *anterior = NULL;
    char nome[50];

    //pegando o nome do setor
    printf("Digite o nome do setor que deseja remover: \n");
    scanf("%s", nome);

    //procurando o setor
    while(aux != NULL && strcmp(aux->setor.nome, nome) != 0){
        anterior = aux;
        aux = aux->prox;
    }

    //removendo o setor
    if(aux == NULL){
        printf("Setor nao encontrado!\n");
    } else if(anterior == NULL){
        *lista = aux->prox;
        free(aux);
        printf("Setor removido com sucesso!\n");
    } else{
        anterior->prox = aux->prox;
        free(aux);
        printf("Setor removido com sucessso!\n");
    }
}