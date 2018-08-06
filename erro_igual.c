#include <stdlib.h>
#include <stdio.h>

int main() {
    int dividendo, divisor, quociente;

    printf("Digite o valor do dividendo: ");
    scanf("%d", &dividendo);

    printf("Agora, forneca o divisor: ");
    scanf("%d", &divisor);

    if (divisor = 0) {  // atribuir 0 a 'divisor' faz if() usar 'divisor' como
                        // "teste": em C, valor ZERO eh considerado "falso", o
                        // que faz pular para o else... :-(
        printf("Nao eh possivel dividir por ZERO!\n");
        return EXIT_FAILURE;
    } else {
        quociente = dividendo / divisor;
    }

    printf("O quociente eh %d.\n", quociente);

    return EXIT_SUCCESS;
}
