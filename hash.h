#ifndef HASH_H_
#define HASH_H_

#include <stdio.h>
#include <stdlib.h>


// Estrutura que possui o valor da chave e a tabela que pertence
struct Chave{
    int valor;
    unsigned short t;
};

// Estrutura que possui as tabelas com as chaves
struct Hash{
    struct Chave *tabela1, *tabela2;
};

// Cria as duas tabelas hash
struct Hash *criar_tab();

// Libera a memória alocada
void free_hash(struct Hash* table);

// Retorna o piso do valor
int piso(double n);

// Funçao que retorna k mod m
int h1(int k);

// Função que retorna piso(m * (k * 0.9 - piso(k * 0.9)))
int h2(int k);

// Função que busca o índice que o valor k está 
int buscar(int k, struct Hash *table);

// Função que insere o valor k em uma das duas tabelas
void inserir(int k, struct Hash *table);

// Função que excluí o valor k em uma das duas tabelas
void excluir(int k, struct Hash *table);

// Função que compara para qsort
int compara(const void *a, const void *b);

// Função que imprime os valores que estão nas tabelas
void print_tab(struct Hash *table);

#endif  // HASH_H_