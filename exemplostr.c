#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>

#define MAX_STRING	30

unsigned contaVogais(char [*]);	// o terminador nulo dispensa passar tam.

int main(void) {
	char var_string[MAX_STRING+1] = "inicial";	// conteudo inicial
	char outra[MAX_STRING+1];
/*
	printf("Digite uma palavra: ");
	scanf("%s", var_string);	// sem o & (porque eh um vetor!)

	printf("A palavra digitada foi %s.\n", var_string);
*/

	printf("Digite uma frase: ");
	gets(var_string);	// sem protecao de tamanho
	// fgets(var_string, sizeof(var_string), stdin);	// com protecao
	__fpurge(stdin);	// limpar o teclado p/ um proximo gets/fgets/getchar
						// em Windows: fflush(stdin)
	
	// Copia de var_string para outra
	// outra = var_string;	/*** INVALIDO! ***/
	strcpy(outra, var_string);

	printf("A frase digitada foi \"%s\" com %u vogais.\n", outra,
		   contaVogais(outra));
	puts(var_string);	// imprime a string isoladamente

	puts("Fim do programa");
	return 0;
}

unsigned contaVogais(char string[]) {
	unsigned contador = 0, indice = 0;
	unsigned tamanho = strlen(string);
	while (indice < tamanho) {
	/*
	while (string[indice] != '\0') { // enquanto nao chega no fim da string
	*/
		char maius = toupper(string[indice]); // converte o caracter
		if (maius == 'A' || maius == 'E' ||
			maius == 'I' || maius == 'O' || maius == 'U') {
			++contador;
		}
		++indice;	// vai para a proxima letra da string (ou \0 se fim)
	}
	return contador;
}

