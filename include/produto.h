#include <stdio.h>  
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "setor.h"

//Definindo a struct do produto
typedef struct produto Produto;

//Definindo a lista encadeada do produto
typedef struct listaProduto ListaProduto;

//Funcao que cria a lista de produtos
void CriaProduto(ListaProduto **lista);

//Função que adiciona um novo produto na lista de setores
void NovoProduto(ListaSetor **lista);

//Função que remove um produto da lista de setores
void RemoveProduto(ListaSetor **lista);

//Função que edita um produto da lista de setores
void EditaProduto(ListaSetor **lista);

//Função para buscar um produto na lista de setores
void BuscaProduto(ListaSetor **lista);

//Função para mostrar os dados das listas de setores
void MostrarDados(ListaSetor **lista);

//Função que irar pegar os dados do arquivo e passar para a lista de setores
void PassarProdutoArquivo(ListaSetor **lista,char *NomeSetor, char *nomeproduto, float preco, char *marca, int quantidade);