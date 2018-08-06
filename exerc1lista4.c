#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

// Prototipo da funcao ("declaracao")
bool testa_primo(unsigned);

// Um "procedimento" (que nao retorna nada) que nao tem parametros
void limpa_tela(void);

int main(void) {
	printf("Digite um numero para verificacao: ");
	unsigned numero;
	scanf("%u", &numero);

	//bool resultado = testa_primo(numero);
	//if (resultado == true) { ou if (resultado) {

	if (testa_primo(numero)) {
		printf("O numero eh primo!\n");
	}
	else {
		printf("O numero NAO eh primo!\n");
	}
	limpa_tela();
	system("pause");
	return EXIT_SUCCESS;
}

bool testa_primo(unsigned num) {
	unsigned submultiplo;
	for (submultiplo = 2; submultiplo < num; ++submultiplo) {
		if (num % submultiplo == 0) {
			return false;
		}
	}
	return true;
}

void limpa_tela(void) {
	// Substitua "cls" por "clear" se for rodar esse programa
	// em Linux ao inves de Windows
	system("cls");
}