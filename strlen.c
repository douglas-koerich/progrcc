#include <stdio.h>

// size_t minha_strlen(char [*]);
size_t minha_strlen(char*);

int main(void) {
	char string[30];

	printf("Digite uma frase: ");
	gets(string);

	printf("O comprimento da frase eh de %u caracteres.\n",
		   minha_strlen(string));

	return 0;
}

size_t minha_strlen(char* str) {
	size_t tamanho = 0;
	for (int i=0; str[i] != '\0'; ++i) {
	// for (int i=0; *(str+i) != '\0'; ++i) {
		++tamanho;
	}
	return tamanho;
}

