#include <stdlib.h>
#include <stdio.h>

// "Prototipo" da funcao: declaracao da nova funcao ANTES do seu primeiro uso (chamada)
int fatorial(int); // apenas o(s) tipo(s) do(s) parametro(s); nao esqueca o ponto-e-virgula

int combinacao(int, int);
int arranjo(int, int);

int main() {
    int n;
    printf("Digite o tamanho do conjunto: ");
    scanf("%d", &n);

    int f;
    f = fatorial(n);

    int p;
    printf("Digite o tamanho de cada tupla formada a partir do conjunto: ");
    scanf("%d", &p);

    printf("O numero de permutacoes (variantes de ordem) do conjunto eh %d.\n", f);
    printf("O numero de combinacoes do conjunto em tuplas eh %d.\n", combinacao(n, p));
    printf("O numero de arranjos do conjunto em tuplas eh %d.\n", arranjo(n, p));

    return EXIT_SUCCESS;
}

// Definicao da nova funcao 'fatorial' (codigo do seu algoritmo)
int fatorial(int n) { // esta declaracao de 'n' nao tem a ver com a
                      // variavel 'n' que existe na funcao main()
    if (n == 0) {
        return 1; // sai da funcao neste ponto, devolvendo um valor constante (1)
    }
    int fat;
    for (fat = 1; n > 0; --n) { // NENHUMA alteracao no 'n' local tem
                                // efeito na variavel 'n' em main()!
        fat = fat * n; // fat *= n;
    }
    // Ao fim do laco, 'fat' tem o valor calculado de n!
    return fat;
}

int combinacao(int elementos, int tupla) {
    int numerador = fatorial(elementos);
    int denominador = fatorial(elementos-tupla) * fatorial(tupla);
    int c = numerador / denominador;
    return c;
}

int arranjo(int n, int p) {
    return fatorial(n) / fatorial(n-p);
}

