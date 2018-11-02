#include <stdlib.h>
#include <stdio.h>
#include <stdio_ext.h>
#include <time.h>
#include "aluno.h" // para conhecer o tipo 'aluno'

int main(void) {
    srand((unsigned) time(0)); // inicializacao da geracao de numeros aleatorios

    aluno calouro; // variavel do novo tipo 'aluno'
    aluno veterano = {
        1234567, // .matricula
        "Luis de Camoes", // .nome
        { 20, 4, 1578 }, // campos da data de nascimento
        // deixa a .mensalidade zerada...
        .disc_em_curso = { // inicializacao de um vetor, mas um vetor de estruturas!
            { "PRGESTR", { 7.0, 6.5, 8.9 }, 10 },
            { "CIRCDIG", { 8.1, [2] = 7.7 } }, // dois preenchimentos parciais (no vetor de notas, e faltas)
            [5] = { "LOGPROG", {}, 15 } // vetor de notas zerado! :-) 
        }
    };

    calouro.matricula = rand();
    printf("Leitura dos dados do aluno: %u.\n", calouro.matricula);
    printf("Nome? "); __fpurge(stdin); gets(calouro.nome);
    printf("Nascimento (d/m/a)? "); scanf("%d/%d/%d",
           &calouro.nascimento.dia, &calouro.nascimento.mes, &calouro.nascimento.ano);
    printf("Mensalidade (R$)? "); scanf("%f", &calouro.mensalidade);

    printf("Dados das disciplinas do aluno: %u.\n", calouro.matricula);
    int disc;
    for (disc=0; disc<6; ++disc) {
        printf("Codigo da disciplina #%d: ", disc+1);
        __fpurge(stdin);
        gets(calouro.disc_em_curso[disc].codigo);
        int nota;
        for (nota=0; nota<3; ++nota) {
            printf("Nota #%d da disciplina %s do aluno %u: ", nota+1,
                   calouro.disc_em_curso[disc].codigo, calouro.matricula);
            scanf("%f", &calouro.disc_em_curso[disc].notas[nota]);
        }
        printf("Numero de faltas do aluno: "); scanf("%u",
               &calouro.disc_em_curso[disc].faltas);
    }
    return EXIT_SUCCESS;
}

