#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main() {
    double num1, num2;
    int escolha;

    printf("Digite o 1o. numero: ");
    scanf("%lf", &num1);
    printf("Digite o 2o. numero: ");
    scanf("%lf", &num2);

    printf("Qual operacao deseja realizar (1-4)? ");
    scanf("%d", &escolha);

    switch (escolha) {
        case 1: {
            double media;
            media = (num1 + num2) / 2;
            printf("A media dos numeros eh %lf.\n", media);
            break;

            // A variavel 'media' eh DESTRUIDA ao sair do
            // bloco {} deste case
        }
        case 2: {
            double diff;
            /*
            if (num1 > num2) {
                diff = num1 - num2;
            } else {
                diff = num2 - num1;
            }
            */
            // diff = fabs(num1 - num2); // nao importando quem eh maior

            // Operador ternario de decisao (equivalente ao if-else acima)
            diff = (num1 > num2)? num1 - num2: num2 - num1;
            printf("A diferenca entre os numeros eh %lf.\n", diff);
            break;
        }
        case 3:
            printf("O produto entre os numeros eh %lf.\n", num1 * num2);
            break;

        case 4:
            if (num2 == 0.0) {
                printf("A divisao nao pode ser feita!\n");
            } else {
                double quoc = num1 / num2; // divisao real, SEM resto!
                printf("A divisao entre os numeros eh %lf.\n", quoc);
            }
            break;

        default: // Escolha invalida!
            printf("Escolha %d INVALIDA!\n", escolha);
            return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

