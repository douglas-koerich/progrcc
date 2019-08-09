#include <stdlib.h>
#include <stdio.h>

int main() {
    // Declaracao de variaveis
    int idade;
    float peso, altura = -1, backup; // inicializacao de apenas uma

    puts("Vamos falar de variaveis...");

    // Atribuicao de valor a variavel
    peso = 70; // constante para variavel
    backup = peso; // variavel para variavel

    // Outras declaracoes podem ser feitas no meio do algoritmo,
    // DESDE que anteriores ao primeiro uso da variavel
    char sexo = '?'; // inicializacao (nao atribuicao) de valor

    /*
    printf("Peso: ");
    printf("%f\n", peso);
    */
    printf("Peso: %.1f\n", peso); // %f pra float...
    printf("Sexo: %c\n", sexo);   // ... e %c pra char

    printf("Digite a sua idade: "); // "prompt" de entrada
    scanf("%d", &idade); // %d pra int; nao esqueca do & antes da variavel!

    printf("Sua idade eh %i\n", idade); // pode usar %i no lugar do %d

    printf("Agora, informe o seu sexo (M/F): ");
    scanf(" %c", &sexo); // sempre ponha um espaco antes do %c no scanf ;-)

    printf("Voce eh do sexo %c\n", sexo);

    puts("Digite seu peso e altura (<Enter> apos cada valor):");
    scanf("%f", &peso);
    scanf("%f", &altura); // use scanf's separados, um para cada variavel

    printf("Seu peso e altura sao, respectivamente, %f e %f\n", peso, altura);

    return EXIT_SUCCESS;
}

