#include <stdio.h>

void somaColunas(size_t, size_t, int [*][*], int [*]);

int main() {
    // Usuario escolhe o tamanho da matriz
    int N, M;
    printf("Digite o numero de linhas da matriz: ");
    scanf("%d", &N);
    printf("Digite o numero de colunas da matriz (e do vetor): ");
    scanf("%d", &M);

    // Declara a matriz com o tamanho escolhido
    int matriz[N][M];

    // Percorre a matriz preenchendo cada uma de suas posicoes
    int n, m;
    for (n=0; n<N; ++n) {
        for (m=0; m<M; ++m) {
            printf("Digite o valor na posicao [%d][%d] da matriz: ", n, m);
            scanf("%d", &matriz[n][m]);
        }
    }

    // Declara o vetor; como ele tem que guardar a soma das colunas, tem
    // que ter um tamanho igual ao numero delas (das colunas)
    int vetor[M];

    // Passa a matriz (de onde le os valores) e o vetor (que vai ser
    // preenchido pela funcao)
    somaColunas(N, M, matriz, vetor);   // soh nomes das variaveis (sem [])!

    // Imprime cada soma de coluna
    for (m=0; m<M; ++m) {
        printf("A soma da coluna %d eh %d\n", m, vetor[m]);
    }
    return 0;
}

void somaColunas(size_t l, size_t c, int m[l][c], int v[c]) {
    // Como a soma eh por coluna, entao o percurso eh por coluna
    int col;
    for (col=0; col<c; ++col) {
        // Zera o total dessa coluna no vetor antes de percorrer as linhas
        // dessa coluna
        v[col] = 0;

        // Soma os valores de cada linha dessa coluna
        int lin;
        for (lin=0; lin<l; ++lin) {
            v[col] += m[lin][col];
        }
    }
    // Ao final do percurso das colunas, o vetor tem as somas de cada uma
    // delas! Nao eh preciso "retornar" o vetor, porque vetores e matrizes
    // passados como parametro sao modificados pela funcao, entao "voltam"
    // alterados para a funcao chamadora (no caso, main)
}

