#include <stdlib.h>
#include <stdio.h>

#define NUM_ELEMENTOS   15  // SEM ponto-e-virgula (nao eh para o compilador, eh para o pre-processador)

int main(void) {
    int x;                  // variavel escalar
    int y[NUM_ELEMENTOS];   // variavel vetor

    printf("O tamanho do vetor na memoria eh %zd bytes.\n", sizeof(y));

    x = 10;     // atribuicao a escalar
    y[0] = 10;  // atribuicao a vetor baseado no indice (inicial = 0)
    y[1] = 3;   // acesso ao elemento eh feito pelo operador [] (indexacao)
    y[2] = -1;
    y[3] = 12;

    // Demais posicoes serao preenchidas atraves de um laco
    int i;
    for (i=4; i<NUM_ELEMENTOS; ++i) {  // comeca com i=4 porque eh a posicao seguinte aquelas que foram preenchidas acima
        printf("Digite o valor para a posicao(indice) %d: ", i);
        scanf("%d", &y[i]); // vai percorrendo o laco usando a variavel-indice que tambem controla o fim do laco
    }

    printf("Digite um novo valor para o primeiro elemento do vetor: ");
    scanf("%d", &y[0]);
    printf("Os quatro primeiros numeros armazenados no vetor sao: %d, %d, %d e %d.\n",
           y[0], y[1], y[2], y[3]);

    printf("Imprimindo todo o vetor: ");
    for (i=0; i<NUM_ELEMENTOS; ++i) {
        printf("%d ", y[i]);
    }
    printf("\n");   // pra nao "colar" com o prompt do terminal na volta do programa...

    return EXIT_SUCCESS;
}
