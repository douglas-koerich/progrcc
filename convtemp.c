#include <stdio.h>

void converte(int, float, float *, float *);

int main(void) {
	float entrada, saida1, saida2;
	int tipo;

	do {
		printf("Digite a unidade de medida (1=celsius; 2=fahrenheit; 3=kelvin): ");
		scanf("%d", &tipo);
	} while (tipo < 1 || tipo > 3);

	printf("Digite o valor da temperatura: ");
	scanf("%f", &entrada);

	converte(tipo, entrada, &saida1, &saida2);

	switch (tipo) {
		case 1:
			printf("%.1f celsius equivale a %.1f fahrenheit e %.1f kelvin.\n",
				   entrada, saida1, saida2);
			break;

		case 2:
			printf("%.1f fahrenheit equivale a %.1f celsius e %.1f kelvin.\n",
				   entrada, saida1, saida2);
			break;

		case 3:
			printf("%.1f kelvin equivale a %.1f fahrenheit e %.1f celsius.\n",
				   entrada, saida1, saida2);
			break;

		default:
			puts("NAO DEVERIA NUNCA CHEGAR AQUI!");
	}
	return 0;
}

void converte(int t, float in, float *out1, float *out2) {
	switch (t) {
		case 1:
			// in (C), out1 (F), out2 (K)
			*out1 = 9 * in/5 + 32;
			*out2 = in + 273;
			break;

		case 2:
			// in (F), out1 (C), out2 (K)
			*out1 = 5*(in - 32)/9;
			*out2 = *out1 + 273;
			break;

		case 3:
			// in (K), out1 (F), out2 (C)
			*out2 = in - 273;
			*out1 = 9*(*out2)/5 + 32;
			break;

		default:
			puts("NAO DEVERIA NUNCA CHEGAR AQUI!");
	}
}
