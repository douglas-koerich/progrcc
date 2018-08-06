#include <stdlib.h>
#include <stdio.h>		// com <> cabecalhos no PATH do sistema
#include "arranjo.h"	// com "" cabecalhos proprios na pasta do programa
#include "combinacao.h"
#include "permutacao.h"

int main(void) {
	printf("Digite quantos elementos existem no conjunto: ");
	unsigned n;
	scanf("%u", &n);

	printf("Quantos elementos serao agrupados juntos: ");
	unsigned p;
	scanf("%u", &p);

	unsigned permutacoes = permutacao(n);
	unsigned combinacoes = combinacao(n, p);
	unsigned arranjos = arranjo(n, p);

	printf("Numero de permutacoes = %u\n", permutacoes);
	printf("Numero de combinacoes (grupos sem ordem definida) = %u\n", combinacoes);
	printf("Numero de arranjos (grupos ordenados) = %u\n", arranjos);

#ifdef PARA_WINDOWS // definido em Projeto > Propriedades > Preprocessador > C/C++
	system("pause");
#endif
	return EXIT_SUCCESS;
}
