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

int verificaSetorVazio(Setor* setor){
    return (setor == NULL);
}

Setor *adicionaSetor(Setor* setor, char *nome, char *descricao, char *produto){
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
    Setor *atual = setor;

    while(atual != NULL){
        if (strcmp(atual->nome, nome) == 0 &&
            strcmp(atual->descricao, descricao) == 0 &&
            strcmp(atual->produto, produto) == 0){
                if(ant == NULL){
                    setor = atual->prox;
                }
                else{
                    ant->prox = atual->prox;
                }
                free(atual);
                return setor;
            }
        ant = atual;
        atual = atual->prox;
    }
    printf("Setor nao encontrado! \n");
        return setor;
}

Setor *liberaSetor(Setor *setor){
    if (setor != NULL) {
        free(setor);
    }
    return NULL;
}

Setor *EscreveSetores(Setor* setor){
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