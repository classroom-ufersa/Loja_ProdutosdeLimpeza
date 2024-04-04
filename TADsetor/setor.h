#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct setor Setor;

Setor *criaSetor(void);

int verificaSetorVazio(Setor* setor);

Setor *adicionaSetor(Setor* setor, char *nome, char *descricao, char *produto);

Setor *removeSetor(Setor *setor, char *nome, char *descricao, char *produto);

Setor *liberaSetor(Setor *setor);