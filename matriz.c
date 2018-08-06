#include <stdlib.h>
#include <stdio.h>
#include "mygets.h"

#define MAX_NOME    15  // "Joaquim", "Manoel", ...
#define NUM_NOTAS   3   // 1o. bim, 2o. bim, Trabalho

// No prototipo de funcoes que passam matrizes, as dimensoes sao informadas
// antes da matriz na lista de parametros
void preenche_notas(size_t, size_t, float[*][*]);

int main(void) {
    size_t num_alunos;
    printf("Digite quantos alunos a turma possui: ");
    scanf("%zd", &num_alunos);

    // Declara um vetor de strings com a capacidade
    // exata (da variavel) para o numero de alunos
    char vetor_nomes[num_alunos][MAX_NOME+1];   // "matriz eh um vetor de vetores"

    int aluno;
    for (aluno=0; aluno<num_alunos; ++aluno) {
        printf("Digite o nome do(a) %do.(a.) aluno(a): ", aluno+1);
        Gets(vetor_nomes[aluno], MAX_NOME+1);   // passa a string da vez
    }

    // Vetor comum, mas com tamanho definido em tempo de execucao do programa
    float medias_alunos[num_alunos];

    // Outro vetor, para as medias das notas de cada etapa
    float medias_etapas[NUM_NOTAS] = {};    // medias zeradas...

    // Matriz de notas dos alunos vs. etapas
    float notas[NUM_NOTAS /*linhas*/][num_alunos /*colunas*/];

    /* Transformando esse codigo para uma chamada de funcao que preenche a matriz
    // Percurso para preencher a matriz: entre visitar as posicoes linha-a-linha ou
    // coluna-a-coluna, vou pela primeira opcao
    int linha, coluna;
    for (linha=0; linha<NUM_NOTAS; ++linha) {   // Para cada linha...
        for (coluna=0; coluna<num_alunos; ++coluna) {   // ... visita todas as suas colunas
            printf("Digite a nota n. %d de %s: ", linha+1, vetor_nomes[coluna]);
            scanf("%f", &notas[linha][coluna]); // ATENCAO! Sempre o primeiro [] eh da linha!
        }
    }
    */
    preenche_notas(NUM_NOTAS, num_alunos, notas);   // dimensoes informadas antes da matriz!

    // Calculo das medias das notas (media de cada linha)
    int linha, coluna;
    for (linha=0; linha<NUM_NOTAS; ++linha) {
        for (coluna=0; coluna<num_alunos; ++coluna) {
            medias_etapas[linha] += notas[linha][coluna];   // usa variavel como acumulador
        }
        // Ao final das colunas, pode-se calcular a media da linha
        medias_etapas[linha] = medias_etapas[linha] / num_alunos;
    }

    // Calculo das medias dos alunos seguira um percurso coluna-a-coluna:
    for (coluna=0; coluna<num_alunos; ++coluna) {   // Para cada coluna...
        medias_alunos[coluna] = 0.0;    // inicializa acumulador das notas
        for (linha=0; linha<NUM_NOTAS; ++linha) {   // ... visita todas as suas linhas
            medias_alunos[coluna] += notas[linha][coluna]; // ATENCAO! nao altera mesmo se
                                                           // inverteu os lacos entre si!!
        }
        medias_alunos[coluna] /= NUM_NOTAS;
    }

    // Imprime a tabela de notas, formatada! :-)
    // Comeca com a linha do cabecalho...
    printf("--NOTA-- ");
    for (aluno=0; aluno<num_alunos; ++aluno) {
        printf("%15s ", vetor_nomes[aluno]);   // %15s: menos de 15, alinha a direita com espacos
    }
    printf("--MEDIA--\n");

    // Agora, a tabela com o vetor de medias na direita...
    for (linha=0; linha<NUM_NOTAS; ++linha) {
        switch (linha) {
            case 0: printf(" 1o. Bim ");
                    break;
            case 1: printf(" 2o. Bim ");
                    break;
            default:printf("Trabalho ");
        }
        for (coluna=0; coluna<num_alunos; ++coluna) {
            printf("%15.1f ", notas[linha][coluna]);
        }
        // Aproveito que estou na linha da tela (pra qual nao posso voltar) e imprimo a media da linha
        printf("%9.1f\n", medias_etapas[linha]);
    }
    // Apos imprimir todas as linhas, falta imprimir a media dos alunos...
    printf("--MEDIA--");
    for (aluno=0; aluno<num_alunos; ++aluno) {
        printf("%15.1f ", medias_alunos[aluno]);
    }
    putchar('\n');  // para saltar uma linha apos a ultima media

    return EXIT_SUCCESS;
}

void preenche_notas(size_t linhas, size_t colunas, float matriz[linhas][colunas]) {
    // Percurso para preencher a matriz: entre visitar as posicoes linha-a-linha ou
    // coluna-a-coluna, vou pela primeira opcao
    int l, c;
    for (l=0; l<linhas; ++l) {   // Para cada linha...
        for (c=0; c<colunas; ++c) {   // ... visita todas as suas colunas
            printf("Digite a nota n. %d: ", l+1);
            scanf("%f", &matriz[l][c]); // ATENCAO! Sempre o primeiro [] eh da linha!
        }
    }
}
