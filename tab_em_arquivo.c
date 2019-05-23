#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define LINHAS 3
#define COLUNAS 4

int main(void) {
    srand(time(0));

    int tabela[LINHAS][COLUNAS];
    int i, j;
    for (i=0; i<LINHAS; ++i) {
        for (j=0; j<COLUNAS; ++j) {
            tabela[i][j] = rand() % 100 + 1; // no intervalo [1, 100]
        }
    }
    FILE* texto = fopen("/tmp/texto.txt", "w");
    if (texto == 0) {
        perror("Nao pude criar o arquivo-texto");
        return EXIT_FAILURE;
    }
    for (i=0; i<LINHAS; ++i) {
        for (j=0; j<COLUNAS; ++j) {
            printf("%3d ", tabela[i][j]);
            fprintf(texto, "%d;", tabela[i][j]);
        }
        putchar('\n');
        fputc('\n', texto);
    }
    fclose(texto);
    return EXIT_SUCCESS;
}

