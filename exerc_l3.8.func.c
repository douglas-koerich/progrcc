/*
=== Enunciado adaptado ===
"Supondo que a populacao de um pais A seja da ordem de X milhoes de
habitantes, com uma taxa anual de crescimento de x% e que a população de
um pais B seja de Y milhoes de habitantes com uma taxa anual de crescimento
de y%, desenvolva uma funcao em C que calcule e retorne o numero de anos
necessarios para que o pais menos populoso ultrapasse ou iguale o pais mais
populoso, mantidas suas taxas de crescimento.
"ATENCAO: analise as taxas de crescimento em relacao as populacoes para que
nao aconteca de calcular //infinito// para o numero de anos!"
*/

#include <stdlib.h>
#include <stdio.h>

unsigned calcula_anos(unsigned X, float x, unsigned Y, float y);

int main(void) {
    unsigned populacao_A, populacao_B;
    float taxa_A, taxa_B;

    printf("Informe a populacao atual de A: ");
    scanf("%u", &populacao_A);
    printf("Qual a taxa de crescimento anual de A? ");
    scanf("%f", &taxa_A);

    printf("Agora, informe a populacao atual de B: ");
    scanf("%u", &populacao_B);
    printf("A que taxa B cresce anualmente? ");
    scanf("%f", &taxa_B);

    unsigned anos = calcula_anos(populacao_A, taxa_A, populacao_B, taxa_B);
    if (anos > 0) {
        printf("Passar-se-ao %u anos ateh que o pais menos "    // quebra de string
               "populoso ultrapasse o mais populoso.\n", anos); // entre linhas NO CODIGO
    }                                                           // (NAO NA TELA!!!)
    return EXIT_SUCCESS;
}

unsigned calcula_anos(unsigned X, float x, unsigned Y, float y) {
    // Verifica se um pais nao tem como atingir o outro
    if ((X < Y && x < y) || (X > Y && x > y)) {
        printf("O pais menos populoso NUNCA atingira o mais populoso!\n");
        return 0;
    }
    // Define quem eh o pais menor com a sua taxa pra comparar com o maior
    unsigned menor = X, maior = Y;
    float taxa_m = x, taxa_M = y;
    if (menor > Y) {
        menor = Y;
        taxa_m = y;
        maior = X;
        taxa_M = x;
    }
    unsigned anos = 0;
    while (menor < maior) {
        menor = menor * (1 + taxa_m/100);
        maior = maior * (1 + taxa_M/100);
        ++anos;
    }
    return anos;
}

