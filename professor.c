#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "professor.h"

// #define VALOR_HR_AULA	18.00
#define ARQUIVO_TXT	"zequinha.db"
#define ARQUIVO_BIN "juquinha.db"

bool grava(const struct professor*);

void exibe2seq(void);
void buscaSeq(int);
size_t contaLinhas(void);

void exibe2bin(void);
void buscaBin(int);
size_t contaRegistros(void);

int main() {
	FILE* temp = fopen(ARQUIVO_TXT, "w");	// garante que o arquivo seja sobrescrito
	if (temp == NULL) {
		perror("Nao pude reiniciar o arquivo-texto");
		return -1;
	}
	fclose(temp);
	temp = fopen(ARQUIVO_BIN, "w");			// idem
	if (temp == NULL) {
		perror("Nao pude reiniciar o arquivo-binario");
		return -1;
	}
	fclose(temp);

	const float VALOR_HR_AULA = 18.00;
	int num_professores;

	printf("Digite o numero de professores da escola: ");
	scanf("%d", &num_professores);

	// Declara o mini-banco de dados do programa, ou seja, o
	// vetor de registros
	// sizeof(professor)*num_professores = num. de BYTES (nao professores!) alocados
	professor* listaProfs = (professor*) malloc(sizeof(professor)*num_professores);
	professor* prof = listaProfs;	// vou usar esse ponteiro como cursor no vetor

	// Laco para leitura dos dados dos professores
	int p, num_M = 0, num_F = 0;
	float media_M = 0.0, media_F = 0.0;
	for (p=0; p<num_professores; ++p) {
		printf("Digite o codigo do professor #%d: ", p+1);
		scanf("%d", &(*prof).codigo);	// 1o. jeito (mais esdruxulo)

		printf("Digite o primeiro nome do professor: ");
		scanf(" %s", prof->prenome);	// 2o. jeito (comumente usado):
										// operador 'seta' (->) eh usado a partir de ponteiro

		char s;
		do {
			printf("Digite o sexo do professor: ");
			scanf(" %c", &s);
			s = toupper(s);	// converte pra maiuscula
		} while (s != 'M' && s != 'F');
		prof->sexo = s;

		printf("Digite o numero de horas-aulas dadas pelo professor: ");
		scanf("%d", &prof->hrs_aulas);

		// Aproveito para fazer os calculos para esse professor
		prof->sal_bruto = prof->hrs_aulas * VALOR_HR_AULA;
		if (prof->sexo == 'M') {
			prof->desconto = prof->sal_bruto * (prof->hrs_aulas > 70? .08: .1);
			++num_M;
			media_M += prof->sal_bruto;
		}
		else {
			prof->desconto = prof->sal_bruto * (prof->hrs_aulas > 70? .07: .05);
			++num_F;
			media_F += prof->sal_bruto;
		}
		// Uma alternativa mais "divertida"... :-)
		// prof->desconto = prof->sal_bruto *
		// 					prof->sexo == 'M'? (prof->hrs_aulas > 70? .08: .1):
		// 									   (prof->hrs_aulas > 70? .07: .05);

		prof->sal_liquido = prof->sal_bruto - prof->desconto;

		// Grava o registro do professor no arquivo
		if (grava(prof) == false) {
			perror("Nao pude gravar o registro");
		}
		++prof;	// vai saltar para a proxima estrutura na memoria
	}
	// Calcula as medias finais
	media_M = media_M / num_M;
	media_F /= num_F;

	// Laco para o relatorio
	puts("\n>>>>> RELATORIO DE PROFESSORES <<<<<");
	puts("Codigo  Nome                  Bruto (R$)  Desconto (R$)  Liquido (R$)");
	puts("------  --------------------  ----------  -------------  ------------");
	for (p=0, prof=listaProfs; p<num_professores; ++p, ++prof) {
		printf("%6d  %-20s  %10.2f  %13.2f  %12.2f\n", prof->codigo, prof->prenome,
			prof->sal_bruto, prof->desconto, prof->sal_liquido);
	}
	printf("\nMedia de salario bruto dos professores: R$ %.2f\n", media_M);
	printf("Media de salario bruto das professoras: R$ %.2f\n", media_F);

	// Libera a area de memoria alocada
	free(listaProfs);
/*
	// A titulo de ilustracao, segue o codigo que le e imprime o conteudo do
	// arquivo-texto
	temp = fopen(ARQUIVO_TXT, "rt");
	if (temp == NULL) {
		perror("Nao pude abrir o arquivo-texto");
		return -1;
	}
	// Vou ler de dois modos: o primeiro, lendo a linha inteira sem separar
	// pelos campos da estrutura
	while (!feof(temp)) {
		char string[1024];
		if (fgets(string, sizeof(string), temp) == NULL) {
			if (ferror(temp)) {
				perror("Nao pude ler o arquivo-texto");
				fclose(temp);
				return -1;
			}
		}
		else {
			printf("%s", string);
		}
	}
	// Agora, vou ler o arquivo novamente, lendo campo por campo para uma
	// estrutura e vou imprimir a estrutura
	rewind(temp);	// volta o "cursor" de leitura para o inicio do arquivo
	while (!feof(temp)) {
		professor aux;
		//if (fscanf(temp, "%d;%s;%c;%d;%f;%f;%f\n",	ATENCAO: O %s vai ler ateh o fim da linha
		//												sem deixar outros dados para os proximos %...
		if (fscanf(temp, "%d;%[A-Za-z];%c;%d;%f;%f;%f\n",	// Usa um "scancode" para delimitar o segundo campo
			&aux.codigo, aux.prenome, &aux.sexo, &aux.hrs_aulas, &aux.sal_bruto,
			&aux.desconto, &aux.sal_liquido) == EOF) {
			if (ferror(temp)) {
				perror("Nao pude ler o arquivo-texto");
				fclose(temp);
				return -1;
			}
		}
		else {
			printf("%d|%s|%c|%d|%.2f|%.2f|%.2f\n", aux.codigo, aux.prenome, aux.sexo,
				aux.hrs_aulas, aux.sal_bruto, aux.desconto, aux.sal_liquido);
		}
	}
	fclose(temp);
*/
	printf("Digite o codigo do professor para busca: ");
	int cod;
	scanf("%d", &cod);

	puts("OPERACOES NO ARQUIVO-TEXTO (SEQUENCIAL)");
	// Exibindo o conteudo do segundo registro
	exibe2seq();
	buscaSeq(cod);
	printf("O numero de linhas (professores) no arquivo eh %u\n", contaLinhas());

	puts("OPERACOES NO ARQUIVO-BINARIO (ALEATORIO)");
	// Exibindo o conteudo do segundo registro
	exibe2bin();
	buscaBin(cod);
	printf("O numero de registros (professores) no arquivo eh %u\n", contaRegistros());

	return 0;
}

bool grava(const struct professor* prf) {
	FILE* arquivo = fopen(ARQUIVO_TXT, "at");
	if (arquivo == NULL) {
		return false;
	}
	// Grava o conteudo da struct campo a campo, na forma de strings (ASCII)
	if (fprintf(arquivo, "%d;%s;%c;%d;%.2f;%.2f;%.2f\n",
			prf->codigo, prf->prenome, prf->sexo, prf->hrs_aulas, prf->sal_bruto,
			prf->desconto, prf->sal_liquido) < 0) {
		fclose(arquivo);
		return false;
	}
	fclose(arquivo);

	arquivo = fopen(ARQUIVO_BIN, "ab");
	if (arquivo == NULL) {
		return false;
	}
	// Grava o conteudo binario da struct (bits/bytes originais)
	if (fwrite(prf, sizeof(struct professor), 1 /* unico registro */, arquivo)
		< 1 /* retornou um num de itens gravados menor do que o pedido */) {
		fclose(arquivo);
		return false;
	}
	fclose(arquivo);
	return true;
}

void exibe2seq(void) {
	FILE* arquivo = fopen(ARQUIVO_TXT, "r");
	if (arquivo == NULL) {
		perror("Nao pude abrir o arquivo");
		return;
	}
	// Para chegar ao segundo registro, nao tenho como saltar o primeiro sem
	// le-lo pois nao sei o seu comprimento
	char dummy[1024];	// soh para ler a primeira linha (primeiro registro)
	if (fgets(dummy, sizeof(dummy), arquivo) == NULL) {
		if (ferror(arquivo)) {
			perror("Nao pude ler o primeiro registro");
		}
		fclose(arquivo);
		return;	// nao ha segundo registro para ler (ou deu erro)
	}
	// A linha lida em 'dummy' eh descartada, porque estou interessado no
	// segundo registro
	professor aux;
	if (fscanf(arquivo, "%d;%[A-Za-z];%c;%d;%f;%f;%f\n",	// Usa um "scancode" para delimitar o segundo campo
		&aux.codigo, aux.prenome, &aux.sexo, &aux.hrs_aulas, &aux.sal_bruto,
		&aux.desconto, &aux.sal_liquido) == EOF) {
		if (ferror(arquivo)) {
			perror("Nao pude ler o segundo registro");
			fclose(arquivo);
			return;
		}
	}
	else {
		printf("%d|%s|%c|%d|%.2f|%.2f|%.2f\n", aux.codigo, aux.prenome, aux.sexo,
			aux.hrs_aulas, aux.sal_bruto, aux.desconto, aux.sal_liquido);
	}
	fclose(arquivo);
}

void exibe2bin(void) {
	FILE* arquivo = fopen(ARQUIVO_BIN, "rb");
	if (arquivo == NULL) {
		perror("Nao pude abrir o arquivo");
		return;
	}
	// Como cada registro foi salvo com seu tamanho original e FIXO, posso saltar
	// o numero de bytes a partir do inicio do arquivo
	if (fseek(arquivo,
			  sizeof(professor) /* numero de bytes a pular */ ,
			  SEEK_SET /* a partir do inicio */) == -1) {
		perror("Nao pude saltar para o segundo registro");
		fclose(arquivo);
		return;
	}
	// Estou com o indicador de posicao do arquivo no inicio do segundo registro,
	// agora vamos le-lo
	professor aux;
	if (fread(&aux, sizeof(professor), 1, arquivo) < 1) {
		if (ferror(arquivo)) {
			perror("Nao pude ler o segundo registro");
			fclose(arquivo);
			return;
		}
	}
	else {
		printf("%d|%s|%c|%d|%.2f|%.2f|%.2f\n", aux.codigo, aux.prenome, aux.sexo,
			aux.hrs_aulas, aux.sal_bruto, aux.desconto, aux.sal_liquido);
	}
	fclose(arquivo);
}

void buscaSeq(int codigo) {
	FILE* arquivo = fopen(ARQUIVO_TXT, "r");
	if (arquivo == NULL) {
		perror("Nao pude abrir o arquivo");
		return;
	}
	while (!feof(arquivo)) {	// Busca ateh o fim ou se encontrar
		professor aux;
		if (fscanf(arquivo, "%d;%[A-Za-z];%c;%d;%f;%f;%f\n",	// Usa um "scancode" para delimitar o segundo campo
			&aux.codigo, aux.prenome, &aux.sexo, &aux.hrs_aulas, &aux.sal_bruto,
			&aux.desconto, &aux.sal_liquido) == EOF) {
			if (ferror(arquivo)) {
				perror("Nao pude ler o registro");
				fclose(arquivo);
				return;
			}
		}
		else if (aux.codigo == codigo) {
			puts("Registro ENCONTRADO!");
			printf("%d|%s|%c|%d|%.2f|%.2f|%.2f\n", aux.codigo, aux.prenome, aux.sexo,
				aux.hrs_aulas, aux.sal_bruto, aux.desconto, aux.sal_liquido);
			fclose(arquivo);
			return;
		}
	}
	printf("Codigo %d nao encontrado!\n", codigo);
	fclose(arquivo);
}

void buscaBin(int codigo) {
	FILE* arquivo = fopen(ARQUIVO_BIN, "rb");
	if (arquivo == NULL) {
		perror("Nao pude abrir o arquivo");
		return;
	}
	while (!feof(arquivo)) {	// Busca ateh o fim ou se encontrar
		int cod;
		if (fread(&cod, sizeof(int), 1, arquivo) < 1) {
			if (ferror(arquivo)) {
				perror("Nao pude ler o registro");
				fclose(arquivo);
				return;
			}
		}
		else if (cod == codigo) {
			puts("Registro ENCONTRADO!");
			// Volto para o inicio do registro para le-lo
			if (fseek(arquivo, -sizeof(int), SEEK_CUR) == -1) {	// -sizeof(int) volta os 4 bytes
				perror("Nao pude voltar para o inicio do registro");
				fclose(arquivo);
				return;
			}
			// Agora estou no inicio do registro novamente
			professor aux;
			if (fread(&aux, sizeof(professor), 1, arquivo) < 1) {
				perror("Nao pude ler o registro");
				fclose(arquivo);
				return;
			}
			printf("%d|%s|%c|%d|%.2f|%.2f|%.2f\n", aux.codigo, aux.prenome, aux.sexo,
				aux.hrs_aulas, aux.sal_bruto, aux.desconto, aux.sal_liquido);
			fclose(arquivo);
			return;
		}
		else {	// Nao coincidiu o codigo, preciso saltar para o inicio do proximo registro
			if (fseek(arquivo, sizeof(professor)-sizeof(int), SEEK_CUR) == -1) {
				perror("Nao pude saltar para o inicio do proximo registro");
				fclose(arquivo);
				return;
			}
		}
	}
	printf("Codigo %d nao encontrado!\n", codigo);
	fclose(arquivo);
}

size_t contaLinhas(void) {
	FILE* arquivo = fopen(ARQUIVO_TXT, "r");
	if (arquivo == NULL) {
		perror("Nao pude abrir o arquivo");
		return 0;
	}
	size_t contador = 0;
	while (!feof(arquivo)) {
		char dummy[1024];	// soh para ler a linha
		if (fgets(dummy, sizeof(dummy), arquivo) == NULL) {
			if (ferror(arquivo)) {
				perror("Nao pude ler o primeiro registro");
				fclose(arquivo);
				return 0;
			}
		}
		else {
			++contador;
		}
	}
	fclose(arquivo);
	return contador;
}

size_t contaRegistros(void) {
	// Le o tamanho do arquivo binario
	FILE* arquivo = fopen(ARQUIVO_BIN, "rb");
	if (arquivo == NULL) {
		perror("Nao pude abrir o arquivo");
		return 0;
	}
	// Posiciona no fim do arquivo
	if (fseek(arquivo, 0, SEEK_END) == -1) {
		perror("Nao pude saltar para o fim do arquivo");
		fclose(arquivo);
		return 0;
	}
	long tamanho_arquivo = ftell(arquivo);
	if (tamanho_arquivo == -1) {
		perror("Erro ao ler o indicador no fim do arquivo");
		fclose(arquivo);
		return 0;
	}
	fclose(arquivo);
	return tamanho_arquivo / sizeof(professor);
}

