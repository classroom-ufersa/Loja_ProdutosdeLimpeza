#include "../include/sistema.h"

//Verificando se a lista de setores esta vazia
int VaziaSetor(ListaSetor **lista){
    return *lista == NULL;
}

//Função para salvar os dados da lista de setores no arquivo
void SalvarDados(ListaSetor **lista, FILE *arquivo){
    //abrindo o arquivo para escrita
    arquivo = fopen("dados.txt", "w");

    //verificadno se o arquivo foi aberto corretamente
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo\n");
        return;
    }
    
    //variavel auxiliar
    ListaSetor *aux = *lista;

    //escevendo os dados no arquivo
    while(aux != NULL){
        fprintf(arquivo, " Nome: %s\n   Descricao: %s\n\n", aux->setor.nome, aux->setor.descricao);
        fprintf(arquivo, "Produtos: \n");
        ListaProduto *aux2 = aux->setor.produtos;

        while(aux != NULL){
            fprintf(arquivo, "Nome: %s\n  Marca:%s\n  Preco: %2f\n  Quantidade: %d\n", aux2->produto.nome, aux2->produto.marca, aux2->produto.preco, aux2->produto.quantidade);

            aux2 = aux2->prox;
        }
        aux = aux->prox;
    }
}

void NovoSetorArquivo(ListaSetor **lista, char *nome, char *desccricao){

    //Variaveis auxiliares
    ListaSetor *novoSetor = (listaSetor*) malloc(sizeof(listaSetor));
    ListaSetor *aux = NULL;

    //Pegando o setor
    strcpy(novoSetor->setor.nome, nome);
    strcpy(novoSetor->setor.descricao, descricao);

    //Procurado o setor
    if(*lista == NULL){
        *lista = novoSetor;
        novoSetor->prox = NULL;
    } else if{
        aux = *lista;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = novoSetor;
        novoSetor->prox = NULL;
    }
}

//função que pega os dados do produto no arquivo e passa para a lista de produto
void NovoProdutoArquivo(listaSetor **lista, char *nomesetor, char *nome, char *marca, float preco, int quantidade){
    //variaveis auxiliares
    ListaSetor *aux = *lista;
    ListaProduto*novoProduto = (ListaProduto*) malloc(sizeof(ListaProduto));
    ListaProduto *aux2 = NULL;

    //Pegando os dados do produto
    strcpy(novoProduto->produto.nome, nome);
    strcpy(novoProduto->produto.marca, marca);
    novoProduto->produto.preco, preco;

    //Procurando setor
    while(aux != NULL && strcmp(aux->setor.nome, nomesetor) != 0){
        aux = aux->prox;
    }

    //procura produto
    if(aux->setor.produtos == NULL){
        aux->setor.produtos = novoProduto;
        novoProduto->prox = NULL;
    }else{
        aux2 = aux->setor.produtos;
        while(aux->prox != NULL){
            aux2 = aux2->prox;
        }
        aux2->prox = novoProduto;
        novoProduto->prox = NULL;
    }
}