#include <stdlib.h>
#include <stdio.h>

// Prototipo do PROCEDIMENTO (nao retorna nada!) que imprime um vetor
void imprime(float [*], int);   // 1o. parametro: vetor de floats; 2o. parametro: num. de elementos
                                // IMPORTANTE: o uso do * dentro dos [] eh limitado ao prototipo
// Alternativa: void imprime(float [], int);

#define NUM_MESES 6 // SEM o ponto-e-virgula!

int main(void) {
    // const int NUM_MESES = 6; /* outra alternativa para definicao de NUM_MESES */
    float comissoes_mensais[NUM_MESES]; // dentro dos colchetes -> no. de elementos

    // Vetor dos percentuais mensais (cada mes tem um percentual diferente)
    float perc_mensal[NUM_MESES] = { 8.0, 7.5, 4.5, 6.5, 8.0, 9.0 };

    /* VARIANTES DA INICIALIZACAO
     * float perc_mensal[NUM_MESES] = {}; --> todos os valores sao zerados
     * float perc_mensal[] = { 8.0, 7.5, 4.5, 6.5 }; --> CUIDADO: eh um vetor de 4 elementos!
     * float perc_mensal[NUM_MESES] = { 8.0, 7.5, 4.5, 6.5 }; --> 6 elementos, sendo os 4 primeiros inicializados (demais zerados!)
     * float perc_mensal[NUM_MESES] = { [2] = 8.0, 7.5, 4.5, 6.5 }; --> idem, soh que agora sao inicializados os 4 ultimos
     * float perc_mensal[NUM_MESES] = { [1] = 8.0, [4] = 4.5 }; --> somente [1] e [4] inicializados, demais zerados
     */

    /*
     * printf("Digite o numero de meses de vendas: ");
     * int n;
     * scanf("%d", &n);
     * float comissoes_mensais[n];
     */

    int mes;
    for (mes = 1 /*janeiro*/; mes <= NUM_MESES /*dezembro*/; ++mes) {
        float venda; // variavel local ao laco (existe apenas dentro do mesmo)
        printf("Digite o valor da venda no mes %d: ", mes);
        scanf("%f", &venda);
        float comissao = venda * perc_mensal[mes-1] / 100;
        comissoes_mensais[mes-1] = comissao;  // copia para a posicao da vez no vetor
                                              // retira -1 do mes pq vetor inicia em 0
    }
    // Impressao das comissoes   
    /*
    for (mes = 0; mes < NUM_MESES; ++mes) {
        printf("Comissao no mes %d: R$ %.2f\n", mes+1, comissoes_mensais[mes]);
    }
    */
    imprime(comissoes_mensais, NUM_MESES);  // na chamada soh passa o nome do vetor, sem []

    float media_das_comissoes = 0.0;
    for (mes = 0; mes < NUM_MESES; ++mes) {
        media_das_comissoes += comissoes_mensais[mes]; // soma a comissao do mes
    }
    media_das_comissoes /= NUM_MESES;  // media_das_comissoes = media_das_comissoes / NUM_MESES;

    printf("A sua comissao media ficou em R$ %.2f\n", media_das_comissoes);

    return EXIT_SUCCESS;
}

void imprime(float vetor[], int num) {
    int i;
    for (i = 0; i < num; ++i) {
        printf("Valor na posicao [%d] do vetor: %f\n", i, vetor[i]);
        // vetor[i] = 1.0; --> CUIDADO: isso alteraria o vetor ORIGINAL comissoes_mensais!!!
    }
}

