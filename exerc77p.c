#include <stdio.h>
#include <ctype.h>

#define MAX_FRASE	100

int main(void) {
	char frase[MAX_FRASE+1], *pc = frase;
	unsigned contador = 0;
	int nivel = 0;	// 0 = espaco; 1 = letra/numero (palavra)

	puts("Digite uma frase abaixo:");
	gets(pc);

	while (*pc != '\0') {
		if (isalnum(*pc)) {
			if (nivel == 0) { // era espaco antes?
				++contador;
			}
			nivel = 1;	// passa a ser (ou continua como) letra/numero
		}
		else {
			nivel = 0;	// passa a ser (ou continua como) espaco/pontuacao
		}
		++pc;
	}
	printf("A frase '%s' tem %u palavras.\n", frase, contador);
	return 0;
}

