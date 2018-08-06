#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    int n;
    printf("Digite um numero para teste: ");
    scanf("%d", &n);

    int inter;
    bool ehPrimo = true;    // inicializa assumindo que eh primo
    for (inter = 2; inter < n; ++inter) {
        if (n % inter == 0) {
            printf("Eh divisivel por %d, NAO eh primo!\n", inter);
            ehPrimo = false;    // o teste desmentiu a premissa/hipotese
            break;  // nao faz sentido continuar testando numeros maiores
        }
    }
    if (ehPrimo == true) {
        printf("O numero eh primo!\n");
    }

    return EXIT_SUCCESS;
}
