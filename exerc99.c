#include <stdlib.h>
#include <stdio.h>
#include <stdio_ext.h>
#include <ctype.h>

/* Vamos trocar as proximas 7 linhas pela inclusao de exerc99.h
#define MAX_NOME	200
struct funcionario {
	char nome[MAX_NOME];
	int horas;
	char turno, categoria;
	float valorhr, inicial, auxilio, final;
};
*/
#include "exerc99.h"

#define MAX_FUNCIONARIOS	5
#define SALARIO_MINIMO		680.00

int main(void) {
	// O cadastro eh um VETOR de registros/estruturas
	struct funcionario cadastro[MAX_FUNCIONARIOS] = {
		{ "Nononono", 0, 'M', 'O', 0.0 },	// indice 0 do cadastro
		{ "NnNnNnNn" }, 	// indice 1: soh o primeiro campo inicializado
		{ .turno = 'M' },	// soh em C11 (VC++ nao!) indice 2: soh turno
							// pula indice sem inicializar
		[MAX_FUNCIONARIOS-1] = { .turno = 'M', .categoria = 'O' }
	};

	// Preenche o cadastro (como eh um vetor, usa um laco)
	for (int i=0; i<MAX_FUNCIONARIOS; ++i) {
		// Declaracao de uma variavel-estrutura com inicializacao dos campos
		struct funcionario rascunho = { "Nononono", 0, 'M', 'O', 0.0 };

		puts("*** CADASTRO DE FUNCIONARIO ***");
		printf("Funcionario n.%d: Nome? ", i+1);
		__fpurge(stdin);	// equivalente ao fflush(stdin) no Windows
		gets(rascunho.nome);	// operador . (ponto): campo de VARIAVEL
		printf("Horas trabalhadas? ");
		scanf("%d", &rascunho.horas);
		do {
			printf("Turno (M/V/N)? ");
			__fpurge(stdin);
			rascunho.turno = toupper(getchar());
		} while (rascunho.turno != 'M' && rascunho.turno != 'V' &&
				 rascunho.turno != 'N');
		do {
			printf("Categoria (O/G)? ");
			__fpurge(stdin);
			rascunho.categoria = toupper(getchar());
		} while (rascunho.categoria != 'O' && rascunho.categoria != 'G');

		// Calculo do valor da hora trabalhada
		if (rascunho.categoria == 'G') {
			if (rascunho.turno == 'N') {
				rascunho.valorhr = SALARIO_MINIMO * 8/100;
			}
			else {
				rascunho.valorhr = SALARIO_MINIMO * 0.05;
			}
		}
		else {
			rascunho.valorhr = SALARIO_MINIMO *
							   (rascunho.turno == 'N'? 0.03: 0.02);
		}
		// Copia campo-a-campo, byte por byte do campo
		cadastro[i] = rascunho;
	}

	// Ponteiro para estrutura, inicializado com o endereco do primeiro
	// registro/estrutura do vetor
	struct funcionario* func = cadastro;
	int i = 0;
	while (i < MAX_FUNCIONARIOS) {
		// Ponteiro eh soh um numero (nao tem campos)! O operador seta
		// (->) permite atingir o campo ATRAVES DO ponteiro
		func->inicial = func->horas * func->valorhr;
		if (func->inicial <= 1000.0) {
			func->auxilio = func->inicial * 0.20;
		}
		else if (func->inicial > 1800.0) {
			func->auxilio = func->inicial * 0.05;
		}
		else {
			func->auxilio = func->inicial * 0.15;
		}
		func->final = func->inicial + func->auxilio;

		++i, ++func;	// soma o tamanho da estrutura no endereco
	}

	// Chama uma funcao para gerar um arquivo contendo a folha de
	// pagamento
	geraFolha(cadastro, MAX_FUNCIONARIOS);

	return EXIT_SUCCESS;
}

void geraFolha(struct funcionario vetor[], size_t num) {
	FILE* folha = fopen("/tmp/folha.txt", "wt");
	if (folha == NULL) {
		perror("Nao pude criar arquivo-texto com a folha:");
		return;
	}
	if (fprintf(folha, "NOME;HORAS;TURNO;CATEGORIA;VALOR-HORA;INICIAL$;AUXILIO$;FINAL$\n") < 0) {
		perror("Nao pude escrever no arquivo-texto:");
		fclose(folha);
		return;
	}
	for (int i=0; i<num; ++i) {
		// Grava um registro no arquivo-texto
		if (fprintf(folha,
					"%s;%d;%c;%c;%.2f;%.2f;%.2f;%.2f\n",
					vetor[i].nome,
					vetor[i].horas,
					vetor[i].turno,
					vetor[i].categoria,
					vetor[i].valorhr,
					vetor[i].inicial,
					vetor[i].auxilio,
					vetor[i].final) < 0) {
			perror("Nao pude escrever registro no arquivo-texto:");
			fclose(folha);
			return;
		}
	}
	fclose(folha);

	// Grava TODOS os registros no arquivo-binario de uma soh vez
	folha = fopen("/tmp/folha.bin", "wb");
	if (folha == NULL) {
		perror("Nao pude criar arquivo-binario com a folha:");
		return;
	}
	if (fwrite(vetor, sizeof(struct funcionario), num, folha) < num) {
		perror("Nao pude escrever no arquivo-binario:");
	}
	fclose(folha);
}

