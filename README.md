<img width=100% src="https://capsule-render.vercel.app/api?type=waving&height=120&color=FFFFFF"/>

[![Typing SVG](https://readme-typing-svg.herokuapp.com/?color=FFFFFF&size=35&center=true&vCenter=true&width=1000&lines=Loja+de+Produto+de+Limpeza;Maria+Clara+e+Shamyra+Carvalho+:%29)](https://git.io/typing-svg)

<h1 align="center">Grupo 19: Loja de Produtos de Limpeza</h1>

## Doscente da turma
- [Rosana Cibely Batista Rego](https://github.com/roscibely)

## Componentes da equipe
- [Maria Clara Saraiva Leal](https://github.com/claraleal12)
- [Shamyra de Fátima Saraiva Carvalho](https://github.com/shamyracarvalhoo)


## Linguagem utilizada

![C](https://img.shields.io/badge/C-007ACC?style=for-the-badge&logo=C&logoColor=white)&nbsp;

Neste arquivo você verá:
- [Linguagem](#1.0-IA's-utilizadas)
- [Introdução](#2.0-Introdução)
- [Problemática](#3.0-problemática)
- [Descrição](#4.0-descrição)
- [Organização do repositório](#5.0-organização-do-repositório)
- [Listas encadeadas](#6.0-listas-encadeadas)
- [Funções em Médico](#7.0-funções-em-médico)
- [Funções em Paciente](#8.0-funções-em-paciente)
- [Funções em tratativas](#9.0--funções-em-tratativas)
- [Funções em main](#10.0-funções-em-main)

## **1.0-IA's utlizada**

### As IA's foram usadas em nosso código com o intuito de tirar dúvidas sobre funções, comandos e etc.

- **ChatGPT**: O ChatGPT é um modelo de linguagem desenvolvido pela OpenAI, projetado para interagir e responder a perguntas em linguagem natural, com base em um amplo conjunto de dados.

- **Github Copilot**: O GitHub Copilot é uma ferramenta de programação baseada em inteligência artificial, desenvolvida pela GitHub e pela OpenAI. Ele fornece sugestões de código em tempo real enquanto você escreve, usando modelos de linguagem avançados para aumentar a produtividade dos desenvolvedores.


## **2.0-Introdução**
A administração de uma loja de produtos de limpeza é crucial para garantir seu funcionamento eficaz e eficiente, abrangendo a gestão dos diversos setores e dos produtos em estoque. Um sistema de gerenciamento especializado para esse tipo de estabelecimento é elaborado com o intuito de simplificar todas as operações essenciais para o bom desempenho do negócio.

## **3.0-Problemática**
Projete um sistema para gerenciamento de uma loja de produtos de limpeza. Seu sistema deve ser capaz de manipular produtos e setores.
## **4.0-Descrição**

Cada setor da loja deve ter os seguintes atributos:
- Nome;
- Descrição;
- Produtos;

Os pacientes devem ter os seguintes atributos:
- Nome;
- Marca;
- Preço;
- Quantidade em estoque.

Um menu com as seguintes opções deverá ser apresentado:
1. Adicionar produto;
2. Remover produto;
3. Editar produto;
4. Adicionar novo setor;
5. Remover setor existente;
6. Listar todos os setores e produtos;
7. Buscar produto;
8. Sair;

A opção Sair é a única que permite sair do programa. Sendo assim, após cada operaçao, o programa volta
ao menu. Além disso, você deve levar em consideração O seguinte: a cada execuçao do seu programa, OS
dados devem ser carregados (armazenados em um arquivo texto); cada novo médico ou paciente cadastrado
deve ser inserido em ordem alfabética (para isso, você pode utilizar as funções da biblioteca padrão deC,
string.h); você deve atualizar o arquivo texto para refletir o estado atual dos dados em virtude da adição
ou remoção.

## **5.0-Organização do Repositório**
A organização desse repositório está disposta da seguinte forma:

``` 
📁 - GerenciamentoDePostoDeSaude
│
└─── bin
│
└─── include
        │
        ├──produto.h
        ├──setor.h
        ├──sistema.h
│
└─── src
        │
        ├──produto.c
        ├──setor.c
        ├──main.c
        ├──sistema.c
        ├──setores.txt
│
└───README.md
```

## **6.0-Listas Encadeadas**

Neste projeto, o sistema de gerenciamento para óticas foi desenvolvido utilizando listas encadeadas, que possibilitam percorrer a lista em uma única direção, do início ao fim.

As listas encadeadas são compostas por nós que armazenam dados e um ponteiro para o próximo nó na sequência. Essa estrutura proporciona uma maneira eficiente de lidar com conjuntos de dados dinâmicos.

Apesar de permitirem apenas a travessia sequencial da lista, as listas encadeadas simples oferecem uma solução eficaz para diversas aplicações de gestão de dados, especialmente quando a ordem dos elementos é relevante e as operações de inserção e remoção são frequentes.

### **Vantagens**
As principais vantagens apresentadas pelo uso de Listas encadeadas são:

- **Flexibilidade:** Oferecem flexibilidade na inserção e remoção de elementos, uma vez que não requerem uma alocação contígua de memória.

- **Inserção e remoção eficiente:** Em comparação com estruturas de dados como vetores, as listas encadeadas oferecem operações eficientes de inserção e remoção de elementos, especialmente quando se trata de operações no meio da lista.

- **Baixo custo de realocação:** A inserção e remoção de elementos em uma lista encadeada não requerem realocação de memória, o que pode ser vantajoso em situações onde a quantidade de elementos na lista é desconhecida ou variável.

### **Desvantagens**
As principais desvantagens apresentadas pelo uso de Listas encadeadas são:

- **Acesso sequencial e menor desempenho:** O acesso aos elementos de uma lista encadeada é sequencial, o que pode resultar em desempenho inferior em comparação com estruturas de dados que oferecem acesso aleatório, como arrays.

- **Consumo de memória**: As listas encadeadas podem consumir mais memória do que outras estruturas de dados, devido à necessidade de armazenar ponteiros adicionais para cada elemento.

## **7.0-Funções em Setor** 
### Função CriaSetor

- **Descrição:** Essa função irá criar a lista de Setor.

```c
void CriaSetor(ListaSetor **lista);
```

### Função NovoSetor

- **Descrição:** Essa função irá criar um Setor e adiciona na lista.

```c
void NovoSetor(ListaSetor **lista);
```

### Função RemoveSetor

- **Descrição:** Essa função pedir para o usuário informar o nome do setor que deseja remover e o remove da lista.

```c
void RemoveSetor(ListaSetor **lista);
```

## **8.0-Funções em Produto**
### Função CriaProduto

- **Descrição:** Essa função irá criar a lista para produtos.

```c
void CriaProduto(ListaProduto **lista);
```

### Função NovoProduto

- **Descrição:** Essa função irá adicionar um produto no setor que o usuário informar, para o produto será informado nome, marca, preço e quantidade em estoque.

```c
void NovoProduto(ListaSetor **lista);
```

### Função RemoveProduto

- **Descrição:** Essa função irá remover um produto (nome informado pelo usuário) de um determinado setor (que também será informado pelo usuário).

```c
void RemoveProduto(ListaSetor **lista);
```

### Função EditaProduto

- **Descrição:** Essa função irá editar informações que o usuário deseja editar de um produto, informando de qual setor é o produto.

```c
void EditaProduto(ListaSetor **lista);
```

### Função BuscaProduto

- **Descrição:** Essa função irá buscar as informações de um produto, informando o nome do setor que ele está e o nome de tal produto.

```c
void BuscaProduto(ListaSetor **lista);
```

### Função MostrarDados

- **Descrição:** Essa função irá mostrar os dados de todos os setores disponíveis, bem como, as informações de todos os produtos que estão em determinados setores.

```c
void MostrarDados(ListaSetor **lista);
```

### Função PassarProdutoArquivo

- **Descrição:** Essa função irá carregar no arquivo txt(dados.txt) os dados das funções usadas durante a execução do programa.

```c
void PassarProdutoArquivo(ListaSetor **lista,char *NomeSetor, char *nomeproduto, float preco, char *marca, int quantidade);
```

## **9.0-Funções em Tratativas**

### Função VaziaSetor

- **Descrição:** Essa função verifica se tem setores cadastrados.

```c
int VaziaSetor(ListaSetor **lista);
```

### Função SalvarDados

- **Descrição:** Essa função serve para pegar os dados que esrtão na lista encadeada e jogar para o arquivo(dados.txt).

```c
void SalvarDados(ListaSetor **lista, FILE *arquivo);
```

### Função verificaCaracterEspecial

- **Descrição:** Essa função veririfica se há caracteres especiais no que o usuário digitar no terminal.

```c
int verificaCaracterEspecial (char* nome);
```

### Função Verificanum

- **Descrição:** Essa função veririfica se há números quando o usuário digitar em um função que só pede string's.

```c
int Verificanum(char* nome);
```

### Função verificanome

- **Descrição:** Esta função vai unir as funções Verificanum e verificaCaracterEspecial.

```c
int verificanome(char* nome);
```

### Função passarMaiuscula

- **Descrição:** Esta função alterar todas as letras para maiúscula.

```c
void passarMaiuscula(char* nome);
```

### Função VerificaInt

- **Descrição:** Essa função veririfica se só há números (usada quando pedir quantidade de produtos).

```c
int VerificaInt(int *nome);
```

### Função VerificaFloat

- **Descrição:** Essa função veririfica se o usuário digitou apenas números, deve aceitar float(usada quando pedir para informar preço de produto).

```c
int VerificaFloat(float *num);
```

## **10.0-Funções em main**

### Função menu

- **Descrição:** Essa função vai englobar todas as outras funções, apresentando o menu principal com as funcionaldiades da loja de produtos de limpeza.

```c
int main (void)
```

<img width=100% src="https://capsule-render.vercel.app/api?type=waving&height=120&color=FFFFFF&section=footer"/>
