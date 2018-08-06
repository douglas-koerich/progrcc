#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

bool testa_primo(int);

int main() {
    int n;
    printf("Digite um numero para teste: ");
    scanf("%d", &n);

    // Usa o retorno da funcao como V/F do 'if'
    if (testa_primo(n)) {
        printf("O numero eh primo!\n");
    } else {
        printf("O numero nao eh primo!\n");
    }
    return EXIT_SUCCESS;
}

bool testa_primo(int x) {
    int inter;
    for (inter = 2; inter < x; ++inter) {
        if (x % inter == 0) {
            return false;
        }
    }
    // Se chegou ateh aqui, nao houve 'inter' que fosse divisor de 'x' (se houvesse,
    // teria saido pelo 'return' que estah dentro do 'if')
    return true;
}
