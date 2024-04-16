#include "setor.c"

void menu(Setor *lista_para_setores, char *local_do_arquivo)
{
    char opcao[100];
    Setor setor_novo;
    Produto produto_novo;

    lista_para_setores = ler_do_arquivo(local_do_arquivo, lista_para_setores);

    while (1)
    {
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

        do
        {
            printf("Escolha uma opcao do menu: ");
            scanf("%s", opcao);
            getchar();
        } while (!numeroInteiro(opcao));

        if (strcmp(opcao, "1") == 0)
        {
            system("cls");
            sleep(1);
            produto_novo = novo_produto();
            lista_para_setores->produto = adicionarProd(lista_para_setores->produto, produto_novo);
            system("cls");
        }
        else if (strcmp(opcao, "2") == 0)
        {
            system("cls");
            lista_para_setores = remove_produto_do_setor(lista_para_setores);
            system("cls");
        }
        else if (strcmp(opcao, "3") == 0)
        {
            system("cls");
            printf("Digite o nome do produto que deseja editar\n");
            char nome_antigo[50];
            scanf(" %[^\n]", nome_antigo);
            lista_para_setores->produto = edita_prod(lista_para_setores->produto, nome_antigo);
            system("cls");
        }
        else if (strcmp(opcao, "4") == 0)
        {
            system("cls");
            setor_novo = novo_setor();
            lista_para_setores = adicionaSetor(lista_para_setores, setor_novo);
            system("cls");
        }
        else if (strcmp(opcao, "5") == 0)
        {
            // lista_para_setores = removeSetor(lista_para_setores);
            system("cls");
        }
        else if (strcmp(opcao, "6") == 0)
        {
            system("cls");
            listaSetor(lista_para_setores);
            system("cls");
        }
        else if (strcmp(opcao, "7"))
        {
/*             system("cls");
            Printf("Digite o nome do produto que deseja buscar: \n");
            char nome[50];
            scanf(" %[^\n]", nome);
            lista_para_setores->produto = busca_prod(lista_para_setores->produto);
            system("cls"); */
        }
        else if (strcmp(opcao, "8"))
        {
            system("cls");
            break;
            system("cls");
        }
    }
}

int main(void)
{
    char local_no_arquivo[50];
    strcpy(local_no_arquivo, "setores.txt");
    Setor *lista_para_setores = NULL;
    menu(lista_para_setores, local_no_arquivo);
    return 0;
}