#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

float calculaMedia(char, float, float, float);

int main(void) {
    float nota1, nota2, nota3, media;
    char tipo;
    printf("Digite a primeira nota: ");
    scanf("%f", &nota1);
    printf("Digite a segunda nota: ");
    scanf("%f", &nota2);
    printf("Digite a terceira nota: ");
    scanf("%f", &nota3);
    do {
        printf("Digite o tipo da media (A/P): ");
        // Sempre que voce usa scanf com %c, qualquer residuo de entrada de
        // um scanf anterior (por exemplo, o <Enter> da digitacao da nota3)
        // vai ser lido como se fosse *O* caracter digitado pelo usuario
        scanf(" %c", &tipo);    // espaco-em-branco antes do %c para limpar o buffer do teclado
        tipo = tolower(tipo);   // converte pra minuscula se for maiuscula
    } while (tipo != 'a' && tipo != 'p');
    media = calculaMedia(tipo, nota1, nota2, nota3);
    // Varia a impressao do nome do tipo de acordo com o resultado do operador ternario de decisao (?:)
    printf("A media %s das notas eh %f\n", (tipo == 'a'? "aritmetica": "ponderada"), media);
    return EXIT_SUCCESS;
}

float calculaMedia(char tipo, float n1, float n2, float n3) {
    int peso1, peso2, peso3;
    if (tipo == 'P' || tipo == 'p') {
        peso1 = 5;
        peso2 = 3;
        peso3 = 2;
    }
    else {
        peso1 = peso2 = peso3 = 1;  // media aritmetica eh caso especial da ponderada
    }
    return (peso1*n1 + peso2*n2 + peso3*n3)/(peso1+peso2+peso3);
}

