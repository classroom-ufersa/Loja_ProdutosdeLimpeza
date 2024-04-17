#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "setor.h"

//Função para verificar se a lista de setores está vazia
int VaziaSetor(ListaSetor **lista);

//Função criada para passar os dados da lista de setores para um arquivo
void SalvarDados(ListaSetor **lista, FILE *arquivo);

//Função criada para carregar os dados do arquivo para a lista de setores
void CarregarDados(ListaSetor **lista, FILE *arquivo);

//Função para pegar os dados do setor no arquivo e passar para a lista de setores
void NovoSetorArquivo(ListaSetor **lista, char *nome, char *descricao);

//Função para pegar os dados do produto no arquivo e passar para a lista de produtos
void NovoProdutoArquivo(ListaSetor **lista, char *nome, char *marca, float preco, int quantidade);