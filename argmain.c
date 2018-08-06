#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_NOME 30

char* myfgets(char*, int, FILE*);

int main(int argc, char* argv[]) {	// int main(int argc, char** argv)
	if (argc < 2) {
		puts("Numero invalido de parametros");
		printf("Use: %s <nome>\n", argv[0]);
		return EXIT_FAILURE;
	}
	/*
	char nome[MAX_NOME];

	printf("Digite seu nome: ");
	myfgets(nome, sizeof(nome), stdin);
	*/

	printf("Bem vindo(a), %s!\n", argv[1]);

	return EXIT_SUCCESS;
}

/*
char* myfgets(char* s, int size, FILE* stream) {
	char* ret = fgets(s, size, stream);
	s[strlen(s)-1] = '\0';
	return s;
}
*/

