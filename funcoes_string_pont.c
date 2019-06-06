#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 50

void strtoupper(char*);
void strtolower(char*);

int main(void) {
    char str1[MAX] = "Uma frase qualquer";
    char str2[MAX];
    // char str2[MAX] = str1; (invalido!)

    size_t tamanho = strlen(str1);

    // Note o uso do \\ para imprimir o proprio caractere '\' na tela ;-)
    printf("str1 tem %zd caracteres uteis (sem contar o '\\0')\n", tamanho);

    // str2 = str1; (invalido!)
    // str2 = "Outra frase qualquer"; (idem)
    strcpy(str2, str1); // str2 = str1;

    strtoupper(str1);
    puts(str1);
    strtolower(str2);
    puts(str2);

    int res = strcmp(str1, str2);
    if (res == 0) { // str1 == str2
        puts("str1 e str2 sao identicas");
    } else if (res > 0) { // str1 > str2
        puts("str1 vem DEPOIS de str2 num dicionario");
    } else { // str1 < str2
        puts("str1 vem ANTES de str2 num dicionario");
    }

    strcat(str2, " e acabou o programa"); // str2 += " e acabou ...
                                          // sem o espaco antes do "e..."
                                          // vai "grudar" com a string anterior
    strcat(str1, str1);
    puts(str1);
    puts(str2);

    return EXIT_SUCCESS;
}

void strtoupper(char* string) {
    size_t num_caracteres = strlen(string);
    int i; // variavel contadora do laco
    for (i=0; i<num_caracteres; ++i, ++string) {
        *string = toupper(*string); // substitui o caractere pela maiuscula
    }
}

void strtolower(char* string) {
    while (*string != '\0') {
        if (isalpha(*string)) { // desnecessario, pois o tolower jah faz isso
            *string = tolower(*string);
        }
        ++string;
    }
}

