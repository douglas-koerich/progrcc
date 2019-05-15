#include <stdlib.h>
#include <stdio.h>

#define NUM_ALUNOS 5
#define NUM_AVALIACOES 2

float media_tabela(size_t, size_t, float [*][*]); // tamanhos ANTES da matriz

int main(void) {
    // Declaracao onde o 1o. indice eh sempre o das LINHAS
    float notas[NUM_ALUNOS][NUM_AVALIACOES]; // 5 lin x 2 cols

    float espelho[][NUM_AVALIACOES] = { // pode-se omitir APENAS
                                        // o primeiro valor
        { 7.5, 8.4 }, // cada linha separadamente
        { 6.8, 9.3 },
        { 3.1, 4.9 },
        { 9.2, 6.7 },
        { 2.3, 8.1 }
    };
    float vazia[NUM_ALUNOS][NUM_AVALIACOES] = {};
    float parcial1[NUM_ALUNOS][NUM_AVALIACOES] = {
        { 6.8, 9.3 },
        { 3.1, 4.9 } // demais ficam zeradas
    };
    float parcial2[NUM_ALUNOS][NUM_AVALIACOES] = {
        [1] = { 6.8, 9.3 }, // primeira linha [0] zerada
        { [1] = 7.4 }, // elemento [0] da linha SEGUINTE zerado
        [4] = { 3.2 }, // linha [3] zerada, elemento [4][1] zerado
    };

    // Atribuicoes aleatorias, para exemplificar
    notas[2][1] = 3.0; // 2o. elemento (2a. coluna) da 3a. linha

    // Preenchimento/percurso da matriz (lacos aninhados)
    puts("Digite as notas dos alunos:");
    int l, c;
    for (l = 0; l < NUM_ALUNOS; ++l) {
        printf("ALUNO no. %d\n", l+1); // a cada nova linha...
        for (c = 0; c < NUM_AVALIACOES; ++c) {
            printf("%da. nota? ", c+1);
            scanf("%f", &notas[l][c]);
        }
    }

    // Percurso por linhas (todas as colunas de cada linha, antes da proxima)
    puts("---- TABELA DE ALUNOS ----");
    for (l = 0; l < NUM_ALUNOS; ++l) {
        for (c = 0; c < NUM_AVALIACOES; ++c) {
            printf("%.1f ", notas[l][c]);
        }
        putchar('\n'); // forca uma mudanca de linha na tela
    }

    // Percurso por COLUNAS (todas as linhas de cada coluna, antes da proxima)
    puts("---- TABELA DE NOTAS ----");
    for (c = 0; c < NUM_AVALIACOES; ++c) {
        for (l = 0; l < NUM_ALUNOS; ++l) {
            printf("%.1f ", notas[l][c]); // **CUIDADO**, nao inverta!!!
        }
        putchar('\n');
    }

    printf("A media das notas eh %.1f\n", media_tabela(NUM_ALUNOS, NUM_AVALIACOES, notas));

    // Matriz com tamanho escolhido pelo usuario
    size_t linhas, colunas;
    printf("Digite o numero de linhas: ");
    scanf("%zd", &linhas); // %zd para o tipo size_t
    printf("E o numero de colunas: ");
    scanf("%zd", &colunas);
    int matriz[linhas][colunas];
    int x, y;
    for (x = 0; x < linhas; ++x) {
        for (y = 0; y < colunas; ++y) {
            matriz[x][y] = rand();
            printf("%15d ", matriz[x][y]); // leia sobre "saida formatada" do printf
        }
        putchar('\n');
    }

    return EXIT_SUCCESS;
}

// Usa os tamanhos pra definir as dimensoes da matriz na passagem dos parametros
float media_tabela(size_t linhas, size_t colunas, float matriz[linhas][colunas]) {
    float soma = 0.0;
    int i, j;
    for (i = 0; i < linhas; ++i) {
        for (j = 0; j < colunas; ++j) {
            soma += matriz[i][j];
        }
    }
    float media = soma / (linhas * colunas); // media aritmetica
    return media;
}

