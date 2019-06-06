#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

bool eh_primo(int);
/*
int soma_primos(int*, size_t); // recebe um ponteiro (para o inicio do vetor)
*/
int soma_primos(const int*, size_t); // versao alternativa que impede o uso do ponteiro
                                     // para ALTERAR o vetor

int main(void) {
    // (... removida a parte de inicializacao de outros vetores que havia aqui ...)

    size_t tamanho; // tipo 'size_t' eh um 'int' voltado para "contagem"
    printf("Digite o numero de elementos/tamanho do vetor: ");
    scanf("%zd", &tamanho);

    // Vetor de tamanho VARIAVEL (nao suportado pelo padrao C89)
    // Eh NECESSARIO que 'tamanho' tenha sido carregada com algum valor valido
    int vetor_primos[tamanho]; // o valor atual da variavel 'tamanho' define
                               // o comprimento do vetor
                               // OBS.: se 'tamanho' mudar depois, o comprimento
                               // nao muda mais!

    vetor_primos[0] = 0;    // armazena um valor na PRIMEIRA posicao
    vetor_primos[tamanho-1] = -1; // CUIDADO! 'tamanho' pode ter sido alterada
                                  // (se para maior, vc pode ter problemas!...)

    int num = 1, contador = 0;
    while (contador < tamanho) {
       if (eh_primo(num)) {
           vetor_primos[contador] = num;
           ++contador;
       }
       printf("%d ", num);
       ++num;
    }
    printf("\nVetor de primos selecionados:\n");
    int i;
    for (i=1; i<=tamanho; ++i) {
        printf("%d ", vetor_primos[i-1]); // Lembrar que o indice comeca em 0
    }
    printf("\n");

    int soma;
    soma = soma_primos(vetor_primos, tamanho); // soh o nome, sem colchetes
                                               // passa o tamanho tambem!
    printf("A soma dos primos encontrados eh %d.\n", soma);
    
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

// int soma_primos(int* vetor, size_t tam) {
int soma_primos(const int* vetor, size_t tam) {
    int s = 0, i = 0;
    while (i < tam) {
        s += *(vetor + i++);
        /*
        s += vetor[i++]; // Lembre-se: usa 'i' como indice ANTES de
                         // incrementa-lo
        */
    }
    return s;
}

