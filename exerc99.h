#ifndef _EXERC99_H_
#define _EXERC99_H_

#define MAX_NOME	200

// Definicao do TIPO, nao esta havendo alocacao de memoria (decl. de var.)
// Deve ser feita FORA de qualquer funcao, se for usada por varias
struct funcionario {		// 'funcionario' eh uma etiqueta/rotulo do tipo
	char nome[MAX_NOME];	// 'nome' eh o identificador do componente/CAMPO
	int horas;
	char turno, categoria;	// dois campos do mesmo tipo-base
	float valorhr, inicial, auxilio, final;
};	// DEVE terminar a definicao com um ponto-e-virgula

// Prototipos das funcoes usadas no programa
void geraFolha(struct funcionario [*], size_t);

#endif

