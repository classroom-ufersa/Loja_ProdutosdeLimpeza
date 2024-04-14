#include "../include/produto.h"

struct produto {
    char nome[50];
    char marca[50];
    float preco;
    int quantEstoque;
    Produto *prox;
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

int verifica_nome_prod(Produto *lista_prod, char nome[50]){
    Produto *listaAux = lista_prod;

    while(listaAux != NULL){
        if(strcmp(listaAux->nome, nome)== 0){
            return 0;
        }
        listaAux = listaAux->prox;
    }
    return 1;
}

int verifica_edicao_nome_prod(Produto *lista_prod, char nome_editado[50], char nome_antigo[50]){
    Produto *listaAux = lista_prod;

    if(strcmp(nome_editado, nome_antigo)== 0){
        printf("Foi digitado o nome que ja estava cadastrado, portanto ele continuara apos a edicao\n");
        return 1;
    }
    while(listaAux != NULL){
        if(strcmp(listaAux->nome, nome_editado)== 0){
            if(strcmp(listaAux->nome, nome_antigo)== 0){
                return 1;
            }
            return 0;
        }
        listaAux = listaAux->prox;
    }
    return 1;
}

Produto *edita_prod(Produto *lista_prod, char *nome_antigo){
    Produto *aux = lista_prod;
    if (aux == NULL){
        printf("Produto nao existente!\n");
    }
    else{
        for(aux = lista_prod; aux != NULL; aux = aux->prox){
            if(strcmp(aux->nome, nome_antigo)== 0){
                char nome_digitado[50], marca_digitada[50];
                float preco_digitado;

                do{
                    printf("Digite o nome editado (por favor digite apenas letras)\n");
                    scanf("%s", nome_digitado);
                    getchar();
                } while (!contem_apenas_letras(nome_digitado));

                do{
                    printf("Digite a marca do produto:\n");
                    scanf("%s", marca_digitada);
                    getchar();
                } while(!contem_apenas_letras(marca_digitada));

                do{
                    printf("Digite o preco do produto:\n");
                    scanf("%f", &preco_digitado);
                } while(lerFloat(&preco_digitado));

                strcpy(aux->nome, nome_digitado);
                strcpy(aux->marca, marca_digitada);
                      (aux->preco = preco_digitado);
                      return lista_prod;
            }
        }
        printf("Esse produto nao existe!\n");
    }
    return lista_prod;
}

Produto * removeProd(Produto *produto, char *nome, char *marca, float preco){
    Produto *ant = NULL;
    Produto *aux = produto;

    while(aux != NULL){
        if(strcmp(aux->nome, nome)== 0 && strcmp(aux->marca, marca)== 0 && (aux->preco == preco)){
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

    if(aux == NULL){
        printf("Ainda nao foi adicionado nenhum produto! \n");
    }
    else {
        while(aux != NULL){

            printf("Nome: %s\n", aux->nome);
            printf("Marca: %s\n", aux->marca);
            printf("Preco: %f\n", aux->preco);

            aux = aux->prox;
        }
    }
}
