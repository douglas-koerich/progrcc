#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        puts("Numero insuficiente de argumentos");
        return EXIT_FAILURE;
    }

    FILE* arquivo = fopen(argv[1], "rb");
    if (arquivo == NULL) {
        perror("Nao foi possivel abrir o arquivo para leitura");
        return EXIT_FAILURE;
    }

    const size_t DIAS = 7, MEDIDAS = 3;
    int d, matriz[DIAS][MEDIDAS];
    for (d = 0; d < DIAS; ++d) {
        if (fread(&matriz[d][0], sizeof(int), MEDIDAS, arquivo) < MEDIDAS) {
            if (ferror(arquivo)) {
                perror("Erro na leitura do arquivo");
            } else {
                puts("\nFim prematuro do arquivo!");
            }
            fclose(arquivo);
            return EXIT_FAILURE;
        }

        // "Pula" o espaco correspondente ah media gravada no arquivo
        fseek(arquivo, sizeof(float), SEEK_CUR);
    }

    for (d = 0; d < DIAS; ++d) {
        printf("%d: ", d+1);
        int m;
        for (m = 0; m < MEDIDAS; ++m) {
            printf("%d ", matriz[d][m]);
        }
        putchar('\n');
    }
    return EXIT_SUCCESS;
 }