#include "lista.h"
#include "setor.h"

listaSetor *crialistaSetor(void){
    return NULL;
}

int verificarlistaVazia(listaSetor *lista){
  if(lista == NULL){
    return 1;
  }
  else {
    return 0;
  }
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

listaSetor *buscarSetor(listaSetor *lista, Setor *setor){
    listaSetor *p;
    while(p != NULL && p->prox != lista && p->setor != setor){
      p = p->prox;
      if (p->setor == setor){
        return p;
      }
    }
    return NULL;
};

listaSetor *removerSetor(listaSetor *lista, Setor *setor, int id){
    listaSetor *atual = lista;

    while(atual != NULL && atual->setor->nome != setor->nome){
      atual = atual->prox;
    }

    if(atual == NULL){
      return lista;
    }
    else{
      lista = atual->prox;
    }

    if (atual->prox != NULL){
      atual->prox->ant = atual->ant;
    }
  free(atual);
  return lista;
}

void imprimirlistaSetor(listaSetor *lista){
  listaSetor *atual = lista;

  while(atual != NULL){
    printf("Setor: %d\n", atual->setor->nome);
    atual = atual->prox;
  }
}
