#include <stdlib.h> // size_t eh um tipo inteiro usado para qtdes./tamanhos
#include <stdio.h>
#include <math.h>

#define TAM 10   // nao tem ponto-e-virgula em comandos do pre-processador

float dm(int [*], size_t);  // 1o. parametro -> vetor; 2o. param -> tamanho
float dp(int [*], size_t);
float media(int [*], size_t);   // usada por dm() e por dp(), nao por main()

int main() {
    int vetor[TAM], i;

    for (i=0; i<TAM; ++i) {
        vetor[i] = i;
    }

    // Vou imprimir o desvio medio que retorna diretamente da funcao dm()
    printf("O desvio medio do conjunto eh %.3f\n", dm(vetor, TAM));

    // Idem para o desvio padrao, vindo da funcao dp()
    printf("O desvio padrao do conjunto eh %.3f\n", dp(vetor, TAM));

    return 0;
}

// Modularizacao de algoritmos: nao repete o laco de calculo da media nas
// funcoes dm() e dp()
float media(int x[], size_t n) {
    float soma = 0.0;
    int i;
    for (i=0; i<n; ++i) {
        soma += x[i];
    }
    return soma / n;
}

float dm(int x[], size_t n) {   // sem asterisco nos colchetes
    float x_barra = media(x, n);    // passa o vetor e tamanho recebidos
                                    // para media() calcular o x_barra
    float soma = 0.0;
    int i;
    for (i=0; i<n; ++i) {
        // Ao inves de usar uma funcao que calcula o modulo da diferenca,
        // fazemos a subtracao analisando quem eh o maior entre os valores
        if (x[i] > x_barra) {
            soma += (x[i] - x_barra);   // parenteses apenas para visualizar
        }
        else {
            soma += x_barra - x[i];
        }
    }
    return soma / n;
}

float dp(int x[], size_t n) {
    float x_barra = media(x, n), sigma, soma = 0.0;
    int i;
    for (i=0; i<n; ++i) {
        // dif eh uma variavel LOCAL AO LACO for(); todas as vezes que um
        // novo passo do laco inicia a variavel eh recriada na memoria
        float dif = x[i] - x_barra;
        soma += pow(dif, 2);
    }
    sigma = sqrt(soma / (n-1));
    return sigma;
}

