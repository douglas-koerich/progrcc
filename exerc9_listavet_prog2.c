#include <stdio.h>
#include <stdio_ext.h>

#define NUM_PRODUTOS	5
#define NUM_LOJAS		4
#define MAX_NOME		100

main() {
	unsigned codProdutos[NUM_PRODUTOS];
	char nomesProdutos[NUM_PRODUTOS][MAX_NOME+1];
	float tabPrecos[NUM_PRODUTOS][NUM_LOJAS]; // 5 x 4
	float tabImpostos[NUM_PRODUTOS][NUM_LOJAS];
	float custoTransporte[NUM_PRODUTOS];

	int produto, loja;

	// Preencher o cadastro de produtos
	for (produto=0; produto<NUM_PRODUTOS; ++produto) {
		printf("\nProduto #%d: Codigo? ", produto+1);
		scanf("%u", &codProdutos[produto]);
		printf("Descricao? ");
		__fpurge(stdin);
		gets(nomesProdutos[produto]);
		printf("Custo de transporte [R$]? ");
		scanf("%f", &custoTransporte[produto]);
	}
	// Monta a tabela de precos e calcula o imposto correspondente
	for (produto=0; produto<NUM_PRODUTOS; ++produto) {
		for (loja=0; loja<NUM_LOJAS; ++loja) {
			printf("Preco do produto \"%s\" na loja #%d [R$]: ", nomesProdutos[produto], loja+1);
			scanf("%f", &tabPrecos[produto][loja]);
			if (tabPrecos[produto][loja] <= 50.0) {
				tabImpostos[produto][loja] = tabPrecos[produto][loja]*0.05;
			}
			else if (tabPrecos[produto][loja] > 100.0) {
				tabImpostos[produto][loja] = tabPrecos[produto][loja]*0.20;
			}
			else {
				tabImpostos[produto][loja] = tabPrecos[produto][loja]*0.10;
			}
		}
	}
	// Relatorio
	for (produto=0; produto<NUM_PRODUTOS; ++produto) {
		printf("\nPRODUTO: %s (%u):\n", nomesProdutos[produto], codProdutos[produto]);
		printf("Custo do transporte: R$ %.2f\n", custoTransporte[produto]);
		printf("Disponível em:\n");
		for (loja=0; loja<NUM_LOJAS; ++loja) {
			if (tabPrecos[produto][loja] > 0.0) {
				float final = tabPrecos[produto][loja]+tabImpostos[produto][loja]+custoTransporte[produto];
				printf("Loja %d a R$ %.2f, com imposto R$ %.2f; preco final R$ %.2f\n", loja+1, tabPrecos[produto][loja], tabImpostos[produto][loja], final);
			}
		}
	}
}

