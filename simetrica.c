#include <stdio.h>
#include <stdbool.h>

bool ehSimetrica(size_t, int[*][*]);

int main() {
	size_t ordem;

	printf("Defina a ordem da matriz: ");
	scanf("%u", &ordem);

	int matriz[ordem][ordem];
	int l, c;

	for (l=0; l<ordem; ++l) {
		for (c=0; c<ordem; ++c) {
			printf("Digite o numero na posicao %d,%d: ", l, c);
			scanf("%d", &matriz[l][c]);
		}
	}
	bool resultado = ehSimetrica(ordem, matriz);

	printf("A matriz %s simetrica!\n", resultado? "EH": "NAO EH");

	return 0;
}

bool ehSimetrica(size_t dimensao, int matriz[dimensao][dimensao]) {
	/*
	// 1o. jeito (trabalhoso)
	int transposta[dimensao][dimensao];
	size_t l, c;

	for (l=0; l<dimensao; ++l) {
		for (c=0; c<dimensao; ++c) {
			transposta[c][l] = matriz[l][c];
		}
	}

	for (l=0; l<dimensao; ++l) {
		for (c=0; c<dimensao; ++c) {
			if (matriz[l][c] != transposta[l][c]) {
				return false;
			}
		}
	}
	// Se cheguei ateh aqui, todas as posicoes coincidiram entre
	// matriz e transposta
	return true;
	*/

	// 2o. jeito: a matriz simetrica tem igualdade entre os elementos
	// equidistantes da diagonal principal
	int l, c;
	for (l=0; l<dimensao; ++l) {
		for (c=0; c<dimensao; ++c) {
			if (matriz[l][c] != matriz[c][l]) {
				return false;
			}
		}
	}
	return true;
}

