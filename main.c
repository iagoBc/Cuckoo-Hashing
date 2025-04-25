#include "hash.h"

int main(){
    struct Hash *table = criar_tab();
    char operacao;
    int k;

    // Lê as operações e as chaves do arquivo
    while (scanf("%c %d", &operacao, &k) != EOF) {
        if (operacao == 'i') {
            inserir(k, table);  // Insere na tabela hash
        } 
        
        else if (operacao == 'r') {
            excluir(k, table);  // Exclui a chave da tabela hash
        }
    }
    
    print_tab(table);

    free_hash(table);
}