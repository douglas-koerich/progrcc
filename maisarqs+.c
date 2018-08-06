#include <stdlib.h>
#include <stdio.h>

#define NUM_NUMEROS 10

int main(void) {
    FILE* arqtab = fopen("/tmp/tabela.bin", "w+b");
    if (arqtab == 0) {
        perror("Nao foi possivel criar/abrir o arquivo");
        return EXIT_FAILURE;
    }
    int numeros[NUM_NUMEROS], quadrados[NUM_NUMEROS];
    int n;
    for (n = 1; n <= NUM_NUMEROS; ++n) {
        numeros[n-1] = n; // numeros[0] = 1, numeros[1] = 2,...
        quadrados[n-1] = n * n;
    }

    // Escrita no arquivo usando a representacao binaria original;
    // TODOS os elementos do vetor sao escritos de uma vez soh
    fwrite(numeros, sizeof(int), NUM_NUMEROS, arqtab);

    // Agora, UM elemento de cada vez...
    for (n = 0; n < NUM_NUMEROS; ++n) {
        fwrite(&quadrados[n], sizeof(int), 1, arqtab);
    }

    // Volta ao inicio do arquivo criado
    rewind(arqtab);

    // Leitura dos dois vetores para novas variaveis
    int num[NUM_NUMEROS], quad[NUM_NUMEROS];
    fread(num, sizeof(int), NUM_NUMEROS, arqtab);
    fread(quad, sizeof(int), NUM_NUMEROS, arqtab);

    for (n = 0; n < NUM_NUMEROS; ++n) {
        printf("O quadrado de %d eh %d\n", num[n], quad[n]);
    }

    // Suponha que eu queira imprimir o TERCEIRO numero inteiro
    // guardado no arquivo (considerando que esse arquivo soh
    // tenha armazenado variaveis inteiras-int):
    fseek(arqtab, sizeof(int) * 2 /* pula 2 */, SEEK_SET);
    int x;
    fread(&x, sizeof(int), 1, arqtab);

    // Agora, quero recuperar o PENULTIMO numero inteiro
    // Devo me posicionar no byte que INICIA o numero no arquivo
    fseek(arqtab, -sizeof(int) * 2 /* 2 atras do fim */, SEEK_END);
    int y;
    fread(&y, sizeof(int), 1, arqtab);

    printf("O terceiro numero eh %d, o penultimo eh %d\n", x, y);

    fclose(arqtab);

    return EXIT_SUCCESS;
}

