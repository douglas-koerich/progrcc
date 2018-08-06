#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/*
#define n   5   // 1a. versao: n eh um numero fixo de valores
                // 2a. versao: n eh uma quantidade de elementos escolhida pelo usuario
*/

int main(void) {
    // Para a 2a. versao, eh necessario ler o valor de n ANTES de declarar
    // o vetor (com um tamanho "variavel", i.e., definido durante a execucao)
    int n;
    printf("Digite o numero de elementos do conjunto (n): ");
    scanf("%d", &n);

    // Eh necessario um vetor para armazenar o conjunto de elementos
    // (nao eh possivel fazer os calculos a medida que os valores sao lidos)
    int x[n];   // conjunto X formado por x1, x2, x3, ..., xn

    // Primeira etapa: ler os valores do conjunto
    // Uma mesma operacao feita sobre varios (ou todos os) elementos do
    // vetor requer o uso de um laco pra repetir tal operacao
    int i;  // variavel para o indice e tambem como contadora do laco
    for (i=1; i<=n; ++i) {
        printf("Digite o valor de x%d: ", i);
        scanf("%d", &x[i-1]);   // x1 eh x[0], x2 eh x[1] e assim por diante
    }
    // Ou entao, faria um laco assim: for (i=0; i<n; ++i), mudando para
    // printf(..., i+1) e scanf(..., &x[i])
    
    // x-"barra" eh a media aritmetica dos valores (soma dividida pelo
    // tamanho do conjunto)
    float x_barra, soma;
    for (i=1, soma=0.0; i<=n; ++i) {
        soma += x[i-1]; // vai somando no total x1, x2, x3, ..., ateh xn
    }
    x_barra = soma / n;

    // Calculo do desvio medio
    for (i=1, soma=0.0; i<=n; ++i) {
        if (x_barra > x[i-1]) {
            soma += x_barra - x[i-1];
        }
        else {
            soma += x[i-1] - x_barra;
        }
        // Poderia ser escrito assim tambem:
        // soma += (x_barra > x[i-1])? (x_barra - x[i-1]): (x[i-1] - x_barra);
    }
    float DM = soma / n;

    // Calculo do desvio padrao
    for (i=1, soma=0.0; i<=n; ++i) {
        // Como vai elevar ao quadrado, nao precisa deduzir o maior,
        // porque vai resultar em positivo de qualquer maneira...
        soma += pow(x[i-1] - x_barra, 2);
    }
    float sigma = sqrt(soma / (n-1));

    // Impressao dos valores
    printf("Media aritmetica (x-\"barra\") = %f\n", x_barra);
    printf("Desvio medio (DM) = %f\n", DM);
    printf("Desvio padrao (sigma) = %f\n", sigma);

    return EXIT_SUCCESS;
}

