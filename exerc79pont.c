#include <stdio.h>
#include <ctype.h>

#define TAM	50

int main() {
	char frase[TAM];	// Variavel-string
	
	// A partir daqui, vou usar apenas ponteiro para me referir ao vetor
	// char* pc = &frase[0];// endereco do primeiro caracter no vetor (string)
	char* pc = frase;

	printf("Digite uma frase: ");
	gets(pc);	// gets(frase);

	unsigned vogais = 0;
	int i;
	
	/*
	char* paux = pc;	// Vou usar um auxiliar pq nao posso perder pc (usado no puts)
	for (i = 0; *paux != '\0'; ++i, ++paux) {	// Percorrer ateh o fim da string
		switch (toupper(*paux)) {		// Analisa elemento a elemento da string
	*/
	
	/*
	for (i = 0; *(pc+i) != '\0'; ++i) {	// for (i = 0; frase[i] != '\0'; ++i) {
		switch (toupper(*(pc+i))) {		// 		switch (toupper(frase[i])) {
	*/
	
	for (i = 0; *(frase+i) != '\0'; ++i) {	// frase[i] <==> *(frase+i)
		switch (toupper(*(frase+i))) {		// eh proibido fazer: frase++
			case 'A':
			case 'E':
			case 'I':
			case 'O':
			case 'U':
				++vogais;
				break;

			default:
				;		// nao faz nada, vamos para o proximo caracter
		}
	}

	puts("Abaixo esta reproduzida a frase:\n");	// vai saltar uma linha extra
	puts(pc);	// puts(frase);
	printf("O numero de vogais eh %u.\n", vogais);

	return 0;
}
