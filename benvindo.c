// Esta linha inclui um arquivo-cabecalho
#include <stdio.h>	// (standard input & output)
#include <stdlib.h>	// (biblioteca de funcoes basicas)

/*
Este programa foi o primeiro dado a turma de Prog. Estruturada
para que eles(as) possam identificar as partes basicas de um
programa em linguagem C.
*/

int main(void) {
	char nome[50];
	printf("Digite o seu nome: "); scanf("%s", nome);
	printf("Bem-vindo(a), %s, qual o ano do seu nascimento? ",
		   nome);
	int ano_nasc, idade;
	scanf("%d", &ano_nasc);
	idade = 2013 - ano_nasc;	// sinal = : comando de atribuicao
	printf("%s, voce completa %d anos no ano corrente!\n",
		   nome, idade);
	return EXIT_SUCCESS;
}

