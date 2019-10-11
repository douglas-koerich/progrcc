#include <stdlib.h>
#include <stdio.h>

// Prototipo do procedimento (sem retorno) que recebe um vetor e o imprime
void imprime_vetor(const int [*], size_t);
                  // ^        ^     ^
                  // |        |     |
                  // |        |     sempre passa o tamanho do vetor pra funcao
                  // |        o uso desse * eh opcional
                  // use const se a funcao nao pode alterar o conteudo do vetor

#define TAMANHO 5

// Exemplos de inicializacao de vetores (fora do escopo do exercicio)
int vetor1[TAMANHO] = { 2, 4, 6, 8, 10 }; // todas as posicoes preenchidas
int vetor2[TAMANHO] = { 2, 4, 6, 8 }; // a ultima posicao nao definida eh zerada
int vetor3[] = { 2, 4, 6, 8 }; // CUIDADO! este vetor tem somente 4 posicoes!
int vetor4[TAMANHO] = { [2] = 6, [4] = 10 }; // soh definiu as posicoes 2 e 4,
                                             // demais (0,1,3) ficam zeradas

int main(void) {
    int m, n;
    
    printf("Digite o tamanho do vetor a ser manipulado: ");
    scanf("%d", &n);

    int v[n] = {}; // Todos os valores zerados (unica opcao para tamanho variavel)

    int indice;
    for (indice = 0; indice < n; ++indice) {
        printf("Digite um numero para a posicao %d do vetor: ", indice);
        scanf("%d", &v[indice]);
    }

    // Imprime a versao original do vetor
    puts("Antes do deslocamento:");
    imprime_vetor(v, n); // na passagem para a funcao se usa *apenas* o nome
                         // da variavel-vetor, sem colchetes!

    printf("Quantos deslocamentos ah esquerda deseja fazer? ");
    scanf("%d", &m);

    int deslocamentos;
    for (deslocamentos = 1; deslocamentos <= m; ++deslocamentos) {
        // Desloca todos os numeros do vetor uma posicao ah esquerda
        
        // Precisa, no entanto, salvar antes aquele que estah na
        // PRIMEIRA posicao (que nao tem uma anterior a si)
        int backup = v[0];
        
        for (indice = 0; indice < n-1; ++indice) { // ateh a PENULTIMA
            v[indice] = v[indice + 1];
        }

        // Salva o valor que estava na primeira posicao na ULTIMA
        v[n-1] = backup;
    }

    // Imprime a versao final do vetor
    puts("Depois do deslocamento:");
    imprime_vetor(v, n);

    return EXIT_SUCCESS;
}

void imprime_vetor(const int vetor[], size_t tamanho) {
    int indice;
    for (indice = 0; indice < tamanho; ++indice) {
        printf("%d ", vetor[indice]);
        vetor[indice] = 0;
    }
    putchar('\n');
}

