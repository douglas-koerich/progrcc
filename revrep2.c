#include <stdio.h>

int main() {
	unsigned n, fn, fn_1, fn_2, num_termo;

	printf("Digite a ordem do termo procurado: ");
	scanf("%u", &n);

	if (n <= 1) {
		fn = n;
	}
	else {
		num_termo = 2;
		fn_1 = 1;
		fn_2 = 0;	// para num_termo=2: f2 = f1 + f0
		do {
			fn = fn_1 + fn_2;	// formula do passo do laco
			fn_2 = fn_1;		// fn_1 vai ser o fn_2 no proximo passo
			fn_1 = fn;			// fn vai ser o fn_1 no proximo passo
		}
		while (++num_termo <= n);	// incrementa antes e compara
	}

	printf("O %uo. termo da serie de Fibonacci eh %u.\n", n, fn);

	return 0;
}

