#include <stdio.h>

int main(int argc, char* argv[]) {
	if (argc < 2) {
		puts("Numero invalido de argumentos");
		printf("Use: %s <nome-do-arquivo>\n", argv[0]);
		return -1;
	}
	FILE* stream;	// a referencia para a stream/arquivo que sera criado
	/*
	stream = fopen(argv[1], "wt");	// "w": cria um NOVO arquivo com nome definido em argv[1]
	if (stream == NULL) {
		perror("Nao pude criar o arquivo");
		return -1;
	}
	printf("Digite uma frase para ser gravada no arquivo: ");
	char frase[100];
	fgets(frase, sizeof(frase), stdin);
	if (fputs(frase, stream) == EOF) {
		perror("Erro ao escrever no arquivo");
		fclose(stream);
		return -1;
	}
	printf("Digite uma letra para gravar no arquivo: ");
	char letra;
	scanf(" %c", &letra);
	if (fputc(letra, stream) == EOF) {
		perror("Erro ao escrever no arquivo");
		fclose(stream);
		return -1;
	}
	fclose(stream);
	*/
	stream = fopen(argv[1], "rt");	// o arquivo 'argv[1]' DEVE existir
	if (stream == NULL) {
		perror("Erro ao abrir o arquivo");
		return -1;
	}
	while (!feof(stream)) {
		/*
		char letra = fgetc(stream);
		if (letra == EOF) {
		*/
		char linha[1024];
		if (fgets(linha, sizeof(linha), stream) == NULL) {
			if (ferror(stream)) {
				perror("Erro ao ler conteudo do arquivo");
				fclose(stream);
				return -1;
			}
		}
		else {
			// putchar(letra);
			fputs(linha, stdout); // printf("%s", linha);
		}
	}
	fclose(stream);
	return 0;
}

