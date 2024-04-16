#ifndef SETOR_H
#define SETOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Definido a struct do setor
typedef struct setor Setor;
 //Definida a lista encadeada de setor
typedef struct listaSetor ListaSetor;

//Função para iniciar a lista de setores
void CriaSetor(ListaSetor **lista);

//Função para adicionar um novo setor
void CriaSetor(ListaSetor **lista);

//Funçaõ para remover um setor
void RemoveSetor(ListaSetor **lista);

#endif //SETOR_H