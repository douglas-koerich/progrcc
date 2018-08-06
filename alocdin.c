#include <stdlib.h> // para alocacao dinamica (tambem)
#include <stdio.h>

#define TAMANHO 10

// int main(void) {
int main(int argc, char* argv[]) {
    if (argc < 2) { // Nao foi digitado o argumento extra com o tamanho do vetor
        puts("Numero invalido de argumentos");
        printf("Digite: %s <num-elementos-vetor>\n", argv[0]);  // imprime o proprio nome do executavel na linha de ajuda
        return EXIT_FAILURE;
    }
    // Alocacao estatica de um vetor na area de variaveis locais ("pilha")
    // tamanho pre-definido (estimado) em tempo de compilacao ("compile-time")
    int vetor_estatico[TAMANHO];

    int i;
    for (i=0; i<TAMANHO; ++i) {
        vetor_estatico[i] = i*2;
    }

    // Alocacao tambem estatica de um vetor na mesma area de variaveis locais
    // tamanho definido pelo usuario (sob demanda), mas LIMITADO pelo tamanho da pilha
    int tamanho;
    /*
    printf("Digite o tamanho do vetor desejado: ");
    scanf("%d", &tamanho);
    */
    // Ao inves de pedir ao usuario atraves da execucao do programa o valor de tamanho
    // que ele(a) deseja adotar, recupera esse valor da linha de comando da chamada do
    // programa
    tamanho = atoi(argv[1]);    // converte, por exemplo, um "5" no inteiro 5
    int vetor_estatico2[tamanho];   // declaracao cria e destroi uma variavel automaticamente

    // Alocacao DINAMICA de um "vetor" na area reservada para a heap do programa
    // tamanho solicitado ao S.O. eh em BYTES
    int* vetor_dinamico = (int*) malloc(tamanho * sizeof(int)); // numero de elementos multiplicado pelo tamanho unitario em bytes

    // Copia do vetor original para este novo vetor
    for (i=0; i<TAMANHO && i<tamanho; ++i) {    // para de percorrer baseado no menor vetor
        vetor_estatico2[i] = vetor_estatico[i];
    }
    for (i=0; i<TAMANHO && i<tamanho; ++i) {
        vetor_dinamico[i] = vetor_estatico[i];  // aplicando [] ao ponteiro, vendo-o como se fosse
                                                // o inicio de um vetor na memoria
    }

    // Confere o conteudo dos vetores
    printf("Original: ");
    for (i=0; i<TAMANHO; ++i) {
        printf("%d ", vetor_estatico[i]);
    }
    putchar('\n');
    printf("Copiado: ");
    for (i=0; i<tamanho; ++i) {
        printf("%d ", vetor_estatico2[i]);
    }
    putchar('\n');
    printf("Copiado de novo: ");
    for (i=0; i<tamanho; ++i) {
        printf("%d ", vetor_dinamico[i]);   // ou *(vetor_dinamico + i)
    }
    putchar('\n');

    // Pede para o S.O. liberar essa area de memoria alocada (CUIDADO: esquecer desse passo
    // pode esgotar a memoria util do programa!!!)
    free(vetor_dinamico);   // CUIDADO-2, "A REVANCHE": Nao perca o valor do endereco devolvido pelo malloc

    return EXIT_SUCCESS;
}
