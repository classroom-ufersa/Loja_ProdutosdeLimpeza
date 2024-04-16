#ifndef SETOR_H
#define SETOR_H

#include "produto.h"

typedef struct setor Setor;

Setor *adicionaSetor(Setor *setor, char *nome, char *descricao);

Setor *removeSetor(Setor *setor, char *nome, char *descricao);

void listaSetor(Setor *setor);

Setor *liberaSetor(Setor *setor);

Setor *EscreveSetores(Setor *setor);

Setor *LerSetores(Setor *setor);

#endif //SETOR_H