#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/* Escreva um programa que imprima e acumule (some) todos os numeros gerados
 * aleatoriamente (randomicos) limitados ao intervalo de 1 a 1000, desde que o
 * numero gerado nao seja divisivel por 19 (dezenove). Se esse for o caso, o
 * programa exibe o total acumulado. */

int main() {
    // Inicializacao (reset) da semente de numeros aleatorios, usando o relogio
    // (tempo) do computador
    srand((unsigned) time(0)); // time(0) -> le o relogio atual do sistema

    int total = 0;  // total acumulado (inicia com zero)
    int n = -1;     // inicia com -1 pra "passar no teste" da primeira vez

    // Enquanto numero gerado NAO for divisivel por 19...
    while (n % 19 != 0) {
        // Gera o numero randomico entre 1 e 1000
        n = (rand() % 1000) /* resto entre 0 e 999 */ + 1;
        /* Alternativa de contorno (nao deixar usar o divisivel por 19) #1:
        if (n % 19 != 0) {
            printf("n = %d\n", n);
            total += n; // total = total + n;   (atualizando/acumulando/somando em total)
        }
        */
        // Alternativa de contorno #2:
        if (n % 19 == 0) {
            break;  // Interrompe o laco agora! e sai para executar a proxima instrucao
                    // depois dele
        }
        printf("n = %d\n", n);
        total += n; // total = total + n;   (atualizando/acumulando/somando em total)
    }
    printf("total = %d\n", total);
    printf("(Parou o laco com o numero %d)\n", n);

    return EXIT_SUCCESS;
}
