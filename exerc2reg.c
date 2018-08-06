#include <stdlib.h>
#include <stdio.h>
#include "exerc2reg.h"	// para conhecer a definicao de 'habitante'

int main() {
	int populacao;
	printf("Digite o tamanho da populacao a ser recenseada: ");
	scanf("%d", &populacao);

	// Ao inves de declarar um vetor alocado estaticamente, vamos aloca-lo
	// dinamicamente
	// 'censo' eh o ponteiro para o "vetor" de registros na memoria
	struct habitante* censo = (struct habitante*) malloc(populacao * sizeof(struct habitante));

	// 1a. funcao: cadastra os habitantes (e salva o cadastro em arquivos)
	cadastraCenso(censo, populacao);

	// Outras funcoes:
	printf("A media salarial da populacao eh %f\n", calculaMediaSalario(censo, populacao));
	int maior, menor;
	menorMaiorIdade(&menor, &maior);	// passa variaveis para serem preenchidas
	printf("A maior idade eh %d e a menor eh %d\n", maior, menor);
	printf("Numero de mulheres com 3 filhos e salario <= 900: %d\n", mulheres3sal900());

	// A impressao do 2o. registro armazenado em arquivo deve ser feita da seguinte forma:
	// (a) No caso do arquivo texto, como cada registro esta em uma linha, deve-se ler e descartar
	// a primeira e ler sem descartar a segunda linha, que eh o registro procurado
	// Isso eh necessario porque nao se sabe o comprimento do registro no arquivo-texto (depende do
	// tamanho da string correspondente) - ACESSO SEQUENCIAL
	FILE* texto = fopen(ARQ_TEXTO, "r");
	if (texto == NULL) {
		perror("Nao pude abrir o arquivo "ARQ_TEXTO);
		free(censo);
		return -1;
	}
	char registro[100];
	// Leitura (e descarte) do primeiro registro
	if (fgets(registro, sizeof(registro), texto) == NULL) {
		perror("Nao conseguiu ler o primeiro registro");
		fclose(texto);
		free(censo);
		return -1;
	}
	// Leitura (e uso) do segundo registro
	if (fgets(registro, sizeof(registro), texto) == NULL) {
		perror("Nao conseguiu ler o segundo registro");
		fclose(texto);
		free(censo);
		return -1;
	}
	printf("Segundo registro (do texto): %s", registro);
	fclose(texto);

	// (b) No caso do arquivo binario, como o tamanho da estrutura eh fixo, pode-se "pular"
	// o primeiro registro, acessando diretamente o segundo - ACESSO ALEATORIO
	FILE* binario = fopen(ARQ_BINARIO, "rb");
	if (binario == NULL) {
		perror("Nao pude abrir o arquivo "ARQ_BINARIO);
		free(censo);
		return -1;
	}
	// Para "pular" para o segundo registro, usa o tamanho do primeiro como "distancia"
	if (fseek(binario, sizeof(struct habitante), SEEK_SET) == -1) {	// SEEK_SET = "inicio do arquivo"
		perror("Nao conseguiu pular o primeiro registro");
		fclose(binario);
		free(censo);
		return -1;
	}
	// Agora o "cursor" de leitura estah sobre o segundo registro, vamos le-lo
	struct habitante rascunho;
	if (fread(&rascunho, sizeof(struct habitante), 1, binario) < 1) {
		perror("Nao conseguiu ler o segundo registro");
		fclose(binario);
		free(censo);
		return -1;
	}
	printf("Segundo registro (do binario): %d-%c-%f-%d\n", rascunho.idade, rascunho.sexo,
		   rascunho.salario, rascunho.filhos);
	fclose(binario);

	// Ao final do programa, nao posso deixar de liberar a memoria alocada
	// dinamicamente
	free(censo);
	
	return 0;
}

void cadastraCenso(struct habitante vetor[], int tamanho) {
	int i = 0;

	// Cria um arquivo-texto para os dados dos habitantes
	FILE* texto = fopen(ARQ_TEXTO, "wt");
	if (texto == NULL) {
		perror("Nao pude criar o arquivo "ARQ_TEXTO);	// une as strings!
		free(vetor);
		exit(-1);	// sai do programa sem voltar para main()
	}
	FILE* binario = fopen(ARQ_BINARIO, "wb");
	if (binario == NULL) {
		perror("Nao pude criar o arquivo "ARQ_BINARIO);
		fclose(texto);
		free(vetor);
		exit(-1);
	}
	while (i < tamanho) {
		puts("*** NOVO CADASTRO ***");
		printf("Idade? "); scanf("%d", &vetor[i].idade);
		printf("Sexo? "); scanf(" %c", &vetor[i].sexo);
		printf("Salario? "); scanf("%f", &vetor[i].salario);
		printf("Filhos? "); scanf("%d", &vetor[i].filhos);

		// Salva esse registro no arquivo texto
		// Como o registro eh formado por campos nao-alfanumericos (nao-texto),
		// preciso usar a saida formatada (fprintf) para salvar no arquivo
		if (fprintf(texto, "%d-%c-%f-%d\n", vetor[i].idade, vetor[i].sexo,
					vetor[i].salario, vetor[i].filhos) < 0) {
			perror("Nao pude gravar um registro no arquivo "ARQ_TEXTO);
		}

		// Salva o mesmo registro no arquivo binario
		// (se retorna um valor menor que o numero de itens solicitados para
		// escrita, houve erro)
		if (fwrite(&vetor[i], sizeof(struct habitante), 1, binario) < 1) {
			perror("Nao pude gravar um registro no arquivo "ARQ_BINARIO);
		}
		++i;
	}
	fclose(texto);
	fclose(binario);
}

float calculaMediaSalario(struct habitante* vetor, int tamanho) {
	float media = 0.0;
	int i;
	for (i=0; i<tamanho; ++i) {
		// Vou usar aritmetica de ponteiro para acessar os registros e seus
		// campos
		media += (vetor+i)->salario;
	}
	media /= tamanho;
	return media;
}

void menorMaiorIdade(int* menor, int* maior) {
	*maior = -1;	// vai perder ja na primeira comparacao
	*menor = 200;	// idem
	FILE* texto = fopen(ARQ_TEXTO, "rt");
	if (texto == NULL) {
		perror("Nao pude abrir o arquivo "ARQ_TEXTO);
		return;
	}
	while (!feof(texto)) {
		struct habitante rascunho;
		if (fscanf(texto, "%d-%c-%f-%d\n", &rascunho.idade, &rascunho.sexo,
			&rascunho.salario, &rascunho.filhos) == EOF) {
			if (ferror(texto)) {
				perror("Nao pude ler do arquivo "ARQ_TEXTO);
				fclose(texto);
				return;
			}
		}
		else {
			if (rascunho.idade > *maior) {
				*maior = rascunho.idade;
			}
			if (rascunho.idade < *menor) {
				*menor = rascunho.idade;
			}
		}
	}
	fclose(texto);
}

int mulheres3sal900(void) {
	int contador = 0;
	FILE* binario = fopen(ARQ_BINARIO, "rb");
	if (binario == NULL) {
		perror("Nao pude abrir o arquivo "ARQ_BINARIO);
		return -1;
	}
	while (!feof(binario)) {	// mesmo teste para verificar fim do arquivo
		struct habitante rascunho;
		if (fread(&rascunho, sizeof(struct habitante), 1, binario) < 1) {
			if (ferror(binario)) {
				perror("Nao pude ler do arquivo "ARQ_BINARIO);
				fclose(binario);
				return -1;
			}
			// Senao, encontrou o fim do arquivo
		}
		else {
			// Testa o conteudo do registro lido
			if (toupper(rascunho.sexo) == 'F' &&
				rascunho.salario <= 900 &&
				rascunho.filhos == 3) {
				++contador;
			}
		}
	}
	fclose(binario);
	return contador;
}

