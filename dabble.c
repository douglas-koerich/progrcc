#include <stdlib.h>		// exit()
#include <stdio.h>		// printf(), gets(), ...
#include <stdio_ext.h>	// __fpurge()

#define MAX_BITS	16

main() {
	char binario[MAX_BITS+1];
	int i;
	short num; // inteiro de 16 bits

	puts("Digite um numero binario com 16 bits max.:");
	__fpurge(stdin);	// while ((c=getchar()) == '\n' && c != EOF);
	// em windows seria fflush(stdin);	(sem o stdio_ext lah em cima)
	gets(binario);

	i = num = 0;
	while (binario[i] != '\0') {	// enquanto nao acha o fim da string
		if (binario[i] != '0' && binario[i] != '1') {
			puts("Numero invalido, nao eh binario!!!");
			exit(-1);	// sai imediatamente do programa
		}
		num += binario[i] - '0';	// converte algarismo caracter -> int
		if (binario[i+1]) {		// se diferente de nulo/falso -> verdadeiro
			num *= 2;
		}
		++i;
	}
	printf("O numero em decimal eh %hd.\n", num);
}

