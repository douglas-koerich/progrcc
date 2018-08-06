#include <stdio.h>

int main() {
	int total1, total2, total3, total0, total_1, N, v, voto;

	printf("Quantos votos serao processados? ");
	scanf("%d", &N);

	for (total1 = total2 = total3 = total0 = total_1 = 0, v = 1;
		 v <= N; ++v) {
		printf("Digite seu voto (%d): ", v);
		scanf("%d", &voto);

		switch (voto) {
			case 1: ++total1; break;
			case 2: ++total2; break;
			case 3: ++total3; break;
			case 0: ++total0; break;
			case -1: ++total_1; break;
			default: printf("Voto invalido!\n");
					 --v;	// pra compensar o ++v, pq este voto nao conta!
		}
	}
	// Letras a, b, c
	printf("Total de votos: 1=%d, 2=%d, 3=%d, brancos=%d, nulos=%d.\n",
		   total1, total2, total3, total0, total_1);

	// Letra d
	if (total0 + total_1 == N) {
		printf("Nao houve vencedor (ninguem recebeu votos)!\n");
	}
	else {
		if (total1 > total2) {
			if (total1 > total3) {
				printf("O candidato 1 venceu!\n");
			}
			else {
				printf("O candidato 3 venceu!\n");
			}
		}
		else {
			if (total2 > total3) {
				printf("O candidato 2 venceu!\n");
			}
			else {
				printf("O candidato 3 venceu!\n");
			}
		}
	}
	return 0;
}

