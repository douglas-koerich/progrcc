#include <stdio.h>

#define MAX_NOME	20

int main() {
	// lembrar que soh poderah ter ateh 19 letras
	// char nome[MAX_NOME] = { 'V', 'e', 'r', 'u', 's', 'c', 'a', '\0' };
	// char nome[MAX_NOME] = "Verusca";	// unico lugar valido para usar =
	// char nome[] = "Verusca";	// vetor criado com o tamanho de Verusca\0
	char nome[MAX_NOME] = "Jose de Alencar";

	// Compilador rejeita!!
	// nome = "Valdivina";

	puts(nome);

	return 0;
}

