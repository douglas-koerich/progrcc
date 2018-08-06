#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/* Nesta versao, vamos deixar o computador escolher um numero aleatorio inicial;
   se esse numero for multiplo de 7, nao sera necessario pedir ao usuario, do
   contrario o usuario deve fornece-lo (e o programa, como na versao anterior,
   deve continuar a pedir o numero enquanto o usuario nao tiver feito da forma
   correta) */

int main()
{
    // Para usar o rand(), deve inicializar a semente para que sempre sejam
    // gerados numeros diferentes pelo algoritmo; para isso, eh melhor usar o
    // "relogio" (contador de segundos) interno do PC como valor de semente
    srand((unsigned) time(0));  // converte de time_t (contador) para unsigned

    // Inicializa a variavel com um valor aleatorio (sorteado) pelo computador
    int numero = rand() % 1000 + 1;    // gera um numero aleatorio entre 1 e 1000
    printf("O computador sorteou %d, se nao for multiplo de 7 voce devera tentar...\n", numero );

    // LACO COM TESTE NO INICIO (USADO QUANDO O VALOR DE TESTE PODE RESULTAR VERDADEIRO ANTES MESMO DO LACO)
    // enquanto resto (numero, 7) <> 0 faca
    while (numero % 7 != 0) {
        // leia numero  ; comando de leitura serah repetido 0 ou mais vezes
        printf("Numero? ");
        scanf("%d", &numero);
    // fim-enquanto
    }
    return EXIT_SUCCESS;
// fim
}
