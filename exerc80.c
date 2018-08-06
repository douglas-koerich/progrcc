#include <stdio.h>
#include <stdio_ext.h>	// contem o prototipo de __fpurge (nao use no Windows!)
#include <string.h>
#include <ctype.h>		// prototipo de isalpha

#define MAX_STRING	80

int main(void) {
	// Declaracao da variavel de "tipo" string
	char string_entrada[MAX_STRING+1];

	// Leitura da variavel
	puts("Digite uma frase: ");
	__fpurge(stdin);	// limpa o teclado no Linux; em Windows: fflush(stdin)
	fgets(string_entrada, sizeof(string_entrada), stdin);	// ou gets(string_entrada)

	// Declara uma segunda variavel string com o tamanho certo
	// para conter a primeira string invertida
	int tamanho = strlen(string_entrada);	// 'tamanho' vai ter o num. de caracteres
	char string_saida[tamanho+1];	// +1 porque strlen NAO contou o terminador nulo!

	// Usa dois indices: 'e' vai atravessar a string de entrada do fim para o comeco,
	// enquanto 's' vai, ao mesmo tempo, atravessar a string de saida do comeco para
	// o fim
	for (int s = 0, e = tamanho-1; e >= 0; --e, ++s) {
		char char_entrada = string_entrada[e];
		// Se nao for letra, soh copia
		if (!isalpha(char_entrada)) {
			string_saida[s] = char_entrada;
			continue;	// volta para o for, para a proxima iteracao (prox. caractere)
						// 'continue' eh o "oposto" do break, forca ir para repeticao
		}
		switch (toupper(char_entrada)) {
			case 'A':
			case 'E':
			case 'I':
			case 'O':
			case 'U':
				// Copia vogal para saida
				string_saida[s] = char_entrada;
				break;

			default:
				string_saida[s] = '#';
		}
	}
	string_saida[tamanho] = '\0';	// ou: string_saida[s] = '\0';	(tire decl do for)

	// Imprime string de saida
	printf("Frase criptografada: %s.\n", string_saida);

	return 0;
}

