#include <stdlib.h>
#include <stdio.h>
#include <math.h> // fabsf

// Tipo do retorno da funcao
// |                             Tipo do parametro passado pra funcao
// |                             |
// v                             v
float calcula_funcao_original(float x) { // x eh o PARAMETRO da funcao
    // Bloco de codigo da funcao
    if (x == 1) { // Teste de parametro (IN)VALIDO
        return 0; // retorna imediatamente com o valor constante 0 (incorreto)
    }
    float f_x; // variavel LOCAL da funcao (existe enquanto estiver executando)
    f_x = 1 / (1 - x); // aplicacao direta da formula
    return f_x; // retorna para quem chamou o valor calculado
}

// Quando a funcao nao eh DEFINIDA (ou seja, implementada) ANTES da sua chamada,
// o compilador nao a conhece e faz uma DECLARACAO implicita. Por isso, nesse
// caso eh necessario fazer uma declaracao explicita da funcao, chamada de
// "prototipo da funcao":
float calcula_funcao_aproximacao(float, int); // como se declarasse uma variavel

int main() {
    float x;
    do {
        printf("Digite um valor para x: ");
        scanf("%f", &x);
    } while (fabsf(x) >= 1.0);

    float erro;
    do {
        printf("Digite o erro maximo a ser considerado na aproximacao: ");
        scanf("%f", &erro);
    } while (erro < 0);

    float y_original, y_aproximado;
    int termos = 0;

    y_original = calcula_funcao_original(x); // CHAMADA e RETORNO da funcao
                                             // que calcula com base na formula
                                             // original

    y_aproximado = 0.0;
    while (fabsf(y_original - y_aproximado) >= erro) {
        ++termos;
        y_aproximado = calcula_funcao_aproximacao(x, termos);
    }

    printf("Foram necessarios %d termos para aproximar f(%f)=%f e f'(%f)=%f\n",
           termos, x, y_original, x, y_aproximado);

    return EXIT_SUCCESS;
}

float calcula_funcao_aproximacao(float x, int n) {
    // Calcula a serie usando os 'n' primeiros termos
    int i;
    float serie;
    for (i=1, serie=0.0; i<=n; ++i) {
        serie += pow(x, i-1);
    }
    return serie;
}

