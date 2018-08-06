/*
DS = RESTO[ TRUNCA(2,6 x M - 0,1) + D + A + QUOCIENTE(A, 4) + QUOCIENTE(S, 4) - 2 x S, 7]
*/

#include <stdio.h>

int main() {
	int D, M, A, S, DS;
	float F;
	int I;

	printf("Dia (1-31)? "); scanf("%d", &D);
	printf("Mes (1-12)? "); scanf("%d", &M);
	printf("Ano (AAAA)? "); scanf("%d", &A);

	if (M == 1 || M == 2) {
		M += 10;
		--A;
	}
	else {
		M -= 2;
	}
	S = A / 100;
	A = A % 100;

	F = 2.6 * M - 0.1;
	I = F;	// TRUNCA

	DS = (I + D + A + A/4 + S/4 - 2*S) % 7;

	printf("Dia da semana: ");
	switch (DS) {
		case 0: printf("Domingo\n");
				break;
		case 1: printf("Segunda-feira\n");
				break;
		case 2: printf("Terca-feira\n");
				break;
		case 3: printf("Quarta-feira\n");
				break;
		case 4: printf("Quinta-feira\n");
				break;
		case 5: printf("Sexta-feira\n");
				break;
		case 6: printf("Sabado\n");
				break;
	}
	return 0;
}

