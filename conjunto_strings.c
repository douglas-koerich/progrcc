#include <stdlib.h>
#include <stdio.h>
#include <stdio_ext.h>

#define NUM_NOMES 3
#define TAM_MAX_NOME 20

#define NUM_LINHAS 2
#define NUM_COLUNAS NUM_LINHAS

int main(void) {
    // Vetor de strings, para conter uma sequencia (lista) de nomes:
    char vetor[NUM_NOMES][TAM_MAX_NOME+1];  // +1 para o \0 de cada string/linha

    // Matriz de strings, para conter uma tabela de nomes:
    char matriz[NUM_LINHAS][NUM_COLUNAS][TAM_MAX_NOME+1];

    // Em suma, quando se quer um conjunto de strings, a matriz de caracteres
    // tem que ser de uma dimensao a mais do que a dimensao pretendida (vetor=1, tabela=2),
    // para conter a dimensao-extra usada pela propria string (que eh um vetor de caracteres)

    char outro_vetor[NUM_NOMES][TAM_MAX_NOME+1] = { "Universidade", "Tuiuti", "Parana" };

    // Preenchendo o vetor de nomes (lista de strings/matriz de caracteres)
    int n;
    for (n = 0; n < NUM_NOMES; ++n) { // laco para percorrer o "vetor"
        printf("Digite o %do. nome: ", n+1);
        __fpurge(stdin);
        gets(vetor[n]); // passa a linha para a qual 'gets' vai fazer o "laco interno" (preenchendo os caracteres)
    }

    // Gravando num arquivo-texto os nomes armazenados no vetor:
    FILE* arq_lista;
    arq_lista = fopen("/tmp/lista.txt", "w");   // cria um novo arquivo para os nomes
    if (arq_lista == 0) {
        perror("Erro ao criar o arquivo /tmp/lista.txt");
        return EXIT_FAILURE;
    }
    for (n = 0; n < NUM_NOMES; ++n) {
        if (fputs(vetor[n], arq_lista) == EOF) { // fputs nao acrescenta o \n ao final da string
            perror("Erro ao escrever no arquivo /tmp/lista.txt");
            fclose(arq_lista);
            return EXIT_FAILURE;
        }
        if (fputc('\n', arq_lista) == EOF) {
            perror("Erro ao saltar de linha no arquivo /tmp/lista.txt");
            fclose(arq_lista);
            return EXIT_FAILURE;
        }
    }
    fclose(arq_lista);

    // Preenchendo a tabela de nomes
    int l, c;
    for (l = 0; l < NUM_LINHAS; ++l) {
        for (c = 0; c < NUM_COLUNAS; ++c) {
            printf("Digite o nome da linha %d, coluna %d: ", l, c);
            __fpurge(stdin);
            gets(matriz[l][c]); // de novo passa uma string (que eh aquela da posicao l,c da matriz tridimensional)
        }
    }
    // Continua a escrever no mesmo arquivo de antes, jah fechado, a partir do seu final
    arq_lista = fopen("/tmp/lista.txt", "a");
    if (arq_lista == 0) {
        perror("Erro ao abrir o arquivo /tmp/lista.txt");
        return EXIT_FAILURE;
    }
    // Guarda no arquivo os nomes da matriz numa tabela alinhada
    for (l = 0; l < NUM_LINHAS; ++l) {
        // Imprime as duas colunas num unico fprintf, com um adereco de coluna:
        fprintf(arq_lista, "| %20s | %20s |\n", matriz[l][0], matriz[l][1]);
    }
    fclose(arq_lista);

    // Verifica qual foi o segundo nome gravado no arquivo:
    // pra isso, precisa ler a primeira linha e descarta-la, e em seguida
    // ler a proxima linha (a segunda)
    char linha[256]; // tamanho suficiente para a maior linha esperada
    arq_lista = fopen("/tmp/lista.txt", "r");
    if (arq_lista == 0) {
        perror("Erro ao abrir o arquivo /tmp/lista.txt para leitura");
        return EXIT_FAILURE;
    }
    for (l = 1; l <= 3; ++l) { // le as tres primeiras linhas pra chegar ao inicio da matriz
       if (fgets(linha, sizeof(linha), arq_lista) == 0) {
            if (ferror(arq_lista)) {
                perror("Erro ao tentar ler a linha");
            } else {
                puts("Fim inesperado do arquivo!");
            }
            fclose(arq_lista);
            return EXIT_FAILURE;
       } else {
           if (l == 2) {
               // Pondo \n no printf vai duplicar com o \n lido pelo fgets:
               // printf("Segundo nome gravado no arquivo foi %s\n", linha);
               printf("Segundo nome gravado no arquivo foi %s", linha);
           }
       }
    }
    // Le os dois primeiros nomes que estao na primeira linha da tabela
    char nome1[TAM_MAX_NOME+1], nome2[TAM_MAX_NOME+1];
    fscanf(arq_lista, "| %[A-Za-z] | %[A-Za-z] |\n", nome1, nome2);
    printf("Os nomes lidos do inicio da tabela no arquivo sao: %s e %s.\n", nome1, nome2);

    fclose(arq_lista);
    return EXIT_SUCCESS;
}

