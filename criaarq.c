#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>

#define MAX_NOME		50
#define MAX_DIRETORIO	200

int main() {
	char nome[MAX_NOME];
	char diretorio[MAX_DIRETORIO];
	char completo[MAX_NOME+MAX_DIRETORIO];

	printf("Digite o nome do arquivo que deseja criar: ");
	gets(nome);
	printf("Digite o caminho completo do diretorio (ex. /tmp/dir1/dir2): ");
	__fpurge(stdin);
	gets(diretorio);

	strcpy(completo, diretorio);	// copia diretorio para completo
	strcat(completo, "/");			// adiciona uma / para separar do nome do arquivo
	strcat(completo, nome);			// adiciona o nome do arquivo

	FILE* stream = fopen("/tmp/fixo.txt", "wt");	// "wt" = cria arquivo (stream) do tipo texto

	// Doravante, todas as operacoes com este arquivo criado devem usar o ponteiro
	// 'stream' como parametro (e nao mais o nome do arquivo)
	
	FILE* outro = fopen(completo, "wt");

	// Apos o uso dos arquivos, as streams devem ser fechadas!
	fclose(stream);	// repare o uso do ponteiro retornado por fopen()
	fclose(outro);

	return 0;
}

