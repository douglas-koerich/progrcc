#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define TAM	20

int main(void) {
	int vetor[TAM], repetidos[TAM], i, j, r = 0;
	int *pv = NULL, *pr = repetidos;

	// Inicializa a "semente" de numeros randomicos
	srand((unsigned)time(0));	// usa o wall clock do PC como semente

	// Preenche o vetor com numeros aleatorios de 0 a 9
	for (i=0, pv = vetor; i<TAM; ++i, ++pv) {
		*pv = rand() % 10;
	}
	// Para cada elemento/numero na posicao i do vetor...
	for (i=0; i<TAM; ++i) {
		bool ehRepetido = false;

		// ... verifica se ja nao esta no vetor de "memoria"
		for (j=0; j<r && !ehRepetido /* ehRepetido == false */; ++j) {
			if (*(vetor+i) == *(repetidos+j)) {
				// Ja contei esse numero, passa para o proximo
				ehRepetido = true;
			}
		}
		if (ehRepetido) {
			// Esquece este numero, vou para o proximo
			continue;	// abandona o resto do laco, vai p/ outro passo
		}
		int contador;

		// ... varre as posicoes seguintes (i+1, i+2, ...)
		for (j=i+1, contador=1; j<TAM; ++j) {
			// ... procurando o mesmo valor nessas posicoes
			if (*(vetor+j) == *(vetor+i)) {
				++contador;
			}
		}
		if (contador > 1) {	// eh repetido?
			printf("O valor %d se repete %d vezes.\n", *(vetor+i), contador);
			
			// Para nao considera-lo novamente quando incrementar i,
			// grava num vetor de "memoria"
			*pr++ = *(vetor+i);	// salva no conteudo de pr, dai incrementa
			++r;
		}
	}
	for (i=0, pv=vetor; i<TAM; ++i) {
		printf("%d ", pv[i]);	// abri excecao p/ mostrar indexacao de ponteiro
	}
	putchar('\n');
	return 0;
}

