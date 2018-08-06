#include <stdio.h>

#define NUM	4

int main() {
	float f[NUM] = { 3.14, 2.71828, -1.5, 4.0 };

	// Vamos imprimir o vetor como estavamos acostumados
	int i;
	printf("*** Conteudo do vetor: ");
	for (i=0; i<NUM; ++i) {
		printf("%f ", f[i]);
	}
	putchar('\n');

	// Imprimindo usando o ponteiro
	float *p = &f[0];
	printf("*** Usando aritmetica de ponteiro pra se deslocar: ");
	for (i=0; i<NUM; ++i) {
		printf("%f@%p ", *p, p);
		++p;	// apontar para o proximo no vetor
	}
	putchar('\n');

	// Duas variantes da versao acima -
	// 1a. opcao:
	// float *p;
	// for (i=0, p=&f[0]; i<NUM; ++i, ++p) {
	// 	printf("%f ", *p);
	// }
	//
	// 2a. opcao:
	// float *p = &f[0];
	// int i = 0;
	// while (i < NUM) {
	// 	printf("%f ", *p++);
	// 	++i;
	// }
	
	/*********************************************************
	 * "O nome da variavel-vetor sem colchetes eh interpretado
	 * pelo compilador como sendo o ENDERECO do primeiro
	 * elemento desse vetor."
	 * Quer dizer: f <=> &f[0]
	 * 'f' eh como um ponteiro FIXO (nao pode ter o valor
	 * alterado)
	 ********************************************************/

	float *q = f;	// repare: SEM o & na frente! (equivale a um ponteiro!)
	printf(">>> Vendo 'f' como um endereco: ");
	for (i=0; i<NUM; ++i, ++q) {
		printf("%f ", *q);
	}
	putchar('\n');

	float *r = f;
	printf("+++ Agora sem alterar o valor do ponteiro, dando saltos a partir dele: ");
	for (i=0; i<NUM; ++i) {
		printf("%f ", *(r+i));
	}
	putchar('\n');

	printf("vvv Sem usar um ponteiro extra, usando o proprio vetor como ponteiro: ");
	for (i=0; i<NUM; ++i) {
		printf("%f ", *(f+i));	// 'f' (sem colchetes) eh um ponteiro!!!
	}
	putchar('\n');

	// Comparando este ultimo laco acima com o primeiro do programa (que
	// usou o vetor na forma convencional), deduz-se que:
	// f[i] <=> *(f+i)
	
	r = f;	// reuso do ponteiro declarado: float *r;
	printf("*** Com INDEXACAO de ponteiro: ");
	for (i=0; i<NUM; ++i) {
		printf("%f ", r[i]);	// pela mesma regra: *(r+i) <=> r[i]
	}
	putchar('\n');

	/*
	printf("p contem inicialmente o endereco %p com o valor %f\n", p, *p);
	p += 2;	// desloca-se 2 posicoes (2 floats) na memoria a frente (+)
	printf("p agora contem o endereco %p com o valor %f\n", p, *p);
	--p;	// desloca-se para tras 1 posicao (1 float) na memoria
	printf("p finalmente contem o endereco %p com o valor %f\n", p, *p);
	*/

	return 0;
}

