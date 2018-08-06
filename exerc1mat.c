#include <stdio.h>
#include <stdio_ext.h>		// __fpurge() --> soh funciona em Linux!!
							// Em Windows: fflush() (nao usa stdio_ext.h)

#define ALUNOS		5		// linhas da matriz
#define QUESTOES	3		// colunas da matriz
#define MAX_NOME	30		// considerando um espaco para o terminador nulo

int main() {
	// Exemplo de inicializacao de matrizes
	char exemplo[ALUNOS][QUESTOES] = {
		{ 'A', 'B', 'C' },	// inicializacao da 1a. linha
		{ 'E', 'B', 'D' },
		{ 'E', 'A', 'C' },
		{ 'B', 'A', 'B' },
		{ 'D', 'C', 'C' }
	};

	char respostas[ALUNOS][QUESTOES];	// matriz de respostas
	char gabarito[QUESTOES];			// vetor de gabarito

	// lista dos nomes dos alunos
	// string lista[ALUNOS];		// nao existe o tipo string, entao...
	char lista[ALUNOS][MAX_NOME];	// ... a matriz eh um vetor de strings

	// Preenche a lista de alunos
	int i;
	for (i=0; i<ALUNOS; ++i) {
		printf("Digite o nome do %do. aluno: ", i+1);
		__fpurge(stdin);	// limpa o teclado entre duas strings
		gets(lista[i]);		// apenas 1 par de colchetes (o 2o. eh da string)!
	}

	// Preenche o gabarito
	for (i=0; i<QUESTOES; ++i) {
		do {
			printf("Digite a resposta correta para a questao %d: ", i+1);
			__fpurge(stdin);	// necessario para leitura de char/string
			char r = getchar();
			gabarito[i] = toupper(r);
		} while (gabarito[i] < 'A' || gabarito[i] > 'E');
	}

	// Preenche a matriz de respostas
	int ind_aluno, ind_questao;
	// Para todos os alunos (linhas)...
	for (ind_aluno=0; ind_aluno<ALUNOS; ++ind_aluno) {	// linha por linha
		// ... le todas as respostas (colunas) do aluno
		for (ind_questao=0; ind_questao<QUESTOES; ++ind_questao) {	// coluna por coluna
			char r;
			do {
				printf("Digite a resposta do(a) aluno(a) %s para a questao %d: ", lista[ind_aluno], ind_questao+1);
				__fpurge(stdin);	// necessario para leitura de char/string
				r = toupper(getchar());
			} while (r < 'A' || r > 'E');
			respostas[ind_aluno][ind_questao] = r;
		}
	}

	// Vetor com os contadores de acertos (um contador por aluno)
	unsigned acertos[ALUNOS] = { 0 };	// todos os contadores nascem zerados

	// Conferencia das respostas (comparacao de cada linha/aluno com o gabarito)
	for (ind_aluno=0; ind_aluno<ALUNOS; ++ind_aluno) {
		for (ind_questao=0; ind_questao<QUESTOES; ++ind_questao) {
			// Compara a resposta (coluna) do aluno (linha) com o gabarito
			if (respostas[ind_aluno][ind_questao] == gabarito[ind_questao]) {
				++acertos[ind_aluno];
			}
		}
	}

	// Resultado final: tabela de acertos por aluno
	for (ind_aluno=0; ind_aluno<ALUNOS; ++ind_aluno) {
		printf("%s: %u\n", lista[ind_aluno], acertos[ind_aluno]);
	}

	// Imprime a matriz de respostas para conferencia
	for (ind_aluno=0; ind_aluno<ALUNOS; ++ind_aluno) {
		printf("%s: ", lista[ind_aluno]);	// antes de varrer as colunas!
		for (ind_questao=0; ind_questao<QUESTOES; ++ind_questao) {
			printf("%c ", respostas[ind_aluno][ind_questao]);
		}
		putchar('\n');	// salto de linha entre alunos
	}

	return 0;
}

