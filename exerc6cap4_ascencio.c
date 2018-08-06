#include <stdlib.h>
#include <stdio.h>

int main() {
    int num, r;
    printf("Digite um numero: ");
    scanf("%d", &num);
    r = num % 2;
    if (r = 0) {   // if (!r) {
        printf("O numero eh par\n");
    } else {
        printf("O numero eh impar\n");
    }
    return EXIT_SUCCESS;
}
