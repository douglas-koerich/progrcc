#include <stdio.h>
#include "exerc102.h"	// seu proprio arquivo-cabecalho

// Funcao para preencher a lista de aprovados no curso
void inscricao(int num_vagas, int num_cursos, candidato vest[num_vagas][num_cursos]) {
	int codigo;
	int num_alunos[num_cursos];	// contadores de alunos em cada coluna/curso
	for (int i=0; i<num_cursos; ++i) {
		num_alunos[i] = 0;	// zera o contador de cada curso
	}
	do {
		printf("Digite o codigo do candidato: "); scanf("%d", &codigo);
		if (codigo > 0) {
			struct candidato ficha;	// rascunho de entrada de dados
			ficha.codigo = codigo;
			printf("Digite a idade: "); scanf("%hu", &ficha.idade);
			printf("Digite a pontuacao: "); scanf("%u", &ficha.pontuacao);
			do {
				printf("Opcao de curso: "); scanf("%d", &ficha.curso);
			} while (ficha.curso < 1 || ficha.curso > NUM_CURSOS);

			// Com os dados do candidato, adiciona-o na matriz, na coluna referente
			// ao curso escolhido
			int curso = ficha.curso;
			int linha = num_alunos[curso-1];	// pega o contador de alunos que ja estao na matriz para este curso
			int coluna = curso-1;
			if (num_alunos[curso-1] < NUM_VAGAS) {
				vest[linha][coluna] = ficha;	// salva a ficha do aluno na posicao correta da matriz
				++num_alunos[curso-1];			// incrementa o contador
			}
		}
	} while (codigo > 0);
}

