#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>    // uso de variavel tipo bool no programa

int main(void) {
    size_t posicoes;
    printf("Digite o numero de elementos do vetor: ");
    scanf("%ld", &posicoes);

    /* A declaracao tardia de um vetor como na linha de codigo abaixo nem sempre
     * eh possivel e/ou vantajosa, porque:
     * a) Nao eh possivel redimensionar esse vetor para um novo tamanho;
     * b) O numero de posicoes pode ser tal que crie um vetor muito grande para
     *    ser armazenado na pilha (como variavel local)
     * c) Alguns compiladores C89 nao aceitam essa declaracao de vetor com tamanho
     *    variavel
     */
    // int vetor[posicoes];

    // Ao inves, vamos criar um "vetor" alocado na heap
    // O uso do (int*) na frente do malloc() eh porque o mesmo me dah um ponteiro
    // "generico" (void*) e esse precisa ser convertido para o tipo correto
    int* vetor = (int*) malloc(posicoes * sizeof(int));

    // A partir de entao, trabalho com o problema usando o "vetor" da maneira
    // convencional
    int i;
    for (i=0; i<posicoes; ++i) {    // para todos os elementos do vetor...
        vetor[i] = rand() % 10;     // de 0 a 9
        printf("%d ", *(vetor+i));  // posso usar aritmetica de ponteiros tambem! :-)
    }
    putchar('\n');

    // Faz a busca e contagem dos valores repetidos
    for (i=0; i<posicoes; ++i) {
        // Desconsidera este numero se ele ja ocorreu antes (e ja o contei)
        int j;
        bool ja_tinha_contado = false;
        for (j=i-1; j>=0; --j) {    // pra isso, tenho que olhar para tras no vetor
            if (vetor[j] == vetor[i]) {
                // Ja havia encontrado o numero da vez antes...
                ja_tinha_contado = true;
                break;  // interrompe o laco for (j=i-1...)
            }
        }
        if (ja_tinha_contado == false) {
            int contador = 1;   // conta a ocorrencia do numero onde estou no vetor
            // Procura pelo mesmo numero nas proximas posicoes
            for (j=i+1; j<posicoes; ++j) {
                if (vetor[j] == vetor[i]) {
                    ++contador;
                }
            }
            if (contador > 1) {
                printf("O numero %d ocorre %d vezes no vetor.\n", vetor[i], contador);
            }
        }
    }

    // Finalmente, por se tratar de um vetor alocado dinamicamente, precisa
    // liberar a memoria reservada
    free(vetor);

    return EXIT_SUCCESS;
}
