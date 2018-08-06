#include <stdio.h>
#include <stdio_ext.h>

#define MAX_STRING	50

int compara(char [*], char [*]);

int main(void) {
	char string1[MAX_STRING+1], string2[MAX_STRING+1];

	printf("Digite a primeira string: ");
	__fpurge(stdin);	// em Windows: fflush(stdin)
	gets(string1);

	printf("Digite a segunda string: ");
	__fpurge(stdin);
	gets(string2);

	// Declara a variavel 'pos' antes de usa-la
	int pos = compara(string1, string2);
	if (pos == -1) {
		puts("As strings sao IGUAIS!");
	}
	else {
		printf("As strings diferem na posicao %d.\n", pos);
	}
	return 0;
}

int compara(char s1[], char s2[]) {
	int i = 0;

	// Enquanto houver caracteres em ambas pra comparar...
	while (s1[i] != '\0' && s2[i] != '\0') {
		// Se forem diferentes...
		if (s1[i] != s2[i]) {
			// ... nem adianta continuar
			return i;
		}
		++i;
	}
	// Saiu do laco, por 1 de 2 motivos:
	// 1. UMA das strings terminou, mas a outra nao! :-(
	if (s1[i] != '\0' || s2[i] != '\0') {
		return i;
	}
	// 2. Ambas as strings terminaram juntas! :-)
	else {
		return -1;
	}
}



