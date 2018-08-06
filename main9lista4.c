#include <stdio.h>
#include <stdlib.h>     // system()
#include "exerc9lista4.h"

#define MAIOR_MAX   100 // constantes sao escritas em MAIUSCULAS
#define MENOR_MIN   10  // sem ponto-e-virgula! (nao eh C, eh linguagem do preprocessador)

void limpa_tela(void) {
    // Compilacao condicional (definida pelo preprocessador)
#if defined WIN32 || defined WIN64   // essas definicoes de compilador 'WINxx' soh existem no Windows
    system("cls");   // 'cls' eh o comando do Windows
#else
    system("clear"); // 'clear' eh o comando do Linux
#endif
}

int main() {
    int min, max;

    do {
        printf("Digite o menor valor: ");
        scanf("%d", &min);
    } while (min < MENOR_MIN);

    do {
        printf("Digite o maior valor: ");
        scanf("%d", &max);
    } while (max > MAIOR_MAX);

    int random = geraAleatorio(min, max);

    limpa_tela();   // procedimento sem parametros

    printf("Numero gerado: %d\n", random);

    return 0;
}

