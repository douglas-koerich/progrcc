#include <stdio.h>
#include <ctype.h>

float calculaMedia(float, float, float, char);

int main() {
    float n1, n2, n3, media;
    char tipo;

    do {
        printf("Digite a primeira nota (0-10): ");
        scanf("%f", &n1);
    } while (n1 < 0 || n1 > 10);
    do {
        printf("Digite a segunda nota (0-10): ");
        scanf("%f", &n2);
    } while (n2 < 0 || n2 > 10);
    do {
        printf("Digite a terceira nota (0-10): ");
        scanf("%f", &n3);
    } while (n3 < 0 || n3 > 10);

    do {
        printf("Media (P)onderada ou (A)ritmetica? ");
        scanf(" %c", &tipo);
        tipo = toupper(tipo);   // para deixar maiuscula! (se fosse p/ minuscula: tolower)
    } while (tipo != 'A' && tipo != 'P');
    // } while (tipo != 'a' && tipo != 'A' && tipo != 'p' && tipo != 'P');

    media = calculaMedia(n1, n2, n3, tipo);

    printf("A media calculada eh %f\n", media);

    return 0;
}

float calculaMedia(float n1, float n2, float n3, char t) {
    if (t == 'A') {
    // if (t == 'A' || t == 'a') {
        return (n1+n2+n3) / 3;
    }
    else {
        float ponderada;
        ponderada = (5*n1 + 3*n2 + 2*n3) / (5+3+2);
        return ponderada;
    }
}

