#include <stdio.h>

/* Operar sobre matrizes usando ponteiros eh um pouco mais complexo,
 * e nao recomendo passar ponteiro de matriz para funcao. Em outras
 * palavras, continue usando a forma "classica" de passar matrizes para
 * funcoes da forma como fizemos no exercicio original
void somaColunas(size_t, size_t, int [*][*], int [*]);
 */

int main() {
    // Usuario escolhe o tamanho da matriz
    int N, M;
    printf("Digite o numero de linhas da matriz: ");
    scanf("%d", &N);
    printf("Digite o numero de colunas da matriz (e do vetor): ");
    scanf("%d", &M);

    // Declara a matriz com o tamanho escolhido
    int matriz[N][M];
    int* pm = &matriz[0][0]; // fazer int* m = matriz provoca warning do compilador

    // Percorre a matriz preenchendo cada uma de suas posicoes
    int n, m;
    for (n=0; n<N; ++n) {
        for (m=0; m<M; ++m) {
            printf("Digite o valor na posicao [%d][%d] da matriz: ", n, m);
            // scanf("%d", &matriz[n][m]);
            // Lembre-se da equivalencia: &matriz[lin][col] <=> matriz + lin*COLUNAS + col
            scanf("%d", pm + n*M + m);  // sem o &!!!
        }
    }

    // Declara o vetor; como ele tem que guardar a soma das colunas, tem
    // que ter um tamanho igual ao numero delas (das colunas)
    // Agora declaro um ponteiro tambem...
    int vetor[M], *pv = vetor;

    // Como a soma eh por coluna, entao o percurso eh por coluna
    for (m=0; m<M; ++m) {
        // Zera o total dessa coluna no vetor antes de percorrer as linhas
        // dessa coluna
        *(pv+m) = 0;  // aritmetica de ponteiro (aponta para endereco do indice 'm')

        // Soma os valores de cada linha dessa coluna
        for (n=0; n<N; ++n) {
            // v[m] += matriz[n][m];
            // A outra equivalencia eh: matriz[lin][col] <=> *(matriz + lin*COLUNAS + col)
            *(pv+m) += *(pm + n*M + m);
        }
    }

    // Imprime cada soma de coluna
    // (Manter 'pv' travado no inicio do vetor no laco acima permite que agora eu continue
    // usando-o pois ainda aponta para o inicio do vetor)
    for (m=0; m<M; ++m, ++pv) {
        printf("A soma da coluna %d eh %d\n", m, *pv);
    }
    return 0;
}

