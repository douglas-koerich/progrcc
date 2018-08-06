#include <stdlib.h>
#include <stdio.h>

int main() {
    int n1, n2;
    printf("Digite o primeiro numero: ");
    scanf("%d", &n1);
    printf("Digite o segundo numero: ");
    scanf("%d", &n2);

    int opcao;
    printf("Operacao desejada:\n");
    printf("1 - Media\n");
    printf("2 - Diferenca do maior pelo menor\n");
    printf("3 - Produto\n");
    printf("4 - Divisao do primeiro pelo segundo\n");
    printf("#> ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1: {
            float media = (n1 + n2) / 2.0;
            printf("A media eh %f.\n", media);
            break;
        }
        case 2: {
            /*
            int diferenca;
            if (n1 > n2) {
                diferenca = n1 - n2;
            } else {
                diferenca = n2 - n1;
            }
            */
            int diferenca = n1 > n2? n1 - n2: n2 - n1;
            printf("A diferenca entre os numeros eh %d.\n", diferenca);
            break;
        }
        case 3:
            printf("O produto eh %d.\n", n1 * n2);
            break;

        case 4:
            // if (n2 == 0) {
            if (0 == n2) {  // notacao Yoda
                printf("Nao eh possivel dividir por zero!\n");
                return EXIT_FAILURE;
            }
            printf("A divisao eh %f.\n", (float) n1 / n2);
            break;

        default:    // outras opcoes
            printf("Opcao INVALIDA!\n");
            return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
