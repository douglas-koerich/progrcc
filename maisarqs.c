#include <stdlib.h>
#include <stdio.h>

int main(void) {
    const char NOME_ARQUIVO[] = "/tmp/tabela.csv";
    FILE* arqtab = fopen(NOME_ARQUIVO, "w+t");
    if (arqtab == 0) {
        perror("Nao foi possivel criar/abrir o arquivo");
        return EXIT_FAILURE;
    }
    // Escrita formatada de caracteres num arquivo
    int n;
    for (n = 1; n <= 10; ++n) {
        int q = n * n;   // q = n²
        //printf("%d,%d\n", n, q);
        fprintf(arqtab, "%d,%d\n", n, q);
    }

    // Volta ao inicio do arquivo criado
    rewind(arqtab);

    // Leitura de cada linha para duas variaveis inteiras
    int x, y;
    while (!feof(arqtab)) {
        fscanf(arqtab, "%d,%d\n", &x, &y);  // "%d,%d\n" igual ao do fprintf!
        printf("O quadrado de %d eh %d\n", x, y);
    }
    fclose(arqtab);

    return EXIT_SUCCESS;
}

