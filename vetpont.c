#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define TAMANHO 10

// 'const' indica para a funcao que o ponteiro/vetor passado como parametro eh READ-ONLY
double soma_v(const double[*], size_t);		// passagem de vetor pra funcao
double soma_p(const double*, size_t);		// passagem de ponteiro pra funcao

int main() {
	double vetor[TAMANHO];
	int i;

	for (i=0; i<TAMANHO; ++i) {
		vetor[i] = exp(i);		// e^i ('e' eh o numero de Euler)
	}

	// Alternativa #1: uso do vetor diretamente
	for (i=0; i<TAMANHO; ++i) {
		printf("%lf ", vetor[i]);
	}
	printf("(soma_v=%lf)\n", soma_v(vetor, TAMANHO));

	// Alternativa #2: ponteiro que recebe o endereco de cada elemento
	for (i=0; i<TAMANHO; ++i) {
		double* p = &vetor[i];
		printf("%lf ", *p);
	}
	putchar('\n');

	// Alternativa #3: ponteiro recebe o endereco do primeiro elemento
	// e usamos aritmetica para percorrer os demais
	double* p = &vetor[0];
	for (i=0; i<TAMANHO; ++i) {
		printf("%lf ", *p);
		++p;	// p vai apontar para o proximo double na memoria/no vetor
	}
	putchar('\n');

	// Alternativa #4: "O NOME/identificador da variavel-vetor eh interpretado
	// pelo compilador como o ENDERECO do seu primeiro elemento"
	p = vetor;	// vetor <=> &vetor[0]
	for (i=0; i<TAMANHO; ++i) {
		printf("%lf ", *p++);	// ++ depois: pega o valor (*p) e depois incrementa p
	}
	// Alternativa #4.a:
	// for (i=0, p=vetor; i<TAMANHO; ++i, ++p) {
	//     printf("%lf ", *p);
	// }
	putchar('\n');

	// Alternativa #5: o ponteiro nao muda ao longo do laco
	for (i=0, p=vetor; i<TAMANHO; ++i) {
		printf("%lf ", *(p+i));	// os parenteses em *(p+i) sao necessarios!!!
	}
	printf("(soma_p=%lf)\n", soma_p(p, TAMANHO));	// p foi preservado ateh aqui

	// Alternativa #6: usando o vetor como se fosse um ponteiro
	// ATENCAO: 'vetor' eh um ponteiro CONSTANTE, entao nao eh possivel fazer ++vetor!!
	for (i=0; i<TAMANHO; ++i) {
		printf("%lf ", *(vetor+i));	// vetor[i] <=> *(vetor+i)
	}								// de onde se deduz que: vetor+i <=> &vetor[i]
	printf("(soma_p=%lf)\n", soma_p(vetor, TAMANHO));	// vetor eh um "endereco"

	// Alternativa #7: usando o ponteiro como se fosse um vetor
	for (i=0, p=vetor; i<TAMANHO; ++i) {
		printf("%lf ", p[i]);	// *(p+i) <=> p[i]	// indexacao no ponteiro
	}							// ATENCAO: !!!NAO!!! eh aplicado * nesse caso, [] o substitui
	putchar('\n');
	

	return 0;
}

double soma_v(const double v[], size_t tam) {
	double soma = 0.0;
	int i;
	for (i=0; i<tam; ++i) {
		soma += v[i];
	}
	return soma;
}

double soma_p(const double* x, size_t tam) {
	double soma = 0.0;
	int i;
	for (i=0; i<tam; ++i) {
		soma += *x++;		// igual a Alternativa #4
		// soma += *(x+i);	// igual a Alternativa #5
		// soma += x[i];	// igual a Alternativa #7
	}
	return soma;
}

