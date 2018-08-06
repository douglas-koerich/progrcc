#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/*
#define n   5   // 1a. versao: n eh um numero fixo de valores
                // 2a. versao: n eh uma quantidade de elementos escolhida pelo usuario
*/

// Prototipos das funcoes que vao operar sobre um vetor passado como parametro!!
float calculaMedia(int [*], size_t);            // precisa passar o vetor E O SEU TAMANHO (a declaracao ficou na chamada)
float calculaDesvioMedio(int [], size_t, float);// pode deixar sem o *; size_t eh um tipo de variavel usada pra tamanhos
float calculaDesvioPadrao(int vetor[*], size_t tamanho, float media);

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
    
    /*
    // x-"barra" eh a media aritmetica dos valores (soma dividida pelo
    // tamanho do conjunto)
    float x_barra, soma;
    for (i=1, soma=0.0; i<=n; ++i) {
        soma += x[i-1]; // vai somando no total x1, x2, x3, ..., ateh xn
    }
    x_barra = soma / n;
    */
    float x_barra = calculaMedia(x, n); // passa apenas o NOME da variavel-vetor!!!

    /*
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
    */
    float DM = calculaDesvioMedio(x, n, x_barra);

    /*
    // Calculo do desvio padrao
    for (i=1, soma=0.0; i<=n; ++i) {
        // Como vai elevar ao quadrado, nao precisa deduzir o maior,
        // porque vai resultar em positivo de qualquer maneira...
        soma += pow(x[i-1] - x_barra, 2);
    }
    float sigma = sqrt(soma / (n-1));
    */
    float sigma = calculaDesvioPadrao(x, n, x_barra);

    // Impressao dos valores
    printf("Media aritmetica (x-\"barra\") = %f\n", x_barra);
    printf("Desvio medio (DM) = %f\n", DM);
    printf("Desvio padrao (sigma) = %f\n", sigma);

    return EXIT_SUCCESS;
}

// Sempre, sempre, sempre, sempre... passar o tamanho do vetor como um
// parametro adicional, pois a funcao pode fazer o calculo da media para
// qualquer vetor (com qualquer tamanho, basta informa-lo no argumento)!
float calculaMedia(int v[], size_t t) {   // remova o * usado no prototipo!!
    float x_barra, soma;
    int i;
    for (i=1, soma=0.0; i<=t; ++i) {
        soma += v[i-1]; // vai somando no total v1, v2, v3, ..., ateh vt
    }
    x_barra = soma / t;
    return x_barra;
}

float calculaDesvioMedio(int v[], size_t t, float m) {
    float soma;
    int i;
    for (i=1, soma=0.0; i<=t; ++i) {
        soma += abs(m - v[i-1]);    // abs() = modulo (numero sem sinal)
    }
    float DM = soma / t;
    return DM;
}

float calculaDesvioPadrao(int v[], size_t t, float m) {
    int i;
    float soma;
    for (i=1, soma=0.0; i<=t; ++i) {
        soma += pow(v[i-1] - m, 2);
    }
    float sigma = sqrt(soma / (t-1));
    return sigma;
}
