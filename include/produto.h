#ifndef PRODUTO_H
#define PRODUTO_H

#include <stdio.h>  
#include <stdlib.h>
#include <string.h>
#include "setor.h"

typedef struct produto Produto;

typedef struct listaProduto listaProduto;

Produto *adicionarProd(Produto *lista_prod, Produto produto);

Produto novo_produto();

int verifica_nome_prod(Produto *lista_prod, char nome[50]);

int verifica_edicao_nome_prod(Produto *lista_prod, char nome_editado[50], char nome_antigo[50]);

Produto *edita_prod(Produto *lista_prod, char *nome_antigo);

Produto *removeProd(Produto *produto, char *nome, char *marca);

void busca_prod(Produto *lista_prod, char *nome);

void lista_prod(Produto *lista_prod);

#endif //PRODUTO_H