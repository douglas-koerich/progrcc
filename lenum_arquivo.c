#include <stdlib.h>
#include <stdio.h>

int main(void) {
    // Abertura do arquivo e mapeamento para variavel stream
    FILE* stream = fopen("teste2.bin", "rb");

    // Eh necessario testar o valor de 'stream' para certificar-se
    // que a abertura teve sucesso
    if (stream == 0) {
        // Houve erro, imprime o que aconteceu
        perror("Erro na abertura do arquivo");
        return EXIT_FAILURE;
    }
    while (!feof(stream)) { // Enquanto NAO encontra o fim do arquivo...
        int num;
        if (fread(&num, sizeof(num), 1, stream) < 1) {
            // Um numero menor do que o pedido pode vir se:
            // a) fim do arquivo;
            // b) erro na leitura
            // Pra diferenciar, usa a funcao que testa se houve erro em operacao
            // de arquivo
            if (ferror(stream)) {
                perror("Erro na leitura do arquivo");
                fclose(stream); // fecha o arquivo que estah aberto
                return EXIT_FAILURE;
            }
        } else {
            // Leu um binario valido, imprime na tela
            printf("%d ", num);
        }
    }
    putchar('\n'); // imprime uma nova-linha avulsa na tela

    // Fechamento da stream, fim do acesso ao arquivo
    fclose(stream);

    return EXIT_SUCCESS;
}

