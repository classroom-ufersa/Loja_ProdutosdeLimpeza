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

void listaSetor(Setor *setor){
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


// int main() {
//     Setor *setor = criaSetor();
//     char nome[50];
//     char descricao[100];
//     char produto[50];
//     int choice;

//     do {
//         printf("\n1. Adicionar setor\n");
//         printf("2. Remover setor\n");
//         printf("3. Imprimir setores\n");
//         printf("4. Escrever setores em arquivo\n");
//         printf("5. Ler setores de arquivo\n");
//         printf("6. Sair\n");
//         printf("Escolha uma opcao: ");
//         scanf("%d", &choice);

//         switch(choice) {
//             case 1:
//                 printf("Digite o nome do setor: ");
//                 scanf("%s", nome);
//                 printf("Digite a descricao do setor: ");
//                 scanf("%s", descricao);
//                 printf("Digite o produto do setor: ");
//                 scanf("%s", produto);
//                 setor = adicionaSetor(setor, nome, descricao, produto);
//                 break;
//             case 2:
//                 printf("Digite o nome do setor a ser removido: ");
//                 scanf("%s", nome);
//                 printf("Digite a descricao do setor a ser removido: ");
//                 scanf("%s", descricao);
//                 printf("Digite o produto do setor a ser removido: ");
//                 scanf("%s", produto);
//                 setor = removeSetor(setor, nome, descricao, produto);
//                 break;
//             case 3:
//                 listaSetor(setor);
//                 break;
//             case 4:
//                 setor = EscreveSetores(setor);
//                 break;
//             case 5:
//                 setor = LerSetores(setor);
//                 break;
//             case 6:
//                 setor = liberaSetor(setor);
//                 printf("Saindo do programa...\n");
//                 break;
//             default:
//                 printf("Opcao invalida!\n");
//         }
//     } while(choice != 6);

//     return 0;
// }