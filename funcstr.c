#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX	50

int main() {
	char prenome[MAX], sobrenome[MAX], nome[2*MAX];

	do {
		printf("Digite o prenome: ");
		gets(prenome);
	} while (islower(prenome[0]));

	do {
		printf("Digite o sobrenome: ");
		gets(sobrenome);
	} while (islower(sobrenome[0]));

	// Inicia nome completo com o prenome
	//nome = prenome;	// compilador nao aceita atribuicao de string com =
	strcpy(nome, prenome);	// strcpy(destino, origem);

	// Concatenacao de string ("gruda" a segunda no fim da primeira)
	//nome += sobrenome;	// isso soh existe em C++ com std::string
	strcat(nome, " ");		// strcat nao poe um espaco automaticamente
	strcat(nome, sobrenome);

	printf("O nome completo eh %s\n", nome);

	if (strcmp(prenome, "Jose") == 0) { // ==0 strings iguais (incl. maius/minus)
		puts("O primeiro nome eh Jose");
	}
	else {
		puts("O primeiro nome NAO eh Jose");
	}

	// strlen() NAO conta o terminador nulo!!!
	int comprimento = strlen(nome);
	printf("O nome completo tem %d letras (contando o espaco)\n", comprimento);

	return 0;
}

