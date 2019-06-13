#include <stdlib.h>
#include <stdio.h>

void imprime_vetor(const int*, size_t);
void imprime_matriz_quadrada(size_t, const int[*][*]);

int main(int argc, char* argv[]) {
    if (argc < 2) {
        puts("Numero insuficiente de parametros");
        printf("Uso: %s <tamanho>\n", argv[0]);
        return EXIT_FAILURE;
    }
    srand(0); // pra gerar sempre a mesma sequencia de numeros
              // entre execucoes consecutivas do programa
    
    /* Vamos trocar as principais variaveis (alocadas estaticamente)
     * do programa por correspondentes alocadas dinamicamente
    // Alocacao estatica (declaracao normal de variaveis)
    size_t tamanho = atoi(argv[1]);
    int vetor[tamanho];
    int matriz[tamanho][tamanho];
    */

    size_t* tamanho = malloc(sizeof(size_t)); // parametro eh numero de bytes 
    *tamanho = atoi(argv[1]); // escreve o conteudo no endereco recebido
    int* vetor = malloc(sizeof(int) * *tamanho); // *tamanho=num. de elementos
    int* matriz = malloc(sizeof(int) * *tamanho * *tamanho);

    // OBS.: nao ha qualquer preenchimento de memoria pelo malloc()

    int i, j;
    /*
    for (i=0; i<tamanho; ++i) {
        vetor[i] = rand() % 100;
        for (j=0; j<tamanho; ++j) {
            matriz[i][j] = rand() % 100;
        }
    }
    */
    for (i=0; i<*tamanho; ++i) {
        *(vetor + i) = rand() % 100; // aritmetica de ponteiro aplicada ao vetor
        for (j=0; j<*tamanho; ++j) {
            // No caso de matriz, deve considerar o "salto" sobre linhas inteiras
            // anteriores (i * tamanho) pra chegar na posicao desejada
            *(matriz + i * *tamanho + j) = rand() % 100;
        }
    }

    imprime_vetor(vetor, *tamanho); // passa o "vetor"/ponteiro como ja sabemos
    imprime_matriz_quadrada(*tamanho, (const int(*)[]) matriz); // usa um cast pra
        // adequar ao tipo de parametro esperado pela funcao - um vetor de ponteiros)

    // No fim do seu uso, todas as areas de memoria alocadas devem ser
    // LIBERADAS
    free(tamanho);  // passa os MESMOS enderecos (valores!) que foram recebidos do malloc()
    free(vetor);
    free(matriz);

    return EXIT_SUCCESS;
}

void imprime_vetor(const int* v, size_t t) {
    int i;
    for (i=0; i<t; ++i) {
        printf("%d ", v[i]);
    }
    putchar('\n');
}

void imprime_matriz_quadrada(size_t t, const int m[t][t]) {
    int i, j;
    for (i=0; i<t; ++i) {
        for (j=0; j<t; ++j) {
            printf("%2d ", m[i][j]);
        }
        putchar('\n');
    }
}

