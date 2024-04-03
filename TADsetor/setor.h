#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct setor *Setor;

Setor *criaSetor(char *nome, char *descricao, char *produto);

int verificaSetorVazio(Setor* setor);

Setor *adicionaSetor(Setor* setor, char *nome, char *descricao, char *produto);

Setor *buscaSetor(Setor *setor, char *nome, char *descricao, char *produto);