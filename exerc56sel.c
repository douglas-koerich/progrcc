#include <stdio.h>
#include <ctype.h>

int main() {
	char opcao;

	printf("De sua nota:\n");
	printf("A. Otimo\n");
	printf("B. Bom\n");
	printf("C. Regular\n");
	printf("D. Ruim\n");
	printf("E. Pessimo\n");
	printf("=> ");
	scanf(" %c", &opcao);	// o espaco no " %c" 'limpa' o teclado

	/*
	opcao = toupper(opcao);	// converte opcao de minuscula (se for) para
							// maiuscula
	*/
	/* Usando as faixas da tabela ASCII
	opcao = opcao - 0x20;	// converte de minuscula para maiuscula
							// (so que opcao teria que ser uma minuscula!)
	*/

	/*
	if (opcao == 'A' || opcao == 'a') {
		printf("Voce digitou 'Otimo'.\n");
	}
	else {
		if (opcao == 'B' || opcao == 'b') {
			printf("Voce digitou 'Bom'.\n");
		}
		else {
			if (opcao == 'C' || opcao == 'c') {
				printf("Voce digitou 'Regular'.\n");
			}
			else {
				if (opcao == 'D' || opcao == 'd') {
					printf("Voce digitou 'Ruim'.\n");
				}
				else {
					if (opcao == 'E' || opcao == 'e') {
						printf("Voce digitou 'Pessimo'.\n");
					}
					else {
						printf("Voce digitou uma OPCAO INVALIDA.\n");
					}
				}
			}
		}
	}
	*/
	switch (opcao) {
		case 'A':
		case 'a':
			printf("Voce digitou 'Otimo'.\n");
			break;
		case 'B':
		case 'b':
			printf("Voce digitou 'Bom'.\n");
			break;
		case 'C':
		case 'c':
			printf("Voce digitou 'Regular'.\n");
			break;
		case 'D':
		case 'd':
			printf("Voce digitou 'Ruim'.\n");
			break;
		case 'E':
		case 'e':
			printf("Voce digitou 'Pessimo'.\n");
			break;
		default:
			printf("Voce digitou uma OPCAO INVALIDA.\n");
	}
	return 0;
}

