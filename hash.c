#include "hash.h"

int m = 11;

struct Hash *criar_tab(){
    struct Hash* hash = (struct Hash*)malloc (sizeof (struct Hash));
    if (hash != NULL) { 
        hash->tabela1 = (struct Chave*)malloc (m * sizeof (struct Chave));  // Aloca m chaves
        hash->tabela2 = (struct Chave*)malloc (m * sizeof (struct Chave));  // Aloca m chaves
        for(int i = 0; i < m; i++){
            hash->tabela1[i].valor = -1; // Inicializa com -1 para indicar vazio
            hash->tabela1[i].t = 0; // Inicializa as chaves da tabela 1 todas pertencendo a 0
            hash->tabela2[i].valor = -1; // Inicializa com -1 para indicar vazio
            hash->tabela2[i].t = 1; // Inicializa as chaves da tabela 2 todas pertencendo a 1
        }
    }
    return hash;
}

void free_hash(struct Hash* table){
    free(table->tabela1); 
    free(table->tabela2);
    free(table);
}

int piso(double n) {
    int inteiro = (int)n;  // Converte o número para inteiro, descartando a parte decimal

    // Se o número for negativo e tiver uma parte decimal, decrementamos o inteiro
    if (n < 0 && n != inteiro) {
        return inteiro - 1;
    }

    return inteiro;  // Retorna o inteiro para números positivos ou negativos exatos
}

int h1(int k){
    return k % m;
}

int h2(int k){
    return piso(m * (k * 0.9 - piso(k * 0.9)));
}

int buscar(int k, struct Hash *table){
    int indice = h1(k);
    if(table->tabela1[indice].valor == -1) return -1; // Retorna -1 se o valor não está na primeira tabela, porque sabemos que não estará na segunda tabela
    else if(table->tabela1[indice].valor == k) return indice; 
    indice = h2(k);
    if(table->tabela2[indice].valor == -1) return -1;
    else return indice; 
    
}

void inserir(int k, struct Hash *table){
    if(table->tabela1[h1(k)].valor == -1 || table->tabela1[h1(k)].valor == -2){ // Se não existe valor (-1 ou -2 = valor excluído)no indice h1(k) da tabela 1 
        table->tabela1[h1(k)].valor = k;
        return;
    }

    else{ 
        int aux = table->tabela1[h1(k)].valor; // Pega o valor que está na tabela 1
        table->tabela2[h2(aux)].valor = aux; // Coloca aux na tabela 2
        table->tabela1[h1(k)].valor = k; // Coloca k na tabela 1
        return;
    }
}

void excluir(int k, struct Hash *table){
    int indice = buscar(k, table); // Busca o índice que está k
    if(indice == -1) return; // Se a busca retorna -1 então o valor não existe nas tabelas
    else if(table->tabela2[indice].valor == k) table->tabela2[indice].valor = -1; // Excluí o valor na tabela 2
    else table->tabela1[indice].valor = -2; // Excluí o valor na tabela 1, mas coloca -2 para indicar que teve um valor excluído na tabela 1
}

int compara(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void print_tab(struct Hash *table){
    int *valores = (int *)malloc(2 * m * sizeof(int)); // Vetor para armazenar os valores
    int count = 0;

    // Copia os valores válidos de tabela1 e tabela2
    for (int i = 0; i < m; i++) {
        if (table->tabela1[i].valor != -1 && table->tabela1[i].valor != -2) {
            valores[count++] = table->tabela1[i].valor;
        }
        if (table->tabela2[i].valor != -1 && table->tabela2[i].valor != -2) {
            valores[count++] = table->tabela2[i].valor;
        }
    }

    // Ordena os valores usando qsort
    qsort(valores, count, sizeof(int), compara);

    // Imprime os valores ordenados
    for (int i = 0; i < count; i++) {
        int aux = buscar(valores[i], table);
        if(valores[i] == table->tabela1[aux].valor) printf("%d,T%d,%d\n", valores[i], table->tabela1[aux].t + 1, aux);
        else printf("%d,T%d,%d\n", valores[i], table->tabela2[aux].t + 1, aux);
    }

    free(valores); // Libera a memória alocada
}

