#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include <ctype.h>

#define NUM_ALUNOS      4   // 100
#define NUM_QUESTOES    3   // 40
#define TAM_MAX_NOME    80

int main() {
    // Vetor de respostas
    char gabarito[NUM_QUESTOES];    // letras A a E

    // Vetor de nomes de alunos
    // (Na verdade, um vetor de strings eh uma matriz de caracteres)
    char lista_nomes[NUM_ALUNOS][TAM_MAX_NOME];

    // Respostas dos alunos
    char matriz_respostas[NUM_ALUNOS][NUM_QUESTOES];

    // Vetor de contadores de acertos (uma posicao para cada aluno)
    int acertos[NUM_ALUNOS] = { 0 }; // zera todas as posicoes

    // Inicia pela leitura do gabarito
    int q;
    for (q=0; q<NUM_QUESTOES; ++q) {
        do {
            printf("Digite a resposta da questao #%d: ", q+1);
            __fpurge(stdin);
            gabarito[q] = toupper(getchar());
        } while (gabarito[q] < 'A' || gabarito[q] > 'E');
    }

    // Le os nomes dos alunos
    int a;
    for (a=0; a<NUM_ALUNOS; ++a) {
        do {
            printf("Digite o nome do aluno #%d: ", a+1);
            __fpurge(stdin);
            gets(lista_nomes[a]);   // colchetes indica qual das strings do vetor
        } while (strlen(lista_nomes[a]) == 0);
    }

    // Le as respostas de cada aluno
    for (a=0; a<NUM_ALUNOS; ++a) {
        for (q=0; q<NUM_QUESTOES; ++q) {
            do {
                printf("Digite a resposta dada pelo aluno %s a questao #%d: ",
                       lista_nomes[a], q+1);
                __fpurge(stdin);
                matriz_respostas[a][q] = toupper(getchar());
            } while (matriz_respostas[a][q] < 'A' || matriz_respostas[a][q] > 'E');
            if (matriz_respostas[a][q] == gabarito[q]) {
                ++acertos[a];
            }
        }
    }

    // Exibe a listagem de nomes e acertos
    for (a=0; a<NUM_ALUNOS; ++a) {
        printf("Nome: %s; Acertos: %d\n", lista_nomes[a], acertos[a]);
    }
    
    return 0;
}
