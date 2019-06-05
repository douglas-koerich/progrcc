#include <stdlib.h>
#include <stdio.h>

void troca(int*, int*);

int main(void) {
    printf("Digite um primeiro valor (x): ");
    int x;
    scanf("%d", &x);

    printf("Digite um segundo valor (y): ");
    int y;
    int* p = &y;
    scanf("%d", p); // aqui eh ERRADO(!) por o & na frente

    troca(&x, p); // passa os ENDERECOS das variaveis

    printf("Agora x = %d, y = %d\n", x, y);
    return EXIT_SUCCESS;
}

void troca(int* a, int* b) {
    int c = *a; // c recebe o valor "no endereco" a
    *a = *b; // o endereco a passa a conter o que estah contido no endereco b
    *b = c;
}

