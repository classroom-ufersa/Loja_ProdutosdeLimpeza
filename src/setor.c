 #include "../include/setor.h"

struct setor {
    char nome[50];
    char descricao[100];
    Produto *produto;
    struct setor* prox;
};


Setor *adicionaSetor(Setor *setor, char *nome, char *descricao){
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

Setor *novo_setor(){
    Setor *novo;

    char nome_digitado[50], descricao_digitada[50];

    do{
        printf("Digite o nome do setor:\n");
        scanf("%s", nome_digitado);
        getchar();
    }while(!contem_apenas_letras(nome_digitado) || strlen(nome_digitado) == 0);

    do{
        printf("Digite a descricao do setor: \n");
        scanf("%s\n", descricao_digitada);
        getchar();
    } while(!contem_apenas_letras(descricao_digitada) || strlen(descricao_digitada) == 0);

    strcpy(novo->nome, nome_digitado);
    strcpy(novo->descricao, descricao_digitada);
    novo->produto = NULL;
    novo->prox = NULL;

    return novo;
}

int verifica_nome_setor(Setor *listaSetor, char nome[50]){
    Setor *listaAux = listaSetor;
    
    while(listaAux != NULL){
        if(strcmp(listaAux->nome, nome) == 0){
            return 0;
        }
        listaAux = listaAux->prox;
    }
    return 1;
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

Setor *insere_produto(Setor *listaSetor){
    char nome[50];
    do{
        printf("Digite o nome do setor que deseja inserir o produto: \n");
        scanf("%s", nome);
        getchar();
    } while(contem_apenas_letras(nome));

    if(verifica_nome_setor(listaSetor, nome)== 0){ 
        Produto novoproduto = novo_produto();
        Setor * aux = encontra_setor(listaSetor, nome);
        aux->produto = adicionarProd(aux->produto, novoproduto);
        return listaSetor;

    } else{
        printf("Esse setor nao existe!\n");
        return listaSetor;
    }
}

Setor *removeSetor(Setor *setor, char *nome, char *descricao){
    Setor *ant = NULL;
    Setor *aux = setor;

    while(aux != NULL){
        if (strcmp(aux->nome, nome) == 0 &&
            strcmp(aux->descricao, descricao) == 0){
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

// Setor *LerSetores(Setor *setor){
//     FILE *arq = fopen("Setores.txt", "rt");
//     if(arq == NULL){
//         printf("Erro ao abrir o arquivo!\n");
//         exit(1);
//     }

//     Setor *aux = setor;
//     while(aux != NULL ){
//         fprintf(arq, "Setor: \n");
//         fprintf(arq, "Nome do setor: %s\n", aux->nome);
//         fprintf(arq, "Descricao do setor: %s\n", aux->descricao);
//         fprintf(arq, "Produto do setor: %s\n", aux->prod);
//         aux = aux->prox;
//     }
//     fclose(arq);
//     return setor;
// }