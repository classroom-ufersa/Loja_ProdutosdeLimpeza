#ifndef LISTAENCADEADA_H
#define LISTAENCADEADA_H

typedef struct setor Setor;
    
typedef struct listaSetor{
    Setor*setor;
    struct listaSetor *prox;
    struct listaSetor *ant;
}listaSetor;

int verificarlistaVazia(listaSetor *lista){
}
listaSetor *crialistaSetor(void){
}
listaSetor *adiconarSetor(listaSetor *lista, Setor *setor){
}
listaSetor *buscarSetor(listaSetor *lista, Setor *setor){
}
listaSetor * removerSetor(listaSetor *lista, Setor *setor){
}
void imprimirlistaSetor(listaSetor *lista){
}
#endif