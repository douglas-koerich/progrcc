#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdio_ext.h>

void imprimeMargem(size_t);
void imprimeFila(bool [*], size_t, char [*]);
void imprimeNumeros(size_t);
void imprimeOnibus(bool [*], bool [*], bool [*], bool [*], size_t);
size_t imprimeLivres(bool [*], size_t);
void vendePoltrona(bool [*], size_t);

#define NUM_FILAS	12

int main(void) {
	int opcao;

	// Inicializacao de vetores:
	bool je[NUM_FILAS] = { true, false, true, false, false, false,
						   false, true, true, false, false, false };

	bool ce[NUM_FILAS] = { true }; // todos os demais zerados (0 = false)
	bool cd[] = { true, true, true, true, true, true,
		          true, true, false, true, true, true };
	bool jd[NUM_FILAS] = { false, true, [6] = true };	// inicializa indices 0, 1 e 6

	do {
		system("clear");	// em Windows, "cls"
		printf("### VIACAO METEORO ###\n");
		printf("1. Janela direita\n");
		printf("2. Corredor direito\n");
		printf("3. Corredor esquerdo\n");
		printf("4. Janela esquerda\n");
		printf("0. Fim do programa\n");
		imprimeOnibus(je, ce, jd, cd, NUM_FILAS);

		do {
			printf("Opcao? ==> ");
			scanf("%d", &opcao);
		} while (opcao < 0 || opcao > 4);

		switch (opcao) {
			case 1:
				if (imprimeLivres(jd, NUM_FILAS) > 0) {
					vendePoltrona(jd, NUM_FILAS);
				}
				break;

			case 2: 
				if (imprimeLivres(cd, NUM_FILAS) > 0) {
					vendePoltrona(cd, NUM_FILAS);
				}
				break;

			case 3: 
				if (imprimeLivres(ce, NUM_FILAS) > 0) {
					vendePoltrona(ce, NUM_FILAS);
				}
				break;

			case 4: 
				if (imprimeLivres(je, NUM_FILAS) > 0) {
					vendePoltrona(je, NUM_FILAS);
				}
				break;

			default:
				; // nao faz nada, o laco vai terminar
		}
	} while (opcao != 0);

	return 0;
}

void imprimeMargem(size_t filas) {
	size_t f;
	for (f = 0; f < filas; ++f) {
		printf("+---");
	}
	printf("+\n");
}

void imprimeFila(bool fila[], size_t tam, char nome[]) {
	size_t f;
	for (f = 0; f < tam; ++f) {
		printf("| %c ", fila[f] == true? 'X': ' ');
	}
	printf("| %s\n", nome);
}

void imprimeNumeros(size_t tam) {
	for (size_t i = 0; i < tam; ++i) {
		printf("  %x ", i);
	}
	printf("\n");
}

void imprimeOnibus(bool janelaEsq[], bool corredorEsq[],
				   bool janelaDir[], bool corredorDir[], size_t filas) {
	printf("\n");
	imprimeNumeros(filas);
	imprimeMargem(filas);
	imprimeFila(janelaDir, filas, "JD");
	imprimeMargem(filas);
	imprimeFila(corredorDir, filas, "CD");
	imprimeMargem(filas);

	printf("|   ");
	for (size_t f = 1; f < filas; ++f) {
		printf("    ");
	}
	printf("|\n");

	imprimeMargem(filas);
	imprimeFila(corredorEsq, filas, "CE");
	imprimeMargem(filas);
	imprimeFila(janelaEsq, filas, "JE");
	imprimeMargem(filas);
	imprimeNumeros(filas);
	printf("\n");
}

size_t imprimeLivres(bool fila[], size_t tam) {
	size_t livres = 0;
	for (size_t f = 0; f < tam; ++f) {
		if (fila[f] == false) {
			++livres;
			if (livres == 1) {
				printf("Livre(s): ");
			}
			printf("%x ", f);
		}
	}
	if (livres == 0) {
		printf("Fila toda ocupada!\n");
		__fpurge(stdin); getchar();
	}
	else {
		printf("\n");
	}
	return livres;
}

void vendePoltrona(bool fila[], size_t tam) {
	unsigned poltrona;

	do {
		printf("Digite o numero da poltrona desejada: ");
		scanf("%x", &poltrona);
	} while (poltrona >= tam || fila[poltrona] == true);

	fila[poltrona] = true;
}

