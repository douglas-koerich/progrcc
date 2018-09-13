#include <stdlib.h>
#include <stdio.h>

double calcula_fatorial(int n) {
    if (n < 0) {
        return 0; // sai da funcao nesta linha
    }
    int x;
    double fatorial;
    for (x=1, fatorial=1.0; x<=n; ++x) {
        fatorial *= x;
    }
    return fatorial;
}

int main() {
    printf("Digite o total de numeros: ");
    int n;
    scanf("%d", &n);

    printf("Digite o tamanho do grupo de numeros: ");
    int p;
    scanf("%d", &p);

    double fat_n = calcula_fatorial(n);
    double fat_p = calcula_fatorial(p);
    double fat_n_menos_p = calcula_fatorial(n-p);

    int C = fat_n / (fat_n_menos_p * fat_p);
    printf("A chance de acerto eh 1 em %d combinacoes\n", C);

    return EXIT_SUCCESS;
}

