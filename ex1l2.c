#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

int main() {
    char ch;
    printf("Digite um caractere qualquer: ");
    scanf(" %c", &ch); // lembre-se de incluir o espaco-em-branco antes do %c

    if (!isalpha(ch)) { // "se NAO(!) eh uma letra do alfabeto...
        puts("Outro");
    } else {
        // Para nao precisar comparar com maiusculas e minusculas, transforma
        // em maiuscula para facilitar
        ch = toupper(ch); // substitui o conteudo da variavel 'ch'

        switch (ch) {
            case 'A': // nao esqueca que deve estar entre ' ' (aspas simples)
            case 'E':
            case 'I':
            case 'O':
            case 'U':
            case 'Y':
                puts("Vogal");
                break;

            default:
                puts("Consoante");
        }
    }
    return EXIT_SUCCESS;
}

