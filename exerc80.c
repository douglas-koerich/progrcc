#include <stdio.h>
#include <ctype.h>

#define MAX	100

int main(void) {
	char frase[MAX+1], invertida[MAX+1];
	puts("Digite uma frase:");
	gets(frase);

	/*
	// Procura o fim da string do usuario
	int i=0;
	while (frase[i] != '\0') {
		++i;	// quando termina, i indica o nulo
	}
	*/
	int i = strlen(frase);	// posiciona no indice igual ao tamanho da
							// string, i.e., sobre o terminador nulo
	int j=0;
	// Precisa decrementar o i antes, porque ele inicia na posicao do nulo
	while (--i >= 0) {	// enquanto nao alcanca o inicio da frase...
		if (!isalpha(frase[i])) {	// nao eh uma letra (alpha)?
			invertida[j] = frase[i];// copia o simbolo como ele eh
		}
		else {
			char letra = tolower(frase[i]);
			switch (letra) {
				case 'a': case 'e': case 'i': case 'o': case 'u':
					invertida[j] = frase[i];	// copia vogal original
					break;

				default:
					invertida[j] = '#';
			}
		}
		++j;
	}
	invertida[j] = '\0';	// nesse ponto j esta depois da ultima letra
	printf("A frase invertida eh %s.\n", invertida);

	return 0;
}

