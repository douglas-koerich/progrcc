#include <stdbool.h>
#include <stdio.h>

int main() {
    float perc_carbono, rokwell, resistencia;

    /*
    int num_amostra = 1;
    while (num_amostra <= 112) {
    */
    int num_amostra;
    for (num_amostra=1; num_amostra<=3; ++num_amostra) {
        // Entrada de dados para esta amostra
        do {
            printf("Digite o percentual de carbono da amostra: ");
            scanf("%f", &perc_carbono);
        } while (perc_carbono < 0.0 || perc_carbono > 100.0);

        printf("Digite a dureza Rokwell da amostra: ");
        scanf("%f", &rokwell);

        do {
            printf("Digite a resistencia a tracao (psi): ");
            scanf("%f", &resistencia);
        } while (resistencia < 0.0);

        // Testes (a), (b) e (c) desta amostra
        bool teste_a = perc_carbono < 7.0; // verdadeiro se abaixo de 7%
        bool teste_b = rokwell > 50;
        bool teste_c = resistencia > 80000;

        // Classificacao da amostra
        int grau;
        if (teste_a && teste_b && teste_c) {
            grau = 10;
        }
        else if (teste_a && teste_b) {
            grau = 9;
        }
        else if (teste_a) {
            grau = 8;
        }
        else {
            grau = 7;
        }
        /*
        int grau = teste_a && teste_b && teste_c? 10:
                   teste_a && teste_b? 9:
                   teste_a? 8: 7;
        */
        // Exibicao do resultado para essa amostra
        printf("O grau da amostra eh %d\n", grau);

        /* Necessario para o laco while(), mas ja contido no laco for()
        // Incrementa o numero da amostra (controle do laco)
        ++num_amostra;
        */

    }   // fim do laco das amostras

    return 0;
}

