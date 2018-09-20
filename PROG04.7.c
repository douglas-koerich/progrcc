#include <stdlib.h>
#include <stdio.h>
#include <ctype.h> // para toupper()

float calcula_media(char, float, float, float);

int main(void) {
    float media, nota1, nota2, nota3;
    char tipo;

    printf("Digite as notas do aluno abaixo:\n");
    printf("Nota 1? ");
    scanf("%f", &nota1);
    printf("Nota 2? ");
    scanf("%f", &nota2);
    printf("Nota 3? ");
    scanf("%f", &nota3);

    do {
        printf("Qual o tipo da media (A: aritm, P: pond)? ");
        scanf(" %c", &tipo);
        tipo = toupper(tipo);
    } while (tipo != 'A' && tipo != 'P');

    media = calcula_media(tipo, nota1, nota2, nota3);

    printf("A media obtida eh %.1f\n", media);

    return EXIT_SUCCESS;
}

float calcula_media(char aritm_ou_pond, float n1, float n2, float n3) {
    float m;
    switch (aritm_ou_pond) {
        case 'A':
            m = (n1 + n2 + n3) / 3;
            break;

        case 'P':
            m = (5*n1 + 3*n2 + 2*n3) / (5+3+2);
            break;

        default:
            printf("Tipo de media INVALIDO!");
            m = 0.0;
    }
    return m;
}

