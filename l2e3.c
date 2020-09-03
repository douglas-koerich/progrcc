#include <stdlib.h>
#include <stdio.h>

int main() {
    int idade;
    printf("Digite a idade do(a) nadador(a): ");
    scanf("%d", &idade);

    if (idade >= 5 && idade <= 7) {
        printf("Infantil A\n");
    } else { // todas as outras faixas
        if (idade >= 8 && idade <= 10) {
            printf("Infantil B\n");
        } else {
            if (idade >= 11 && idade <= 13) {
                printf("Juvenil A\n");
            } else {
                if (idade >= 14 && idade <= 17) {
                    printf("Juvenil B\n");
                } else {
                    // A linha/faixa etaria restante
                    printf("Adulto");
                }
            }
        }
    }
    return EXIT_SUCCESS;
}