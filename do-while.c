#include <stdlib.h>
#include <stdio.h>

int main() {
    float altura;
    char genero;

    do {
        printf("Digite a sua altura (m): ");
        scanf("%f", &altura);
    } while (altura < 0.3 || altura > 2.4);

    /* Uma alternativa (nao muito boa) para o do-while
    altura = 0.0;
    while (altura < 0.3 || altura > 2.4) {
        printf("Digite a sua altura (m): ");
        scanf("%f", &altura);
    }
    */

    do {
        printf("Digite o genero (M/F): ");
        scanf(" %c", &genero);
    } while (genero != 'm' && genero != 'M' &&
             genero != 'f' && genero != 'F');

    float peso_ideal;
    if (genero == 'm' || genero == 'M') {
        peso_ideal = 72.7 * altura - 58;
    } else {
        peso_ideal = 62.1 * altura - 44.7;
    }
    printf("Seu peso ideal eh %.1f kg.\n", peso_ideal);

    return EXIT_SUCCESS;
}

