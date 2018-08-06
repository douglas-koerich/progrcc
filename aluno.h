#ifndef ALUNO_H
#define ALUNO_H

#define NUM_NOTAS	3
#define MAX_NOME	80

// DEFINICAO do registro/estrutura
// Importante: a Definicao NAO cria variaveis, ou seja, NAO aloca espaco em memoria;
// Em outras palavras, a Definicao eh um "molde" para as futuras variaveis.
struct aluno {
	char nome[MAX_NOME+1];
	float notas[NUM_NOTAS];
	int faltas;
};

// typedef permite dar um "apelido" a um tipo
// Ex: typedef unsigned char byte;
typedef struct aluno discente;
// 'discente' eh um novo nome para o tipo 'struct aluno'
// Posso assim declarar variaveis como:
// struct aluno umAluno; OU
// discente umAluno;

// Pode-se aglutinar o typedef com a struct assim:
/*
typedef struct aluno {	// nesse caso, pode-se omitir 'aluno'
	char nome[MAX_NOME+1];
	float notas[NUM_NOTAS];
	int faltas;
} discente;
*/

#endif // ALUNO_H
