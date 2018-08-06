#include <stdio.h>
#include <stdio_ext.h>
#include <ctype.h>

#define MAX	100

int main(void) {
	char frase[MAX+1];	// espaco extra para o terminador nulo!

	/* Para brincarmos com o __fpurge
	char usuario[MAX+1];
	puts("Qual o seu nome?");
	gets(usuario);
	printf("Quantos anos voce tem? ");
	int idade;
	scanf("%d", &idade);

	printf("Caro(a) %s, digite uma frase: ", usuario);
	// fflush(stdin);
	__fpurge(stdin);
	*/
	puts("Digite uma frase: ");
	gets(frase);

	/*
	int i, contador;
	for (i=contador=0; frase[i] != '\0'; ++i) {
	*/
	int i = 0, contador = 0;
	while (frase[i]) {	// while (frase[i] != '\0')
		char simbolo = toupper(frase[i]);	// cada elemento eh um char
		switch (simbolo) {
			case 'A':
			case 'E':
			case 'I':
			case 'O':
			case 'U':
				++contador;
				break;

			default:
				;	// nao faz nada, eh consoante, algarismo ou etc.
		}
		++i;
	}
	puts(frase);
	printf("A frase comeca com %c.\n", frase[0]);
	printf("Foram digitadas %d vogais.\n", contador);
	return 0;
}

