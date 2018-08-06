#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>  // toupper()

// "Declaracao" antecipada da funcao
float calculaMedia(float, float, float, char);

int main(void) {
    float nota_1, nota_2, nota_3;
    char opcao;
    printf("Digite a primeira nota: ");
    scanf("%f", &nota_1);
    printf("Digite a segunda nota: ");
    scanf("%f", &nota_2);
    printf("Digite a terceira nota: ");
    scanf("%f", &nota_3);

    do {
        printf("Digite o tipo de media (A=aritmetica, P=ponderada): ");
        scanf(" %c", &opcao);
    } while (opcao != 'a' && opcao != 'A' && opcao != 'p' && opcao != 'P');

    // float m = calculaMedia(nota_1, nota_2, nota_3, opcao);

    printf("A media calculada eh %.2f.\n", calculaMedia(nota_1, nota_2, nota_3, opcao));

    return EXIT_SUCCESS;
}

float calculaMedia(float n1, float n2, float n3, char tipo) {
    float media;

    tipo = toupper(tipo);   // Transforma a letra na sua versao maiuscula

    if (tipo == 'A' || tipo == 'a') {   // Comparacao com minuscula eh dispensavel
                                        // porque usamos a conversao por toupper()
        media = (n1 + n2 + n3) / 3;
    } else if (tipo == 'P') {
        media = (5*n1 + 3*n2 + 2*n3) / (5+3+2);
    } else {
        // Foi indicada uma letra invalida
        return 0.0;
    }

    return media;
}
