#ifndef SETOR_H
#define SETOR_H

#include "produto.h"

typedef struct setor Setor;

Setor *adicionaSetor(Setor *setor, char *nome, char *descricao);

int verifica_nome_setor(Setor *listaSetor, char nome[50]);

Setor *encontra_setor(Setor *lista_setor, char nome[50]);

Setor *insere_produto(Setor *listaSetor);

Setor *removeSetor(Setor *setor, char *nome, char *descricao);

void listaSetor(Setor *setor);

Setor *liberaSetor(Setor *setor);

void EscreveSetores(Setor *lista_para_setores, char *local_no_arq);

#endif //SETOR_H