#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
    // Abertura do arquivo e mapeamento para variavel stream
    FILE* stream = fopen("teste.txt", "r");

    // Eh necessario testar o valor de 'stream' para certificar-se
    // que a abertura teve sucesso
    if (stream == 0) {
        // Houve erro, imprime o que aconteceu
        perror("Erro na abertura do arquivo");
        return EXIT_FAILURE;
    }
    while (feof(stream) == false) { // Enquanto NAO encontra o fim do arquivo...
        /*
        fscanf(stream, "%c", &caractere); // como o scanf, mas agora lendo
                                          // de 'stream' ao inves do teclado
        */
        char caractere = fgetc(stream);
        if (caractere == EOF) {
            // EOF pode vir por:
            // a) fim do arquivo mesmo;
            // b) erro na leitura
            // Pra diferenciar, usa a funcao que testa se houve erro em operacao
            // de arquivo
            if (ferror(stream) == true) {
                perror("Erro na leitura do arquivo");
                fclose(stream); // fecha o arquivo que estah aberto
                return EXIT_FAILURE;
            }
        } else {
            // Eh um caractere valido, imprime na tela
            /*
            printf("%c", caractere);
            */
            putchar(caractere); // funcao que imprime apenas um caractere (nao
                                // imprime outros tipos, como int, float, ...)
        }
    }

    // Fechamento da stream, fim do acesso ao arquivo
    fclose(stream);

    return EXIT_SUCCESS;
}

