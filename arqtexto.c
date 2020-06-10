#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define MAX_NOME_ARQ 120

int main(void) {
    char nome_arquivo[MAX_NOME_ARQ+1]; // reserva +1 para o terminador nulo
    puts("Digite o nome (com caminho, se necessario) do arquivo:");
    scanf("%s", nome_arquivo); // sem espacos no nome do arquivo

    /* Abertura do arquivo */
    FILE* stream = fopen(nome_arquivo, "r");
    FILE* dupl = fopen("/tmp/copia.txt", "w");

    /* Eh INDISPENSAVEL testar o retorno da abertura */
    if (stream == NULL || dupl == NULL) {
        perror("Nao foi possivel abrir o arquivo");
        return EXIT_FAILURE;
    }

    /* Faz a leitura de cada byte/caractere do arquivo ateh o seu fim */
    while (feof(stream) == false) { // while (!feof(stream))
        char var = fgetc(stream);

        /* Novamente, precisa verificar o retorno da chamada ao sistema */
        if (var == EOF) { // fim de arquivo OU erro!
            if (ferror(stream) == true) {
                perror("Houve erro na leitura do arquivo");
                fclose(stream);
                fclose(dupl);
                return EXIT_FAILURE;
            } // else ... (fim de arquivo, nao faz nada, volta pro while)
        } else {// caractere valido (diferente de EOF...)
            printf("%c ", var);
            var = toupper(var); // converte pra maiuscula
            if (fputc(var, dupl) == EOF) { // EOF se houver erro!
                perror("Houve erro na escrita no arquivo");
                fclose(stream);
                fclose(dupl);
                return EXIT_FAILURE;
            }
        }
    }

    /* Fechamento do arquivo */
    fclose(stream);
    fclose(dupl);

    return EXIT_SUCCESS;
}

