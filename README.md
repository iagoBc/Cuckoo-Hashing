# Cuckoo Hashing

Implementação de uma tabela hash com duas tabelas e duas funções de
espalhamento, seguindo a estratégia de **Cuckoo Hashing**. O projeto foi
desenvolvido em C como atividade de algoritmos e estruturas de dados.

## Como funciona

- A tabela possui duas estruturas internas, `T1` e `T2`.
- Cada chave pode ser posicionada em um índice calculado por uma das funções
  de hash.
- A capacidade de cada tabela é de 11 posições.
- O programa aceita operações de inserção e remoção pela entrada padrão.
- Ao final do processamento, as chaves existentes são exibidas em ordem
  crescente.

As funções de hash implementadas são:

```text
h1(k) = k mod 11
h2(k) = floor(11 * (0.9k - floor(0.9k)))
```

## Requisitos

- GCC
- GNU Make

## Compilação

Na raiz do projeto, execute:

```bash
make
```

Esse comando gera o executável `myht`. Para remover o executável e os arquivos
gerados pela compilação:

```bash
make clean
```

Também é possível compilar manualmente:

```bash
gcc hash.c main.c -o myht -Wall
```

## Entrada

Cada linha deve conter uma operação e uma chave inteira, separados por espaço:

| Operação | Descrição |
| --- | --- |
| `i k` | Insere a chave `k` |
| `r k` | Remove a chave `k` |

O programa lê operações até o fim da entrada (EOF). Depois disso, imprime o
conteúdo final das tabelas.

## Saída

Cada chave encontrada é impressa no formato:

```text
chave,tabela,índice
```

Onde `tabela` é `T1` ou `T2`, e `índice` é a posição ocupada pela chave na
tabela correspondente.

## Exemplo

Com o projeto compilado, execute:

```bash
printf 'i 10\ni 21\ni 5\nr 21\n' | ./myht
```

Saída:

```text
5,T1,5
10,T2,0
```

## Estrutura do projeto

```text
.
├── hash.c   # Implementação das tabelas e operações de hash
├── hash.h   # Estruturas e declarações públicas
├── main.c   # Leitura das operações e execução do programa
├── Makefile # Comandos de compilação e limpeza
└── Hash.pdf # Material relacionado à atividade
```

## Funções principais

- `criar_tab`: aloca e inicializa as duas tabelas.
- `inserir`: insere uma chave na tabela hash.
- `buscar`: procura uma chave nas tabelas.
- `excluir`: remove uma chave.
- `print_tab`: imprime as chaves armazenadas em ordem crescente.
- `free_hash`: libera a memória alocada.

## Licença

Este projeto não possui uma licença definida.
