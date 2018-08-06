#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include <string.h> // operacoes fundamentais com strings

void strtoupper(char [*]);  // converte todas as letras para maiusculo

#define MAX_TAM_PALAVRA_FRASE 200

int main(void) {
    char string1[MAX_TAM_PALAVRA_FRASE+1];  // espaco-extra para '\0'
    char string2[MAX_TAM_PALAVRA_FRASE+1] = { 'a', 'l', 'o', 'h', 'a' };
    char string3[MAX_TAM_PALAVRA_FRASE+1] = "ciao!";

    char caractere;

    printf("A string2 contem %s e a string3 contem %s.\n",
           string2, string3);
    printf("Digite algo para a string1: ");
    /* scanf consegue ler ateh encontrar um separador de palavras (\n, \t
     * ou espaco em branco)
    scanf(" %s", string1);  // sem o & na frente, porque eh vetor/ponteiro!
    */
    gets(string1);

    printf("Agora, string1 tem o conteudo: %s.\n", string1);

    // Consertando o primeiro caractere caso nao seja maiusculo
    string1[0] = toupper(string1[0]);   // cada caractere eh acessivel individualmente!

    puts("Imprimindo cada string deste programa:");
    puts(string1);
    puts(string2);
    puts(string3);

    // char string4[MAX_TAM_PALAVRA_FRASE] = string3;  (Erro no compilador)
    char string4[MAX_TAM_PALAVRA_FRASE];
    // string4 = string3;   (Erro no compilador)
    strcpy(string4, string3);
    printf("string4 = %s.\n", string4);

    strcat(string2, string1);   // string2 += string1
    printf("string2 = %s.\n", string2);

    int comp = strcmp(string3, string1);
    printf("comp = %d.\n", comp);
    comp = strcmp(string4, string3);
    printf("comp = %d.\n", comp);

    printf("O comprimento de string2 eh %zu.\n", strlen(string2));
    printf("O comprimento de string3 eh %zu.\n", strlen(string3));

    strtoupper(string4);
    printf("A string4 modificada para maiusculas ficou %s.\n", string4);

    printf("Digite um caractere qualquer: ");
    // scanf(" %c", &caractere);
    caractere = getchar();

    puts("Voce digitou o caractere ");
    putchar(caractere);
    putchar('\n');  // aspas simples porque se trata de UM caractere

    return EXIT_SUCCESS;
}

void strtoupper(char string[]) {
    int i = 0;
    while (string[i] != '\0') {
        string[i] = toupper(string[i]);
        ++i;
    }
}

