#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_FRASE 1000

int main(void) {
    // Leitura da frase
    char frase[MAX_FRASE];
    puts("Digite abaixo a sua frase:");
    gets(frase);

    // Outra variavel para a frase invertida
    char invertida[MAX_FRASE];

    // Percorre a frase original do fim para o inicio
    int i = strlen(frase) - 1;
    int j = 0; // para copiar para a invertida
    while (i >= 0) {
        if (isalpha(frase[i])) {
            char letra = toupper(frase[i]); // converte pra maiuscula para
                                            // diminuir o numero de alternativas
            switch (letra) {
                case 'A': case 'E': case 'I': case 'O': case 'U': case 'Y':
                    invertida[j] = frase[i]; // copia a vogal
                    break;
                
                default: // consoantes
                    invertida[j] = '#';
            }
        } else {
            invertida[j] = frase[i];
        }
        --i, ++j;
    }
    // No final da copia, j estah na posicao seguinte do ultimo caractere
    // preenchido na invertida; PRECISA finalizar com \0 ali!...
    invertida[j] = '\0';

    printf("Frase criptografada: %s\n", invertida);

    return EXIT_SUCCESS;
}

