#include <stdlib.h>
#include <stdio.h>

#define MAX 8192    // tamanho maximo de uma linha lida de cada vez

int main(void) {
    FILE *arq1, *arq2;
    arq1 = fopen("/tmp/nome_do_arquivo", "r");  // caminho completo do arquivo
                                                // "r" --> arquivo tem que existir
                                                //     --> somente leitura a partir do inicio
    if (arq1 == NULL) { // se retorna NULL, nao pode abrir o arquivo
        perror("Erro ao abrir o arquivo");
        return EXIT_FAILURE;
    }
    arq2 = fopen("outro_arquivo", "w"); // esse arquivo no diretorio (pasta) local (.)
                                        // "w" --> cria o arquivo, se ja existir "trunca" (remove conteudo anterior)
                                        //     --> somente escrita a partir do inicio

    while (!feof(arq1)) {  // enquanto NAO (!) for encontrado o fim do arquivo...
        /* Leitura e escrita de caracter por caracter
        char c = fgetc(arq1);

        // Pode ser que a leitura tenha sido da marca do fim de arquivo, entao
        // devo verificar
        if (c == EOF) {     // EOF ocorre por fim de arquivo OU erro na leitura
            if (ferror(arq1)) { // testa se EOF retornou por causa de erro (e nao de fim)
                perror("Erro ao ler do arquivo");
                fclose(arq1); fclose(arq2); // saida com fechamento manual dos arquivos
                return EXIT_FAILURE;
            }
        }
        else {
            // O caracter eh valido, pode usa-lo
            printf("O caracter lido do arquivo eh %c.\n", c);
            fputc(c, arq2);
        }
        */
        char linha[MAX];
        if (fgets(linha, sizeof(linha) /* = MAX */, arq1) == NULL) {
            if (ferror(arq1)) { // testa se NULL retornou por causa de erro (e nao de fim)
                perror("Erro ao ler do arquivo");
                fclose(arq1); fclose(arq2); // saida com fechamento manual dos arquivos
                return EXIT_FAILURE;
            }
        }
        else {
            // fgets termina a string lida com um \n (antes do \0)
            printf("A linha lida do arquivo eh %s", linha);
            fputs(linha, arq2);
        }
    }

    fclose(arq1);
    fclose(arq2);

    return EXIT_SUCCESS;
}
