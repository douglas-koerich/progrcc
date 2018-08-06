#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <time.h>
#include "exerc1_listaarq_prog2.h"

#define MAX_CLIENTES	3
#define MAX_STRING		512

int main() {
	FILE* arqClientes;
/*
	Cliente tabelaClientes[MAX_CLIENTES], *pCliente;
	int i;

	srand((unsigned)time(0));

	// Cadastro de clientes
	arqClientes = fopen("/tmp/clientes.txt", "wt");
	if (arqClientes == NULL) {
		perror("Nao pode criar arquivo de clientes");
		return -1;
	}
	for (i=0; i<MAX_CLIENTES; ++i) {
		printf(">>> CADASTRO DO CLIENTE #%d <<<\n", i+1);
		tabelaClientes[i].codigo = rand();
		printf("Digite o nome do cliente: ");
		__fpurge(stdin);
		gets(tabelaClientes[i].nome);
		printf("Digite o endereco: ");
		__fpurge(stdin);
		gets(tabelaClientes[i].endereco);
		printf("Digite o telefone no formato (DDD)NNNNNNNNN: ");
		scanf("(%d)%d", &tabelaClientes[i].ddd, &tabelaClientes[i].telefone);
	}
	// Escreve no arquivo-texto
	for (i=0, pCliente=tabelaClientes; i<MAX_CLIENTES; ++i, ++pCliente) {
		fprintf(arqClientes, "%d\n", pCliente->codigo);
		fprintf(arqClientes, "%s\n", pCliente->nome);
		fprintf(arqClientes, "%s\n", pCliente->endereco);
		fprintf(arqClientes, "[%03d]%04d-%04d\n", pCliente->ddd, pCliente->telefone/10000,
				pCliente->telefone%10000);
	}
*/
	char string[MAX_STRING];

	arqClientes = fopen("/tmp/clientes.txt", "r");
	if (arqClientes == NULL) {
		perror("Nao pode ler arquivo de clientes.");
		return -1;
	}
	// Vou "pular" o primeiro registro de cliente para imprimir o segundo
	// Como nao sei quantos bytes sao ocupados pelo primeiro registro, sou forcado
	// a le-lo descartando as strings que o compoem
	fgets(string, sizeof(string), arqClientes);
	fgets(string, sizeof(string), arqClientes);
	fgets(string, sizeof(string), arqClientes);
	fgets(string, sizeof(string), arqClientes);

	// Supoe-se estar na primeira string do segundo registro
	fgets(string, sizeof(string), arqClientes);
	puts(string);
	fgets(string, sizeof(string), arqClientes);
	puts(string);
	fgets(string, sizeof(string), arqClientes);
	puts(string);
	fgets(string, sizeof(string), arqClientes);
	puts(string);
	
	fclose(arqClientes);
	return 0;
}
