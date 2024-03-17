#ifndef LISTAENCADEADA_H
#define LISTAENCADEADA_H

typedef struct setor Setor;

typedef struct listaSetor{
    Setor*setor;
    struct listaSetor *prox;
    struct listaSetor *ant;
}listaSetor;

listaSetor *crialistaSetor(void){

}

listaSetor *adiconarSetor(listaSetor *lista, Setor *setor){

}

listaSetor *buscarSetor(listaSetor *lista, Setor *setor){

}

listaSetor * removerSetor(listaSetor *lista, Setor *setor){

}

int verificarlistaVazia(listaSetor *lista){

}

void imprimirlistaSetor(listaSetor *lista){

}

#endif