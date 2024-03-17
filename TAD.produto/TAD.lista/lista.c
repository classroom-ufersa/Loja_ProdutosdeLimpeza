#include "lista.h"
#include "setor.h"

listaSetor *crialistaSetor(void){
    return NULL;
}

listaSetor *adiconarSetor(listaSetor *lista, Setor *setor){
    listaSetor *nova_lista = (listaSetor*)malloc(sizeof(listaSetor));

    if (nova_lista == NULL) {
    printf("Erro na alocação de memória");
    exit(1);
    }

     nova_lista->setor = setor;
    if (lista == NULL) {
    nova_lista->prox = nova_lista;
    nova_lista->ant = nova_lista;
    return nova_lista;
}

    nova_lista->prox = lista;
    nova_lista->ant = lista->ant;
    lista->ant->prox = nova_lista;
    lista->ant = nova_lista;

return lista;
};

