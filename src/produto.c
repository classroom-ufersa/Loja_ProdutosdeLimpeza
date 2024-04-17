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
    verificanome(nomeSetor);
    passarMaiuscula(nomeSetor);
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
    verificanome(nomeProduto);
    passarMaiuscula(nomeProduto);

    printf("Digite a marca do produto: ");
    scanf(" %[^\n]", marca);
    verificanome(marca);
    passarMaiuscula(marca);

    printf("Digite o preco do produto: ");
    scanf("%f", &preco);
    VerificaFloat(&preco);

    printf("Digite a quantidade do produto: ");
    scanf("%d", &quantidade);
    VerificaInt(&quantidade);

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
    verificanome(nomeSetor);
    passarMaiuscula(nomeSetor);

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
    verificanome(nomeProduto);
    passarMaiuscula(nomeProduto);

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

void EditaProduto(ListaSetor ** lista){
    //variaves auxiliares
    char nomeSetor[50];
    char nomeProduto[50];
    char marca[100];
    float preco;
    int quantidade;

    //lendo o nome do setor
    printf("Digite o nome do setor: ");
    scanf(" %[^\n]", nomeSetor);
    verificanome(nomeSetor);
    passarMaiuscula(nomeSetor);

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
    verificanome(nomeProduto);
    passarMaiuscula(nomeProduto);

    //buscando o produto
    ListaProduto *auxProduto = aux->setor.produtos;

    while(auxProduto != NULL && strcmp(auxProduto->produto.nome, nomeProduto) != 0){
        auxProduto = auxProduto->prox;
    }

    //verificando se o produto existe
    if(auxProduto == NULL){
        printf("Produto nao encontrado\n");
        return;
    }

    //perguntando ao usuario oque ele deseja editar
    int opcao;

    do{
        printf("1 - Editar nome\n");
        printf("2 - Editar marca\n");
        printf("3 - Editar preco\n");
        printf("4 - Editar quantidade\n");
        printf("5 - Sair\n");
        printf("Digite a opcao desejada: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Digite o novo nome: ");
            scanf(" %[^\n]", auxProduto->produto.nome);
            verificanome(auxProduto->produto.nome);
            passarMaiuscula(auxProduto->produto.nome);
            break;
        case 2:
            printf("Digite a nova marca: ");
            scanf(" %[^\n]", auxProduto->produto.marca);
            verificanome(auxProduto->produto.marca);
            passarMaiuscula(auxProduto->produto.marca);
            break;
        case 3:
            printf("Digite o novo preco: ");
            scanf("%f", &auxProduto->produto.preco);
            VerificaFloat(&auxProduto->produto.preco);

            break;
        case 4:
            printf("Digite a nova quantidade: ");
            scanf("%d", &auxProduto->produto.quantidade);
            VerificaInt(&auxProduto->produto.quantidade);

            break;
        case 5:
            break;
        default:
            printf("Opcao invalida\n");
            break;
        }   
    }while(opcao != 5);    

    printf("Produto editado com sucesso\n");

}

void BuscaProduto(ListaSetor **lista){
    //variaveis auxiliares
    char nomeSetor[50];
    char nomeProduto[50];

    //lendo o nome do setor
    printf("Digite o nome do setor: ");
    scanf(" %[^\n]", nomeSetor);
    verificanome(nomeSetor);
    passarMaiuscula(nomeSetor);

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
    verificanome(nomeProduto);
    passarMaiuscula(nomeProduto);

    //buscando o produto
    ListaProduto *auxProduto = aux->setor.produtos;

    while(auxProduto != NULL && strcmp(auxProduto->produto.nome, nomeProduto) != 0){
        auxProduto = auxProduto->prox;
    }

    //verificando se o produto existe
    if(auxProduto == NULL){
        printf("Produto nao encontrado\n");
        return;
    }

    //exibindo os dados do produto
    printf("Produto encontrado\n");
    printf("Nome: %s\n", auxProduto->produto.nome);
    printf("marca: %s\n", auxProduto->produto.marca);
    printf("Preco: %.2f\n", auxProduto->produto.preco);
    printf("Quantidade: %d\n", auxProduto->produto.quantidade);
    printf("\n");
}

void MostrarDados(ListaSetor **lista){
    //variaveis auxiliares
    ListaSetor *aux = *lista;
    ListaProduto *auxProduto = NULL;

    //exibindo os dados
    while(aux != NULL){
        printf("Nome: %s\n", aux->setor.nome);
        printf("Descricao: %s\n\n", aux->setor.descricao);
        printf("Produtos\n");

        auxProduto = aux->setor.produtos;

        while(auxProduto != NULL){
            printf("Nome: %s\n", auxProduto->produto.nome);
            printf("Marca: %s\n", auxProduto->produto.marca);
            printf("Preco: %.2f\n", auxProduto->produto.preco);
            printf("Quantidade: %d\n", auxProduto->produto.quantidade);
            printf("\n");

            auxProduto = auxProduto->prox;
        }

        aux = aux->prox;

    }
}

//Função que irar pegar os dados do arquivo e passar para a lista de setores
void PassarProdutoArquivo(ListaSetor **lista,char *NomeSetor, char *nomeproduto, float preco, char *marca, int quantidade){
    //variaveis auxiliares
    ListaSetor *aux = *lista;
    ListaProduto *novoProduto = (ListaProduto *)malloc(sizeof(ListaProduto));
    ListaProduto *auxProduto = NULL;

    //buscando o setor
    while(aux != NULL && strcmp(aux->setor.nome, NomeSetor) != 0){
        aux = aux->prox;
    }

    //verificando se o setor existe
    if(aux == NULL){
        printf("Setor nao encontrado\n");
        return;
    }

    //criando o novo produto
    strcpy(novoProduto->produto.nome, nomeproduto);
    strcpy(novoProduto->produto.marca, marca);
    novoProduto->produto.preco = preco;
    novoProduto->produto.quantidade = quantidade;

    //inserindo o produto na lista de produtos do setor
    novoProduto->prox = aux->setor.produtos;
    aux->setor.produtos = novoProduto;
}