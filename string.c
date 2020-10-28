#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define TAMANHO 10

int num_vogais(const char [*]); // recebe o vetor/string, mas nao pode altera-lo

int main(void) {
    // Isto NAO eh uma String!
    char vetor[5] = { 'a', 'b', 'c', 'd', 'e' }; // agrupamento de caracteres
                                                 // (colecao de caracteres individuais)

    // Estas sao Strings!
    char palavra[TAMANHO] = { 'L', 'a', 'p', 'i', 's', '\0' }; // terminador nulo apos a ultima letra (ou
                                                               // simbolo valido) eh o que caracteriza uma string
    char palavra_[TAMANHO] = "LAPIS"; // tem o mesmo efeito (e eh a utilizada de fato) que a maneira anterior
    char frase[100] = "Esta eh a minha frase inaugural";

    const char MENSAGEM_FIXA[] = "Esta eh uma mensagem que nunca serah substituida na memoria";

    printf("O conteudo da palavra eh %s\n", palavra);
    puts("Uma constante string");
    puts(frase);
    /* Extra: impressao de caractere isolado: printf("%c\n", vetor[0]); */ putchar(vetor[0]); putchar('\n');

    /*
    puts("\nDigite abaixo uma nova frase para a posteridade:");
    // scanf("%s", frase);
    gets(frase);
    printf("Voce digitou a frase \"%s\"\n", frase);
    printf("O numero de vogais da frase eh %d\n", num_vogais(frase));
    printf("Reimprimindo a string digitada: %s\n", frase);
    */

    strcpy(frase, palavra_); // atribuicao: frase = palavra_
    printf("A frase modificada eh %s\n", frase);

    printf("O comprimento da frase eh %zu\n", strlen(frase));

    strcat(frase, " PRETO"); // concatenacao: frase += " PRETO";
    printf("A frase modificada (novamente) eh %s\n", frase);

    if (strcmp(palavra, palavra_) == 0) {
        puts("As strings sao iguais");
    } else {
        puts("As strings sao diferentes");
    }

    return EXIT_SUCCESS;
}

int num_vogais(const char string[]) {
    int i = 0, vogais = 0;
    while (string[i] != '\0') { // enquanto nao encontra o fim da string (palavra/frase)
        char simbolo = toupper(string[i]);
        switch (simbolo) {
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
            case 'Y':
                ++vogais;
                break;

            default:
                ; // comando vazio
        }
        ++i;
    }
    return vogais;
}