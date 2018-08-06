#ifndef PACIENTE_H
#define PACIENTE_H

// ### DEFINICAO ### do registro de um paciente:
// Os campos que compoem a informacao agregada sao
// - Nome do paciente
// - Idade
// - Sexo
// - Altura
// - Peso

#define MAX_NOME	30

// ATENCAO! A definicao da estrutura NAO cria uma variavel para conter
// valores! Isso significa que nenhuma posicao de memoria foi alocada
// ateh agora!
struct Paciente {
	// Campos
	char nome[MAX_NOME];
	int idade;
	char sexo;
	float altura;
	float peso;	// poderia declarar numa linha soh: float altura, peso;
};	// nao esquecer o ponto-e-virgula apos a chave que fecha a definicao

// Vamos atribuir um novo nome (apelido) ao tipo 'struct Paciente'
typedef struct Paciente Enfermo;	// typedef <nome-velho> <nome-novo>

// Prototipo de funcao: calculo do IMC de um paciente
float calculaIMC(struct Paciente*);	// passa ponteiro para evitar a copia
									// de todos os campos para a funcao

#endif

