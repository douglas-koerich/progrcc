#include <stdlib.h>
#include <stdio.h>

int main() {
    // Dados de entrada: populacao inicial (n0) e taxa de crescimento (p)
    double n0, p;

    printf("Qual eh a quantidade inicial de bacterias? ");
    scanf("%lf", &n0);
    printf("Qual eh a taxa (0-1) de crescimento por segundo? ");
    scanf("%lf", &p);

    // Outros dados de entrada, nao tao explicitos no enunciado
    int periodo, intervalo;

    // Para facilitar, vamos pedir que o periodo (total) seja dado em dias, e o
    // intervalo (para as parciais) seja dado em horas
    printf("Digite o tempo total da simulacao do crescimento, em dias: ");
    scanf("%d", &periodo);
    printf("Digite o tempo decorrido entre cada contabilizacao parcial da populacao, em horas: ");
    scanf("%d", &intervalo);

    // Dado acumulativo usado na saida: populacao no momento atual (n)
    double n;

    /*
    // Primeiro segundo:
    n = n0 * (1 + p);

    // Segundo, terceiro, quarto, quinto... segundo:
    n0 = n;
    n = n0 * (1 + p);
    */
    // Eh necessario converter aquelas medidas de tempo para segundos, a fim de determinar
    // quando, em cada passo, sera impresso o subtotal e a decisao de parar a simulacao, ja
    // que o laco eh executado "por segundo de crescimento"
    periodo = periodo * 3600 * 24;  // periodo *= 3600*24;
    intervalo = intervalo * 3600;   // intervalo *= 3600;

    // Laco que "executa para cada segundo da simulacao", atualizando a populacao
    int cronometro = 0;
    while (cronometro <= periodo) { // pelo tempo total da simulacao...
        if (cronometro % intervalo == 0) {
            printf("n(%d) = %.5e\n", cronometro, n0);
        }
        n = n0 * (1 + p);   // atualiza a populacao
        n0 = n;             // prepara para a proxima iteracao (proximo segundo)
        ++cronometro;       // proximo segundo
    }

    return EXIT_SUCCESS;
}
