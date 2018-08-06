#include <stdlib.h>
#include <stdio.h>

int main() {
    int idade;

    printf("Digite a idade do nadador: ");
    scanf("%d", &idade);

    // Teste: 5 <= idade <= 7
    // idade >= 5 e idade <= 7
    if (idade >= 5 && idade <= 7) {
        printf("Infantil A\n");
    }
    else {
        if (idade >= 8 && idade <= 10) {
            printf("Infantil B\n");
        }
        else {
            if (idade >= 11 && idade <= 13) {
                printf("Juvenil A\n");
            }
            else {
                if (idade >= 14 && idade <= 17) {
                    printf("Juvenil B\n");
                }
                else {
                    if (idade >= 18) {
                        printf("Adulto\n");
                    }
                    else {
                        // Menores que 5
                        printf("INVALIDO\n");
                    }
                }
            }
        }
    }
    /*
    // Como a unica operacao feita dentro de cada else eh um novo if-else, pode-se
    // fazer isto:
    if (idade >= 5 && idade <= 7) {
        printf("Infantil A\n");
    }
    else if (idade >= 8 && idade <= 10) {
        printf("Infantil B\n");
    }
    else if (idade >= 11 && idade <= 13) {
        printf("Juvenil A\n");
    }
    else if (idade >= 14 && idade <= 17) {
        printf("Juvenil B\n");
    }
    else if (idade >= 18) {
        printf("Adulto\n");
    }
    else {
        // Menores que 5
        printf("INVALIDO\n");
    }
    */

    /*
    // Como os testes sao mutuamente exclusivos, i.e., a mesma variavel nao poderia
    // dar verdadeiro para diferentes faixas, podemos simplificar assim:
    if (idade < 5) {
        printf("INVALIDO\n");
    }
    else if (idade <= 7)
        printf("Infantil A\n");
    }
    else if (idade <= 10) {
        printf("Infantil B\n");
    }
    else if (idade <= 13) {
        printf("Juvenil A\n");
    }
    else if (idade <= 17) {
        printf("Juvenil B\n");
    }
    else {
        printf("Adulto\n");
    }
    */
    return EXIT_SUCCESS;
}
