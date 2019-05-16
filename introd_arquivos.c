#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LOCAL 256

int main(void) {
    char local[256];
    puts("Digite o caminho completo do arquivo que deseja abrir: ");
    gets(local);
    // FILE* stream = fopen("/tmp/exemplo.txt", "r");
    FILE* stream = fopen(local, "r"); // abre para leitura
    if (stream == 0) {
        perror("Nao foi possivel abrir o arquivo");
        return EXIT_FAILURE;
    }
    strcat(local, ".cpy"); // mudando o nome do arquivo que vai ser criado...
    FILE* stream2 = fopen(local, "w");
    if (stream2 == 0) {
        perror("Nao foi possivel criar a copia maiuscula");
        fclose(stream); // nao deixe o (outro) arquivo original aberto
        return EXIT_FAILURE;
    }
    char c;
    while (!feof(stream)) { // enquanto nao chega ao fim do arquivo
        c = fgetc(stream);  // le o proximo caractere
        if (c != EOF) {     // nao leu a marca de fim de arquivo?
            putchar(c);     // imprime na tela
            c = toupper(c);
            if (fputc(c, stream2) == EOF) {
                perror("Erro na escrita do caractere no arquivo");
                fclose(stream2); // fecha os dois arquivos abertos
                fclose(stream);
                return EXIT_FAILURE;
            }
        }
    }
    fclose(stream2);
    fclose(stream);
    return EXIT_SUCCESS;
}

