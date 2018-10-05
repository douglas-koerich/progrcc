#include <stdlib.h>
#include <stdio.h>
#include <stdio_ext.h>
#include <ctype.h>

int main(void) {
    FILE* stream = fopen("teste2.txt", "w");
    if (stream == 0) {
        perror("Erro ao criar o arquivo");
        return EXIT_FAILURE;
    }
    char caractere;
    do {
        printf("Digite uma letra ou algarismo (outra coisa para encerrar): ");
        __fpurge(stdin); // limpa o buffer do teclado antes de nova leitura
        caractere = getchar(); // equivalente a scanf("%c", &caractere);
        if (isalnum(caractere)) {
            // Soh escreve no arquivo se for alfanumerico...
            /*
            fprintf(stream, "%c", caractere);
            */
            if (fputc(caractere, stream) == EOF) { // EOF indica erro
                perror("Erro ao escrever no arquivo");
            }
        }
    } while (isalnum(caractere));

    fclose(stream);

    return EXIT_SUCCESS;
}

