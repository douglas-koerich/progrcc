/* Escreva um programa que chama uma funcao a qual devolve a soma de 
 * todos os multiplos de 3 no intervalo de dois limites (inferior e
 * superior) passados como ARGUMENTOS para a funcao (que os recebe como
 * PARAMETROS) */

#include <stdio.h>

int somaMultiplos3(int, int);
void imprimaMultiplos3(int, int);
void msgErro(void);

int soma;	// Variavel global

int main() {
	int a, b, soma_mult3;

	printf("Digite o valor inicial: ");
	scanf("%d", &a);
	printf("Digite o valor final: ");
	scanf("%d", &b);

	soma_mult3 = somaMultiplos3(a, b);
	imprimaMultiplos3(a, b);
	
	printf("A soma dos multiplos no intervalo eh %d\n.", soma_mult3);

	return 0;
}

// Isto eh uma funcao
int somaMultiplos3(int inf, int sup) {
	int soma = 0;
	if (sup < inf) {
		msgErro();
		return 0;
	}
	int n;
	for (n=inf; n<=sup; ++n) {
		// Variavel local ao bloco do LACO (fora dele nao existe!)
		bool ehMultiplo = (n % 3 == 0);
		if (ehMultiplo) {
			soma += n;
		}
	}
	return soma;
}

// Isto eh um procedimento
void imprimaMultiplos3(int inf, int sup) {
	if (sup < inf) {
		msgErro();
		return;
	}
	int n = inf;
	while (n <= sup) {
		if (n % 3 == 0) {
			printf("%d ", n);
		}
		++n;
	}
	printf("\n");
}

// Isto tambem eh...
void msgErro(void) {
	printf("Valores invalidos!\n");
}

