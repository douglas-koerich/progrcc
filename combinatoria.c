#include <stdio.h>
#include <stdlib.h>

void exibeMsgErro(char m[]);	// prototipo da funcao
int calculaFatorial(int);

void limpaTela(void) {
	system("clear");
}

int main() {
	int i, n, p, n_p, A, fn, fp, fn_p;

	printf("Digite o valor de n: ");
	scanf("%d", &n);
	printf("Digite o valor de p: ");
	scanf("%d", &p);

	if (n < 0) {
		exibeMsgErro("n eh negativo");
		return -1;
	}
	if (p < 0) {
		exibeMsgErro("p invalido");
		return -1;
	}
	fn = calculaFatorial(n);	// o argumento eh n
	fp = calculaFatorial(p);	// o argumento eh p
	fn_p = calculaFatorial(n-p);	// o argumento eh o resultado de n-p

	A = fn / (fp * fn_p);
	/*
	 A = calculaFatorial(n) / (calculaFatorial(p) * calculaFatorial(n-p));
	 printf("O fatorial de %d eh %d.\n", n, calculaFatorial(n));
	 */
	printf("Arranjo = %d\n", A);

	return 0;	// termina o programa normalmente (com "sucesso")
}

int calculaFatorial(int y) {	// y eh o parametro de entrada
	int x, f;	// variaveis LOCAIS da funcao calculaFatorial
				// obs: y TAMBEM eh considerada como variavel local
	if (y == 0) {
		return 1;	// se chega aqui, sai da funcao
	}
	for (x=f=1; x<=y; ++x) {
		f = f*x;
	}
	return f;
}

void exibeMsgErro(char msg[]) {
	limpaTela();
	printf("Erro no programa: %s\n", msg);
	// exit(-1);
}

