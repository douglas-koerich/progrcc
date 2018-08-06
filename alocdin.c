#include <stdlib.h>
#include <stdio.h>

#define TAMANHO 20

// Variavel global, precisa ter um tamanho pre-definido ("em tempo de compilacao")
int vetor_global[TAMANHO];  // inicializada automaticamente com zeros

int main(void) {
    // Variavel local, tambem com tamanho pre-definido
    int vetor_local[TAMANHO];   // nao existe pre-inicializacao (conteudo indefinido)

    int tamanho = TAMANHO/2;    // Poderia ser um tamanho digitado pelo usuario
    // Outra variavel local, agora com tamanho definido durante a execucao do programa
    int vetor_local_[tamanho];

    // "Variavel" alocada dinamicamente, com tamanho fixo ou digitado pelo usuario
    int* vetor_alocado = (int*) malloc(tamanho * sizeof(int)); // passa o total de BYTES!!!

    // Preenche o vetor global
    int i;
    for (i=0; i<TAMANHO; ++i) {
        vetor_global[i] = rand() % 1000;
    }

    // Copio para os vetores locais
    for (i=0; i<TAMANHO; ++i) {
        vetor_local[i] = vetor_global[i];
    }
    int menor_tam = tamanho < TAMANHO? tamanho: TAMANHO;    // usa como limite do laco
                                                            // o menor valor entre os dois
    for (i=0; i<menor_tam; ++i) { // pode ser que tamanho < TAMANHO
        vetor_local_[i] = vetor_global[i];
    }

    // Copio do vetor global para o vetor alocado
    for (i=0; i<menor_tam; ++i) {
        //*(vetor_alocado+i) = vetor_global[i];   // usando vetor_alocado como ele eh (um ponteiro)
        vetor_alocado[i] = vetor_global[i];       // usando o ponteiro como se fosse um vetor
    }

    for (i=0; i<TAMANHO; ++i) {
        printf("%d ", vetor_global[i]);
    }
    putchar('\n');
    for (i=0; i<TAMANHO; ++i) {
        printf("%d ", vetor_local[i]);
    }
    putchar('\n');
    for (i=0; i<menor_tam; ++i) {
        printf("%d ", vetor_local_[i]);
    }
    putchar('\n');
    for (i=0; i<menor_tam; ++i) {
        printf("%d ", vetor_alocado[i]);
    }
    putchar('\n');

    // Ao inves de variaveis comuns que nao podem ter seu tamanho alterado
    // apos a criacao, uma "variavel" alocada dinamicamente (no caso de ser vetor)
    // pode ser "esticada" ou "encolhida" usando realloc()
    vetor_alocado = (int*) realloc(vetor_alocado, sizeof(int) * tamanho/2);
    for (i=0; i<tamanho/2; ++i) {
        printf("%d ", vetor_alocado[i]);
    }
    putchar('\n');

    // Ao contrario das variaveis comuns, eh responsabilidade do programador
    // chamar o sistema operacional para liberar a memoria alocada
    free(vetor_alocado);    // tem que ser o ponteiro com o conteudo (endereco)
                            // recebido do malloc (ou alterado pelo realloc)

    return EXIT_SUCCESS;
}
