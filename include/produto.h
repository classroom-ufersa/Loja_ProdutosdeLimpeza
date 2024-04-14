#ifndef PRODUTO_H
#define PRODUTO_H

#include "sistema.h"

typedef struct produto Produto;

Produto *adicionarProd(Produto *lista_prod, Produto produto);

Produto *criaProd(void);

Produto *removeProd(Produto *produto, char *nome, char *marca, float preco);

#endif //PRODUTO_H