#include "setor.c"

void cabecalho();

int main(){
    char op[100];
    Produto *produto = NULL;
    char nome[50], marca[50];
    float preco;
    
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

    printf("Digite a opcao desejada: ");
        scanf(" %s", &op);
        getchar();

    if(strcmp(op, "1")== 0){
        sleep(1);
            
    }
    }
}  
