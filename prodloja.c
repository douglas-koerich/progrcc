/*
Faça um programa que carregue:
a) um vetor com os códigos numéricos de cinco produtos;
b) uma matriz 5×4 com os preços dos cinco produtos em quatro lojas
   diferentes;
c) um outro vetor com o custo de transporte dos cinco produtos.

Calcule uma segunda matriz 5×4 com os valores dos impostos de cada produto,
sendo que esses obedecem à tabela a seguir:

Preço                      : Percentual de Imposto
Até R$ 50,00               : 5%
Entre R$ 50,01 e R$ 100,00 : 10%
Acima de R$ 100,00         : 20%

Mostre um relatório com o codigo do produto, o número da loja onde o produto
se encontra, o valor do imposto a pagar, o custo de transporte, o preço bruto
e o preço final (preço bruto acrescido do valor do imposto e do custo do transporte).
*/

#include <stdio.h>

#define PRODUTOS	5
#define LOJAS		4

int main() {
	// letra (a)
	int codigos[PRODUTOS];
	int p;

	for (p=0; p<PRODUTOS; ++p) {
		printf("Digite o codigo do produto #%d: ", p+1);
		scanf("%d", &codigos[p]);
	}

	// letra (b)
	float precos[PRODUTOS][LOJAS];
	int l;

	for (p=0; p<PRODUTOS; ++p) { // para cada linha/codigo
		for (l=0; l<LOJAS; ++l) { // para cada coluna/loja
			printf("Preco do produto %d na loja #%d [R$]: ", codigos[p], l+1);
			scanf("%f", &precos[p][l]);
		}
	}

	// letra (c)
	float transporte[PRODUTOS];

	for (p=0; p<PRODUTOS; ++p) {
		printf("Digite o custo de transporte do produto %d: ", codigos[p]);
		scanf("%f", &transporte[p]);
	}

	// Tabela de impostos
	float impostos[PRODUTOS][LOJAS];

	for (p=0; p<PRODUTOS; ++p) { // para cada linha/codigo
		for (l=0; l<LOJAS; ++l) { // para cada coluna/loja
			if (precos[p][l] <= 50.00) {
				impostos[p][l] = precos[p][l] * 5.0/100;
			}
			else {
				if (precos[p][l] <= 100.00) {
					impostos[p][l] = precos[p][l] * 0.10;
				}
				else {
					impostos[p][l] = precos[p][l] * 0.2;
				}
			}
		}
	}

	// Relatorio
	for (p=0; p<PRODUTOS; ++p) {
		printf(">>> PRODUTO %d <<<\n", codigos[p]);
		for (l=0; l<LOJAS; ++l) {
			printf("\t>>> LOJA %d <<<\n", l+1);
			printf("\t\tImposto: R$ %.2f\n", impostos[p][l]);
			printf("\t\tTransporte: R$ %.2f\n", transporte[p]);
			printf("\t\tPreco Bruto: R$ %.2f\n", precos[p][l]);
			float total = precos[p][l] + transporte[p] + impostos[p][l];
			printf("\t\tPreco Final: R$ %.2f\n", total);
		}
	}

	return 0;
}

