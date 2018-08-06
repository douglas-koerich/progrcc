#include <stdio.h>
#include <math.h>

int main() {
	int termos;
	do {
		printf("Digite o numero de termos da serie (max. 50): ");
		scanf("%d", &termos);
	} while (termos > 50);
	
	float S = 0.0;
	float t;
	int n, num;

	for (n=num=1; n<=termos; ++n, num+=2) {
		t = 1.0 / pow(num, 3);
		if (n % 2 == 0) {
			S -= t;
		}
		else {
			S += t;
		}
	}

	float pi = pow(S*32, 1.0/3);
	printf("O valor de pi calculado com %d termos eh %f.\n", termos, pi);

	return 0;
}

