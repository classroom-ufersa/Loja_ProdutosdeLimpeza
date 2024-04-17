#include "setor.c"
#include "produto.c"
#include "sistema.c"

int main (void){

    //variavel de opcao
    char opcao;

    //variavel de tratativa
    int tratativa;

    //variavel que ira guardar os dados do arquivo
    FILE *setor;

    //inicalizando a lista de setores
    ListaSetor *listaSetor;
    CriaSetor(&listaSetor);

    //carregando os dados do arquivo para a lista de setores
    CarregarDados(&listaSetor, setor);

    //menu principal
    do{

        printf("-------------Menu Principal-------------\n");
        printf("1 - Adicionar Produto\n");
        printf("2 - Remover Produto\n");
        printf("3 - Editar Produto\n");
        printf("4 - Adicionar Setor\n");
        printf("5 - Remover Setor\n");
        printf("6 - Buscar Produtos\n");
        printf("7 - Listar Setores e Produtos\n");
        printf("8 - Sair\n");

        printf("Opcao: ");
        scanf("%c", &opcao);
        system("clear");

        switch (opcao) 
        {
            case '1':
            //verificando se a lista de setores esta vazia
            if(VaziaSetor(&listaSetor)){
                printf("Nenhum setor cadastrado, para adicionar um produto adicione um setor\n");
                break;
            }

            NovoProduto(&listaSetor);
            break;

            case '2':
            //verificando se a lista de setores esta vazia
            if(VaziaSetor(&listaSetor)){
                printf("Nenhum setor cadastrado, para remover um produto adicione um setor\n");
                break;
            }
            RemoveProduto(&listaSetor);
            break;

            case '3':
            //verificando se a lista de setores esta vazia
            if(VaziaSetor(&listaSetor)){
                printf("Nenhum setor cadastrado, para editar um produto adicione um setor\n");
                break;
            }
            EditarProduto(&listaSetor);
            break;

            case '4':
            NovoSetor(&listaSetor);
            break;

            case '5':
            //verificando se a lista de setores esta vazia
            if(VaziaSetor(&listaSetor)){
                printf("Nenhum setor cadastrado\n");
                break;
            }
            RemoveSetor(&listaSetor);
            break;

            case '6':
            //verificando se a lista de setores esta vazia
            if(VaziaSetor(&listaSetor)){
                printf("Nenhum setor cadastrado\n");
                break;
            }
            BuscaProduto(&listaSetor);
            break;

            case '7':
            //verificando se a lista de setores esta vazia
            if(VaziaSetor(&listaSetor)){
                printf("Nenhum setor cadastrado\n");
                break;
            }
            MostrarDados(&listaSetor);
            break;

            case '8':
            break;

            default:
                printf("Opcao invalida\n");
                break;
        }
    } while (opcao != '8');

    SalvarDados(&listaSetor, setor);
    printf("Progarma encerrado com sucesso!\n");
    return 0;
}