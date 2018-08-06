#include <stdlib.h>
#include <stdio.h>

// "Declaracao" da funcao: PROTOTIPO
int fatorial(int);  // "assinatura" da funcao

int permutacao(int);
int arranjo(int, int);
int combinacao(int, int);

int main() {
    float P, Y;
    int n;
    
    printf("Digite o valor de Y: ");
    scanf("%f", &Y);
    printf("Quantos termos serao usados? ");
    scanf("%d", &n);

    int i;
    for (i = 1, P = 1.0; i <= n; ++i) {
        /*
        int F, j;
        for (j = F = 1; j <= (i - 1); ++j) {
            F = F * j;  // F *= j;
        }
        */
        // Esta variavel F ***NAO*** eh a mesma variavel daquela dentro da
        // funcao 'fatorial'
        int F = fatorial(i-1);  // chamada (desvio para) a funcao
        P = P * Y / F;  // P *= Y/F;
    }

    printf("O produtorio resulta %f.\n", P);

    int p;
    int P_, C, A;

    printf("Vamos brincar de analise combinatoria?\n");
    printf("Quantos elementos ha no conjunto? ");
    scanf("%d", &n);
    printf("Quantos elementos havera em cada disposicao (de arranjo ou combinacao)? ");
    scanf("%d", &p);
    /*
    P_ = fatorial(n);
    A = fatorial(n) / fatorial(n-p);
    C = fatorial(n) / (fatorial(n-p) * fatorial(p));
    printf("P = %d\n", P_);
    printf("A = %d\n", A);
    printf("C = %d\n", C);
    */
    printf("P = %d\n", permutacao(n));
    printf("A = %d\n", arranjo(n, p));
    printf("C = %d\n", combinacao(n, p));

    return EXIT_SUCCESS;
}

// Definicao da funcao: IMPLEMENTACAO
int fatorial(int numero) {
    if (numero < 0) {
        return 0;   // nao posso calcular...
    }
    int F, j;
    for (j = F = 1; j <= numero; ++j) {
        F = F * j;  // F *= j;
    }
    return F;
}

int permutacao(int n) {
    /*
    int P = fatorial(n);
    return P;
    */
    return fatorial(n);
}

int arranjo(int n, int p) {
    int num = fatorial(n);
    int den = fatorial(n-p);
    return num / den;
}

int combinacao(int n, int p) {
    return fatorial(n) / (fatorial(n-p) * fatorial(p));
}

