#include <stdlib.h>
#include <stdio.h>

#define NOME_ARQUIVO    "/tmp/saida.txt"

int main(void) {
    FILE* saida = fopen(NOME_ARQUIVO, "w");
    if (saida == 0) {
        perror("Nao foi possivel criar o arquivo");
        return EXIT_FAILURE;
    }
    char caractere;
    do {
        printf("Digite um caractere: ");
        scanf(" %c", &caractere);
        if (caractere != '0') {
            if (fputc(caractere, saida) == EOF) {
                perror("Erro na escrita do arquivo");
                fclose(saida);
                return EXIT_FAILURE;
            }
        }
    } while (caractere != '0'); // '0' eh diferente de 0
    return EXIT_SUCCESS;
}

