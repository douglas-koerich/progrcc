#include <stdbool.h>
#include <ctype.h>
#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include "exerc6reg.h"

#define NUM_VEICULOS 5

int main() {
	// Mini-banco de dados em memoria
	struct renavam cadastro[NUM_VEICULOS];

	// Preenche o cadastro em memoria
	int v;
	puts("PREENCHIMENTO DO CADASTRO");
	for (v=0; v<NUM_VEICULOS; ++v) {
		printf("=== Veiculo %d ===\n", v+1);
		printf("Nome do proprietario? ");
		__fpurge(stdin);
		gets(cadastro[v].proprietario);

		char aux[MAX_PLACA+1];	// variavel local ao laco do-while
		bool placaValida;
		do {
			placaValida = true;
			printf("Placa [XXX9999]? ");
			__fpurge(stdin);
			gets(aux);
			if (strlen(aux) < MAX_PLACA) {
				placaValida = false;
			}
			else {
				int i=0;
				while (aux[i] != '\0') { // enquanto nao chega ao fim da string
					aux[i] = toupper(aux[i]);	// converte para maiuscula
					if (i <= 2) { // posicao de letra?
						if (!isalpha(aux[i])) {
							placaValida = false;
							break;	// interrompe o laco while, nao faz sentido continuar
						}
					}
					else {
						if (!isdigit(aux[i])) {
							placaValida = false;
							break;
						}
					}
					++i;
				}
			}
		} while (!placaValida);	// placaValida == false
		strcpy(cadastro[v].placa, aux);	// copia string-placa validada para cadastro

		printf("Modelo do veiculo? ");
		__fpurge(stdin);
		gets(cadastro[v].modelo);

		do {
			printf("Ano de fabricacao? ");
			scanf("%u", &cadastro[v].ano);
		} while (cadastro[v].ano < 1917 || cadastro[v].ano > 2015);

		printf("Numero do chassi? ");
		__fpurge(stdin);
		gets(cadastro[v].chassi);

		printf("Cor? ");
		__fpurge(stdin);
		gets(cadastro[v].cor);

		char comb;
		do {
			printf("Combustivel [ADGVF]? ");
			__fpurge(stdin);
			comb = toupper(getchar());	// getchar() le do teclado, toupper() converte
		} while (comb!='A' && comb!='D' && comb!='G' && comb!='V' && comb!='F');
		cadastro[v].combustivel = comb;
	}

	// Letra (a)
	unsigned num2000diesel = pos2000(cadastro, NUM_VEICULOS);
	printf("Sao %u veiculos a partir de 2000 movidos a diesel\n", num2000diesel);

	// Letra (b)
	gravaArq("/tmp/lista.txt", cadastro, NUM_VEICULOS);

	// Letra (c)
	size_t tamRetornado;
	struct renavam* adulterados = buscaAdult(cadastro, NUM_VEICULOS, &tamRetornado);
	puts("\nVEICULOS ADULTERADOS");
	for (v=0; v<tamRetornado; ++v) {
		printf("%s\n", (adulterados+v)->placa);	// aritmetica de ponteiro
	}
	free(adulterados);	// este valor de ponteiro nao pode ter sido perdido!
	return 0;
}

unsigned pos2000(struct renavam cad[], size_t tam) {
	unsigned contador = 0;
	int i;
	for (i=0; i<tam; ++i) {
		if (cad[i].ano >= 2000 && cad[i].combustivel == 'D') {
			++contador;
		}
	}
	return contador;
}

void gravaArq(char* nomeArq, struct renavam* cad, size_t tam) {
	FILE* arquivo = fopen(nomeArq, "w");
	if (arquivo == NULL) {
		perror("Nao pude criar o arquivo");
		return;
	}
	// Vou usar o proprio ponteiro recebido que tem inicialmente o inicio do vetor de
	// registros para caminhar pelo vetor
	int i;
	for (i=0; i<tam; ++i, ++cad) {	// ponteiro caminha a cada novo registro
		if ((cad->placa[0] == 'A' || cad->placa[0] == 'B') &&
			(cad->placa[MAX_PLACA-1] == '0'	|| cad->placa[MAX_PLACA-1] == '2' ||	// ATENCAO: caracter numerico, nao valor!
			 cad->placa[MAX_PLACA-1] == '4' || cad->placa[MAX_PLACA-1] == '7')) {	// MAX_PLACA tem o terminador nulo
			if (fprintf(arquivo, "%s\t%s\n", cad->proprietario, cad->placa) < 0) {
				perror("Nao pude escrever no arquivo");
				fclose(arquivo);
				return;
			}
		}
	}
	fclose(arquivo);
}

struct renavam* buscaAdult(struct renavam* cad, size_t tam, size_t* tamAdult) {
	struct renavam* retorno = NULL;
	*tamAdult = 0;	// zera o contador no endereco da variavel passada por parametro
	int i;
	for (i=0; i<tam; ++i, ++cad) {	// ponteiro caminha a cada novo registro
		bool chassiEhFalso = false;
		if (strlen(cad->chassi) < MAX_CHASSI) {
			chassiEhFalso = true;
		}
		else {
			int j=0;
			while (cad->chassi[j] != '\0') { // enquanto nao chega ao fim da string
				if (j < 2 || j > MAX_CHASSI-3) { // posicao de letra?
					if (!isalpha(cad->chassi[j])) {
						chassiEhFalso = true;
						break;	// interrompe o laco while, nao faz sentido continuar
					}
				}
				else {
					if (!isdigit(cad->chassi[j])) {
						chassiEhFalso = true;
						break;
					}
				}
				++j;
			}
		}
		if (chassiEhFalso) {
			retorno = (struct renavam*) realloc(retorno, (*tamAdult+1)*sizeof(struct renavam));
			memcpy(retorno + *tamAdult, cad, sizeof(struct renavam));
			++(*tamAdult);
		}
	}
	return retorno;	// o tamanho "volta" pela variavel tamAdult (passagem por referencia)
}


