#include <stdio.h>
#include <stdio_ext.h>

#define PRODUTOS	5
#define LOJAS		4
#define MAX_NOME	20

// ERRATA: Na letra (a), leia-se: "vetor com os nomes de cinco produtos".

int main(void) {
	char produtos[PRODUTOS][MAX_NOME+1];
	float precos[PRODUTOS][LOJAS];
	float transporte[PRODUTOS];
	float impostos[PRODUTOS][LOJAS];
	int prod, loj;

	// Leitura dos nomes e custos de transporte
	for (prod=0; prod<PRODUTOS; ++prod) {
		printf("Digite o nome do produto #%d: ", prod+1);
		__fpurge(stdin);
		gets(produtos[prod]);

		printf("Qual o custo do seu transporte? ");
		scanf("%f", &transporte[prod]);
	}
	// Leitura dos precos nas lojas
	for (prod=0; prod<PRODUTOS; ++prod) {
		printf("Precos do produto %s:\n", produtos[prod]);
		for (loj=0; loj<LOJAS; ++loj) {
			printf("Loja #%d? ", loj+1);
			scanf("%f", &precos[prod][loj]);
		}
	}
	// Calculos dos impostos
	for (prod=0; prod<PRODUTOS; ++prod) {
		for (loj=0; loj<LOJAS; ++loj) {
			if (precos[prod][loj] <= 50.00) {
				impostos[prod][loj] = precos[prod][loj] * 0.05;
			}
			else if (precos[prod][loj] > 100.00) {
				impostos[prod][loj] = precos[prod][loj] * 0.20;
			}
			else {
				impostos[prod][loj] = precos[prod][loj] * 0.10;
			}
		}
	}
	// Impressao do relatorio
	for (prod=0; prod<PRODUTOS; ++prod) {
		printf("PRODUTO: %s\n", produtos[prod]);
		printf("  Transporte: R$ %.2f\n", transporte[prod]);
		for (loj=0; loj<LOJAS; ++loj) {
			printf("  Loja %d\n", loj+1);
			printf("    Preco bruto: R$ %.2f\n", precos[prod][loj]);
			printf("    Imposto: R$ %.2f\n", impostos[prod][loj]);
			float liquido = precos[prod][loj] + impostos[prod][loj] + transporte[prod];
			printf("    Preco final: R$ %.2f\n", liquido);
		}
	}
	return 0;
}

