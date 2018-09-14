#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // para uso do toupper()
#include <time.h>   // para uso do time() no srand()
#include <unistd.h> // para uso do sleep()

int lanca_dado(void);
void suspense(void);

int main(void) {
    srand(time(0)); // usa o numero de segundos Epoch como semente da
                    // geracao pseudorandomica
    char c;
    do {
        printf("Jogador 1, digite 'A' para lancar o seu dado: ");
        scanf(" %c", &c);
    } while (toupper(c) != 'A');
    
    int a = lanca_dado();

    do {
        printf("Jogador 2, digite 'B' para lancar o seu dado: ");
        scanf(" %c", &c);
    } while (toupper(c) != 'B');

    int b = lanca_dado();

    suspense();
    printf("a = %d, b = %d\n", a, b);

    if (a > b) {
        printf("Vitoria do jogador 1\n");
    } else if (a < b) {
        printf("Vitoria do jogador 2\n");
    } else {
        printf("Empate!\n");
    }

    return EXIT_SUCCESS;
}

int lanca_dado(void) {
    int aleatorio = rand() % 6 + 1; // resto limita de 0 a 5, somando 1
                                    // temos os valores do "dado" (virtual)
    return aleatorio;
}

void suspense(void) {
    printf("E o vencedor eh");
    int i;
    for (i=1; i<=5; ++i) {
        printf(".\n");
        sleep(1);
    }
}

