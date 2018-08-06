#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

bool ehPrimo(int);

#define MAX 9   // Permite que o vetor seja redimensionado (porem eh sempre bom conferir)

int main(void) {
    // int n = 1; /* variavel escalar */
    // int lista[MAX] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };      // inicializacao completa
    // int lista[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };         // inicializacao completa de um vetor de 9 posicoes (equivale a anterior)
    // int lista[MAX] = { 1, 2, 3 };                        // inicializacao parcial
    // int lista[] = { 1, 2, 3 };                           // inicializacao COMPLETA de um vetor de 3 posicoes (NAO equivale a anterior)
    // int lista[MAX];                                      // nao inicializado (valores desconhecidos)
    // int lista[MAX] = { 0 };                              // inicializacao com zeros
    int lista[MAX] = { 1, 2, 3, [6] = 10, [MAX-1] = 20 };   // inicializacoes "salteadas"

    // int lista[MAX] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };  // "estouro" da capacidade do vetor
                                                            // A linguagem C NAO IMPEDE essa condicao, mas ela tem riscos!!!

    printf("O numero de elementos do vetor criado eh %zd.\n", sizeof(lista)/sizeof(int));

    // Para percorrer/transitar o vetor, precisa de um laco
    int posicao;
    for (posicao = 0; posicao < MAX; ++posicao) {
        printf("Digite um numero para a posicao %d: ", posicao);
        scanf("%d", &lista[posicao]);   // nao basta o nome da variavel, precisa dizer qual dos elementos na lista (no vetor)
    }
    printf("O ultimo valor armazenado no vetor eh %d.\n", lista[MAX-1]);    // indexacao: acesso a um valor especifico
    for (posicao = 0; posicao < MAX; ++posicao) {
        if (ehPrimo(lista[posicao])) {  // passa o valor "da vez" indicado pela posicao (indice no vetor)
            printf("O numero %d eh primo na posicao %d!\n", lista[posicao], posicao);
        }
    }
    return EXIT_SUCCESS;
}

// Definicao de MACRO em C (nao eh o mesmo que funcao, eh uma simples substituicao)
#define EH_DIVISIVEL(a, b) (a % b == 0)

bool ehPrimo(int n) {
    int i;
    for (i=2; i<n; ++i) {
        // if (n % i == 0) {
        if (EH_DIVISIVEL(n, i)) {
            return false;
        }
    }
    return true;
}
