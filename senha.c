#include <stdio.h>
#include <stdio_ext.h>

int main() {
    unsigned senha;
    char tecla;

    FILE* arquivo;

    // Tenta abrir o arquivo existente
    arquivo = fopen("/tmp/senha.txt", "r+");    // ler e escrever (+)
    if (arquivo == NULL) {
        arquivo = fopen("/tmp/senha.txt", "w"); // cria se houver erro (ou nao existir)
        if (arquivo == NULL) {
            perror("Erro ao criar o arquivo de senha");
            return -1;
        }
        senha = 1;  // comeca tudo de novo
    }
    else {
        // Le a ultima senha do arquivo
        if (fscanf(arquivo, "%u", &senha) == EOF) {
            perror("Erro na leitura do arquivo");
            fclose(arquivo);
            arquivo = fopen("/tmp/senha.txt", "w");
            if (arquivo == NULL) {
                perror("Erro ao criar o arquivo de senha");
                return -1;
            }
            senha = 1;  // comeca tudo de novo
        }
        else {
            ++senha;    // continua da proxima
        }
    }
    do {
        printf("\r%03d", senha);
        rewind(arquivo);    // volta para a posicao inicial
        fprintf(arquivo, "%03d", senha);

        __fpurge(stdin);
        tecla = getchar();
        if (tecla == ' ') {
            ++senha;
        }
    } while (tecla == ' ');

    fclose(arquivo);

    return 0;
}

