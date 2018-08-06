#include <stdio.h>

double numBacterias(double, double, int);

int main(void) {
	double populacao_inicial, taxa_cresc_segundo;
	int periodo;

	printf("Qual eh a populacao inicial de bacterias? ");
	scanf("%le", &populacao_inicial);
	printf("Qual a taxa de crescimento (bacterias/segundo)? ");
	scanf("%lf", &taxa_cresc_segundo);
	printf("Quantos dias para populacao final? ");
	scanf("%d", &periodo);

	printf("A populacao final serah de %e bacterias.\n",
		   numBacterias(populacao_inicial, taxa_cresc_segundo, periodo));

	return 0;
}

double numBacterias(double n0, double p, int dias) {
	double num = n0;
	int d;
	for (d=1; d<=dias; ++d) {
		int h;
		for (h=1; h<=24; ++h) {
			int m;
			for (m=1; m<=60; ++m) {
				int s;
				for (s=1; s<=60; ++s) {
					num = num * (1 + p);
				}
			}
		}
		// printf("Populacao no fim do %do. dia: %e\n", d, num);
	}
	/*
	int s, segtotal = dias * 24 * 60 * 60;
	for (s = 1; s <= segtotal; ++s) {
		num = num * (1 + p);
	}
	*/
	return num;
}

