#include <stdlib.h>
#include <stdio.h>
#include <stdio_ext.h>

#define MAX_NOME 50

int main(void) {
    char nome[MAX_NOME];
    int faltas;
    float nota1, nota2, media;

    FILE* binario = fopen("/tmp/bd.dat", "wb"); // cria como binario
    if (binario == 0) {
        perror("Erro ao criar arquivo binario");
        return EXIT_FAILURE;
    }
    puts("*** DIGITE OS DADOS DOS ALUNOS (nome vazio para encerrar) ***");
    do {
        printf("Nome? "); __fpurge(stdin); gets(nome);
        if (nome[0] != '\0') { // string nao vazia?
            printf("Faltas? "); scanf("%d", &faltas);
            do {
                printf("Nota 1? "); scanf("%f", &nota1);
            } while (nota1 < 0.0 || nota1 > 10.0);
            do {
                printf("Nota 2? "); scanf("%f", &nota2);
            } while (nota2 < 0.0 || nota2 > 10.0);
            media = (nota1 + nota2) / 2;

            // fwrite(origem, tamanho_da_unidade, num_unidades, stream)
            if (fwrite(nome, sizeof(char), MAX_NOME, binario) < MAX_NOME) {
               perror("Nao foi possivel escrever o nome do aluno");
               fclose(binario);
               return EXIT_FAILURE;
            }
            if (fwrite(&faltas, sizeof(int), 1, binario) < 1) {
               perror("Nao foi possivel escrever as faltas do aluno");
               fclose(binario);
               return EXIT_FAILURE;
            }
            if (fwrite(&nota1, sizeof(float), 1, binario) < 1) {
               perror("Nao foi possivel escrever a nota #1 do aluno");
               fclose(binario);
               return EXIT_FAILURE;
            }
            if (fwrite(&nota2, sizeof(float), 1, binario) < 1) {
               perror("Nao foi possivel escrever a nota #2 do aluno");
               fclose(binario);
               return EXIT_FAILURE;
            }
            if (fwrite(&media, sizeof(float), 1, binario) < 1) {
               perror("Nao foi possivel escrever a media do aluno");
               fclose(binario);
               return EXIT_FAILURE;
            }
        }
    } while (nome[0] != '\0');

    fclose(binario);

    return EXIT_SUCCESS;
}
