#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define TAMANHO 10

bool eh_primo(int);

int main(void) {
    /*
    int vetor_primos[10];   // os primeiros 10 numeros primos serao
                            // armazenados aqui
    */
    int vetor_primos[TAMANHO];

    vetor_primos[0] = 0;    // armazena um valor na PRIMEIRA posicao
    /*
    vetor_primos[9] = -1;   // armazena um valor na ULTIMA posicao
    */
    vetor_primos[TAMANHO-1] = -1;

    int num = 1, contador = 0;
    //while (contador < 10) { // repete enquanto nao chega ao total desejado
    while (contador < TAMANHO) {
       if (eh_primo(num)) {
           /*
           if (contador == 0) {
               vetor_primos[0] = num; // eh o primeiro primo
           } else if (contador == 1) {
               vetor_primos[1] = num; // eh o segundo primo
           } ...
           */
           vetor_primos[contador] = num;
           ++contador;
           /* O par de linhas acima poderia ser escrito assim:
            * vetor_primos[contador++] = num; // incrementa 'contador' DEPOIS
            *                                 // de usa-lo como indice do vetor
            */
       }
       printf("%d ", num);
       ++num;
    }
    printf("\nVetor de primos selecionados:\n");
    int i;
    //for (i=1; i<=10; ++i) {
    for (i=1; i<=TAMANHO; ++i) {
        printf("%d ", vetor_primos[i-1]); // Lembrar que o indice comeca em 0
    }
    printf("\n");
    
    return EXIT_SUCCESS;
}

bool eh_primo(int numero) {
    int divisor = numero-1;
    while (divisor > 1) {
        if (numero % divisor == 0) {
            return false;
        }
        --divisor;
    }
    return true;
}

