#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define TAM 20

void maior_menor(int [*], size_t, int*, int*);
// void maior_menor(int*, size_t, int*, int*);

int main() {
    srand((unsigned) time(0));

    int vetor[TAM], i;

    puts("Vetor gerado:");
    for (i=0; i<TAM; ++i) {
        vetor[i] = rand() % 1000;   // 0 a 999
        printf("%d ", vetor[i]);
    }
    putchar('\n');  // putchar() imprime um caracter <=> printf("%c")

    int maior, menor;
    maior_menor(vetor, TAM, &maior, &menor);
    // Nesta chamada, o ponteiro-parametro pmaior recebe o endereco da
    // variavel maior, como se acontecesse assim:
    // int* pmaior = &maior;

    printf("Maior valor=%d, menor=%d\n", maior, menor);

    return 0;
}

void maior_menor(int vet[], size_t tam, int* pmaior, int* pmenor) {
//void maior_menor(int* vet, size_t tam, int* pmaior, int* pmenor) {
    int M  = vet[0], m = vet[0], i;
    /* VERSAO ORIGINAL SEM PONTEIROS
    for (i=0; i<tam; ++i) {
        if (vet[i] > M) {
            M = vet[i];
        }
        if (vet[i] < m) {
            m = vet[i];
        }
    }
    */
    /* UM PONTEIRO AUXILIAR, PORQUE GOSTEI DE USAR PONTEIRO!! ;-)
    for (i=0; i<tam; ++i) {
        int *p = &vet[i];
        if (*p > M) {
            M = *p;
        }
        if (*p < m) {
            m = *p;
        }
    }
    */
    /* NAVEGANDO PELO VETOR USANDO ARITMETICA DE PONTEIRO, MUDANDO-O!
    int *p;
    for (i=0, p=&vet[0]; i<tam; ++i, ++p) {
        if (*p > M) {
            M = *p;
        }
        if (*p < m) {
            m = *p;
        }
    }
    */
    /* NAVEGANDO PELO VETOR USANDO ARITMETICA DE PONTEIRO, SEM MUDA-LO!
    int *p;
    for (i=0, p=&vet[0]; i<tam; ++i) {
        if (*(p+i) > M) {
            M = *(p+i);
        }
        if (*(p+i) < m) {
            m = *(p+i);
        }
    }
    */
    /*
     * +-----------------------------------------------------------+
     * | "O nome da variavel-vetor (sem colchetes) eh visto pelo   |
     * | compilador como o endereco do primeiro elemento do vetor. |
     * | Nesse caso, a variavel comporta-se como um ponteiro, mas  |
     * | que nao pode ser associado a outros enderecos."           |
     * |              vetor eh equivalente a &vetor[0]             |
     * | De modo geral:                                            |
     * |    (vetor + i) eh equivalente a &vetor[i]                 |
     * |    *(vetor + i) equivale a vetor[i]                       |
     * +-----------------------------------------------------------+
     */
    /* NAVEGANDO PELO VETOR USANDO ARITMETICA APLICADA AO PROPRIO VETOR
     * (NAO EH POSSIVEL FAZER ++vet, OU ALGO PARECIDO, PORQUE vet NAO SE
     * ALTERA!)
    for (i=0; i<tam; ++i) {
        if (*(vet+i) > M) {
            M = *(vet+i);
        }
        if (*(vet+i) < m) {
            m = *(vet+i);
        }
    }
    */
    /* NAVEGANDO PELO VETOR USANDO PONTEIRO, INDEXANDO-O! */
    int *p;
    for (i=0, p=vet; i<tam; ++i) {
        if (p[i] > M) {
            M = p[i];
        }
        if (p[i] < m) {
            m = p[i];
        }
    }

    *pmaior = M;
    *pmenor = m;
}

