#include <stdio.h>

int kombi(int, int);
int fatorial(int);

int main(void) {
	int n, p;

	printf("Digite o numero de elementos (n): ");
	scanf("%d", &n);
	printf("Digite o tamanho da associacao (p): ");
	scanf("%d", &p);

	printf("Numero de combinacoes desses elementos: %d\n",
		   kombi(n, p));

	return 0;
}

int kombi(int n, int r) {
	int fat_n, fat_r, fat_n_r, C;

	/*
	for (i=fat_n=1; i<=n; ++i) {
		fat_n = fat_n * i;
	}
	*/
	fat_n = fatorial(n);

	/*
	for (i=fat_r=1; i<=r; ++i) {
		fat_r = fat_r * i;
	}
	*/
	fat_r = fatorial(r);

	/*
	for (i=fat_n_r=1; i<=(n-r); ++i) {
		fat_n_r = fat_n_r * i;
	}
	*/
	fat_n_r = fatorial(n-r);

	C = fat_n / (fat_r * fat_n_r);

	return C;
}

int fatorial(int x) {
	int i, f;
	for (i=f=1; i<=x; ++i) {
		f = f * i;
	}
	return f;
}
