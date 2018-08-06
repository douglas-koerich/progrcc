#include <stdio.h>
#include <math.h>	// necessario para a funcao sqrt() da biblioteca
					// nao esqueca de usar -lm no final da linha do gcc!

int main(void) {
	int a, b, c;	// normal seria real, mas pensemos em triangulos com
					// lados inteiros... :-)
	printf("Digite o lado a: "); scanf("%d", &a);
	printf("Digite o lado b: "); scanf("%d", &b);
	printf("Digite o lado c: "); scanf("%d", &c);

	float s = (a + b + c) / 2.0;	// parenteses sao obrigatorios aqui!!!
									// usei 2.0 pra forcar divisao real
	float K = sqrt(s * (s-a) * (s-b) * (s-c));

	printf("O semiperimetro eh %.1f e a area eh %.3f.\n", s, K);
	return 0;
}

