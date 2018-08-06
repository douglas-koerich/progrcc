/*
// Pre-estreia de Estruturas de Dados e Algoritmos: algoritmo de insercao
// direta para manter a coluna (do curso) ordenada de forma decrescente
// pela pontuacao
void ordenaInsercao(int num_vagas, int num_cursos, candidato vest[num_vagas][num_cursos], int curso, candidato* novo) {
	for (int i=1; i<num_vagas; ++i) {
		struct candidato aux = vest[i][curso-1];
		for (int j=i-1; j>=0; --j) {

}
*/

#include "exerc102.h"	// seu proprio arquivo-cabecalho

void inscricao(int num_vagas, int num_cursos, candidato vest[num_vagas][num_cursos]);
void arquiva(int num_vagas, int num_cursos, candidato vest[num_vagas][num_cursos]);

int main(void) {
	candidato vestibular[NUM_VAGAS][NUM_CURSOS];

	// Preenche o cadastro
	inscricao(NUM_VAGAS, NUM_CURSOS, vestibular);

	// Arquiva o cadastro
	arquiva(NUM_VAGAS, NUM_CURSOS, vestibular);

	return 0;
}
