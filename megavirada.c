#include <stdio.h>

/*
double calculaFatorial(double y) {	// y eh um 'parametro'
	double x, f;			// x e f sao variaveis locais (soh visiveis na funcao)
	for (x=f=1; x<=y; ++x) {
		f *= x;
	}
	return f;
}
*/

// Prototipos das funcoes ("declaracao")
double calculaFatorial(double);						// funcao
double calculaCombinacao(double, double, double);	// funcao
void imprimeCombinacao(double);						// procedimento (nao tem retorno)
void dahTchau(void);								// procedimento (sem retorno nem parametro)

int main() {
	double n, p, C; // numeros de 64 bits
	double fat_n, fat_p, fat_n_p;	// n!, p!, (n-p)!

	printf("Quantos valores para combinar? ");
	scanf("%lf", &n);

	printf("Quantos elementos em cada combinacao? ");
	scanf("%lf", &p);

	// Laco para calcular o fatorial de n
	/*
	double i;
	for (i=fat_n=1; i<=n; ++i) {
		fat_n *= i;
	}
	*/
	fat_n = calculaFatorial(n);

	// Laco para calcular o fatorial de p
	/*
	for (i=fat_p=1; i<=p; ++i) {
		fat_p *= i;
	}
	*/
	fat_p = calculaFatorial(p);

	// Laco para calcular o fatorial de n-p
	/*
	for (i=fat_n_p=1; i<=(n-p); ++i) {
		fat_n_p *= i;
	}
	*/
	fat_n_p = calculaFatorial(n-p);	// subtrai primeiro e passa para funcao depois

	// Calculo da combinacao
	// C = fat_n / (fat_n_p * fat_p);
	C = calculaCombinacao(fat_n, fat_n_p, fat_p);

	/*
	 * C = calculaFatorial(n) / (calculaFatorial(p) * calculaFatorial(n-p));
	 */

	// printf("O numero de combinacoes eh %lf\n", C);
	/*
	 * printf("O numero de combinacoes eh %lf\n",
	 * 		  calculaFatorial(n) / (calculaFatorial(p) * calculaFatorial(n-p)));
	 */
	imprimeCombinacao(C);

	dahTchau();

	return 0;
}

double calculaFatorial(double y) {	// y eh um 'parametro'
	double x, f;			// x e f sao variaveis locais (soh visiveis na funcao)
	for (x=f=1; x<=y; ++x) {
		f *= x;
	}
	return f;
}

double calculaCombinacao(double a, double b, double c) {
	double C;	// nao eh a mesma variavel de main()
	C = a / (b * c);
	return C;
}

void imprimeCombinacao(double X) {
	if (X < 0) {
		return;	// sai da funcao imediatamente
	}
	printf("O numero de combinacoes eh %lf\n", X);
}

void dahTchau(void) {
	printf("Ate logo!\n");
}

