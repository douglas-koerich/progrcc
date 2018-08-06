#include <stdbool.h>
#include <stdio.h>

int main() {
	unsigned num;
	bool ehValido;

	do {	// faca-...
		printf("Digite o numero par limitante: ");
		scanf("%u", &num);
		ehValido = num % 2 == 0;	// eh valido se resto for igual a zero
		if (!ehValido) {
			printf("Numero invalido!\n");
		}
	}
	while (!ehValido); // ...-enquanto

	// enquanto-...
	unsigned n = 1, soma = 0;	// soma eh o "acumulador" do resultado
	while (n <= num) {
		// ...-faca
		if (n % 3 == 0) {	// eh divisivel por 3?
			soma += n;	// (soma = soma+n) atualiza o valor do "acumulador"
		}
		++n;	// (n = n+1) vai testar o proximo
	}

	printf("A soma dos numeros divisiveis por 3 entre 0 e %u eh %u.\n",
		   num, soma);

	return 0;
}

