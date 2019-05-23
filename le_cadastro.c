#include <stdlib.h>
#include <stdio.h>

#define MAX_NOME 100

int main(void) {
    FILE* bd = fopen("/tmp/bd.txt", "r");
    if (bd == 0) {
        perror("Nao foi possivel abrir o arquivo");
        return EXIT_FAILURE;
    }
    unsigned soma_idades = 0, contador = 0;

    while (!feof(bd)) {
        char nome[MAX_NOME];
        unsigned idade;
        float altura;
        char sexo;

        // Ao inves de indicar para o fscanf a entrada/leitura de uma string com %s,
        // vamos delimitar a faixa de caracteres que ele pode considerar como parte
        // valida dessa string; do contrario, ele nao saberia que a virgula e os
        // numeros que vem na sequencia NAO fazem parte da mesma string que ele leria
        // com o %s
        /*
        if (fscanf(bd, "%s, %u, %f, %c\n", nome, &idade, &altura, &sexo) == EOF) {
        */
        if (fscanf(bd, "%[A-Za-z ], %u, %f, %c\n", nome, &idade, &altura, &sexo)
            == EOF) {
            if (ferror(bd)) { // foi erro mesmo ou foi fim de arquivo?
                perror("Erro ao ler do arquivo");
                fclose(bd);
                return EXIT_FAILURE;
            }
        } else {
            puts("Dados lidos:");
            printf("Nome --> %s\n", nome);
            printf("Idade -> %u\n", idade);
            printf("Altura-> %.2f\n", altura);
            printf("Sexo --> %c\n", sexo);

            ++contador;
            soma_idades += idade;
        }
    }
    fclose(bd);

    float media_idades = (float) soma_idades / contador;
    printf("A media das idades eh %.1f anos.\n", media_idades);

    return EXIT_SUCCESS;
}

