#include <stdlib.h>
#include <stdio.h>

// Este programa recebe parametros da carga do programa (rotinas
// do sistema operacional que carregam/chamam a funcao main); esses
// parametros sao "strings" que foram digitadas na linha de comando
int main(int num, char* parametros[]) {
    printf("O numero de parametros passados pra main eh %d.\n", num);

    // O nome do arquivo a ser carregado para a memoria eh informado
    // na linha de comando e portanto passado como parametro para a
    // funcao main
    if (num < 2) {
        puts("Numero insuficiente de parametros");
        printf("Digite: %s <[caminho/] nome-do-arquivo>\n", parametros[0]);
        return EXIT_FAILURE;
    }
    FILE* arquivo = fopen(parametros[1], "rt");
    if (arquivo == NULL) { // no lugar de 0, uso NULL (ponteiro nulo)
        perror("Nao pude abrir o arquivo");
        return EXIT_FAILURE;
    }
    char buffer[1024];
    fscanf(arquivo, " %s", buffer);
    printf("Lida palavra: %s.\n", buffer);

    fseek(arquivo, 0, SEEK_END);    // vai para o fim do arquivo
    long tamanho = ftell(arquivo);  // recupera o numero de posicao (=tamanho)
    printf("Posicao do fim (tamanho) = %ld.\n", tamanho);

    // Como o arquivo pode ser maior que 8 MiB, pode nao caber em uma
    // variavel local, entao eh melhor (do que uma global) usar a heap
    char* conteudo_arquivo = malloc(tamanho * sizeof(char));
    fseek(arquivo, 0, SEEK_SET); // volta ao inicio para leitura do conteudo

    unsigned contador = 0;
    while (!feof(arquivo)) {
        char c = fgetc(arquivo);
        if (c == EOF) {
            if (ferror(arquivo)) {
                perror("Nao pude ler o arquivo");
                fclose(arquivo);

                // Nao pode sair do programa sem liberar a memoria do malloc!!
                free(conteudo_arquivo);

                return EXIT_FAILURE;
            }
        } else {
            *(conteudo_arquivo + contador) = c;
            ++contador;
        }
    }

    // Imprime os tres primeiros caracteres do arquivo (na memoria)
    printf("Inicio: %c%c%c.\n", conteudo_arquivo[0],
           conteudo_arquivo[1], conteudo_arquivo[2]);

    // Imprime os tres ultimos caracteres
    printf("Fim: %c%c%c.\n", conteudo_arquivo[tamanho-3],
        conteudo_arquivo[tamanho-2], conteudo_arquivo[tamanho-1]);

    free(conteudo_arquivo);
    fclose(arquivo);

    return EXIT_SUCCESS;
}

