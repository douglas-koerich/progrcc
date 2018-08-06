#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <time.h>
#include "exerc1_listaarq_prog2.h"

#define MAX_DOCUMENTOS	5

int main() {
	FILE* arqDocumentos;
/*
	Documento tabelaDocumentos[MAX_DOCUMENTOS], *pDocumento;
	int i;

	srand((unsigned)time(0));

	// Cadastro de documentos 
	arqDocumentos = fopen("/tmp/docs.utp", "wb");
	if (arqDocumentos == NULL) {
		perror("Nao pode criar arquivo de documentos");
		return -1;
	}
	for (i=0; i<MAX_DOCUMENTOS; ++i) {
		printf(">>> CADASTRO DO DOCUMENTO #%d <<<\n", i+1);
		tabelaDocumentos[i].numero = rand();
		printf("Digite o valor do documento [R$]: ");
		scanf("%f", &tabelaDocumentos[i].valor);
		printf("Digite a data de emissao (DD/MM/AAAA): ");
		__fpurge(stdin);
		scanf("%d/%d/%d", &tabelaDocumentos[i].emissao.dia, &tabelaDocumentos[i].emissao.mes,
			  &tabelaDocumentos[i].emissao.ano);
		printf("Digite a data de vencimento (DD/MM/AAAA): ");
		__fpurge(stdin);
		scanf("%d/%d/%d", &tabelaDocumentos[i].vencimento.dia, &tabelaDocumentos[i].vencimento.mes,
			  &tabelaDocumentos[i].vencimento.ano);
		printf("Digite o codigo do cliente: ");
		scanf("%d", &tabelaDocumentos[i].cliente);
	}
	// Escreve no arquivo binario
	fwrite(tabelaDocumentos, sizeof(Documento), MAX_DOCUMENTOS, arqDocumentos); 
*/
	Documento doc;

	arqDocumentos = fopen("/tmp/docs.utp", "rb");
	if (arqDocumentos == NULL) {
		perror("Nao pode ler arquivo de documentos");
		return -1;
	}
	// Vou pular o primeiro registro e imprimir o segundo
	// Como sei o tamanho de cada registro (em bytes), posso "saltar" para essa
	// posicao usando fseek
	fseek(arqDocumentos, sizeof(Documento), SEEK_SET);
	fread(&doc, sizeof(Documento), 1, arqDocumentos);
	printf("Numero doc.: %d\n", doc.numero);
	printf("Valor doc.: R$%.2f\n", doc.valor);
	printf("Emitido em %02d/%02d/%04d\n", doc.emissao.dia, doc.emissao.mes, doc.emissao.ano);
	printf("Vence em %02d/%02d/%04d\n", doc.vencimento.dia, doc.vencimento.mes, doc.vencimento.ano);
	printf("Cliente (codigo): %d\n", doc.cliente);

	fclose(arqDocumentos);
	return 0;
}
