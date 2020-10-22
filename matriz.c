#include <stdlib.h>
#include <stdio.h>

int media_dia(const int [*], size_t);
void imprime_medicoes(size_t, size_t, const int [*][*]);

int main(void) {
    const int NUM_DIAS = 5; // 1 medicao por dia da semana
    const int NUM_ESTACOES = 3; // 3 estacoes de medicao
    int medicoes[NUM_DIAS][NUM_ESTACOES], i, j;

    /* Exemplo de inicializacao:
       int matriz[2][3] = { {2, 4, 6}, {1, 2, 3} };
       int matriz[][3] = { {2, 4, 6}, {1, 2, 3} };
       int matrix[2][3] = {
           [1] = { [1] = 5 };
       }
    */

    // Percurso por linha de cada coluna
    for (j = 0; j < NUM_ESTACOES; ++j) {
        for (i = 0; i < NUM_DIAS; ++i) {
            printf("Digite a %da. medicao [mm] da estacao #%d: ", i+1, j+1);
            scanf("%d", &medicoes[i][j]);
        }
    }

    imprime_medicoes(NUM_DIAS, NUM_ESTACOES, medicoes);

    for (i = 0; i < NUM_DIAS; ++i) {
        int media_pluviometrica = media_dia(medicoes[i], NUM_ESTACOES);
        printf("A media de chuva no %o. dia foi %d mm.\n", i+1, media_pluviometrica);
    }

    int maior_medida, menor_medida;
    maior_medida = menor_medida = medicoes[0][0];

    // Percurso por coluna de cada linha
    for (i = 0; i < NUM_DIAS; ++i) {
        for (j = 0; j < NUM_ESTACOES; ++j) {
            if (medicoes[i][j] > maior_medida) {
                maior_medida = medicoes[i][j];
            }
            if (medicoes[i][j] < menor_medida) {
                menor_medida = medicoes[i][j];
            }
        }
    }
    printf("A maior e menor medidas foram, respectivamente, %d mm e %d mm.\n",
           maior_medida, menor_medida);

    return EXIT_SUCCESS;
}

int media_dia(const int lista[], size_t num_elementos) {
    int soma = 0, i;
    for (i = 0; i < num_elementos; ++i) {
        soma += lista[i];
    }
    return soma / num_elementos;
}

void imprime_medicoes(size_t linhas, size_t colunas, const int tabela[linhas][colunas]) {
    printf("%5s%15s%15s%15s\n", "Dia", "Estacao 1", "Estacao 2", "Estacao 3");
    int dia, estacao;
    for (dia = 0; dia < linhas; ++dia) {
        printf("%5d", dia+1);
        for (estacao = 0; estacao < colunas; ++estacao) {
            printf("%15d", tabela[dia][estacao]);
        }
        printf("\n");
    }
}