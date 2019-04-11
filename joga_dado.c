#include <stdlib.h>
#include <stdio.h>

void joga_dado_viciado(void); // nao ha retorno nem parametros
                              // funcao que nao retorna eh chamada "procedimento"

int main(void) { // main() eh uma funcao que nao recebe nada neste programa
    int jogadas;
    printf("Quantas vezes deseja jogar o dado? ");
    scanf("%d", &jogadas);

    int j;
    for (j=1; j<=jogadas; ++j) {
        joga_dado_viciado();
    }
    return EXIT_SUCCESS;
}

void joga_dado_viciado(void) {
    // O dado estah "viciado" porque o rand() nao foi pre-configurado com srand()
    int num = rand() % 6 + 1; // faixa de 1 a 6 (soma 1 ao resto que vai de 0 a 5)
    printf("%d\n", num);
}

