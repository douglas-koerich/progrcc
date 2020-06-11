#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "estacao.h"

int main(void) {
    FILE* arquivo = fopen(NOME_ARQ_BINARIO, "rb");
    if (arquivo == NULL) {
        perror("Nao foi possivel abrir o arquivo");
        return EXIT_FAILURE;
    }
    while (feof(arquivo) == false) {
        estacao entrada;
        if (fread(&entrada, sizeof(estacao), 1, arquivo) < 1) {
            if (ferror(arquivo) == true) {
                perror("Erro ao ler o conteudo do arquivo");
                fclose(arquivo);
                return EXIT_FAILURE;
            }
        } else {
            printf("%-15s ", entrada.nome);
            int m;
            for (m = 0; m < NUM_MEDICOES; ++m) {
                printf("%2d ", entrada.medicoes[m]);
            }
            putchar('\n');
        }
    }
    fclose(arquivo);
    return EXIT_SUCCESS;
}
