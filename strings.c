#include <stdio.h>
#ifndef WIN32	// se NAO em windows
#include <stdio_ext.h> 	// para o __fpurge usado no linux
#endif

#define MAX	50

int main() {
	// Declaracao de string com inicializacao
	char string[MAX+1] = "Teste";	// MAX caracteres + 1 terminador nulo
	char outra[MAX+1];

	printf("A string inicializada eh %s\n", string);	// sem colchetes ([])

	printf("Digite o conteudo da segunda string (max. 50): ");
	scanf(" %s", outra);	// Espaco antes do %s; NAO antepor o & na variavel nesse caso!!!
	printf("A string digitada foi %s\n", outra);

	printf("Digite novamente: ");
	// Precisa limpar o buffer do teclado no sistema
#ifdef WIN32	// em windows
	fflush(stdin);
#else			// caso contrario (ex. linux)
	__fpurge(stdin);
#endif
	gets(outra);
	printf("A nova tentativa foi %s\n", outra);

	puts("Esta eh uma string constante");
	puts(outra);	// para imprimir uma string variavel

	return 0;
}

