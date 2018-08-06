#include <stdio.h>

double fatorial(long int);
long int combinacao(long int, long int);

int main() {
	long int n, p;

	printf("Digite o valor de n: ");
	scanf("%ld", &n);

	printf("Digite o valor de p: ");
	scanf("%ld", &p);

	printf("As combinacoes de %ld valores, em grupos de %ld elementos, eh %ld.\n",
		n, p, combinacao(n, p));

	return 0;
}

long int combinacao(long int n, long int p) {
	return fatorial(n)/(fatorial(n-p) * fatorial(p));
}

double fatorial(long int x) {
	double f = 1;
	while (x >= 1) {
		f *= x--;
	}
	return f;
}

