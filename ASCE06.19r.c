#include <stdlib.h>
#include <stdio.h>
#ifndef WINDOWS // se NAO for Windows
#include <stdio_ext.h>
#endif

#define TAM_VETOR 5

void limpa_buffer_teclado(void);
void imprime_vetor(const char [*], size_t); // com ou sem asterisco dentro dos colchetes
void preenche_vetor(char [*], size_t);

int main(void) {
    // const int TAM_VETOR = 20;
    char A[TAM_VETOR], B[TAM_VETOR]; // conjuntos de caracteres ASCII

    // Preenche os vetores
    int i;
    puts("Conteudo do vetor A"); // salto de linha (\n) eh automatico
    preenche_vetor(A, TAM_VETOR); // na chamada da funcao, passa como parametro
                                  // SOMENTE o nome do vetor (A, no caso)
    puts("Conteudo do vetor B");
    preenche_vetor(B, TAM_VETOR);
    imprime_vetor(A, TAM_VETOR);
    imprime_vetor(B, TAM_VETOR);

    int j;
    for (i=0, j=TAM_VETOR-1; i<TAM_VETOR; ++i, --j) { // a medida que i avanca em A,
                                                      // j retrocede no vetor B
        char temp = A[i];
        A[i] = B[j];
        B[j] = temp;
    }
    imprime_vetor(A, TAM_VETOR);
    imprime_vetor(B, TAM_VETOR);

    return EXIT_SUCCESS;
}

void limpa_buffer_teclado(void) {
#ifdef WINDOWS // lembre-se de colocar essa opcao no compilador Windows
    fflush(stdin);
#else
    __fpurge(stdin);
#endif
}

void imprime_vetor(const char V[], size_t tam) { // aqui SEM o asterisco dentro!
    int t;
    for (t=0; t<tam; ++t) {
        putchar(V[t]); // funcao que imprime um caractere isolado
    }
    putchar('\n');
}

void preenche_vetor(char X[], size_t x) {
    int i;
    for (i=0; i<x; ++i) {
        printf("Digite um caractere para a posicao %d: ", i);
        limpa_buffer_teclado();
        X[i] = getchar(); // funcao para leitura de um caractere
    }
}

