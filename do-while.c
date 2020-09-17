#include <stdlib.h>
#include <stdio.h>

/* Gera e imprime numeros randomicos (aleatorios) ateh que o
   numero gerado seja multiplo de 7

#include <time.h>

int main() {
    srand(time(0));
    int num;
    do {
        num = rand() % 100 + 1; // numero sorteado de 1 a 100
        printf("%d\n", num);
    } while (num % 7 != 0);
    return EXIT_SUCCESS;
}

*/

/* Faca um programa que receba a altura e o sexo de uma pessoa e que calcule e mostre
o seu peso ideal, utilizando as seguintes formulas:
a) para homens: (72,7 x altura) – 58
b) para mulheres: (62,1 x altura) – 44,7
*/

#include <ctype.h>

int main() {
    float altura;
    char genero;

    printf("Digite a sua altura: ");
    scanf("%f", &altura);

    do {
        printf("Informe o seu genero (M/F): ");
        scanf(" %c", &genero);
        genero = toupper(genero);
    } while (genero != 'M' && genero != 'F');

    float peso_ideal;
    if (genero == 'M') {
        peso_ideal = 72.7 * altura - 58;
    } else {
        peso_ideal = 62.1 * altura - 44.7;
    }

    printf("O seu peso ideal eh %f\n", peso_ideal);

    return EXIT_SUCCESS;
}