#include <stdio.h>
#include <stdio_ext.h>  // __fpurge
#include <string.h>     // strlen, strcat

#define NOME_ARQUIVO    "./teste.txt"   // no diretorio (pasta) local de
                                        // onde chamou a execucao do programa
#define NOVO_ARQUIVO    "/tmp/novo.txt" // caminho completo de diretorio

int main() {
    // Ponteiro para uma estrutura interna da linguagem C (nao eh necessario
    // manipular o conteudo dessa estrutura, basta usar o ponteiro em si)
    FILE* stream;

    // Vou abrir o arquivo desejado (./teste.txt)
    stream = fopen(NOME_ARQUIVO, "rt");
    if (stream == NULL) { // NULL eh indicacao de erro na operacao com arquivo
        // puts("Erro na abertura do arquivo");
        perror("Erro na abertura do arquivo");
        return -1;  // retorna do programa com um codigo de ERRO
    }
    // Le o primeiro caracter existente no arquivo e imprime-o na tela
    char ch = fgetc(stream);
    if (ch == EOF) {    // EOF pode vir do fgetc() em duas situacoes:
        // 1a. situacao: EOF="end-of-file" (fim do arquivo foi encontrado)
        // 2a. situacao: houve um ERRO de leitura
        // Pra saber qual eh o caso entre as situacoes, usa ferror()
        if (ferror(stream)) {   // houve de fato um ERRO???
            perror("Erro na leitura do arquivo");
            fclose(stream); // jah estah aberto, entao fecha
            return -1;
        }
        else {  // nao, encontrou de fato o fim do arquivo
            puts("Fim do arquivo");
        }
    }
    else { // ch != EOF, entao eh um caracter valido para ser impresso
        printf("O caracter lido do arquivo eh %c.\n", ch);
    }
    // Le todos os caracteres do arquivo, ateh o final
    rewind(stream); // "rebobina" X-D o arquivo para o inicio
    while (!feof(stream)) { // "enquanto NAO(!) for encontrado o fim do arquivo"
        ch = fgetc(stream);
        if (ch != EOF) {    // esta leitura pode ter encontrado o fim,
                            // mas jah estou dentro do laco... :-(
            putchar(ch);    // putchar exibe o caracter na tela
        }
    }

    // Apos o uso desejado do arquivo, deve fecha-lo no sistema
    fclose(stream);

    // Vou criar um novo arquivo para armazenar uma frase
    stream = fopen(NOVO_ARQUIVO, "wt"); // sobrescreve se jah existir...
    if (stream == NULL) { // pode ser que nao haja permissao para escrita...
        perror("Erro ao criar o arquivo");
        return -1;
    }

    // Le uma frase digitada pelo usuario
    char frase[200];
    puts("Digite uma frase para ser salva no arquivo:");
    gets(frase);

    // Salva no arquivo caracter por caracter... :-/
    int i = 0;
    while (frase[i] != '\0') {
        if (fputc(frase[i], stream) == EOF) { // EOF indica ERRO no fputc!
            perror("Erro ao escrever no arquivo");
            fclose(stream);
            return -1;
        }
        ++i;
    }
    // Ao fim da escrita, fecha o arquivo
    fclose(stream);

    // Le a primeira linha de um arquivo texto escolhido pelo usuario
    char nome_arquivo[100];
    printf("Digite o nome do arquivo: ");
    scanf(" %s", nome_arquivo);
    stream = fopen(nome_arquivo, "r");  // 't' fica implicito
    if (stream == NULL) {
        perror("Erro ao abrir o arquivo de linhas");
        return -1;
    }
    // fgets() coloca na string toda a linha, incluindo o \n lido
    if (fgets(frase, sizeof(frase), stream) == NULL) {
        if (ferror(stream)) {
            perror("Erro ao ler uma nova linha do arquivo");
            fclose(stream);
            return -1;
        }
        else {
            puts("Fim do arquivo");
        }
    }
    else {
        printf("Linha obtida do arquivo: %s\n", frase);
    }

    // Ler o restante das linhas...
    while (!feof(stream)) {
        if (fgets(frase, sizeof(frase), stream) != NULL) {
            printf("%s", frase);
        }
    }

    // Fecha o arquivo
    fclose(stream);

    // Exemplo de escrita de strings/linhas num arquivo
    stream = fopen("/tmp/log.txt", "w");
    if (stream == NULL) {
        perror("Erro ao criar o arquivo de logs");
        return -1;
    }
    char log[200];
    puts("Digite abaixo um conjunto de linhas para serem logadas no arquivo (<Enter> para finalizar):");
    do {
        __fpurge(stdin);
        // gets() troca o \n digitado no fim da linha por um \0 (terminador
        // nulo...
        gets(log);
        if (strlen(log) > 0) {
            // Por causa dessa substituicao (de \n por \0) do gets(),
            // precisamos adicionar o \n "na mao"
            strcat(log, "\n");

            // Ao contrario de puts() que sempre coloca o \n no final,
            // fputs() respeita a string como ela esta (no caso, sem \n)
            if (fputs(log, stream) == EOF) {
                perror("Erro ao escrever a linha no arquivo de logs");
                fclose(stream);
                return -1;
            }
        }
    } while (strlen(log) > 0);

    fclose(stream);

    int vetor[] = { 34, 12, 57, 9, 33, 26, 15, 20, 49, -1 };
    stream = fopen("/tmp/vetor.txt", "wt");
    if (stream == NULL) {
        perror("Erro ao criar arquivo de numeros");
        return -1;
    }
    int i = 0;
    while (vetor[i] >= 0) {
        if (fprintf(stream, "vetor[%d] = %d\n", i, vetor[i]) < 0) {
            perror("Erro ao escrever o valor do vetor no arquivo");
            fclose(stream);
            return -1;
        }
        ++i;
    }
    fclose(stream);

    unsigned num_linha;
    printf("Digite o numero da linha que deseja ler do arquivo: ");
    scanf("%u", &num_linha);

    stream = fopen("/tmp/vetor.txt", "r");
    if (stream == NULL) {
        perror("Erro ao abrir o arquivo de numeros");
        return -1;
    }
    char linha[200];
    for (i=1; i<num_linha; ++i) {
        // Linhas anteriores vao ser descartadas (eh o unico modo de se
        // chegar a uma linha especifica, ja que nao se sabe o tamanho
        // das linhas anteriores para "saltar" sobre elas)
        if (fgets(linha, sizeof(linha), stream) == NULL) {
            int retorno;
            if (ferror(stream)) {
                perror("Erro ao saltar sobre linhas anteriores");
                retorno = -1;
            }
            else {
                puts("Encontrou o fim do arquivo antes...");
                retorno = 0;
            }
            fclose(stream);
            return retorno;
        }
        // Nao faz nada com a linha lida...
    }
    // Agora estou para ler a linha desejada!
    if (fgets(linha, sizeof(linha), stream) == NULL) {
        if (ferror(stream)) {
            perror("Erro ao ler a linha desejada");
            fclose(stream);
            return -1;
        }
    }
    else {
        printf("Linha lida: %s\n", linha);
    }
    fclose(stream);

    int matriz[2][3] = {
        { 1, 35, 17 },
        { 563, 341, 2 }
    };
    stream = fopen("/tmp/matriz.txt", "w");
    if (stream == NULL) {
        perror("Erro ao criar o arquivo da matriz");
        return -1;
    }
    int l, c;
    for (l=0; l<2; ++l) {
        for (c=0; c<3; ++c) {
            fprintf(stream, "%5d ", matriz[l][c]);
        }
        fputc('\n', stream);
    }
    fclose(stream);

    return 0;
}

