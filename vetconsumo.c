/* Escreva um programa em C que colete as distancias percorridas
 * por um carro diariamente ao longo de uma semana e o consumo
 * de combustivel tambem de cada dia. Calcule as medias diarias e
 * semanal de consumo desse veiculo */

#include <stdlib.h>
#include <stdio.h>

#define DIAS 7 // sendo do pre-processador nao usa ponto-e-virgula nem '='

int main(void) {
    /* Variaveis escalares...
    int dist1, dist2, dist3, dist4, dist5, dist6, dist7;
    float cons1, cons2, cons3, cons4, cons5, cons6, cons7;
    */

    /*
    // Variaveis compostas homogeneas: vetores
    int distancias[DIAS]; // conjunto de 7 valores inteiros
    float consumos[DIAS], medias[DIAS]; // conjuntos de 7 valores reais
    */

    // Alternativa com numero de dias variavel:
    int dias;
    do {
        printf("Quantos dias pretende coletar? ");
        scanf("%d", &dias);
    } while (dias <= 0 || dias > DIAS);
    
    int distancias[dias];
    float consumos[dias], medias[dias];

    /* Acessos corretos aos vetores
     * printf("%d", distancias[0]);
     * scanf("%f", &consumos[1]);
     *
     * Acessos invalidos
     * printf("%d", distancias[7]); <-- O INDICE 7 NAO EXISTE!
     * scanf("%f", &consumos[-1]); <-- IDEM PARA -1!
     * Porem, a linguagem C ACEITA os comandos acima!!!
     */

    // Percurso nos vetores para preenche-los
    int dia;
    for (dia = 1; dia <= dias; ++dia) {
        printf("Qual foi a distancia percorrida no dia %d? ", dia);
        scanf("%d", &distancias[dia-1]); // lembre que inicia em 0
        printf("E o consumo, quanto foi? ");
        scanf("%f", &consumos[dia-1]); // no mesmo dia/indice :-)

        // Aproveita e calcula a media diaria
        medias[dia-1] = distancias[dia-1] / consumos[dia-1];
        printf("Nesse dia, a media foi %.1f\n", medias[dia-1]);
    }

    float media_geral, soma = 0.0;
    for (dia = 0; dia < dias; ++dia) { // comeca com 0 pra usar como
                                       // indice (repare o sinal <)
        soma += medias[dia]; // agora nao subtrai 1 do indice!
    }
    media_geral = soma / 7;
    printf("A media geral de consumo foi %.1f\n", media_geral);

    return EXIT_SUCCESS;
}

