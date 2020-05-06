#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

// Escreva um programa que leia as 5 respostas de multipla
// escolha (a-e) para uma prova aplicada a 3 alunos, comparan-
// do-as com as respostas de um gabarito pre-definido. Informe // a nota de cada aluno ao final da sua leitura correspondente

float calcula_nota(char [], size_t);

#define NUM_QUESTOES 5 // NAO termina com ;
#define NUM_ALUNOS 3

int main(void) {
    // const int NUM_QUESTOES = 5;

    // int questoes;
    // printf("Digite quantas questoes tinha a prova: ");
    // scanf("%d", &questoes);
    // char prova[questoes]; <-- declaracao de um vetor de tamanho
    //                           "variavel", i.e., cujo tamanho eh
    //                           definido no momento da execucao

    // Variaveis para leitura das respostas do(a) aluno(a)
    // char resp_1, resp_2, resp_3, resp_4, resp_5;
    char prova[NUM_QUESTOES]; /* conjunto/vetor de elementos do tipo 'char' */

    // Variaveis com as respostas do gabarito
    /*
    char gab_1 = 'a', gab_2 = 'a', gab_3 = 'c', gab_4 = 'd',
         gab_5 = 'b';
    */
    // char gabarito[NUM_QUESTOES] = { 'a', 'a', 'c', 'd', 'b' };
    /*
     * gabarito[0] = 'a'; <-- em C, a numeracao das posicoes (indices)
     *                        inicia em 0 (zero)
     * gabarito[1] = 'a';
     * (...)
     * gabarito[4] = 'b'; <-- ultima posicao VALIDA do vetor
     */

    /*
    // EXTRA: VARIANTES DA INICIALIZACAO ACIMA
    char gabarito[] = { 'a', 'a', 'c', 'd', 'b' };
    char gabarito[5] = { 'a', 'a', 'c' }; // 2 restantes zeradas
    char gabarito[5] = { [2] = 'c', [4] = 'b' }; // outras zeradas
    */

    // Laco para cada um dos alunos
    int aluno;
    float notas[NUM_ALUNOS];
    for (aluno = 1; aluno <= NUM_ALUNOS; ++aluno) {
        printf("Respostas do(a) aluno(a) #%d:\n", aluno);

        // Leitura das respostas desse(a) aluno(a)
        /*
        do {
            printf("Digite a 1a. resposta: ");
            scanf(" %c", &resp_1);
        } while (resp_1 < 'a' || resp_1 > 'e');
        printf("Digite a 2a. resposta: "); scanf(" %c", &resp_2);
        printf("Digite a 3a. resposta: "); scanf(" %c", &resp_3);
        printf("Digite a 4a. resposta: "); scanf(" %c", &resp_4);
        printf("Digite a 5a. resposta: "); scanf(" %c", &resp_5);
        */
        int questao;
        for (questao = 0; questao < NUM_QUESTOES; ++questao) {
            do {
                printf("Digite a %da. resposta: ", questao+1);
                scanf(" %c", &prova[questao]);
            } while (prova[questao] < 'a' || prova[questao] > 'e');
        }

        // Calculo da nota
        float nota;
        /*
        if (tolower(resp_1) == gab_1) {
            nota += 2.0;
        }
        if (tolower(resp_2) == gab_2) {
            nota += 2.0;
        }
        if (tolower(resp_3) == gab_3) {
            nota += 2.0;
        }
        if (tolower(resp_4) == gab_4) {
            nota += 2.0;
        }
        if (tolower(resp_5) == gab_5) {
            nota += 2.0;
        }
        for (questao = 0, nota = 0.0; questao < NUM_QUESTOES; ++questao) {
            if (prova[questao] == gabarito[questao]) {
                nota += 2.0;
            }
        }
        */
        notas[aluno-1] = calcula_nota(prova, NUM_QUESTOES); // Passa o vetor:
                                                            // - sem colchetes no nome
                                                            // - com tamanho em parametro separado
        printf("O(a) aluno(a) obteve nota %.1f\n", notas[aluno-1]);
    }
    return EXIT_SUCCESS;
}

float calcula_nota(char prova[], size_t tamanho) {
    char gabarito[NUM_QUESTOES] = { 'a', 'a', 'c', 'd', 'b' };
    float nota;
    for (questao = 0, nota = 0.0; questao < tamanho; ++questao) {
        if (prova[questao] == gabarito[questao]) {
            nota += 2.0;
        }
    }
    return nota;
}


