#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
    bool primeiro = true;
    FILE* texto = fopen("/tmp/texto.txt", "r");
    if (texto == 0) {
        perror("Nao foi possivel abrir o arquivo");
        return EXIT_FAILURE;
    }
    int num, maior;
    while (!feof(texto)) {
        fscanf(texto, "%d;", &num);
        if (primeiro == true) {
            maior = num;
            primeiro = false;
        } else {
            if (num > maior) {
                maior = num;
            }
        }
    }
    printf("O maior numero lido do arquivo foi %d.\n", maior);
    fclose(texto);
    return EXIT_SUCCESS;
}

