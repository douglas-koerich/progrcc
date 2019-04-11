#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <ctype.h>

size_t gera_senha(void);    // void significa "vazio" neste caso, sem parametros para a funcao

int main() {
    srand(time(0)); // inicializa a "semente" de numeros aleatorios com a leitura
                    // dos ticks do relogio do PC (segundos desde a meia-noite de 1/1/1970)
    
    size_t comprimento = gera_senha(); // sem parametros, gera por conta propria

    printf("\nO comprimento da senha gerada eh %zd.\n", comprimento); // %zd para size_t

    return EXIT_SUCCESS;
}

size_t gera_senha(void) {
    char codigo_ascii;
    size_t contador = 0;
    do {
        codigo_ascii = rand() % 128; // valores entre 0 a 127 (codigos da tabela)
        if (isalnum(codigo_ascii)) { // soh aceita letras e numeros
            printf("%c", codigo_ascii);
            ++contador;
        }
    } while (contador < 10 || !iscntrl(codigo_ascii)); // enquanto nao for um caractere
                                                       // de controle (inicio da tabela)
    return contador;
}

