#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    int idade;       // conteudo indeterminado apos a sua criacao
    float peso, altura;
    char sexo = '?'; // inicializacao (variavel "nasce" com o valor)

    idade = 0;       // atribuicao de valor a uma variavel
    peso = altura = 0.0; // ambas recebem o mesmo valor

    printf("Digite a sua idade: ");
    scanf("%d", &idade); // leitura de valor do console para a variavel

    printf("Digite o seu peso: ");
    scanf("%f", &peso);

    printf("Digite a sua altura: ");
    scanf("%f", &altura);

    printf("Digite o seu genero: ");
    scanf(" %c", &sexo); // espaco entre " e % para limpar a memoria de caracteres jah lidos

    printf("Idade=%d, peso=%f, altura=%f, sexo=%c.\n", idade, peso, altura, sexo);

    bool logica = true;
    printf("logica = %d.\n", logica);
    logica = false;
    printf("logica = %d.\n", logica);

    return EXIT_SUCCESS;
}

