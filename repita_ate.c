#include <stdio.h>

// inicio
int main() {
    // declare genero : caracter
    char genero;

    // declare dia, mes : inteiro
    int dia, mes;

    // leia dia, mes
    printf("Digite o dia (1-31): ");
    scanf("%d", &dia);
    printf("Digite o mes (1-12): ");
    scanf("%d", &mes);

    // repita
    // repeat {
    do {    // faca...
        // leia genero
        printf("Digite o genero (M/F): ");
        scanf(" %c", &genero);  // espaco-em-branco antes do % limpa os espacos/saltos de linha do teclado
    }
    // ate genero = 'M' ou genero = 'F'
    // until genero == 'M' || genero == 'F'
    while (genero != 'M' && genero != 'm' && genero != 'F' && genero != 'f');
    /* ou:
    do {
        printf("Digite o genero (M/F): ");
        scanf("%c", &genero);
        genero = toupper(genero);   // converte a letra (se for) para maiusculo
    }
    */
    // se dia = 8 e mes = 3 entao
    if (dia == 8 && mes == 3) {
        // se genero = 'F' entao
        if (genero == 'F' || genero == 'f') {
            // escreva "Parabens!"
            printf("Parabens!\n");
        // senao
        } else {
            // escreva "Corra pra floricultura!"
            printf("Corra pra floricultura!\n");
        // fim-se
        }
    // fim-se
    }
// fim
}
