#include <stdlib.h>
#include <stdio.h>

int main() {
    unsigned idade;
    printf("Digite a idade do nadador: ");
    scanf("%u", &idade);

    // Teste das faixas de idade relacionadas no enunciado
    if (idade >= 5 && idade <= 7) {
        printf("Infantil A\n");
    } else {
        // Estar no bloco do 'else' significa (idade < 5 || idade > 7), i.e.,
        // todas as outras faixas
        if (idade >= 8 && idade <= 10) {
            printf("Infantil B\n");
        } else {
            if (idade >= 11 && idade <= 13) {
                printf("Juvenil A\n");
            } else {
                if (idade >= 14 && idade <= 17) {
                    printf("Juvenil B\n");
                } else {
                    if (idade >= 18) {
                        printf("Adulto\n");
                    } else {
                        printf("INVALIDO\n");
                    }
                }
            }
        }
    }
    /*
    // Uma segunda forma de escrever a escada if-else acima, que soh contem if's
    // e else's aninhados eh:
    if (idade >= 5 && idade <= 7) {
        printf("Infantil A\n");
    } else if (idade >= 8 && idade <= 10) {
        printf("Infantil B\n");
    } else if (idade >= 11 && idade <= 13) {
        printf("Juvenil A\n");
    } else if (idade >= 14 && idade <= 17) {
        printf("Juvenil B\n");
    } else if (idade >= 18) {
        printf("Adulto\n");
    } else {
        printf("INVALIDO\n");
    }
    */
    /*
    // Se as faixas fossem TODAS mutuamente exclusivas, poder-se-ia fazer assim
    if (idade >= 5 && idade <= 7) {
        printf("Infantil A\n");
    }
    if (idade >= 8 && idade <= 10) {
        printf("Infantil B\n");
    }
    if (idade >= 11 && idade <= 13) {
        printf("Juvenil A\n");
    }
    if (idade >= 14 && idade <= 17) {
        printf("Juvenil B\n");
    }
    if (idade >= 18) {
        printf("Adulto\n");
    }
    if (idade <= 4) { // para cobrir o "caso contrario" implicito da tabela
        printf("INVALIDO\n");
    }
    */
    return EXIT_SUCCESS;
}

