#include <stdio.h>

int compara(char [*], char [*]);

#define MAX	50

int main(void) {
	char string1[MAX+1], string2[MAX+1];
	puts("Digite a primeira string: ");
	gets(string1);
	puts("Digite a segunda string: ");
	gets(string2);

	int indice = compara(string1, string2);
	if (indice == -1) {
		puts("As strings sao iguais");
	}
	else {
		printf("As strings diferem na posicao %d.\n", indice);
	}
	return 0;
}

int compara(char s1[], char s2[]) {
	int i = 0;
	while (s1[i] == s2[i]) {
		if (s1[i] == '\0') {
			return -1;
		}
		++i;
	}
	return i;
}

