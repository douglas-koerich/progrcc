#include <stdlib.h>
#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>

void grava_e_libera(char* [], int);

int main(int argc, char* argv[]) {
    // Recebe na linha de comando o tamanho do cadastro de nomes
    if (argc < 2) {
        puts("Numero insuficiente de parametros");
        printf("Uso: %s <tamanho-do-cadastro>\n", argv[0]);
        return EXIT_FAILURE;
    }
    int n = atoi(argv[1]);  // converte a string do numero em inteiro
    char* lista_nomes[n];   // declaracao estatica (sem alocacao dinamica)

    int i;
    for (i=0; i<n; ++i) {
        char string_entrada[100];
        printf("Digite o nome completo para cadastro: ");
        __fpurge(stdin);
        gets(string_entrada);

        // Vou copiar a string digitada para o vetor/lista de strings,
        // alocando para o elemento/ponteiro correspondente (char*[i])
        // o numero de bytes de tamanho justo para a string
        int tamanho_string = strlen(string_entrada); // num. chars antes do '\0'
        lista_nomes[i] = malloc(tamanho_string+1); // +1 para o '\0' nao contado pelo strlen()
        strcpy(lista_nomes[i], string_entrada); // copia string normalmente
    }
    grava_e_libera(lista_nomes, n);
    return EXIT_SUCCESS;
}

void grava_e_libera(char* vetor_strings[], int num_strings) {
    FILE* arquivo = fopen("/tmp/nomes.txt", "w");
    if (arquivo == NULL) {
        // Nao esquece de liberar os ponteiros
        int i;
        for (i=0; i<num_strings; ++i) {
            free(vetor_strings[i]);
        }
        return;
    }
    int i;
    for (i=0; i<num_strings; ++i) {
        fputs(vetor_strings[i], arquivo); // grava_e_...
        fputc('\n', arquivo);
        free(vetor_strings[i]); // ... _libera
    }
    fclose(arquivo);
}

