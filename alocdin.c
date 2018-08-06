#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
/*
#include <sys/time.h>
#include <sys/resource.h>
*/
#define MAX 30000000	// se for alocado na pilha vai abortar o programa

int main() {
	// double vetor[MAX];
	double* vetor = (double*) malloc(sizeof(double)*MAX);
	int i;
/*
	struct rlimit rlim;
	if (getrlimit(RLIMIT_STACK, &rlim) < 0) {
		puts("Nao pode ler o valor limite da pilha");
		return EXIT_FAILURE;
	}
	printf("Pilha: cur=%lld, max=%lld.\n", (long long) rlim.rlim_cur, (long long) rlim.rlim_max);
*/
	srand((unsigned) time(0));

	for (i=0; i<MAX; ++i) {
		vetor[i] = (rand() % 1000) * log10(i);
		// PERIGO: *vetor++ = ...
		// Pode fazer: *(vetor+i) = ...
	}

	/*
	for (i=0; i<MAX; ++i) {
		printf("%lf\n", vetor[i]);
	}
	*/
	printf("Primeiro numero: %lf\n", *vetor);
	printf("Ultimo numero: %lf\n", *(vetor+MAX-1));	// vetor[MAX-1]

	// Nao esquecer de liberar a memoria antes de sair do programa!!!
	free(vetor);

	puts("Fim do programa");
	return 0;
}

