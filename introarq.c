#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

int main(void) {
    // Abre o arquivo em modo somente-leitura ("r")
    FILE* arquivo = fopen("/tmp/cantiga.txt", "r");
    if (arquivo == 0) {
        perror("Nao foi possivel abrir o arquivo");
        return EXIT_FAILURE;
    }

    // Cria outro arquivo com as letras em MAIUSCULAS
    FILE* o_grito = fopen("/tmp/gritos.txt", "w");
    if (o_grito == 0) {
        perror("Nao foi possivel criar o outro arquivo");
        fclose(arquivo);
        return EXIT_FAILURE;
    }
    while (!feof(arquivo)) { // enquanto nao (!) for encontrado fim do arquivo
        char caractere = fgetc(arquivo);
        if (caractere == EOF) {
            if (ferror(arquivo)) { // verifica se o EOF eh devido a erro
                perror("Erro na leitura do arquivo");
                fclose(arquivo);
                fclose(o_grito);    // nao esqueca deste tambem!
                return EXIT_FAILURE;
            }
            continue;   // abandona o resto do laco, vai para novo passo
        }
        printf("%c", caractere);

        // Alem de imprimir na tela, escreve no "grito" em maiuscula
        if (fputc(toupper(caractere), o_grito) == EOF) {
            perror("Erro na escrita do arquivo");
            fclose(arquivo);
            fclose(o_grito);
            return EXIT_FAILURE;
        }
    }

    // Fecha o arquivo
    fclose(arquivo);    // usa o handler para outras operacoes com arquivo
    return EXIT_SUCCESS;
}

