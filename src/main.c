#include "setor.c"
#include "produto.c"
#include "sistema.c"

int main(void)
{   

    //Variavel de opcao
    char opcao;

    //Variavel de tratativa
    int tratativa;

    //Variavel que irar guardar os dados do arquivo
    FILE *setor;

    //Inicializando a lista de setores
    ListaSetor *listaSetor;
    CriaSetor(&listaSetor);

    //Carregando os dados do arquivo

    int Quantidade;
    char NomeSetor[200];
    char NomeProduto[200];
    char Marca[200];
    char linha[200];
    char Descricao[200];
    float Preco;

    //abrindo o arquivo
    setor = fopen("dados.txt", "r");

    //verificando se o arquivo foi aberto corretamente
    if (setor == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }

    //pegando os dados do arquivo
    while (fgets(linha, 200, setor) != NULL)
    {
        //pegando o nome do setor
        if(strstr(linha, "Nome do setor: ") != NULL){
           sscanf(linha, "Nome do setor: %s   Descricao: %s\n", NomeSetor, Descricao);
           ListaSetor *NovoSetor = (ListaSetor *)malloc(sizeof(ListaSetor));

            strcpy(NovoSetor->setor.nome, NomeSetor);
            strcpy(NovoSetor->setor.descricao, Descricao);

            NovoSetor->prox = NULL;

            if(listaSetor == NULL){
                listaSetor = NovoSetor;
            }
            else{
                ListaSetor *aux = listaSetor;
                while(aux->prox != NULL){
                    aux = aux->prox;
                }
                aux->prox = NovoSetor;
            }

        }

        else if(strstr(linha, "Produtos: ")){
            while(fgets(linha, 200, setor) != NULL)
            {
                if(strstr(linha, "Nome: ") != NULL){
                    sscanf(linha, "Nome: %s   Marca: %s    Preco: %f    Quantidade: %d\n", NomeProduto, Marca, &Preco, &Quantidade);
                    PassarProdutoArquivo(&listaSetor, NomeSetor, NomeProduto, Preco, Marca, Quantidade);
                }
                else{
                    break;
                }
            }
        }
    }

    

    //Menu principal
    do
    {
            
        printf("Menu Principal\n");
        printf("1 - Adicionar Prpduto\n");
        printf("2 - Remover produto\n");
        printf("3 - Editar produto\n");   
        printf("4 - Adicionar setor\n");
        printf("5 - Remover setor\n");
        printf("6 - Buscar produtos\n");
        printf("7 - Listar setores e seus produtos\n");
        printf("8 - Sair\n");
    
        printf("Opcao: ");
        scanf(" %c", &opcao);
        system("cls");
        opcao = Opcao(opcao);
        switch (opcao)
        {
            case '1':
                //Verificando se a lista de setores está vazia
                if(VaziaSetor(&listaSetor)){
                    printf("Nenhum setor cadastrado\n");
                    break;
                }
                system ("cls");
                NovoProduto(&listaSetor);
                system ("cls");
                break;

            case '2':
                //Verificando se a lista de setores está vazia
                if(VaziaSetor(&listaSetor)){
                    printf("Nenhum setor cadastrado\n");
                    break;
                }
                system ("cls");
                RemoveProduto(&listaSetor);
                system ("cls");
                break;

            case '3':
                //Verificando se a lista de setores está vazia
                if(VaziaSetor(&listaSetor)){
                    printf("Nenhum setor cadastrado\n");
                    break;
                }
                system ("cls");
                EditaProduto(&listaSetor);
                system ("cls");
                break;

            case '4':
                NovoSetor(&listaSetor);
                system ("cls");
                break;               

            case '5':
                //Verificando se a lista de setores está vazia
                if(VaziaSetor(&listaSetor)){
                    printf("Nenhum setor cadastrado\n");
                    break;
                }
                system ("cls");
                RemoveSetor(&listaSetor);
                system ("cls");
                break;

            case '6':
                //Verificando se a lista de setores está vazia
                if(VaziaSetor(&listaSetor)){
                    printf("Nenhum setor cadastrado\n");
                    break;
                }
                system ("cls");
                BuscaProduto(&listaSetor);
                system ("cls");
                break;

            case '7':
                //Verificando se a lista de setores está vazia
                if(VaziaSetor(&listaSetor)){
                    printf("Nenhum setor cadastrado\n");
                    break;
                }
                system ("cls");
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
    printf("Programa encerrado com sucesso!\n");
    return 0;
}