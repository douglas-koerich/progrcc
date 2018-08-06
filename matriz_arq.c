#include <stdio.h>
#include <stdlib.h>

#define LINHAS 3
#define COLUNAS 4

#define ARQ_TEXTO   "/tmp/matriz.txt"
#define ARQ_BINARIO "/tmp/matriz.bin"

int main(int argc, char* argv[]) {
    int matriz[LINHAS][COLUNAS] = {
        { 1, -4, 5, 2 },
        { 0, 3, 8, -12 },
        { 9, 2, 1, 0 }
    };
    FILE* arqmat_txt = fopen(ARQ_TEXTO, "w+");  // criar, escrever e ler depois
    if (arqmat_txt == NULL) {
        perror("Nao foi possivel criar o arquivo-texto da matriz");
        return EXIT_FAILURE;
    }
    int l, c;
    for (l = 0; l < LINHAS; ++l) {
        for (c = 0; c < COLUNAS; ++c) {
            printf("%3d ", matriz[l][c]);   // na tela
            if (fprintf(arqmat_txt, "%3d ", matriz[l][c]) < 0) { // no arquivo-texto
                perror("Erro ao escrever no arquivo-texto");
                return EXIT_FAILURE;
            }
        }
        putchar('\n');  // salto-de-linha na tela
        if (fputc('\n', arqmat_txt) == EOF) {   // idem no arquivo
            perror("Erro ao escrever no arquivo-texto");
            return EXIT_FAILURE;
        }
    }
    // Uma vez salva a matriz no arquivo, vou recupera-la de lah e calcular a soma
    // da SEGUNDA linha
    // Como o arquivo foi criado com w+, precisa voltar ao inicio dele para fazer a leitura
    // a partir dali
    rewind(arqmat_txt);
    char linha[256];
    // Pula a primeira linha da matriz escrita no arquivo-texto
    if (fgets(linha, sizeof(linha), arqmat_txt) == NULL) {
        puts("Erro inesperado de leitura da matriz");
        return EXIT_FAILURE;
    }
    int soma = 0;
    for (c = 0; c < COLUNAS; ++c) {
        int numero;
        if (fscanf(arqmat_txt, "%d", &numero) == EOF) {
            puts("Erro inesperado de leitura da linha");
            return EXIT_FAILURE;
        }
        soma += numero;
    }
    printf("(TEXTO) A soma da segunda linha eh %d.\n", soma);

    fclose(arqmat_txt);

    // Vamos repetir TODO o processo, dessa vez gravando e lendo de um arquivo
    // binario (os numeros inteiros serao armazenados no seu formato binario
    // original)
    FILE* arqmat_bin = fopen(ARQ_BINARIO, "w+b");  // 'b' indica arquivo binario
    if (arqmat_bin == NULL) {
        perror("Nao foi possivel criar o arquivo-binario da matriz");
        return EXIT_FAILURE;
    }
    for (l = 0; l < LINHAS; ++l) {
        for (c = 0; c < COLUNAS; ++c) {
            if (fwrite(&matriz[l][c], sizeof(int), 1, arqmat_bin) < 1) {
                perror("Erro ao escrever no arquivo-binario");
                return EXIT_FAILURE;
            }
        }
    }
    // Uma vez salva a matriz no arquivo, vou recupera-la de lah e calcular a soma
    // da SEGUNDA linha
    // Como o arquivo esta no formato binario, e todos os numeros tem o mesmo
    // comprimento em bytes, posso "pular" uma linha inteira sem le-la
    if (fseek(arqmat_bin, COLUNAS*sizeof(int), SEEK_SET) < 0) {   // pula o tamanho correspondente a uma coluna
        perror("Nao foi possivel deslocar-se no arquivo-binario");
        return EXIT_FAILURE;
    }
    soma = 0;
    for (c = 0; c < COLUNAS; ++c) {
        int numero;
        if (fread(&numero, sizeof(int), 1, arqmat_bin) < 1) {
            perror("Erro inesperado de leitura da linha");
            return EXIT_FAILURE;
        }
        soma += numero;
    }
    printf("(BINARIO) A soma da segunda linha eh %d.\n", soma);

    fclose(arqmat_bin);

    return EXIT_SUCCESS;
}
