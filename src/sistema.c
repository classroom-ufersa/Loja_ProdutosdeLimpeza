#include "C:\Users\marii\OneDrive\Área de Trabalho\Loja_ProdutosdeLimpeza\include\sistema.h"

//verificando se a lista de setores está vazia
int VaziaSetor(ListaSetor **lista){
    return *lista == NULL;
}

//Função para salvar os dados da lista de setores no arquivo
void SalvarDados(ListaSetor **lista, FILE *arquivo){
    //Abrindo o arquivo em modo de escrita
    arquivo = fopen("dados.txt", "w");

    //verificando se o arquivo foi aberto corretamente
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo\n");
        return;
    }

    //variavel auxiliar
    ListaSetor *aux = *lista;

    //escrevendo os dados no arquivo
    while(aux != NULL){
        fprintf(arquivo, "Nome %s   Descricao %s\n\n", aux->setor.nome, aux->setor.descricao);                                                                                                          
        fprintf(arquivo, "Produtos\n");
        ListaProduto *aux2 = aux->setor.produtos;

        while(aux2 != NULL){
            fprintf(arquivo, "Nome %s   Marca %s    Preco %f    Quantidade %d\n", aux2->produto.nome, aux2->produto.marca, aux2->produto.preco, aux2->produto.quantidade);

            aux2 = aux2->prox;
        }

        aux = aux->prox;
    }
}

//TRATATIVAS

//verifica se há caracteres especiais no nome
int verificaCaracterEspecial (char* nome) {
    int i;
    for(i = 0; i < strlen(nome); i++){
        if(((nome[i] >= 33 && nome[i] <= 47) || (nome[i] >= 58 && nome[i] <= 64) || (nome[i] >= 91 && nome[i] <= 96) || (nome[i] >= 123 && nome[i] <= 126))){
            return 1;
        }
    }
    return 0;
}

//verifica se há números no nome
int Verificanum(char* nome) {
    for (int i = 0; nome[i] != '\0'; i++) {
        if (isdigit(nome[i])) {
            return 1;
        }
    }
    return 0;

}

//junção das funções de verificação de caracteres especiais e números
int verificanome(char* nome) {
    if (verificaCaracterEspecial(nome) == 1) {
        printf("Nome invalido! Digite apenas letras.\n");
        return 1;
    }
    if (Verificanum(nome) == 1) {
        printf("Nome invalido! Digite apenas letras.\n");
        return 1;
    }
    return 0;
}

//passar os dados informados pelo usuário para maiúsculo
void passarMaiuscula(char* nome) {
    for (int i = 0; nome[i] != '\0'; i++) 
    {
        nome[i] = toupper(nome[i]);
    }
}

//verifica se so há numeros
int VerificaInt(int *nome) {
    for (int i = 0; nome[i] != '\0'; i++) {
        if (!isdigit(nome[i])) {
            return 1; // Não são apenas números
        }
    }
    return 0; // São apenas números
}

//verificando se o usuario digitou apenas numeros, deve aceitar float
int VerificaFloat(float *num) {
    int i;
    int ponto = 0;
    for (i = 0; num[i] != '\0'; i++) {
        if (!isdigit(num[i])) {
            if (num[i] == '.') {
                ponto++;
            } else {
                return 1;
            }
        }
    }
    if (ponto > 1) {
        return 1;
    }
    return 0;
}

char Opcao(char opcao)
{
    // verificando se o usuadio digitou apenas um caracter e se esse caracter é um numero
    if(getchar() != '\n')
    {
        printf("Opcao invalida! Digite apenas um caracter: ");
        while(getchar() != '\n'){
            scanf(" %c", &opcao);
        }
    }
    return opcao;
}