 #include "setor.h"

typedef struct setor {
    char nome[50];
    char descricao[100];
    char produto[50];
    struct setor* prox;
} Setor;

Setor *criaSetor(char *nome, char *descricao, char *produto){
   Setor *novo_setor = (Setor*)malloc(sizeof(Setor));
        if(novo_setor == NULL){
            printf("Erro ao alocar a memoria!\n");
            exit(1);
        }
    strcpy(novo_setor->nome, nome);
    strcpy(novo_setor->descricao, descricao);
    strcpy(novo_setor->produto, produto);
    novo_setor->prox = NULL;
    return novo_setor;
}

int verificaSetorVazio(Setor* setor){
    if (setor == NULL){
        return 1;
    }
    else{
        return 0;
    }
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

Setor *buscaSetor(Setor *setor, char *nome, char *descricao, char *produto){
    Setor *atual = setor;
    while(atual != NULL){
        if(strcmp(atual->nome, nome)== 0 &&
           strcmp(atual->descricao, descricao) == 0 &&
           strcmp(atual->produto, produto) == 0) {
            return atual;
           } 
           atual = atual->prox;
    }
    return NULL;
}

Setor *retiraSetor(Setor *setor, char *nome, char *descricao, char *produto){
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
    
}

int main() {
    Setor *setor = NULL;
    Setor *novo_setor = criaSetor("Alimentos", "Setor de alimentos", "Comida");
    setor = adicionaSetor(setor, "Alimentos", "Setor de alimentos", "Comida");
    printf("%s\n", novo_setor->nome);
    printf("%s\n", novo_setor->descricao);
    printf("%s\n", novo_setor->produto);
    return 0;

}