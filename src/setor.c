 #include "../include/setor.h"

struct setor {
    char nome[50];
    char descricao[100];
    Produto *produto;
    struct setor* prox;
};


Setor *adicionaSetor(Setor *setor, char *nome, char *descricao, char *prod){
    Setor *novo_setor = (Setor*)malloc(sizeof(Setor));

    if(novo_setor == NULL){
        printf("Erro na alocacao de memoria!\n");
        exit(1);
    }

    strcpy(novo_setor->nome, nome);
    strcpy(novo_setor->descricao, descricao);
    novo_setor->produto = NULL;
    novo_setor->prox = NULL;

    if (setor == NULL){
        return novo_setor;
    }

    Setor *aux = setor;
    while(aux->prox != NULL){
        aux = aux->prox;
    }
    return setor;
}

Setor *novo_setor(Setor *listaSetor){
    
}

Setor *encontra_setor(Setor *lista_setor, char nome[50]){
    Setor *aux_setor;

    for(aux_setor = lista_setor; aux_setor != NULL ; aux_setor = aux_setor->prox){
        if(strcmp(aux_setor->nome, nome)== 0){
            return aux_setor;
        }
    }
    return NULL;
}

Setor *insere_produto(Setor *lista_setor){
    char nome[50];
    do{
        printf("Digite o nome do setor que deseja inserir o produto: \n");
        scanf("%s", nome);
        getchar();
    } while(contem_apenas_letras(nome));

    if(verifica_nome_prod(lista_prod, nome)== 0){ 
        Setor * aux = encontra_setor(lista_setor, nome);
        aux->produto = adicionarProd(aux->produto, produto);
        return lista_prod;

    } else{
        printf("Esse setor nao existe!\n");
        return lista_prod;
    }
}

Setor *removeSetor(Setor *setor, char *nome, char *descricao, char *prod){
    Setor *ant = NULL;
    Setor *aux = setor;

    while(aux != NULL){
        if (strcmp(aux->nome, nome) == 0 &&
            strcmp(aux->descricao, descricao) == 0 &&
            strcmp(aux->produto, prod) == 0){
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

void listaSetor(Setor *setor){
    if(setor == NULL){
        printf("Setor vazio");
        return;
    }

     Setor *aux = setor;
     while(aux != NULL){
        printf("Nome do setor: %s\n", aux->nome);
        printf("Descricao do setor: %s\n", aux->descricao);
        printf("Produto do setor: %s\n", aux->prod);

        aux = aux->prox;
     }
}

Setor *liberaSetor(Setor *setor){
    if (setor != NULL) {
        free(setor);
    }
    return NULL;
}

// void EscreveSetores(Setor *setor, char *local_no_arq){
//     FILE *arq = fopen(local_no_arq, "wt");
//     if(arq == NULL){
//         perror("Erro ao abrir o arquivo!\n");
//         exit(1);
//     }
//     Setor *aux = setor;

//     while(aux != NULL){
//         fprintf(arq, "Setor: \n");
//         fprintf(arq, "Nome do setor: %s\n", aux->nome);
//         fprintf(arq, "Descricao do setor: %s\n", aux->descricao);
//         fprintf(arq, "Produto do setor: %s\n", aux->prod);
//         Produto *p = aux->prod;
//     }
//     fclose(arq);
// }

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
        fprintf(arq, "Produto do setor: %s\n", aux->prod);
        aux = aux->prox;
    }
    fclose(arq);
    return setor;
}