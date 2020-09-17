#include <stdlib.h>
#include <stdio.h>

int main() {
    int x;
    printf("Digite o numero do qual deseja imprimir a tabuada: ");
    scanf("%d", &x);

    int fator = 1;
    while (fator <= 10) {
        printf("%2d x %2d = %3d\n", x, fator, x * fator);
        ++fator; // fator = fator + 1 (fator += 1)
    }
    return EXIT_SUCCESS;
}