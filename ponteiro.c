#include <stdlib.h>
#include <stdio.h>

#if 0
void muda(int*, int*);

int main(void) {
	/*
	char a, b = ' ';
	char* x; // ponteiro para um char, mas com endereco indefinido
	char* y = NULL; // (NULL = 0) <-- eh um endereco INVALIDO, portanto y nao pode ser
				    // usado
	// char *x, *y; <-- 2 ponteiros declarados
	// char x, *y; <-- x eh um char, y eh um ponteiro para um char

	// Operador de referencia ("endereco de")
	x = &a;
	y = &b;

	printf("Digite um caractere qualquer: ");
	// scanf(" %c", &a);
	scanf(" %c", x); // agora NAO PODE ter o & (pois x jah eh um endereco!)

	// Operador de indirecao ("conteudo no endereco")
	// b = a;
	*y = a;

	printf("Voce digitou o caractere '%c'\n", b);
	*/

	int a = 5, b = 10;
	printf("a = %d, b = %d\n", a, b);
	/*
	int* pa = &a;
	int* pb = &b;
	*pa = 20;
	*pb = 50;
	*/
	muda(&a, &b);
	printf("a = %d, b = %d\n", a, b);

	return EXIT_SUCCESS;
}

void muda(int* a, int* b) {
	printf("Em a = %d, em b = %d\n", *a, *b);
	printf("Digite novo valor de a: ");
	scanf("%d", a); // <-- a jah eh o endereco de memoria a ser alterado
 	printf("Digite o novo valor para b: ");
	scanf("%d", b);
	printf("a = %d, b = %d\n", *a, *b);
}

#define MAX 5

int main(void) {
	int vetor[MAX], c, *p = vetor; /* O nome de uma variavel-vetor eh interpretado
								      pelo compilador como sendo um "ponteiro"
									  CONSTANTE para o endereco do seu primeiro
									  elemento na memoria */
	int i;
	for (i = 0, c = 'A'; i < MAX; ++i, ++c, ++p) {
		*p = c;
		printf("%d ", *p);
	}
	/*
	for (i = 0; i < MAX; ++i, ++vetor) { <-- "vetor" nao pode ser alterado!!!
		printf("%c ", *vetor);
	}
	*/
	putchar('\n');
	return EXIT_SUCCESS;
}

#define NUM 3

float calc_media(const int*, size_t);

int main(void) {
	int vet[NUM] = { 3, 6, -2 };
	float media = calc_media(vet, NUM);
	printf("A media eh %f\n", media);
	return EXIT_SUCCESS;
}
#endif

float calc_media(const int* v, size_t n) {
	float s = 0.0;
	int i;
	for (i = 0; i < n; ++i, ++v) {
		s += *v;
	}
	return s / n;
}

int main(void) {
	size_t tamanho;
	printf("Digite o numero de elementos do vetor a ser preenchido: ");
	scanf("%zu", &tamanho);

	/*
	int vetor[tamanho]; // soh eh valido para opcao de compilacao >= C99 (C11, C14)
	*/
	int* vetor = malloc(tamanho * sizeof(int)); // comprimento do bloco de memoria em BYTES
	
	int i;
	for (i = 0; i < tamanho; ++i) {
		printf("Digite o valor a ser armazenado na posicao/indice [%d]: ", i);
		scanf("%d", vetor + i); // scanf("%d", &vetor[i]);
	}

	float m = calc_media(vetor, tamanho);

	free(vetor); // deve passar o ***MESMO*** valor de endereco recebido do malloc

	printf("A media do conteudo do vetor eh %.2f\n", m);

	return EXIT_SUCCESS;
}