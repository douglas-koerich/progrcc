#include <stdlib.h>
#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include <ctype.h>

#define MAX_TAM_PALAVRA 100 // maximo tamanho real = 99 (reserva um para o \0)

int main(void) {
    // Declaracao de uma variavel-string
    char string_1[] = { 'O', 'l', 'a', '\0' }; // nao se faz assim...
    char string_2[] = "Ola"; // ainda aqui sao 4 bytes utilizados

    char string_x[] = "Bom dia!\n"; // aqui sao 9 caracteres + \0 = 10 posicoes

    printf("%s\n", string_1); // impressao de uma variavel-string com printf
    puts(string_2); // impressao direta de uma string (com \n forcado)

    // Imprimindo a segunda letra da string
    printf("%c\n", string_1[1]);
    putchar(string_2[1]); // se imprime apenas um caractere, nao tem \n no final,
    putchar('\n'); // ... entao imprime o \n como constante numas segunda chamada

    // Exibindo o codigo ASCII da primeira letra
    printf("%hhd\n", string_1[0]); // da letra 'O'

    char string_3[MAX_TAM_PALAVRA] = "Ola"; // apenas 4 das 100 posicoes serao
                                            // efetivamente preenchidas
    char string_4[MAX_TAM_PALAVRA]; // sem valor inicial

    /*
    printf("Digite uma palavra ou frase: ");
    scanf(" %s", string_4); // com espaco na frente do %s para limpar <Enter> de leituras anteriores
                            // SEM o & na frente do nome da variavel-string!!!
    printf("Voce digitou %s.\n", string_4); // foi armazenado apenas o que veio antes do primeiro espaco/enter
    */

    // Limpa o buffer deixado por scanf...
    __fpurge(stdin);

    printf("Digite novamente: ");
    gets(string_4);
    printf("Agora a string eh %s.\n", string_4);

    // Copia de uma string para outra
    // string_3 = string_4; (C nao permite copia de vetores assim)
    int i = 0;
    /*
    do {
        string_3[i] = string_4[i];
    } while (string_4[i++] != '\0'); // incrementa DEPOIS de comparar!
    */
    strcpy(string_3, string_4); // copia string_4 (origem) para string_3 (destino)

    printf("A outra string tambem tem agora \"%s\".\n", string_3);
    printf("Ela tem %zd caracteres.\n", strlen(string_3));

    if (strcmp(string_3, string_4) == 0) {
        puts("As strings sao iguais (como era de se esperar)");
    } else {
        puts("Oh!, as strings sao diferentes :-o");
    }

    if (isupper(string_3[0]))
        string_3[0] = tolower(string_3[0]); // converte pra minuscula
    else
        string_3[0] = toupper(string_3[0]); // converte pra MAIUSCULA

    if (strcmp(string_3, string_4) == 0) {
        puts("As strings sao iguais (como era de se esperar)");
    } else {
        puts("Oh!, as strings sao diferentes :-o");
    }

    char string_A[MAX_TAM_PALAVRA] = "Universidade", string_B[MAX_TAM_PALAVRA] = "Tuiuti";
    strcat(string_A, " ");
    strcat(string_A, string_B);
    printf("string_A = %s, string_B = %s\n", string_A, string_B);

    return EXIT_SUCCESS;
}

