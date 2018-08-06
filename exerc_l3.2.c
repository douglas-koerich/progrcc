#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/* Alteracoes no enunciado:
 * 1) O usuario escolhe a quantidade de valores, ateh o limite maximo de 500
 * 2) Numeros sao gerados aleatoriamente, com valor maximo igual a 10000
 */

int main() {
    unsigned qtde_valores;
    /*
    do {
        printf("Digite o numero de valores: ");
        scanf("%u", &qtde_valores);
    } while (qtde_valores == 0 || qtde_valores > 500);
    */
    do {
        printf("Digite o numero de valores: ");
        scanf("%u", &qtde_valores);
        if (qtde_valores == 0) {
            continue;   // vah diretamente ao teste pra verificar se repete
        }
        printf("Voce digitou %u, certo?!\n", qtde_valores);
    } while (qtde_valores == 0 || qtde_valores > 500);

    unsigned menor, maior; // memoria dos limites em passos anteriores
    unsigned acumulador = 0;
    printf("Sequencia de numeros:\n");

    srand((unsigned) time(0));
    unsigned contador = 1; // contagem de 1 a qtde_valores
    while (contador <= qtde_valores) {
        unsigned numero = rand() % 10001;   // limita ao intervalo 0-10000
        printf("%u ", numero);

        if (contador == 1) { // nao existe memoria de limites ainda...
            menor = maior = numero; // atribuicao em cascata
        } else { // ja tendo a memoria...
            if (numero < menor) {
                menor = numero; // atualiza memoria do limite inferior
            }
            if (numero > maior) {
                maior = numero; // idem para limite superior
            }
        }
        acumulador += numero;
        ++contador;
        // Se o numero gerado for menor que 1000, aborta a geracao dos
        // proximos
        if (numero < 1000) {
            qtde_valores = contador;    // para calculo correto da media
            break;  // interrompe esse passo e o laco sem novo teste!
        }
    }
    /*
    unsigned contador;
    for (contador = 1; contador <= qtde_valores; ++contador) {
        unsigned numero = rand() % 10001;   // limita ao intervalo 0-10000
        printf("%u ", numero);

        if (contador == 1) { // nao existe memoria de limites ainda...
            menor = maior = numero; // atribuicao em cascata
        } else { // ja tendo a memoria...
            if (numero < menor) {
                menor = numero; // atualiza memoria do limite inferior
            }
            if (numero > maior) {
                maior = numero; // idem para limite superior
            }
        }
        acumulador += numero;
    }
    */
    float media = (float) acumulador / qtde_valores;
    printf("\nO menor valor foi %u.\n", menor);
    printf("O maior valor foi %u.\n", maior);
    printf("A media dos valores eh %f.\n", media);

    /** LACOS INFINITOS:
    while (true) {
    }
    for (;;) {
    }
    **/

    return EXIT_SUCCESS;
}

