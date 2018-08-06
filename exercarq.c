/* Escreva um programa em C que leia o nome, peso e altura
 * de um grupo de pessoas e armazene essas informacoes num
 * arquivo texto, onde cada linha corresponde aos dados de
 * uma pessoa.
 * O programa deve interromper a leitura ao receber um nome
 * que inicie com um algarismo.
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdio_ext.h> // para usar __fpurge()
#include <ctype.h> // para usar isdigit()

#define MAX_NOME 300

int main(void) {
    char nome[MAX_NOME];
    float peso, altura;

    FILE* arquivo = fopen("/tmp/exercicio.txt", "w");
    if (arquivo == 0) {
        perror("Erro na criacao do arquivo");
        return EXIT_FAILURE;
    }

    do {
        printf("Digite o nome da pessoa: ");
        __fpurge(stdin); // para limpar o buffer de uma leitura anterior...
        gets(nome);
        if (!isdigit(nome[0])) { // confere o inicio da string
            printf("Digite o peso da pessoa: ");
            scanf("%f", &peso);
            printf("Digite a altura: ");
            scanf("%f", &altura);

            fprintf(arquivo, "%s, %.1f, %.2f\n", nome, peso, altura);
        }
    } while (!isdigit(nome[0]));

    fclose(arquivo);

    return EXIT_SUCCESS;
}

