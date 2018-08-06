/*
 * Construa um programa que leia um conjunto de numeros inteiros
 * para preencher uma matriz 10×10 e a partir dai, gere um vetor
 * com os elementos maiores que o primeiro elemento de cada linha
 * e outro vetor com os elementos menores que o primeiro de cada
 * coluna.
 */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(void) {
    srand((unsigned) time(NULL));

    size_t tamanho;
    printf("Digite o tamanho da matriz desejada: ");
    scanf("%zd", &tamanho);
    
    /*
    // 1a. opcao: declarar a matriz de forma estatica
    int matriz[tamanho][tamanho];   // nao sera alocada se ultrapassar a capacidade da pilha (de variaveis locais)
    */

    // 2a. opcao: alocacao dinamica (lembrando que a dimensao informada eh dada em bytes, e nao elementos)
    int* matriz = malloc(tamanho*tamanho * sizeof(int));

    puts("Matriz gerada (nao lida do teclado):");
    int l, c;
    for (l = 0; l < tamanho; ++l) {
        for (c = 0; c < tamanho; ++c) {
            *(matriz + l*tamanho + c) = rand() % 10000 + 1;
            printf("%5d ", *(matriz + l*tamanho + c));
        }
        putchar('\n');
    }

    // Aproveitamos que se optou pela alocacao dinamica e fazemos
    // o mesmo com um dos vetores
    int vetor_maiores[tamanho*(tamanho-1)]; // pior caso, todas as colunas de cada linha com valores maiores
    int* vetor_menores = malloc(tamanho*(tamanho-1) * sizeof(int));

    // Brincando com o intercambio entre vetor e ponteiro:
    // Vou manipular o vetor declarado como tal na forma de ponteiro;
    // e vou usar indexacao ([]) no ponteiro que recebeu o endereco da area alocada

    size_t contador_maiores = 0; // quantos numeros armazenados em vetor_maiores
    size_t contador_menores = 0; // idem para o vetor_menores

    // Para gerar o vetor de maiores, faz o percurso na matriz por linhas
    for (l = 0; l < tamanho; ++l) {
        int maior = *(matriz + l*tamanho + 0);  // coluna 0
        for (c = 1; c < tamanho; ++c) {
            int num = *(matriz + l*tamanho + c);
            if (num > maior) {
                // Aproveita que o contador esta com o valor do indice a ser usado agora
                *(vetor_maiores + contador_maiores) = num;
                ++contador_maiores;
            }
        }
    }

    // Para gerar o vetor de menores, faz o percurso na matriz por colunas
    for (c = 0; c < tamanho; ++c) {
        int menor = *(matriz + 0*tamanho + c);  // linha 0
        for (l = 1; l < tamanho; ++l) {
            int num = *(matriz + l*tamanho + c);
            if (num < menor) {
                vetor_menores[contador_menores++] = num;
            }
        }
    }

    // Imprime os vetores
    int i;
    puts("Vetor dos maiores:");
    for (i = 0; i < contador_maiores; ++i) {    // imprime soh a "parte util" (preenchida) do vetor
        printf("%d ", *(vetor_maiores + i));
    }
    puts("\nVetor dos menores:");
    for (i = 0; i < contador_menores; ++i) {
        printf("%d ", vetor_menores[i]);
    }
    putchar('\n');

    // Libera memoria alocada dinamicamente
    free(matriz);
    free(vetor_menores);

    return EXIT_SUCCESS;
}
