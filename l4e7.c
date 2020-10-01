#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

float calcula_media(float, float, float, char);

int main(void) {
    float n1, n2, n3;
    
    printf("Digite a nota #1: "); scanf("%f", &n1);
    printf("Digite a nota #2: "); scanf("%f", &n2);
    printf("Digite a nota #3: "); scanf("%f", &n3);

    char opcao;
    do {
        printf("Media (A)ritmetica ou (P)onderada? ");
        scanf(" %c", &opcao);
        opcao = toupper(opcao);
    } while (opcao != 'A' && opcao != 'P');

    float media;
    media = calcula_media(n1, n2, n3, opcao);

    printf("A media calculada eh %.2f\n", media);

    return EXIT_SUCCESS;
}

float calcula_media(float nota1, float nota2, float nota3, char tipo) {
    float media;
    switch (tipo) {
        case 'A':
            media = (nota1 + nota2 + nota3) / 3;
            break;

        case 'P':
            media = (5 * nota1 + 3 * nota2 + 2 * nota3) / (5 + 3 + 2);
            break;

        default:
            media = -1.0; // media invalida porque o tipo passado eh invalido!
    }
    return media;
}