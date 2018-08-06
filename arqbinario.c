#include <stdlib.h>
#include <stdio.h>

#define NUM_ELEMENTOS 5

int main(void) {
    int i, vetor[NUM_ELEMENTOS] = { 1 };
    vetor[1] = 2;
    printf("Digite o valor a ser armazenado na ultima posicao do vetor: ");
    scanf("%d", &vetor[NUM_ELEMENTOS-1]);

    // Vamos salvar esses valores em dois arquivos, um texto e outro binario
    FILE* texto = fopen("/tmp/texto.txt", "w");
    if (texto == NULL) {
        perror("Erro ao criar o arquivo texto");
        return EXIT_FAILURE;
    }
    FILE* binario = fopen("/tmp/binario.bin", "wb");
    if (binario == NULL) {
        perror("Erro ao criar o arquivo binario");
        fclose(texto);
        return EXIT_FAILURE;
    }
    for (i = 0; i < NUM_ELEMENTOS; ++i) {
        fprintf(texto, "%d ", vetor[i]);
        // fwrite pede o ENDERECO do que sera escrito de forma binaria no arquivo
        fwrite(&vetor[i], sizeof(int), 1, binario);
    }
    fclose(texto);
    fclose(binario);

    return EXIT_SUCCESS;
}
