 #include "../include/setor.h"

struct setor {
    char nome[50];
    char descricao[100];
    char produto[50];
    struct setor* prox;
};

Setor *criaSetor(void){
    return NULL;
}

int verificaSetorVazio(Setor *setor){
    return (setor == NULL);
}

Setor *adicionaSetor(Setor *setor, char *nome, char *descricao, char *produto){
    Setor *novo_setor = (Setor*)malloc(sizeof(Setor));

    if(novo_setor == NULL){
        printf("Erro na alocacao de memoria!\n");
        exit(1);
    }

    strcpy(novo_setor->nome, nome);
    strcpy(novo_setor->descricao, descricao);
    strcpy(novo_setor->produto, produto);
    if (setor == NULL){
        novo_setor->prox = novo_setor;
    }
    return novo_setor;
}

Setor *removeSetor(Setor *setor, char *nome, char *descricao, char *produto){
    Setor *ant = NULL;
    Setor *aux = setor;

    while(aux != NULL){
        if (strcmp(aux->nome, nome) == 0 &&
            strcmp(aux->descricao, descricao) == 0 &&
            strcmp(aux->produto, produto) == 0){
                if(ant == NULL){
                    setor = aux->prox;
                }
                else{
                    ant->prox = aux->prox;
                }
                free(aux);
                return setor;
            }
        ant = aux;
        aux = aux->prox;
    }
    printf("Setor nao encontrado! \n");
        return setor;
}

void imprimeSetor(Setor *setor){
    if(setor == NULL){
        printf("Setor vazio");
        return;
    }

     Setor *aux = setor;
     while(aux != NULL){
        printf("Nome do setor: %s\n", aux->nome);
        printf("Descricao do setor: %s\n", aux->descricao);
        printf("Produto do setor: %s\n", aux->produto);

        aux = aux->prox;
     }
}

Setor *liberaSetor(Setor *setor){
    if (setor != NULL) {
        free(setor);
    }
    return NULL;
}

Setor *EscreveSetores(Setor *setor){
    FILE *arq = fopen("Setores.txt", "wt");
    if(arq == NULL){
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }
    Setor *aux = setor;

    while(aux != NULL){
        fprintf(arq, "Setor: \n");
        fprintf(arq, "Nome do setor: %s\n", aux->nome);
        fprintf(arq, "Descricao do setor: %s\n", aux->descricao);
        fprintf(arq, "Produto do setor: %s\n", aux->produto);
        aux = aux->prox;
    }
    fclose(arq);
    return setor;
}

Setor *LerSetores(Setor *setor){
    FILE *arq = fopen("Setores.txt", "rt");
    if(arq == NULL){
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }

    Setor *aux = setor;
    while(aux != NULL ){
        fprintf(arq, "Setor: \n");
        fprintf(arq, "Nome do setor: %s\n", aux->nome);
        fprintf(arq, "Descricao do setor: %s\n", aux->descricao);
        fprintf(arq, "Produto do setor: %s\n", aux->produto);
        aux = aux->prox;
    }
    fclose(arq);
    return setor;
}