#include <stdlib.h>
#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include <ctype.h>

#define MAX_NOME 50

int main(void) {
    char nome[MAX_NOME];
    unsigned idade;
    float altura;
    char genero;

    FILE* banco_de_dados = fopen("/tmp/bd.txt", "a");
    if (banco_de_dados == 0) {
        perror("Nao pode abrir (ou criar) o banco de dados");
        return EXIT_FAILURE;
    }

    puts("*** DIGITE DADOS CADASTRAIS (nome vazio para terminar) ***");
    do {
        __fpurge(stdin); // limpeza do laco anterior
        printf("Nome? "); gets(nome);
        if (strlen(nome) > 0) { // nome nao eh "vazio"?
            printf("Idade? "); scanf("%u", &idade);
            printf("Altura (m)? "); scanf("%f", &altura);
            do {
                printf("Genero (M/F)? "); scanf(" %c", &genero);
                genero = toupper(genero);
            } while (genero != 'M' && genero != 'F');
            fprintf(banco_de_dados, "%s, %u, %.2f, %c\n", nome, idade, altura,
                    genero);
        }
    } while (strlen(nome) > 0); // repete se nome nao foi vazio

    fclose(banco_de_dados);

    return EXIT_SUCCESS;
}

