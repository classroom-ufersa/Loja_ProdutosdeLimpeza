#include "../include/produto.h"
#include "../include/setor.h"

struct produto {
    char nome[50];
    char marca[50];
    float preco[10];
    int qntEstoque;
};

struct listaProduto{
    Produto *produto;
    struct listaProduto *prox;
};

void criaProduto(ListaProduto **lista){
    *lista = NULL;
}

void NovoProduto(ListaSetor **lista){
    //variaveis auxiliares
    char nomeSetor[50];
    
}

Produto novo_produto(){
    Produto produto;
    char nome[50], marca[50], preco [10];
    int qntEstoque;

    do {
        printf("Digite o nome do produto: \n");
        scanf(" %[^\n]", nome);
    } while(!contem_apenas_letras(nome) || strlen(nome) > 50);

    do {
        printf("Digite a marca do produto:\n");
        scanf(" %[^\n]", marca);
    } while(!contem_apenas_letras(marca) || strlen(marca) > 50);

    do {
        printf("Digite o preco do produto: \n");
        scanf(" %[^\n]", preco);
        fflush(stdin);
    } while(!numero_decimal(preco) || strlen(preco) > 10);

    do {
        printf("Digite a quantidade em estoque do produto: \n");
        scanf("%d", &qntEstoque);
        fflush(stdin);
    } while(qntEstoque < 0);

    strcpy(produto.nome, nome);
    strcpy(produto.marca, marca);
    strcpy(produto.preco, preco);
    produto.qntEstoque = qntEstoque;

    produto.prox = NULL;
    return produto;
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
            if(strcmp(listaAux->nome, nome_antigo) != 0){
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
                char nome_digitado[50], marca_digitada[50], preco_digitado[10];
                int qntEstoque_digitado;

                do{
                    printf("Digite o nome editado (por favor digite apenas letras)\n");
                    scanf("%49s", nome_digitado);
                    getchar();
                } while (!contem_apenas_letras(nome_digitado));

                do{
                    printf("Digite a marca do produto:\n");
                    scanf("%49s", marca_digitada);
                    getchar();
                } while (!contem_apenas_letras(marca_digitada));

                do{
                    printf("Digite o preco do produto:\n");
                    scanf("%9s", preco_digitado);
                } while (!numero_decimal(preco_digitado));

                do {
                    printf("Quantidade em estoque: \n");
                    scanf("%d\n", &qntEstoque_digitado);
                    getchar();
                } while (qntEstoque_digitado < 0);

                strcpy(aux->nome, nome_digitado);
                strcpy(aux->marca, marca_digitada);
                strcpy(aux->preco, preco_digitado);
                      aux->qntEstoque = qntEstoque_digitado;
                      return lista_prod;
            }
        }
        printf("Esse produto nao existe!\n");
    }
    return lista_prod;
}

void busca_prod(Produto *lista_prod, char *nome){
    upper_string(nome);

    Produto *aux = lista_prod;
    int encontrado = 0;

    while(aux != NULL){
        char *nome_prod = aux->nome;
        upper_string(nome_prod);

        if(strstr(nome_prod, nome) != NULL){
            printf("Produto encontrado: \n");
            formata_nome(nome);
            formata_nome(nome_prod);
            printf("Nome do produto: %s\n", aux->nome);
            printf("Marca ddo produto: %s\n", aux->marca);
            printf("Preco do produto: %s\n", aux->preco);
            printf("Quantidade em estoque: %d\n", aux->qntEstoque);

        }
        formata_nome(nome_prod);
        aux = aux->prox;
    }
    formata_nome(nome);

    if(!encontrado){
        printf("Produto nao encontrado!\n");
    }
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
            printf("Preco: %s\n", aux->preco);
            printf("Quantidade em estoque: %d\n",aux->qntEstoque);

            aux = aux->prox;
        }
    }
}