#include <stdlib.h>
#include <stdio.h>

#define NUM_CONTAS	5

main() {
	int codigos[NUM_CONTAS], indice_conta, indice_verificacao, opcao, conta;
	float saldos[NUM_CONTAS], deposito, saque, total;

	for (indice_conta = 0; indice_conta < NUM_CONTAS; ++indice_conta) {
		do {
			printf("Numero da %da. conta: ", indice_conta+1);
			scanf("%d", &codigos[indice_conta]);
			for (indice_verificacao = 0; indice_verificacao < indice_conta; ++indice_verificacao) {
				if (codigos[indice_verificacao] == codigos[indice_conta]) {
					printf("Codigo repetido, digite outro.\n");
					codigos[indice_conta] = 0;
					break;	// nao faz sentido continuar comparando...
				}
			}
		} while (codigos[indice_conta] <= 0);
		do {
			printf("Saldo inicial da %da. conta (cod. %d): ", indice_conta+1, codigos[indice_conta]);
			scanf("%f", &saldos[indice_conta]);
		} while (saldos[indice_conta] < 0);
	}
	do {
		//system("clear");	// em Windows, system("cls");
		printf("*** BANCO URBANO ***\n");
		printf("1. Efetuar deposito.\n");
		printf("2. Efetuar saque.\n");
		printf("3. Consultar o ativo bancario.\n");
		printf("4. Finalizar o programa.\n");
		printf("\nOpcao (1-4)? ");
		scanf("%d", &opcao);

		switch (opcao) {
			case 1:
				printf("Digite o numero da conta: ");
				scanf("%d", &conta);
				for (indice_conta=0; indice_conta<NUM_CONTAS; ++indice_conta) {
					if (codigos[indice_conta] == conta) {
						// Achei!
						break;
					}
				}
				if (indice_conta == NUM_CONTAS) { // chegou no fim s/ encontrar
					printf("Conta nao encontrada!\n");
				}
				else {
					printf("Digite o valor do deposito: ");
					scanf("%f", &deposito);
					printf("Saldo anterior = R$ %.2f.\n", saldos[indice_conta]);
					saldos[indice_conta] += deposito;
					printf("Saldo atual = R$ %.2f.\n", saldos[indice_conta]);
				}
				break;

			case 2:
				printf("Digite o numero da conta: ");
				scanf("%d", &conta);
				for (indice_conta=0; indice_conta<NUM_CONTAS && codigos[indice_conta] != conta; ++indice_conta);	// eh isso mesmo!!!
				if (indice_conta == NUM_CONTAS) { // chegou no fim s/ encontrar
					printf("Conta nao encontrada!\n");
					break;	// encerra prematuramente o case (ignora o resto)
				}
				printf("Digite o valor do saque: ");
				scanf("%f", &saque);
				if (saque > saldos[indice_conta]) {
					printf("Saldo insuficiente.\n");
					break;	// aqui tambem eh um ponto de saida do case
				}
				printf("Saldo anterior = R$ %.2f.\n", saldos[indice_conta]);
				saldos[indice_conta] -= saque;
				printf("Saldo atual = R$ %.2f.\n", saldos[indice_conta]);
				break;

			case 3:
				for (total=0.0, indice_conta=0; indice_conta<NUM_CONTAS; ++indice_conta) {
					total += saldos[indice_conta];
				}
				printf("Ativo bancario = R$ %.2f.\n", total);
				break;

			case 4:
				printf("Fim do programa...\n");
				break;

			default:
				printf("Opcao invalida!\n");
		}
	} while (opcao != 4);
}

