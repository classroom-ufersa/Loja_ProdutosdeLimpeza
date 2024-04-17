#ifndef SISTEMA_H
#define SISTEMA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "setor.h"

//Função para verificar se a lista de setores esta vazia
int VaziaSetor(ListaSetor **lista);

void SalvarDados(ListaSetor **lista, FILE *arquivo);

void NovoSetorArquivo(ListaSetor **lista, char *nome, char *descricao);

void NovoProdutoArquivo(ListaSetor **lista, char *nome, char *marca, float preco, int quantidade);

#endif //SISTEMA_H 