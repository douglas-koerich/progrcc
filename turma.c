#include <stdio.h>
#include <stdio_ext.h>
#include "aluno.h"

#define NUM_ALUNOS	3
#define TOTAL_AULAS 72

int main() {
	/*
	// Vamos iniciar ilustrando como seria o programa para um aluno apenas
	char nome[MAX_NOME+1];
	float notas[NUM_NOTAS];
	int faltas;
	*/
	// Nao mais variaveis avulsas, mas um REGISTRO de aluno
	// DECLARACAO de uma variavel-estrutura
	// struct aluno umAluno;
	struct aluno turma[NUM_ALUNOS];

	// Para todos os alunos da turma:
	int a;
	for (a=0; a<NUM_ALUNOS; ++a) {
		// Inicia pedindo as informacoes do aluno:
		printf("Digite o nome do(a) aluno(a): ");
		__fpurge(stdin);
		//gets(nome);
		//gets(umAluno.nome);
		gets(turma[a].nome);
		printf("Quantas faltas do(a) aluno(a) %s? ", turma[a].nome);
		//scanf("%d", &faltas);
		//scanf("%d", &umAluno.faltas);
		scanf("%d", &turma[a].faltas);
		int n;
		for (n=1; n<=NUM_NOTAS; ++n) {
			printf("Digite a %da. nota: ", n);
			//scanf("%f", &notas[n-1]);
			//scanf("%f", &umAluno.notas[n-1]);
			scanf("%f", &turma[a].notas[n-1]);
		}

		// Vamos calcular a media do aluno:
		float media = 0.0;
		for (n=0; n<NUM_NOTAS; ++n) {
			//media += notas[n];
			//media += umAluno.notas[n];
			media += turma[a].notas[n];
		}
		media /= NUM_NOTAS;

		// Vamos calcular a frequencia do aluno:
		//float freq = 100.0*(TOTAL_AULAS-faltas)/TOTAL_AULAS;
		//float freq = 100.0*(TOTAL_AULAS-umAluno.faltas)/TOTAL_AULAS;
		float freq = 100.0*(TOTAL_AULAS-turma[a].faltas)/TOTAL_AULAS;

		// Vamos determinar o resultado do aluno:
		if (freq < 75.0) {
			printf("O(A) aluno(a) %s foi REPROVADO(A) por faltas (freq=%.1f%%).\n", turma[a].nome, freq);
		}
		else {
			if (media >= 7.0) {
				printf("O(A) aluno(a) %s foi APROVADO(A) (media=%.1f).\n", turma[a].nome, media);
			}
			else if (media < 4.0) {
				printf("O(A) aluno(a) %s for REPROVADO(A) (media=%.1f).\n", turma[a].nome, media);
			}
			else {
				printf("O(A) aluno %s esta em Exame (media=%.1f).\n", turma[a].nome, media);
			}
		}
	}
	return 0;
}

