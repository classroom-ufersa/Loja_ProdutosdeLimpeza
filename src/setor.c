#include "C:\Users\shamy\Desktop\estruturas 1- unidade 3\Loja_ProdutosdeLimpeza\include\setor.h"
#include "C:\Users\shamy\Desktop\estruturas 1- unidade 3\Loja_ProdutosdeLimpeza\include\produto.h"
#include "C:\Users\shamy\Desktop\estruturas 1- unidade 3\Loja_ProdutosdeLimpeza\include\sistema.h"
struct setor
{
    char nome[50];
    char descricao[100];
    ListaProduto *produtos;
};
struct listaSetor
{
    Setor setor;
    struct listaSetor *prox;
};

void CriaSetor(ListaSetor **lista){
    *lista = NULL;
}

void NovoSetor(ListaSetor **lista){
    //Variaveis auxiliares
    ListaSetor *novoSetor = (ListaSetor*) malloc(sizeof(ListaSetor));
    ListaSetor *aux = NULL;

    //Pegando o setor
    printf("Digite o nome do setor: ");
    scanf("%s", novoSetor->setor.nome);
    verificanome(novoSetor->setor.nome);
    passarMaiuscula(novoSetor->setor.nome);

    printf("Digite a descricao do setor: ");
    scanf("%s", novoSetor->setor.descricao);
    verificanome(novoSetor->setor.descricao);
    passarMaiuscula(novoSetor->setor.descricao);

    //Procurando o setor
    if(*lista == NULL){
        *lista = novoSetor;
        novoSetor->prox = NULL;
        printf("Setor adicionado com sucesso\n");
    }else{
        aux = *lista;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = novoSetor;
        novoSetor->prox = NULL;
        printf("Setor adicionado com sucesso\n");
    }
}

void RemoveSetor(ListaSetor **lista){
    //Variaveis auxiliares
    ListaSetor *aux = *lista;
    ListaSetor *anterior = NULL;
    char nome[50];

    //Pegando o nome do setor
    printf("Digite o nome do setor que deseja remover: ");
    scanf("%s", nome);
    verificanome(nome);
    passarMaiuscula(nome);

    //Procurando o setor
    while(aux != NULL && strcmp(aux->setor.nome, nome) != 0){
        anterior = aux;
        aux = aux->prox;
    }

    //Removendo o setor
    if(aux == NULL){
        printf("Setor nao encontrado\n");
    }else if(anterior == NULL){
        *lista = aux->prox;
        free(aux);
        printf("Setor removido com sucesso\n");
    }else{
        anterior->prox = aux->prox;
        free(aux);
        printf("Setor removido com sucesso\n");
    }
}