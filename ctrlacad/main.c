#include <stdlib.h>
#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include "aluno.h"

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("%s: parametros insuficientes\n", argv[0]);
        printf("Uso: %s <num-alunos> <nome-arquivo>\n", argv[0]);
        return EXIT_FAILURE;
    }
    int num_alunos = atoi(argv[1]); // converte da string para um int
    char nome_arquivo_texto[64];
    char nome_arquivo_binario[64];
    strcpy(nome_arquivo_texto, argv[2]);
    strcat(nome_arquivo_texto, ".txt");
    strcpy(nome_arquivo_binario, argv[2]);
    strcat(nome_arquivo_binario, ".bin");

    FILE* arqtexto = fopen(nome_arquivo_texto, "wt");
    if (arqtexto == 0) {
        perror("Erro ao criar o arquivo texto de cadastro");
        return EXIT_FAILURE;
    }
    FILE* arqbin = fopen(nome_arquivo_binario, "wb");
    if (arqbin == 0) {
        perror("Erro ao criar o arquivo binario de cadastro");
        fclose(arqtexto);
        return EXIT_FAILURE;
    }

    // Declara um VETOR de REGISTROS
    aluno turma[num_alunos];
    int a;

    // Abordagem (1): gravar cada campo individualmente
    puts("Cadastro dos alunos:");
    for (a = 0; a < num_alunos; ++a) {
        turma[a].matricula = a + 101; // 101, 102, 103, ...
        fprintf(arqtexto, "%u,", turma[a].matricula); // (1)
        fwrite(&turma[a].matricula, sizeof(unsigned), 1, arqbin); // (1)
        printf("Nome? ");
        __fpurge(stdin);
        gets(turma[a].nome_completo);
        fprintf(arqtexto, "%s,", turma[a].nome_completo); // (1)
        fwrite(&turma[a].nome_completo, sizeof(char), MAX_NOME, arqbin); // (1)
        printf("Data (d/m/a)? ");
        scanf("%u/%u/%u", &turma[a].data_nasc.dia, &turma[a].data_nasc.mes,
              &turma[a].data_nasc.ano);
        fprintf(arqtexto, "%02d/%02d/%02d,", turma[a].data_nasc.dia,
                turma[a].data_nasc.mes, turma[a].data_nasc.ano); // (1)
        fwrite(&turma[a].data_nasc.dia, sizeof(int), 1, arqbin); // (1)
        fwrite(&turma[a].data_nasc.mes, sizeof(int), 1, arqbin); // (1)
        fwrite(&turma[a].data_nasc.ano, sizeof(int), 1, arqbin); // (1)
        int n;
        float soma;
        for (n = 0, soma = 0.0; n < NUM_NOTAS; ++n) {
            printf("Nota %d? ", n+1);
            scanf("%f", &turma[a].notas[n]); // cada [] pro seu vetor
            fprintf(arqtexto, "%.1f,", turma[a].notas[n]); // (1)
            soma += turma[a].notas[n];
        }
        fwrite(&turma[a].notas, sizeof(float), NUM_NOTAS, arqbin); // (1)
        turma[a].media = soma / 4;
        fprintf(arqtexto, "%.1f,", turma[a].media); // (1)
        fwrite(&turma[a].media, sizeof(float), 1, arqbin); // (1)
        printf("Faltas? ");
        scanf("%u", &turma[a].faltas);
        fprintf(arqtexto, "%u\n", turma[a].faltas); // (1)
        fwrite(&turma[a].faltas, sizeof(unsigned), 1, arqbin); // (1)
    }
    fclose(arqtexto);
    fclose(arqbin);

    puts("\nRELATORIO:");
    puts("Mtr Nome---------------- Nasc.--- Media Faltas");
    for (a = 0; a < num_alunos; ++a) {
        printf("%3d ", turma[a].matricula);
        printf("%20s ", turma[a].nome_completo);
        printf("%2d/%2d/%2d ", turma[a].data_nasc.dia, turma[a].data_nasc.mes,
               turma[a].data_nasc.ano);
        printf("%5.1f ", turma[a].media);
        printf("%6u\n", turma[a].faltas);
    }
    return EXIT_SUCCESS;
}

