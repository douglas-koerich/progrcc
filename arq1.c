#include <stdio.h>

int main(void) {
	FILE *arquivo, *copia;

	// Abre o arquivo 'exemplo.txt' como stream de texto, somente-leitura
	arquivo = fopen("exemplo.txt", "rt");

	// Precisa verificar o retorno de fopen; alguns possiveis problemas
	// a) Arquivo 'exemplo.txt' nao existe
	// b) Arquivo corrompido
	// c) Nao tem permissao para abrir o arquivo
	if (arquivo == NULL) {
		perror("Nao pude abrir o arquivo");
		return -1;
	}
	// O arquivo esta aberto e posicionado no primeiro byte (como eh
	// stream de texto, este byte eh um caracter ASCII)

	// Cria o arquivo de copia, para escrita
	char nome[100];
	printf("Digite o nome do arquivo de copia: ");
	gets(nome);
	copia = fopen(nome, "wt");
	if (copia == NULL) {
		perror("Nao pude criar a copia");
		return -1;
	}
	// Vou ler TODOS os bytes do arquivo (ate o fim/EOF)
	while (feof(arquivo) == 0) {	// nao cheguei no fim do arquivo...
		char simbolo = fgetc(arquivo);	// apos ler, posiciona no proximo

		// DEVE verificar se leu EOF, que significa:
		// a) Nao eh um caracter, eh a marca de fim do arquivo
		// b) Erro na leitura do byte
		if (simbolo == EOF) {
			// Para se certificar de que foi erro (e nao fim do arquivo),
			// usa a funcao que testa se houve erro
			if (ferror(arquivo) != 0) {
				perror("Nao pude ler o arquivo");
				return -1;	// fecha o arquivo automaticamente
			}
			else {
				puts("\nFim do arquivo, ate logo...");
			}
		}
		else {
			// Nao foi lido EOF, entao eh um byte/caracter valido
			putchar(simbolo);

			// Copia o caracter para o arquivo de copia
			if (fputc(simbolo, copia) == EOF) {	// testa erro de escrita
				perror("Nao pude escrever na copia");
				return -1;
			}
		}
	}
	// Apos o uso do arquivo, fecha a stream
	fclose(arquivo);
	fclose(copia);

	return 0;
}

