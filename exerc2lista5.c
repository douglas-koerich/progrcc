#include <stdlib.h>
#include <stdio.h>

#define NUM_ELEMENTOS 20 // sem ponto-e-virgula!

int main(void) {
    int var_vetor[NUM_ELEMENTOS];

    int i;
    for (i = 0; i < NUM_ELEMENTOS; ++i) {
        printf("Digite var_vetor[%d]? ", i);
        scanf("%d", &var_vetor[i]);
    }
    // Mesmo nao pedido pelo enunciado, vou imprimir o vetor apos as leituras
    for (i = 0; i < NUM_ELEMENTOS; ++i) {
        printf("%d ", var_vetor[i]);
    }
    printf("\n"); // nova linha apos imprimir todos os numeros

    int numeros[NUM_ELEMENTOS];     // os numeros diferentes encontrados no vetor
    int contadores[NUM_ELEMENTOS];  // o contador de cada numero; esse contador fica
                                    // na mesma posicao do numero em 'numeros' pra
                                    // associar um ao outro (numero ao contador)
    unsigned qtde_numeros_diferentes = 0; // permite saber quanto dos vetores acima
                                          // foi ocupado
    
    // Percorre o vetor lido do usuario
    for (i = 0; i < NUM_ELEMENTOS; ++i) {
        // Procura o numero da vez no vetor de numeros ja encontrados
        int j;

        // Percorre a "area util" (ja preenchida) dos vetores de controle
        for (j = 0; j < qtde_numeros_diferentes; ++j) {
            if (numeros[j] == var_vetor[i]) {
                ++contadores[j];
                break;
            }
        }
        // Se 'j' chegou ao valor 'qtde_numeros_diferentes', entao eh porque
        // o 'break' nao aconteceu --> numero nao tinha sido encontrado antes no vetor
        if (j == qtde_numeros_diferentes) {
            numeros[j] = var_vetor[i]; // salva nessa posicao (primeira livre) o numero
            contadores[j] = 1;         // inicia a contagem do novo numero
            ++qtde_numeros_diferentes; // computa o novo numero na lista de encontrados
        }
    }

    // Exibe a lista dos repetidos
    for (i = 0; i < qtde_numeros_diferentes; ++i) {
        if (contadores[i] > 1) { // o numero nessa posicao eh repetido?
            printf("O numero %d repetiu-se %d vezes.\n", numeros[i], contadores[i]);
        }
    }
    return EXIT_SUCCESS;
}

