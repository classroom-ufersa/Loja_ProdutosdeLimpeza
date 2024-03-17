#ifndef SECAO_H
#define SECAO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

struct setor{
    char nome[50];
    char descricao[100];
    char produto[50]
};

typedef struct setor Setor;

listaSetor *criarSetor(char nome[50], char descricao[50], char produto[50], listaSetor *lista);

#endif
