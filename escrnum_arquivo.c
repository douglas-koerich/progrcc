#include <stdlib.h>
#include <stdio.h>

int main(void) {
    FILE* stream = fopen("teste2.bin", "wb");
    if (stream == 0) {
        perror("Erro ao criar o arquivo");
        return EXIT_FAILURE;
    }
    int numero;
    do {
        printf("Digite um numero (0 para encerrar): ");
        scanf("%d", &numero);
        if (numero != 0) {
            // Testa se o numero escrito eh igual ao numero pedido
            if (fwrite(&numero, sizeof(numero), 1, stream) < 1) {
                perror("Erro ao escrever no arquivo");
            }
        }
    } while (numero != 0);

    fclose(stream);

    return EXIT_SUCCESS;
}

