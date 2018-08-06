#include <stdlib.h>
#include <stdio.h>
#include <math.h>

unsigned determina_num_termos_aproximacao(float, float);

int main(void) {
    printf("Digite o valor de x para teste: ");
    float x;
    scanf("%f", &x);
    printf("Digite o erro maximo aceitavel: ");
    float erro;
    scanf("%f", &erro);

    printf("Sao necessarios %u termos para aproximacao pela serie.\n",
           determina_num_termos_aproximacao(x, erro));

    return EXIT_SUCCESS;
}

unsigned determina_num_termos_aproximacao(float x, float dif) {
    if (x <= -1.0 || x >= 1.0) {
        return 0;   // condicao de "entrada"/parametro invalida/o
    }
    float y_alvo;   // valor de f(x) aplicando o x recebido
    y_alvo = 1 / (1 - x);

    float y_aprox;  // valor calculado pela serie f'(x) para um determinado
                    // numero de termos
                    // Esse numero de termos vai sendo incrementado dentro
                    // do laco enquanto a diferenca entre y_alvo e y_aprox
                    // for maior que o erro (dif)
    unsigned termos = 0;    // numero de termos serah incrementado pelo
                            // laco enquanto dif nao for alcancado
    y_aprox = 0;    // inicializacao do somatorio, ou seja, f'(x)
    do {
        y_aprox += pow(x, termos);  // soma o proximo termo pra entao conferir
                                    // se o erro maximo foi atingido
                                    // (note o uso do contador de termos como
                                    // expoente)
        ++termos;   // contabiliza o termo (pode ser o proximo expoente se o
                    // laco repetir...)
    } while (fabsf(y_aprox- y_alvo) > dif); // testa diferenca em modulo
    return termos;
}

