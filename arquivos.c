#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool eh_vogal(char);

int main(int argc, char* argv[]) {
    if (argc < 2) {
        puts("Numero insuficiente de parametros");
        printf("Uso: %s <nome-do-arquivo>\n", argv[0]);
        return EXIT_FAILURE;
    }
    // Apesar de poder usar argv[1] diretamente, preferiu-se ter uma variavel-string com
    // nome mais representativo do seu conteudo
    const size_t MAX_NOME_ARQUIVO = 128;
    char nome_arquivo[MAX_NOME_ARQUIVO];
    strcpy(nome_arquivo, argv[1]);

    // Para manipular o conteudo de qualquer arquivo em C, eh necessario abri-lo primeiro
    FILE* stream = fopen(nome_arquivo, "r");
    if (stream == NULL) { // indicacao ou nao de erro na operacao de abertura
        perror("Nao foi possivel abrir o arquivo");
        return EXIT_FAILURE;
    }

    // Cria um segundo arquivo, desta vez para escrita
    char nome_copia[MAX_NOME_ARQUIVO];
    strcpy(nome_copia, nome_arquivo);
    strcat(nome_copia, ".bkp");
    FILE* copia = fopen(nome_copia, "w");
    if (copia == NULL) { // sempre verifica a operacao com arquivo
        perror("Nao foi possivel criar a copia");
        fclose(stream); // fecha o outro arquivo que jah estah aberto
        return EXIT_FAILURE;
    }

    unsigned contador = 0;
    while (feof(stream) == false) { // Testa se chegou ao fim do conteudo do arquivo
        // Le um caractere (byte) do arquivo
        char c = fgetc(stream);
        if (c == EOF) { // nao leu um caractere valido
            if (ferror(stream)) {
                perror("Nao foi possivel efetuar a leitura do arquivo");
                fclose(stream); // garante o fechamento dos arquivos
                fclose(copia);
                return EXIT_FAILURE;
            }
            // else: trata-se de ter encontrado o fim do arquivo de fato, nao eh um caractere a testar
        }
        else {
            if (eh_vogal(c)) {
                ++contador;
            }
            c = toupper(c);
            if (fputc(c, copia) == EOF) { // nesse caso EOF eh /sempre/ uma indicacao de erro
                perror("Nao foi possivel efetuar a escrita na copia");
                fclose(stream); fclose(copia);
                return EXIT_FAILURE;
            }
        }
    }
    printf("O numero de vogais contidas no arquivo eh %u\n", contador);

    // Como nao precisa mais acessar o arquivo de copia, fecha-o
    fclose(copia);

    // Retorna ao inicio do arquivo de entrada
    rewind(stream);

    contador = 0;
    while (!feof(stream)) {
        char linha[1024];

        // Le uma linha completa do arquivo(-texto!)
        if (fgets(linha, sizeof(linha), stream) == NULL) { // pode ser erro ou fim do arquivo
            if (ferror(stream)) {
                perror("Nao foi possivel ler uma nova linha do arquivo");
                fclose(stream);
                return EXIT_FAILURE;
            }
        } else {
            ++contador;
        }
    }

    printf("O numero de linhas do arquivo eh %u\n", contador);

    // Antes de encerrar o programa, nao deve esquecer de fechar o(s) arquivo(s) aberto(s)
    fclose(stream);

    return EXIT_SUCCESS;
}

bool eh_vogal(char simbolo) {
    if (!isalpha(simbolo)) {
        return false;
    }
    simbolo = toupper(simbolo);
    return simbolo == 'A' || simbolo == 'E' ||
           simbolo == 'I' || simbolo == 'O' ||
           simbolo == 'U' || simbolo == 'Y';
}