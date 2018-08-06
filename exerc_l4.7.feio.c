#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

// Prototipo da funcao:
float calcula_media(float, float, float /*, char */);

// Variavel GLOBAL (visivel e -PIOR- acessivel por todas as funcoes)
char tipo;

int main() {
    float n1, n2, n3, m;
    do {
        printf("Digite a primeira nota: ");
        scanf("%f", &n1);
        printf("Digite a segunda nota: ");
        scanf("%f", &n2);
        printf("Digite a terceira nota: ");
        scanf("%f", &n3);
        printf("Tipo da media (A/P): ");
        scanf(" %c", &tipo);   // espaco antes do % para limpar scanfs anteriores
        m = calcula_media(n1, n2, n3 /*, tipo */);
    } while (m < 0.0);
    printf("A media obtida eh %.1f.\n", m);

    return EXIT_SUCCESS;
}

// Definicao (implementacao) da funcao:
float calcula_media(float nota1, float nota2, float nota3 /*, char tipo */) {
    float media;
    tipo = toupper(tipo);   // para testar apenas as maiusculas
    if (nota1 < 0.0 || nota1 > 10.0 ||
        nota2 < 0.0 || nota2 > 10.0 ||
        nota3 < 0.0 || nota3 > 10.0 ||
        (tipo != 'A' && tipo != 'P')) {
        printf("Parametros invalidos!\n");
        return -1.0; // saida da funcao diretamente desse ponto!
    }
    if (tipo == 'A') {
        media = (nota1 + nota2 + nota3) / 3;    // media aritmetica
    } else {
        media = (5*nota1 + 3*nota2 + 2*nota3) / (5+3+2); // media ponderada
    }
    return media;
}

