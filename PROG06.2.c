#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MESES 12
#define PRODUTOS 4

#define MAX_NOME_MES 4 // "xxx\0"
#define MAX_NOME_PRODUTO 10

int main(void) {
    // Vetores de strings sao vetores de vetores de caracteres (i.e. matrizes)
    const char meses[MESES][MAX_NOME_MES] = {
        "jan", // primeira linha/string da matriz
        "fev", "mar", "abr", "mai", "jun", "jul", "ago", "set", "out", "nov", "dez"
    };
    const char produtos[PRODUTOS][MAX_NOME_PRODUTO] = {
        "Prego", "Porca", "Arruela", "Parafuso"
    };

    int tabela[PRODUTOS][MESES];

    // Preenche tabela com numeros aleatorios no intervalo 1000 a 5000
    srand((unsigned) time(0)); // inicializa gerador de aleatorios
    int prod, mes;
    for (prod=0; prod<PRODUTOS; ++prod) {
        for (mes=0; mes<MESES; ++mes) {
            tabela[prod][mes] = rand() % 4001 + 1000;
        }
    }

    // Imprime o cabecalho da tabela
    printf("%*s ", MAX_NOME_PRODUTO, "Produto"); // O '*' aqui eh para definir o tamanho da impressao
                                                 // como sendo MAX_NOME_PRODUTO que eh o primeiro parametro
    for (mes=0; mes<MESES; ++mes) {
        printf("%*s ", MAX_NOME_MES, meses[mes]); // usa soh um indice da matriz para se referir a linha/string inteira na matriz 'meses'
    }
    putchar('\n');

    // Imprime a tabela com uma coluna ah esquerda exibindo o nome
    for (prod=0; prod<PRODUTOS; ++prod) {
        // Comeca imprimindo o nome do produto (ainda nao eh a impressao da tabela!)
        printf("%*s ", MAX_NOME_PRODUTO, produtos[prod]);

        // Agora sim, imprime todas as colunas da tabela (meses) dessa linha (produto)
        for (mes=0; mes<MESES; ++mes) {
            printf("%*d ", MAX_NOME_MES, tabela[prod][mes]);
        }
        putchar('\n');
    }

    // Letra (a): percurso por linha/produto
    for (prod=0; prod<PRODUTOS; ++prod) {
        int soma = 0;
        for (mes=0; mes<MESES; ++mes) {
            soma += tabela[prod][mes];
        }
        printf("Soma anual de '%s': %d\n", produtos[prod], soma);
    }
    // Letra (b): percurso por coluna/mes
    for (mes=0; mes<MESES; ++mes) {
        int soma = 0;
        for (prod=0; prod<PRODUTOS; ++prod) {
            soma += tabela[prod][mes]; // NAO inverte os indices entre os colchetes!!!
        }
        printf("Soma dos produtos no mes '%s': %d\n", meses[mes], soma);
    }

    return EXIT_SUCCESS;
}

