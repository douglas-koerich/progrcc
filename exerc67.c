#include <stdio.h>

int n;	// Exemplo de variavel global: a partir deste ponto, TODAS as
		// funcoes podem acessar (e ALTERAR) o conteudo dessa variavel

void imprimeSerieFibonacci(void) {
	if (n <= 0) {
		return;		// deixa (sai d)a funcao neste ponto
	}
	// Se nao saiu da funcao na linha 5, entao n eh PELO MENOS igual a 1,
	// o que significa imprimir 0 (primeiro termo)
	printf("0 ");
	if (n > 1) {
		printf("1 ");
		if (n > 2) {
			int f_n, f_n_1, f_n_2; // variaveis para calcular fn = fn-1+fn-2
			f_n_2 = 0;	// primeiro fn-2 (anterior-ao-anterior)
			f_n_1 = 1;	// primeiro fn-1 (anterior)
			
			int termo;
			for (termo=3; termo<=n; ++termo) { // comeca a calcular pelo...
				f_n = f_n_1 + f_n_2;		   // ... terceiro termo
				printf("%d ", f_n);
				f_n_2 = f_n_1;
				f_n_1 = f_n;
			}
		}
	}
	printf("\n");
}

int main() {
	printf("Digite o numero de termos da serie que deseja imprimir: ");
	scanf("%d", &n);

	imprimeSerieFibonacci();

	return 0;
}
