#ifndef PRODUTO_H
#define PRODUTO_H

#include "sistema.h"

typedef struct produto Produto;

Produto *adicionarProd(Produto *produto, char *nome, char *marca, float preco);

Produto *criaProd(void);

Produto *removeProd(Produto *produto, char *nome, char marca, float preco);

Produto *editaProd(Produto *produto, char *nome, char *marca, float preco);

#endif //PRODUTO_H