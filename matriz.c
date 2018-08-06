#include <stdlib.h>
#include <stdio.h>

void imprime_matriz(size_t, size_t, const int [*][*]);  // const para nao alterar o conteudo

#define NUM_LINHAS  3
#define NUM_COLUNAS 4

int main(void) {
    int matriz[NUM_LINHAS][NUM_COLUNAS] = {
        { 2, 4, 6, 8 }, // primeira linha
        { 1, 3, 5, 7 }, // segunda linha
        { 1, 2, 3 }, // terceira linha "incompleta" (preenchida com 0s)
    };
    int outra[][NUM_COLUNAS] = {
        { 1, 2, 3, 4 },
        { 5, 6, 7, 8 }
    }; // define o numero de linhas como 2

    printf("Digite um fator de multiplicacao: ");
    int fator;
    scanf("%d", &fator);

    // Percurso "convencional": linha-a-linha
    int i, j;
    for (i = 0; i < NUM_LINHAS; ++i) { // para cada linha...
        for (j = 0; j < NUM_COLUNAS; ++j) { // para cada coluna da linha...
            matriz[i][j] *= fator;
        }
    }
    // Percurso menos usual, mas valido: coluna-a-coluna
    for (i = 0; i < NUM_COLUNAS; ++i) { // para cada coluna...
        for (j = 0; j < 2; ++j) { // para cada linha da coluna...
            outra[j][i] *= fator; // o primeiro colchetes eh SEMPRE o do indice da LINHA
        }
    }

    puts("Matriz 'matriz':");
    imprime_matriz(NUM_LINHAS, NUM_COLUNAS, matriz);
    puts("Matriz 'outra':");
    imprime_matriz(2, NUM_COLUNAS, outra);

    return EXIT_SUCCESS;
}

void imprime_matriz(size_t linhas, size_t colunas, const int m[linhas][colunas]) {
    int i, j;
    for (i = 0; i < linhas; ++i) {
        for (j = 0; j < colunas; ++j) {
            printf("%3d ", m[i][j]);
        }
        putchar('\n');  // ao final da linha, salta para proxima...
    }
}

