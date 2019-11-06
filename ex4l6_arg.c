#include <stdlib.h>
#include <stdio.h>

void soma_colunas(size_t, size_t, const int [*][*], int [*]);

int main(int num_args, char* lista_args[]) { // int main(int argc, char** argv);
    if (num_args < 3) { // a contagem inclui o proprio nome do programa
                        // na linha de comando
        printf("%s: argumentos insuficientes\n", lista_args[0]); // [0] eh o nome
        printf("Dica: %s <linhas> <colunas>\n", lista_args[0]);
        return EXIT_FAILURE;
    }
    int linhas, colunas;
    linhas = atoi(lista_args[1]); // segundo argumento: numero de linhas
    colunas = atoi(lista_args[2]); // terceiro: numero de colunas

    int matriz[linhas][colunas];

    int l, c;
    for (l = 0; l < linhas; ++l) {
        for (c = 0; c < colunas; ++c) {
            printf("Valor de %d,%d? ", l, c);
            scanf("%d", &matriz[l][c]);
        }
    }

    puts("Matriz digitada");
    for (l = 0; l < linhas; ++l) {
        for (c = 0; c < colunas; ++c) {
            printf("%3d ", matriz[l][c]);
        }
        putchar('\n');
    }

    int vetor_somas[colunas];

    soma_colunas(linhas, colunas, matriz, vetor_somas);

    puts("Soma das colunas");
    for (c = 0; c < colunas; ++c) {
        printf("%d ", vetor_somas[c]);
    }
    putchar('\n');

    return EXIT_SUCCESS;
}

void soma_colunas(size_t N, size_t M, const int m[N][M], int v[M]) {
    int l, c;
    for (c = 0; c < M; ++c) {
        v[c] = 0;
        for (l = 0; l < N; ++l) {
            v[c] += m[l][c];
        }
    }
}

