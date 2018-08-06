#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int main(void) {
    float *X, *Y;   // dois vetores de entrada, alocados dinamicamente
    float *D;       // vetor de saida

    size_t tamanho_X, tamanho_Y;
    printf("Digite o tamanho do vetor X: ");
    scanf("%ld", &tamanho_X);
    printf("Digite o tamanho do vetor Y: ");
    scanf("%ld", &tamanho_Y);

    // Cria os vetores X e Y na memoria de alocacao dinamica
    X = (float*) malloc(tamanho_X * sizeof(float));
    Y = (float*) malloc(tamanho_Y * sizeof(float));

    // Preenche o conteudo dos vetores com numeros aleatorios de 0.0 a 0.19
    int x, y, z;
    bool repetido;
    for (x=0; x<tamanho_X; ++x) {
        // Repete a geracao do numero...
        do {
            X[x] = (rand() % 20) / 100.0;
            repetido = false;
            for (z=x-1; z>=0; --z) {
                if (X[z] == X[x]) {
                    repetido = true;
                    break;
                }
            }
        // ... enquanto ele ja tiver ocorrido numa posicao anterior de X
        } while (repetido == true);
        printf("%.2f ", X[x]);
    }
    putchar('\n');
    for (y=0; y<tamanho_Y; ++y) {
        do {
            *(Y+y) = rand() % 20 / 100.0;
            repetido = false;
            for (z=y-1; z>=0; --z) {
                if (*(Y+z) == *(Y+y)) {
                    repetido = true;
                    break;
                }
            }
        } while (repetido == true);
        printf("%.2f ", Y[y]);
    }
    putchar('\n');

    // Letra (b) do exercicio
    // Qual o tamanho do vetor D? Resp.: o mesmo tamanho de X, para o caso de
    // Y nao ter nenhum dos elementos de X
    D = (float*) malloc(tamanho_X * sizeof(float));
    int d = 0;  // indice de onde estou no vetor D
    for (x=0; x<tamanho_X; ++x) {
        bool achei_em_y = false;
        for (y=0; y<tamanho_Y; ++y) {
            if (X[x] == Y[y]) {
                achei_em_y = true;
                // Nao adianta continuar dentro do Y, ja achei!...
                break;
            }
        }
        if (achei_em_y == false) {
            D[d] = X[x];    // copio o X que NAO achei em Y para o vetor D
            ++d;            // vou para a proxima posicao livre em D para continuar
        }
    }

    // Imprime o vetor D
    for (x=0; x<d; ++x) {   // nao percorre o vetor inteiro, apenas ateh onde foi em D
        printf("%.2f ", D[x]);
    }
    putchar('\n');

    // Concluidos os trabalhos, libera todos os vetores
    free(D);
    free(Y);
    free(X);

    return EXIT_SUCCESS;
}
