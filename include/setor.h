#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Definindo a struct do setor
typedef struct setor Setor;

//Definindo a lista encadeada do setor
typedef struct listaSetor ListaSetor;

//Função para iniciar a lista de setores
void CriaSetor(ListaSetor **lista);

//Função para adicionar um novo setor
void NovoSetor(ListaSetor **lista);

//Função para remover um setor
void RemoveSetor(ListaSetor **lista);