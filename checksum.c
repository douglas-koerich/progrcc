#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define TAM	10

int checksum(unsigned char*, size_t);
unsigned long somatorio(unsigned short*, size_t);

int main(void) {
	srand((unsigned) time(0));
	unsigned short vetor[TAM];	// vetor de numeros inteiros c/ 2 bytes
	unsigned short* x = vetor;
	for (int i=0; i<TAM; ++i) {
		vetor[i] = rand() % 65536;	// unsigned short armazena: 0-65535
		/*
		x[i] = ...	// x eh indexado
		*(x+i) = ...// x eh fixo
		*x++ = ...	// nao fixa x, caminha com ele pra frente no vetor
		*/
	}
	/* Modo #0: sem ponteiro
	for (int i=0; i<TAM; ++i) {
		printf("%hu ", vetor[i]);
	}
	*/
	/* Modo #1: ponteiro v inicia no comeco do vetor e caminha por ele
	unsigned short* v = vetor;
	for (int i=0; i<TAM; ++i, ++v) {
		printf("%hu ", *v);
	}
	*/
	/*
	// Modo #2: ponteiro v inicia no comeco do vetor e eh fixo nele
	unsigned short* v = vetor;
	for (int i=0; i<TAM; ++i) {
		printf("%hu ", *(v+i));
	}
	*/
	/* Modo #3: usa o nome do vetor como ponteiro
	for (int i=0; i<TAM; ++i) {
		printf("%hu ", *(vetor+i));	// comparando com modo #0: vetor[i] <=> *(vetor+i)
	}
	*/
	// Modo #4: "indexacao de ponteiro" (se vetor[i] <=> *(vetor+i), entao ...)
	unsigned short* v = vetor;
	for (int i=0; i<TAM; ++i) {
		printf("%hu ", v[i]);	// (... *(v+i) <=> v[i]) SEM ASTERISCO ANTES DE v!!!
	}
	putchar('\n');
/*
	int chksum = checksum((unsigned char*) &vetor[0],	// cast p/ eliminar warning
						  TAM*sizeof(unsigned short));  // ha 1000 bytes em 500 shorts
	printf("\n\nO checksum do conteudo do vetor eh %d.\n", chksum);

	unsigned long soma = somatorio(vetor,	// s/ cast porque quer ver como ushort
								   TAM);	// vai olhar para 500 ushorts
	printf("A soma dos inteiros no vetor eh %lu.\n", soma);
*/
	return 0;
}

int checksum(unsigned char* p, size_t t) {	// funcao enxerga uma area de
											// memoria com unsigned char's
											// ao inves de unsigned short's
	int chksum = 0, i = 1;
	while (i <= t) {
		/*
		chksum += *p;	// pega o conteudo do byte apontado por 'p'
		++p, ++i;		// ao incrementar 'p' (endereco numerico),
						// acaba por apontar para o proximo byte no vetor
		*/
		chksum += *p++;	// 1) pega o conteudo; 2) incrementa o ponteiro
						// diferente de ++*p (incrementa o conteudo!)
		++i;
	}
	return chksum;
}

unsigned long somatorio(unsigned short* p, size_t t) {
	unsigned long soma = 0;
	int i = 1;
	while (i <= t) {
		soma += *p;
		++i, ++p;	// ++p faz o numero aumentar de 2 (tamanho de cada short)
	}
	return soma;
}

