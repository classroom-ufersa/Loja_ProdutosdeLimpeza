#include "../include/setor.h"

struct setor {
    char nome[50];
    char descricao[100];
    Produto *produto;
    struct setor* prox;
};


Setor *adicionaSetor(Setor *setor, Setor setor_preenchido){
    Setor *novo_setor = (Setor*)malloc(sizeof(Setor));

    if(novo_setor == NULL){
        printf("Erro na alocacao de memoria!\n");
        exit(1);
    }

    strcpy(novo_setor->nome, setor_preenchido.nome);
    strcpy(novo_setor->descricao, setor_preenchido.descricao);
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

Setor novo_setor(){
    Setor novo;

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

    strcpy(novo.nome, nome_digitado);
    strcpy(novo.descricao, descricao_digitada);
    novo.produto = NULL;
    novo.prox = NULL;

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
    Produto produto = novo_produto();
    do{
        printf("Digite o nome do setor que deseja inseir o produto: \n");
        scanf("%s", nome);
        getchar();
    } while(contem_apenas_letras(nome));

    if(verifica_nome_setor(listaSetor, nome)== 0){
        Setor *aux = encontra_setor(listaSetor, nome);
        aux->produto = adicionarProd(aux->produto, produto);
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

void EscreveSetores(Setor *lista_para_setores, char *local_no_arq){
    FILE *arq = fopen(local_no_arq, "wt");
    if(arq == NULL){
        perror("Erro ao abrir o arquivo!\n");
        exit(1);
    }
    Setor *aux = lista_para_setores;

    while(aux != NULL){
        fprintf(arq, "Setor:\t%s\t%s", aux->nome, aux->descricao);
        Produto *produto = aux->produto;
        while(produto != NULL){
            fprintf(arq, "Produtos:\t%s\t%s\t%s\t%d", produto->nome, produto->marca, produto->preco, produto->qntEstoque);
            produto = produto->prox;
        }
        aux = aux->prox;
    }
    fclose(arq);
}

Setor *ler_do_arquivo(char *local_do_arquivo, Setor *lista_para_setores){
    FILE *arq = fopen(local_do_arquivo, "rt");
    if(arq == NULL){
        perror("erro aoa abrir o arquivo");
        exit(1);
    }
    char linha[200];
    Setor setor;
    Produto produto;

    while(fgets(linha, 200, arq) != NULL){
        Setor *aux;
        if (strstr(linha, "Setor") != NULL){
            sscanf(linha, "\t%s\t%s\t", setor.nome, setor.descricao);
            setor.prox = NULL;
            setor.produto = NULL;
            lista_para_setores = adicionaSetor(lista_para_setores, setor);
            aux = encontra_setor(lista_para_setores, setor.nome);

        }
        else{
            sscanf(linha, "Produtos: \t%s\t%s\t%s\t%d\t", produto.nome, produto.marca, produto.preco, &produto.qntEstoque);
            aux->produto = adicionarProd(aux->produto, produto);
        } 
        
    } 
    fclose(arq);
    return lista_para_setores;
}

Setor *remove_produto_do_setor(Setor* lista){
    char setor[50];
    char prod[50];
    char marca[50];
    printf("Insira o nome do setor que esta o produto: ");
    scanf(" %[^\n]", setor);
    printf("Insira o nome do produto: ");
    scanf(" %[^\n]", prod);
    Setor * aux = encontra_setor(lista, setor);
    aux->produto = removeProd(aux->produto, prod, marca);
    return lista;
}