#include <stdio.h>
#include <stdio_ext.h>
#include <ctype.h>
#include "paciente.h"	// inclui a definicao da struct

#define CAPACIDADE_ENFERMARIA	3

int main() {
	// ### DECLARACAO ### de variaveis-registros que conterao valores
	// em cada um dos seus campos (e, por consequencia, ocupam memoria)
	struct Paciente paciente1;	// 'struct Paciente' eh o TIPO da variavel
	Enfermo paciente2;	// usa a mesma estrutura com um nome diferente
	struct Paciente lista[CAPACIDADE_ENFERMARIA];	// VETOR de registros!

	// Preenche o cadastro do paciente 1
	puts("Dados do paciente #1");
	printf("Nome? "); gets(paciente1.nome);	// use PONTO quando for variavel-registro
	printf("Idade? "); scanf("%d", &paciente1.idade);
	printf("Sexo? "); __fpurge(stdin); paciente1.sexo = toupper(getchar());
	printf("Altura? "); scanf("%f", &paciente1.altura);
	printf("Peso? "); scanf("%f", &paciente1.peso);

	// Preenche os dados do paciente 2
	struct Paciente* p = &paciente2;	// ponteiro para um registro na memoria
	puts("Dados do paciente #2");
	printf("Nome? "); __fpurge(stdin); gets(p->nome);	// use SETA quando for ponteiro p/ registro
	printf("Idade? "); scanf("%d", &p->idade);
	printf("Sexo? "); __fpurge(stdin); p->sexo = toupper(getchar());
	printf("Altura? "); scanf("%f", &p->altura);
	printf("Peso? "); scanf("%f", &p->peso);

	// Preenche o vetor
	// 1o. metodo: usando a variavel-vetor
	int i;
	for (i=0; i<CAPACIDADE_ENFERMARIA; ++i) {
		printf("Dados do paciente de enfermaria #%d\n", i+1);
		printf("Nome? "); __fpurge(stdin); gets(lista[i].nome);	// repare a indexacao do elemento-registro
		printf("Idade? "); scanf("%d", &lista[i].idade);			// [i] vai ANTES do ponto!
		printf("Sexo? "); __fpurge(stdin); lista[i].sexo = toupper(getchar());
		printf("Altura? "); scanf("%f", &lista[i].altura);
		printf("Peso? "); scanf("%f", &lista[i].peso);
	}
	/*
	// 2o. metodo: usando um ponteiro para se deslocar (aritmetica!) pelo vetor
	p = lista;	// nome do vetor <=> endereco do primeiro elemento (p = &lista[0])
	for (i=0; i<CAPACIDADE_ENFERMARIA; ++i, ++p) {
		printf("Dados do paciente de enfermaria #%d\n", i+1);
		printf("Nome? "); __fpurge(stdin); gets(p->nome);
		printf("Idade? "); scanf("%d", &p->idade);
		printf("Sexo? "); __fpurge(stdin); p->sexo = toupper(getchar());
		printf("Altura? "); scanf("%f", &p->altura);
		printf("Peso? "); scanf("%f", &p->peso);
	}
	*/
	printf("IMC do paciente 1 = %.1f\n", calculaIMC(&paciente1));
	printf("IMC do paciente 2 = %.1f\n", calculaIMC(&paciente2));

	return 0;
}

float calculaIMC(struct Paciente* p) {
	float imc;
	imc = p->peso/(p->altura*p->altura);
	return imc;
}

