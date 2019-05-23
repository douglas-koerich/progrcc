#include <stdlib.h>
#include <stdio.h>

#define MAX 50 // Agora tem que bater com a escrita

int main(void) {
    FILE* arq = fopen("/tmp/bd.dat", "rb");
    if (arq == 0) {
        perror("Ferrou, nao consegui ler");
        return EXIT_FAILURE;
    }
    while (!feof(arq)) {
        char nome[MAX];
        int faltas;
        float notas[3]; // vetor com nota1, nota2 e media

        // fread(destino, tamanho_unitario, num_unidades, stream)
        if (fread(nome, sizeof(char), MAX, arq) < MAX) {
            if (ferror(arq)) { // foi erro ou fim do arquivo?
                perror("Ferrou mesmo, nao deu pra ler");
                fclose(arq);
                return EXIT_FAILURE;
            } else {
                break; // leu fim do arquivo, interrompe
            }
        }
        if (fread(&faltas, sizeof(int), 1, arq) < 1) {
            if (ferror(arq)) { // foi erro ou fim do arquivo?
                perror("Ferrou mesmo, nao deu pra ler");
                fclose(arq);
                return EXIT_FAILURE;
            } else {
                break;
            }
        }
        // Escolhi ler as notas de uma soh vez
        if (fread(notas, sizeof(float), 3, arq) < 3) {
            if (ferror(arq)) { // foi erro ou fim do arquivo?
                perror("Ferrou mesmo, nao deu pra ler");
                fclose(arq);
                return EXIT_FAILURE;
            } else {
                break;
            }
        }
        printf("Aluno(a): %s, faltas: %d, nota 1: %.1f, nota 2: %.1f, media:  %.1f\n",
               nome, faltas, notas[0], notas[1], notas[2]);
    }
    fclose(arq);

    return EXIT_SUCCESS;
}
