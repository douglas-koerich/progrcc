#include <stdlib.h>
#include <stdio.h>

#define NUM_NOMES   5
#define TAM_NOME    100

int main(void) {
    // Lista de nomes = vetor de strings = matriz de caracteres
    char lista_nomes[NUM_NOMES][TAM_NOME] = {
        "Anonimo",  // inicializacao da primeira linha da matriz (da primeira string)
        "Desconhecido",
        "Ignorado",
        "Esquecido",
        "Desprezado"
    };

    // Para imprimir uma lista, i.e. um vetor, usa-se um laco apenas
    int n;
    for (n = 0; n < NUM_NOMES; ++n) {
        printf("O %do. individuo chama-se %s.\n", n+1, lista_nomes[n]); // apenas um indice na "matriz"
    }

    // Le o terceiro nome diretamente
    printf("Digite o nome do agora 'Ignorado': ");
    gets(lista_nomes[2]);

    // Imprimindo a lista atualizada:
    for (n = 0; n < NUM_NOMES; ++n) {
        printf("O %do. individuo chama-se %s.\n", n+1, lista_nomes[n]);
    }

    return EXIT_SUCCESS;
}
