#include "../include/produto.h"
#include "../include/setor.h"

struct produto
{
    char nome[50];
    char marca[100];
    float preco;
    int quantidade;
};
struct listaProduto
{
    Produto produto;
    struct listaProduto *prox;
};

void CriaProduto(ListaProduto **lista){
    *lista = NULL;
}

void NovoProduto(ListaSetor **lista){
    //variaves auxiliares
    char nomeSetor[50];
    char nomeProduto[50];
    char marca[100];
    float preco;
    int quantidade;

    //lendo o nome do setor
    printf("Digite o nome do setor: ");
    scanf(" %[^\n]", nomeSetor);

    //buscando o setor
    ListaSetor *aux = *lista;

    while(aux != NULL && strcmp(aux->setor.nome, nomeSetor) != 0){
        aux = aux->prox;
    }

    //verificando se o setor existe
    if(aux == NULL){
        printf("Setor nao encontrado\n");
        return;
    }

    //lendo os dados do produto
    printf("Digite o nome do produto: ");
    scanf(" %[^\n]", nomeProduto);

    printf("Digite a marca do produto: ");
    scanf(" %[^\n]", marca);

    printf("Digite o preco do produto: ");
    scanf("%f", &preco);

    printf("Digite a quantidade do produto: ");
    scanf("%d", &quantidade);

    //criando o novo produto

    ListaProduto *novo = (ListaProduto *)malloc(sizeof(ListaProduto));
    strcpy(novo->produto.nome, nomeProduto);
    strcpy(novo->produto.marca, marca);
    novo->produto.preco = preco;
    novo->produto.quantidade = quantidade;

    //inserindo o produto na lista de produtos do setor
    novo->prox = aux->setor.produtos;
    aux->setor.produtos = novo;

    printf("Produto adicionado com sucesso\n");
}

void RemoveProduto(ListaSetor **lista){
    //variaveis auxiliares
    char nomeSetor[50];
    char nomeProduto[50];

    //lendo o nome do setor
    printf("Digite o nome do setor: ");
    scanf(" %[^\n]", nomeSetor);

    //buscando o setor
    ListaSetor *aux = *lista;

    while(aux != NULL && strcmp(aux->setor.nome, nomeSetor) != 0){
        aux = aux->prox;
    }

    //verificando se o setor existe
    if(aux == NULL){
        printf("Setor nao encontrado\n");
        return;
    }

    //lendo o nome do produto
    printf("Digite o nome do produto: ");
    scanf(" %[^\n]", nomeProduto);

    //buscando o produto
    ListaProduto *auxProduto = aux->setor.produtos;
    ListaProduto *anterior = NULL;

    while(auxProduto != NULL && strcmp(auxProduto->produto.nome, nomeProduto) != 0){
        anterior = auxProduto;
        auxProduto = auxProduto->prox;
    }

    //verificando se o produto existe
    if(auxProduto == NULL){
        printf("Produto nao encontrado\n");
        return;
    }

    //removendo o produto
    if(anterior == NULL){
        aux->setor.produtos = auxProduto->prox;
    }else{
        anterior->prox = auxProduto->prox;
    }

    free(auxProduto);
    printf("Produto removido com sucesso\n");
}

void EditaProduto(ListaSetor **lista){
    //variaveis auxiliares
    char nomeSetor[50];
    char nomeProduto[50];
    char marca[100];
    float preco;
    int quantidade;

    //lendo o nome do setor
    printf("Digite o nome do setor: ");
    scanf(" %[^\n]", nomeSetor);

    //buscando o setor
    ListaSetor *aux = *lista;

    while(aux != NULL && strcmp(aux->setor.nome, nomeSetor) != 0){
        aux = aux->prox;
    }

    //verificando se o setor existe

}