#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h> // soh funciona em Unix/Linux!

unsigned espera_aleatoria(void);  // prototipo da funcao sem parametros
void espera_fixa(void); // prototipo da funcao sem parametros e sem retorno

int main(void) {    // usa void para definir main() sem parametros
    unsigned antes = time(0);   // le o contador de segundos do PC
    printf("Antes = %u", antes);
    fflush(stdout); // força a impressao mesmo sem o \n da saida bufferizada
                    // stdout = tela do console/terminal

    // Primeira versao: a funcao de delay "espera" por um tempo aleatorio
    // e devolve o numero de segundos que esperou...
    unsigned intervalo = espera_aleatoria();  // nao ha parametros! (parenteses vazios)

    unsigned depois = time(0);
    printf(", depois = %u\n", depois);
    printf("(intervalo = %u)\n", intervalo);

    // De novo, agora com espera pre-conhecida (fixa)
    antes = time(0);
    espera_fixa();  // nem recebe, nem devolve nada
    depois = time(0);
    printf("Antes = %u, depois = %u\n", antes, depois);

    return EXIT_SUCCESS;
}

unsigned espera_aleatoria(void) {
    srand((unsigned) time(0));
    unsigned segundos = rand() % 10 + 1;    // 1 a 10 segundos
    sleep(segundos);    // suspende a execucao do programa pelo tempo dado
    return segundos;
}

void espera_fixa(void) {
    const unsigned SEGUNDOS = 5;    // "variaveis" constantes em MAIUSCULAS
    sleep(SEGUNDOS);
    // return;  (opcional)
}

