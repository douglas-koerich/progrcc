/* Escreva uma funcao em linguagem C que calcule o logaritmo de um numero N em
 * uma base B, dados N e B como parametros para a funcao. */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

// Declaracao da funcao: "prototipo"
float logBf(float, float);  // (assinatura da funcao)
void tabela_logBf(int, int, float);

int main(void) {    // main() eh uma funcao sem parametros de entrada, entao usa void
    float N, B, L;
    printf("Digite o numero N: ");
    scanf("%f", &N);
    printf("Digite a base B: ");
    scanf("%f", &B);

    // Chamada da funcao -> desvio da execucao para dentro da funcao logBf
    L = logBf(N, B);    // A variavel local L salva o valor retornado pela funcao

    printf("O logaritmo de %.3f na base %.3f eh %.3f.\n", N, B, L);
    printf("O logaritmo de %.3f na base %.3f eh %.3f.\n", N, B*2, logBf(N, B*2));

    // Imprime uma tabela de logaritmos
    printf("Digite os numeros minimo e maximo (inteiros) para impressao de uma tabela de logaritmos: ");
    int m, M;
    scanf("%d %d", &m, &M);

    printf("***** TABELA DE LOGARITMOS *****\n");
    tabela_logBf(m, M, B);

    return EXIT_SUCCESS;
}

// Definicao da funcao: tipo-retorno=float; nome-func=logBf; lista-param=n, b
float logBf(float n, float b)
{
    if (n == 1) {
        return 0;   // retorna imediatamente a partir daqui
    }
    float L;    // Esta variavel NAO EH A MESMA variavel declarada na funcao main()
    L = log10f(n) / log10f(b);
    return L;   // O tipo da variavel que eh devolvida/retornada deve ser
                // o mesmo do tipo-retorno da funcao
}

void tabela_logBf(int inf, int sup, float base) {
    if (sup < inf) {
        return; // nao devolve nada, simplesmente sai da funcao pois nao ha nada a fazer...
    }
    int num;
    for (num = inf; num <= sup; ++num) {
        float l = logBf(num, base);
        printf("n = %d, log(n) = %.3f\n", num, l);
    }
}
