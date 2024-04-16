#include "setor.c"

void menu(Setor *lista_para_setores, char *local_do_arquivo){
    char opcao [100];
    Setor setor_novo;
    Produto produto_novo;

    lista_para_setores = ler_no_arquivo(local_no_arquivo, lista_para_setores);

    while(1){
    printf("-------------MENU-------------\n");
    printf("[1] Adicionar produto \n");
    printf("[2] Remover produto \n");
    printf("[3] Editar produto \n");
    printf("[4] Adicionar novo setor\n");
    printf("[5] Remover setor existente\n");
    printf("[6] Listar setores existentes\n");
    printf("[7] Buscar produto \n");
    printf("[8] Sair \n");
    printf("--------------------------------\n");

    do{
        printf("Escolha uma opcao do menu: ");
        scanf("%s", opcao);
        getchar();
    }while(!numeroInteiro(opcao));

    if(strcmp(opcao, "1")== 0){
        system("cls");
        slee(1);
        produto_novo = novo_produto(lista_para_setores);
        lista_para_setores = adicionarProd(lista_para_setores, produto_novo);
        system("cls");
    } else if(strcmp(opcao, "2")== 0){
        system("cls");
        lista_para_setores = removeProd(lista_para_setores);
        system("cls");
    } else if(strcmp(opcao, "3")== 0){
        system("cls");
        lista_para_setores = edita_prod(lista_para_setores);
        system("cls");
    } else if(strcmp(opcao, "4")== 0){
        system("cls");
        lista_para_setores = adicionaSetor(lista_para_setores);
        system("cls");
    } else if(strcmp(opcao, "5")== 0){
        lista_para_setores = removeSetor(lista_para_setores);
        system("cls");
    } else if(strcmp(opcao, "6")== 0){
        system("cls");
        lista_para_setores = listarSetor(lista_para_setores);
        system("cls");
    } else if(strcmp(opcao, "7"))

    }  
}

int main(void){
    char local_no_arquivo;
    strcpy(local_no_arquivo, "");
    Setor *lista_para_setores;
    menu(lista_para_setores, local_no_arquivo);

    return 0;
}