#include "C:\Users\marii\OneDrive\Área de Trabalho\Loja_ProdutosdeLimpeza\include\sistema.h"

//verificando se a lista de setores está vazia
int VaziaSetor(ListaSetor **lista){
    return *lista == NULL;
}

//Função para salvar os dados da lista de setores no arquivo
void SalvarDados(ListaSetor **lista, FILE *arquivo){
    //Abrindo o arquivo em modo de escrita
    arquivo = fopen("dados.txt", "w");

    //verificando se o arquivo foi aberto corretamente
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo\n");
        return;
    }

    //variavel auxiliar
    ListaSetor *aux = *lista;

    //escrevendo os dados no arquivo
    while(aux != NULL){
        fprintf(arquivo, "Nome %s   Descricao %s\n\n", aux->setor.nome, aux->setor.descricao);                                                                                                          
        fprintf(arquivo, "Produtos\n");
        ListaProduto *aux2 = aux->setor.produtos;

        while(aux2 != NULL){
            fprintf(arquivo, "Nome %s   Marca %s    Preco %f    Quantidade %d\n", aux2->produto.nome, aux2->produto.marca, aux2->produto.preco, aux2->produto.quantidade);

            aux2 = aux2->prox;
        }

        aux = aux->prox;
    }
}

//Função para carregar os dados do arquivo para a lista de setores
void CarregarDados(ListaSetor **lista, FILE *arquivo){
   //Variaves auxiliares
    char linha[200];
    char NomeSetor[50];
    char DescricaoSetor[100];
    char NomeProduto[50];
    char MarcaProduto[100];
    float PrecoProduto;
    int QuantidadeProduto;
    
    //Abrindo o arquivo em modo de leitura
    arquivo = fopen("dados.txt", "r");

    //verificando se o arquivo foi aberto corretamente
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo\n");
        return;
    }

    //lendo os dados do arquivo
    while(fgets(linha, 200, arquivo) != NULL){
        if(strstr(linha, "Nome") != NULL){
            sscanf(linha, "Nome %s   Descricao %s", NomeSetor, DescricaoSetor);
            NovoSetorArquivo(lista, NomeSetor, DescricaoSetor);
        }else if(strstr(linha, "Produtos") != NULL){
            while(fgets(linha, 200, arquivo) != NULL && strstr(linha, "Nome") == NULL){
                sscanf(linha, "NomeProduto %s   Marca %s    Preco %f    Quantidade %d", NomeProduto, MarcaProduto, &PrecoProduto, &QuantidadeProduto);
                NovoProdutoArquivo(lista, NomeSetor, NomeProduto, MarcaProduto, PrecoProduto, QuantidadeProduto);
            }
        }
    }
}

void NovoSetorArquivo(ListaSetor **lista, char *nome, char *descricao){
    //Variaveis auxiliares
    ListaSetor *novoSetor = (ListaSetor*) malloc(sizeof(ListaSetor));
    ListaSetor *aux = NULL;

    //Pegando o setor
    strcpy(novoSetor->setor.nome, nome);
    strcpy(novoSetor->setor.descricao, descricao);

    //Procurando o setor
    if(*lista == NULL){
        *lista = novoSetor;
        novoSetor->prox = NULL;
    }else{
        aux = *lista;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = novoSetor;
        novoSetor->prox = NULL;
    }
}

//Função que pega os dados do produto no arquivo e passa para a lista de produtos
void NovoProdutoArquivo(ListaSetor **lista, char *nomesetor, char *nome, char *marca, float preco, int quantidade){
    //Variaveis auxiliares
    ListaSetor *aux = *lista;
    ListaProduto *novoProduto = (ListaProduto*) malloc(sizeof(ListaProduto));
    ListaProduto *aux2 = NULL;

    //Pegando o produto
    strcpy(novoProduto->produto.nome, nome);
    strcpy(novoProduto->produto.marca, marca);
    novoProduto->produto.preco = preco;

    //Procurando o setor
    while(aux != NULL && strcmp(aux->setor.nome, nomesetor) != 0){
        aux = aux->prox;
    }

    //Procurando o produto
    if(aux->setor.produtos == NULL){
        aux->setor.produtos = novoProduto;
        novoProduto->prox = NULL;
    }else{
        aux2 = aux->setor.produtos;
        while(aux2->prox != NULL){
            aux2 = aux2->prox;
        }
        aux2->prox = novoProduto;
        novoProduto->prox = NULL;
    }
}