#include <stdio.h>
#include <ctype.h>

// #define MAX_NOME	100

int main(int numargs, char* params[]) {
	FILE* stream;	// stream eh uma representacao LOGICA do arquivo fisico

	if (numargs < 3) { // o nome do programa na linha de comando conta como
					   // um (o primeiro) argumento/parametro de main
		puts("Numero invalido de parametros");
		printf("Use: %s <arq-entrada> <arq-saida>\n", params[0]);
		return -1;
	}
	/*
	char nome_do_arquivo[MAX_NOME];
	printf("Digite o nome do arquivo-TEXTO que vai ser lido: ");
	gets(nome_do_arquivo);
	*/

	// Para manipular (ler ou escrever) o conteudo, devo primeiro ABRIR
	// o arquivo (ou melhor, a stream)
	//stream = fopen(nome_do_arquivo, "rt");	// r = read (ler); t = texto
	stream = fopen(params[1], "rt");	// r = read (ler); t = texto
	if (stream == NULL) {
		perror("Nao foi possivel abrir o arquivo");
		return -1;
	}
	// Vou CRIAR um outro arquivo chamado minusc.txt com o mesmo conteudo
	// mas apenas com letras minusculas
	//FILE* saida = fopen("minusc.txt", "w");	// w = create; t implicito
	FILE* saida = fopen(params[2], "w");	// w = create; t implicito
	if (saida == NULL) {
		perror("Nao pude criar o arquivo");
		fclose(stream);	// educado que sou, fecho o que esta aberto...
		return -1;
	}
	// Laco para ler caracter por caracter do arquivo, ateh o seu fim
	unsigned maiusculas = 0;
	while (!feof(stream)) {		// faca enquanto NAO fim-do-arquivo
		char caracter = fgetc(stream);	// le o proximo caracter da stream
		if (caracter == EOF) {	// erro ou fim do arquivo de fato
			if (ferror(stream)) {	// retorna verdadeiro se houve erro
				perror("Nao foi possivel ler o arquivo");
				fclose(stream);
				return -1;
			}
		}
		else {	// nao; eh um caracter valido...
			if (isupper(caracter)) {
				++maiusculas;
			}
			if (fputc(tolower(caracter), saida) == EOF) { // deu erro?
				perror("Nao foi possivel escrever no arquivo");
				fclose(saida);
				fclose(stream);
				return -1;
			}
		}
	}
	// Programadores educados fecham os arquivos abertos
	fclose(stream);
	fclose(saida);

	printf("Encontrei %u maiusculas no arquivo.\n", maiusculas);
	return 0;
}

