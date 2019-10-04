#include <stdlib.h>
#include <stdio.h> // define as funcoes e estruturas de arquivos
#include <ctype.h>

int main(void) {
    puts(">>> Impressao via system()");
    system("cat potatoes.txt"); // exibicao do conteudo de forma indireta
                                // (usando o utilitario 'cat' do shell)
    puts("<<<");

    FILE* stream; // modelo abstrato de um arquivo no ANSI C
                  // 'stream' eh a variavel, 'FILE*' eh o tipo

    // Para ter acesso ao conteudo do arquivo (tanto para leitura como
    // para escrita) eh necessario ABRI-LO junto ao sistema operacional
    stream = fopen("potatoes.txt", "r"); // funcao de abertura/criacao
                                         // de arquivo ("r" = read/leitura)
    // Eh IMPORTANTE (para evitar crashes) que voce verifique o valor
    // retornado por fopen()
    if (stream == 0) {
        perror("Falha ao abrir o arquivo");
        return EXIT_FAILURE;
    }

    // CRIA um novo arquivo com o conteudo selecionado do primeiro
    FILE* stream2 = fopen("/tmp/nao-vogais.txt", "w"); // "w" cria/escreve
    if (stream2 == 0) {
        perror("Falha ao criar novo arquivo");
        fclose(stream); // nao esquece o primeiro aberto
        return EXIT_FAILURE;
    }

    // Leitura e impressao do conteudo...
    puts(">>> Impressao propria do programa");
    // Enquanto nao alcanca o fim do arquivo/conteudo...
    while (!feof(stream)) { // "enquanto nao-fim-do-arquivo..."
        char byte = fgetc(stream); // leh um byte do arquivo
        if (byte == EOF) { // ativou ("leu") o sinal de fim de arquivo?
            if (ferror(stream)) { // foi retornado EOF por causa de erro?
                perror("Erro na leitura do arquivo"); // imprime com causa
                fclose(stream); // fecha o arquivo antes de abandonar a
                                // leitura!
                fclose(stream2); // nao deixa o arquivo de saida aberto!
                return EXIT_FAILURE;
            }
        } else {
            // Caractere valido, imprime na tela
            char minusc = tolower(byte);
            if (minusc != 'a' && minusc != 'e' && minusc != 'i' &&
                minusc != 'o' && minusc != 'u' && minusc != 'y') {
                putchar(byte); // imprime as nao-vogais

                // Escreve esse tambem no arquivo de saida (nao-vogais.txt)
                if (fputc(byte, stream2) == EOF) { // retornou com erro?
                    perror("Erro na escrita do arquivo");
                    fclose(stream2);
                    fclose(stream);
                    return EXIT_FAILURE;
                }
            }
        }
    }
    puts("<<<");

    /*
    // Volta o "cursor" de leitura do arquivo para o inicio
    rewind(stream); // "rebobina a fita do arquivo" X-D

    while (!feof(stream)) {
        // Quando aprendermos strings voltamos a este exemplo!...
    }
    */

    // Conclui o acesso ao arquivo FECHANDO-O junto ao sistema operacional
    fclose(stream); // note que nao ha referencia ao nome do arquivo aqui

    return EXIT_SUCCESS;
}

