#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define MAX_NOME 100
#define MAX_LINHA 200

int main(void) {
    // Abre um arquivo ja existente para leitura do seu conteudo
    char nome_arquivo[MAX_NOME];
    printf("Digite o nome do arquivo para leitura: ");
    gets(nome_arquivo);

    FILE* handle;   // para o arquivo de leitura

    // fopen("/tmp/pobre_molhado.txt"... nome constante
    handle = fopen(nome_arquivo, "rt"); // 'handle' eh o meio de acesso ao arquivo
    if (handle == 0) {  // eh INDISPENSAVEL testar se o handle eh valido (dif. 0/)
        perror("Erro no acesso ao arquivo");
        return EXIT_FAILURE;
    }

    // Para o arquivo de escrita...
    FILE* outro = fopen("/tmp/invertido.txt", "wt");
    if (outro == 0) {
        perror("Erro na criacao do arquivo");
        fclose(handle); // nao deixa o arquivo aberto com sucesso sem fecha-lo
        return EXIT_FAILURE;
    }

    // Leitura de arquivo texto:
    // 1o. modo, byte a byte
    while (!feof(handle)) { // enquanto nao encontra o fim do arquivo...
        char c = fgetc(handle); // le o proximo byte do arquivo
        if (c == EOF) { // encontrou o fim do arquivo pela leitura OU houve erro
            if (ferror(handle)) { // verifica se das hipoteses acima EH um erro
                perror("Erro na leitura do arquivo");
                fclose(handle); // nao ha mais o que fazer como o arquivo
                return EXIT_FAILURE;
            }
            // o 'else' aqui nao tem utilidade, pois seria a conclusao de que o
            // arquivo acabou mesmo...
        }
        // Nao leu EOF, entao eh um caractere/byte valido
        else {
            putchar(c);
            if (islower(c)) {
                c = toupper(c);
            } else {
                c = tolower(c);
            }
            if (fputc(c, outro) == EOF) { // nesse caso, EOF eh codigo de erro
                perror("Erro na escrita do arquivo");
                fclose(outro);
                fclose(handle);
                return EXIT_FAILURE;
            }
        }
    }
    fclose(outro); // fecha assim que nao for mais usado

    // Volta para o inicio do arquivo a fim de repetir a leitura do arquivo
    rewind(handle);

    // Para mais um arquivo de escrita...
    FILE* copia = fopen("/tmp/copia.txt", "wt");
    if (copia == 0) {
        perror("Erro na criacao do arquivo");
        fclose(handle); // nao deixa o arquivo aberto com sucesso sem fecha-lo
        return EXIT_FAILURE;
    }

    // 2o. modo, linha a linha
    while (!feof(handle)) {
        char l[MAX_LINHA];
        if (fgets(l, MAX_LINHA, handle) == 0) { // se retornou 0, encontrou o fim
                                                // OU houve erro
            if (ferror(handle)) { // verifica se das hipoteses acima EH um erro
                perror("Erro na leitura do arquivo");
                fclose(handle); // nao ha mais o que fazer como o arquivo
                return EXIT_FAILURE;
            }
        } else {
            // puts(l); puts SEMPRE poe um \n no final, mesmo se eu ja o tenha
            //          lido do arquivo
            printf("%s", l);
            if (fputs(l, copia) == EOF) {
                perror("Erro na escrita do arquivo");
                fclose(copia);
                fclose(handle);
                return EXIT_FAILURE;
            }
        }
    }
    fclose(copia);
    
    // Ao termino do uso do arquivo, fecha o acesso ao mesmo
    fclose(handle);
    return EXIT_SUCCESS;
}

