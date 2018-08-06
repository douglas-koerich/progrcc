#include <stdio.h>

// Cuidado! A linha de cabecalho e a coluna de referencia (da esquerda)
// NAO contam na dimensao da matriz, porque se referem a um outro tipo
// de dados (a matriz eh de numeros e aquelas informacoes sao strings)

// #define MAX_PRODUTOS 10
#define MESES           12

int main() {
    char nomes_meses[MESES][4] = {  // 3 + 1 para o terminador nulo!!!
        "Jan", "Fev", "Mar", "Abr", "Mai", "Jun",
        "Jul", "Ago", "Set", "Out", "Nov", "Dez"
    };

    int num_produtos;
    printf("Digite quantos produtos serao tabelados: ");
    scanf("%d", &num_produtos);

    // int tabela[MAX_PRODUTOS][MESES];
    int tabela[num_produtos][MESES];

    // Percurso na matriz para preencher as vendas
    int lin, col;
    for (lin = 0; lin < num_produtos; ++lin) {
        printf("Digite as vendas do produto num. %d\n", lin+1);
        for (col = 0; col < MESES; ++col) {
            // Usa o mesmo indice que marca a coluna onde estah na tabela
            // para buscar no vetor de nomes de meses o nome desta coluna
            printf("Digite as vendas do mes %s: ", nomes_meses[col]);
            scanf("%d", &tabela[lin][col]);
        }
    }
    // Os totais por produto sao os somatorios das linhas
    // Declara um vetor com o mesmo tamanho do numero de linhas para ter
    // esses totais
    int tot_produtos[num_produtos];
    for (lin = 0; lin < num_produtos; ++lin) {
        tot_produtos[lin] = 0;
        for (col = 0; col < MESES; ++col) {
            tot_produtos[lin] += tabela[lin][col];
        }
    }

    // Os totais por mes sao os somatorios das colunas
    int tot_meses[MESES] = { 0 };

    // ATENCAO! O percurso aqui eh por COLUNA!
    for (col = 0; col < MESES; ++col) {
        for (lin = 0; lin < num_produtos; ++lin) {
            tot_meses[col] += tabela[lin][col]; // nao inverte indices!!!
        }
    }

    // Impressao da tabela e seus totais

    // Cabecalho da tabela:
    printf("Produto ");
    for (col = 0; col < MESES; ++col) {
        printf("%5s ", nomes_meses[col]);
    }
    puts("TOTAL");

    // Cada linha da tabela...
    for (lin = 0; lin < num_produtos; ++lin) {
        // "Nome" do produto (nao estah na matriz)
        printf("Prod. %c ", 'A'+lin);   // 'B' para lin=1, 'C' para lin=2, ...

        // Quantidades dos meses
        for (col = 0; col < MESES; ++col) {
            printf("%5d ", tabela[lin][col]);
        }
        // Soma dessa linha (total de vendas desse produto)
        printf("%5d\n", tot_produtos[lin]);
    }
    // Uma linha adicional para as somas das colunas (total dos meses)
    printf("TOTAL    ");
    for (col = 0; col < MESES; ++col) {
        printf("%5d ", tot_meses[col]);
    }
    putchar('\n');  // equivale a fazer um printf("\n");

    return 0;
}

