#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

bool eh_primo(int);
int soma_primos(int [*], size_t); // pode usar int[] tambem

int main(void) {
    /* Vetores inicializados: */
    int vetor_1[5] = { 1, 1, 2, 3, 5 }; // primeiros numeros de Fibonacci
    int vetor_2[] = { 1, 1, 2, 3, 5 }; // tamanho do vetor definido pelo numero de valores
    int vetor_3[5] = { 1, 1, 2 }; // os dois ultimos valores sao ZERADOS
    int vetor_4[] = { 1, 1, 2 }; // este vetor NAO PODE armazenar os valores 3 e 5 depois,
                                 // a nao ser que substitua os valores atuais
    int vetor_5[5] = { [2] = 2, 3, 5 }; // "pula" os indices 0 e 1 (ficam com valores ZERADOS)
    int vetor_6[5] = { [1] = 1, [3] = 3 }; // todas as demais ficam ZERADAS
    int vetor_7[5] = {}; // TODOS os valores zerados ("vazio")

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

int soma_primos(int vetor[], size_t tam) { // colchetes VAZIOS(!) aqui
    int s = 0, i = 0;
    while (i < tam) {
        s += vetor[i++]; // Lembre-se: usa 'i' como indice ANTES de
                         // incrementa-lo
    }
    return s;
}

