#include <stdlib.h>
#include <stdio.h>

#define NUM_CORRIDAS    10  // SEM ponto-e-virgula!

float calcula_media(int, int, float [*], size_t);

int main(void) {
    const float marcas_referencia[NUM_CORRIDAS] = {
        10.98, 10.87, 10.76, 9.97, 10.56, 9.95, 10.24, 10.54, 9.94, 10.13
    };
    /* Outras inicializacoes possiveis:
    float exemplo_1[NUM_CORRIDAS] = { 1.0, 2.0 };   // 8 restantes = 0.0
    float exemplo_2[NUM_CORRIDAS] = {}; // todos os valores zerados
    float exemplo_3[] = { 1.0, 2.0 };  // vetor com 2 posicoes!!
    float exemplo_4[NUM_CORRIDAS] = { 1.0, 2.0, [6] = 7.0 }; // indices 0, 1 e 6 inicializados, demais zerados
    */
    float tempos_100m[NUM_CORRIDAS];  // dez corridas em um periodo mensal
    float pior, melhor;

#if 0   // usa o preprocessador para "comentar" um trecho sem usar
        // /* */ que ja existe internamente...
    printf("Digite o tempo da primeira corrida: ");
    scanf("%f", &tempos_100m[0]);
    /*
    // Curiosidade: para atribuicao a vetor, usamos tambem o indice
    tempos_100m[1] = tempos_100m[0];
    */
    printf("Digite o tempo da segunda corrida: ");
    scanf("%f", &tempos_100m[1]);
#endif
    int i, indice_pior, indice_melhor;
    for (i=1; i<=NUM_CORRIDAS; ++i) {
        printf("Digite o tempo da %da. corrida: ", i);
        scanf("%f", &tempos_100m[i-1]);
        if (tempos_100m[i-1] > marcas_referencia[i-1]) { // compara os vetores na mesma posicao...
            printf("Voce estah %.2f s acima da marca.\n",
                   tempos_100m[i-1] - marcas_referencia[i-1]);
        }
        if (i == 1) {
            pior = melhor = tempos_100m[i-1];
            indice_pior = indice_melhor = 0;    // indice da primeira posicao
        } else {
            if (pior < tempos_100m[i-1]) {
                pior = tempos_100m[i-1];
                indice_pior = i-1;
            }
            if (melhor > tempos_100m[i-1]) {
                melhor = tempos_100m[i-1];
                indice_melhor = i-1;
            }
        }
    }
    printf("O pior e o melhor tempo sao, respectivamente, %.2f e %.2f.\n",
           tempos_100m[indice_pior], tempos_100m[indice_melhor]);

    /*
    // Calculo da media, descartando o pior e o melhor tempo
    float soma = 0.0;
    for (i=0; i<NUM_CORRIDAS; ++i) {
        if (i == indice_pior || i == indice_melhor) {
            // "Pula" essas posicoes
            continue;   // aborta essa iteracao, vai para proxima
        }
        soma += tempos_100m[i];    // usa o proprio i
    }
    float media = soma / (NUM_CORRIDAS-2); // divide pelo numero de elementos nao descartados
    printf("A media do periodo foi %.2f.\n", media);
    */

    // A chamada a uma funcao que passa um vetor como parametro soh usa o NOME do vetor (sem [])
    float media = calcula_media(indice_pior, indice_melhor, tempos_100m, NUM_CORRIDAS);
    printf("A media do periodo foi %.2f.\n", media);

    return EXIT_SUCCESS;
}

float calcula_media(int ind_descarte_1, int ind_descarte_2, float vetor[], size_t num_elementos) {
    float soma = 0.0;
    int i;
    for (i=0; i<num_elementos; ++i) {
        if (i == ind_descarte_1 || i == ind_descarte_2) {
            continue;
        }
        soma += vetor[i];
    }
    return soma / (num_elementos - 2);
}

