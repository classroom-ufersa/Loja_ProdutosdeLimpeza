#include "C:\Users\marii\OneDrive\Área de Trabalho\github\Loja_ProdutosdeLimpeza\include\produto.h"
#include "C:\Users\marii\OneDrive\Área de Trabalho\github\Loja_ProdutosdeLimpeza\include\setor.h"
#include "C:\Users\marii\OneDrive\Área de Trabalho\github\Loja_ProdutosdeLimpeza\include\sistema.h"

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

    //Variavel auxiliar
    ListaSetor *aux = *lista;

    //Percorrendo a lista de setores
    while(aux != NULL){
        //Salvando o nome e a descrição do setor
        fprintf(arquivo, "Nome do setor: %s   Descricao: %s\n", aux->setor.nome, aux->setor.descricao);

        //Salvando os produtos do setor
        ListaProduto *auxProduto = aux->setor.produtos;
        fprintf(arquivo, "Produtos: \n");
        while(auxProduto != NULL){
            fprintf(arquivo, "Nome: %s   Marca: %s    Preco: %.2f    Quantidade: %d\n", auxProduto->produto.nome, auxProduto->produto.marca, auxProduto->produto.preco, auxProduto->produto.quantidade);
            auxProduto = auxProduto->prox;
        }
        fprintf(arquivo, "\n");
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

//Função para verificar se o usuario esta digitando apenas a opção que tem no menu
char Opcao(char opcao)
{
    // verificando se o usuadio digitou apenas um caracter e se esse caracter é um numero
    while(getchar() != '\n'){
        printf("Opcao invalida");
        scanf(" %c", &opcao);
    }
    return opcao;
}