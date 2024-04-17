#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "setor.h"

//Função para verificar se a lista de setores está vazia
int VaziaSetor(ListaSetor **lista);

//Função criada para passar os dados da lista de setores para um arquivo
void SalvarDados(ListaSetor **lista, FILE *arquivo);

//verifica se há caracteres especiais no nome
int verificaCaracterEspecial (char* nome);

//verifica se há números no nome
int Verificanum(char* nome);

//junção das funções de verificação de caracteres especiais e números
int verificanome(char* nome);

//passar os dados informados pelo usuário para maiúsculo
void passarMaiuscula(char* nome);

//verifica se so há numeros
int VerificaInt(int *nome);

//verificando se o usuario digitou apenas numeros, deve aceitar float
int VerificaFloat(float *num);

//verifica se o usuário está digitando a opcao correta e se essa opcao esta no menu
char Opcao(char opcao); 
