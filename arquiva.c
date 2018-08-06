#include <stdio.h>
#include <stdio_ext.h>
#include "exerc102.h"	// seu proprio arquivo-cabecalho

// Funcao para arquivar o cadastro
void arquiva(int num_vagas, int num_cursos, candidato vest[num_vagas][num_cursos]) {
	char nome[100];

	printf("Digite o nome do arquivo a ser criado: ");
	__fpurge(stdin);
	gets(nome);

	FILE* arq = fopen(nome, "wb");
	if (arq == NULL) {
		perror("Nao pude criar o arquivo:");
		return;
	}
	// Para todos os registros do cadastro, grava no arquivo por curso/coluna
	for (int curso = 0; curso < num_cursos; ++curso) {
		for (int vaga = 0; vaga < num_vagas; ++vaga) {
			if (fwrite(&vest[vaga][curso], sizeof(candidato), 1, arq) < 1) {	// grava 1 candidato em arq
				perror("Nao pude escrever no arquivo:");
				fclose(arq);
				return;
			}
		}
	}
	fclose(arq);
}

