#include <stdlib.h>
#include <stdio.h>
#include <stdio_ext.h>
#include <ctype.h>
#include "registro.h" // para o programa conhecer a 'struct aluno'

#define NUM_ALUNOS 25

int main(void) {
    struct aluno um_aluno; // variavel 'um_aluno' do tipo 'struct aluno'
    struct aluno turma[NUM_ALUNOS]; // vetor de registros do tipo 'struct aluno'
    estudante outro_aluno; // variavel do mesmo tipo que as anteriores, apenas
                           // usando um nome diferente
    struct aluno conhecido = { 123, "Juquinha", 57, 'M', 2009 };
    estudante conhecida = { 451, "Georgina", .turno = 'V' }; // curso e ano zerados

    // Leitura das informacoes de um_aluno
    printf("Digite os dados do aluno: ");
    printf("RA? "); scanf("%d", &um_aluno.ra); // uso do ponto para acesso ao campo
    __fpurge(stdin); 
    printf("Nome? "); gets(um_aluno.nome);
    printf("Curso? "); scanf("%d", &um_aluno.curso);
    char t;
    do {
        __fpurge(stdin);
        printf("Turno? ");
        t = toupper(getchar()); // le ja convertendo pra maiuscula
    } while (t != 'M' && t != 'V' && t != 'N');
    um_aluno.turno = t;
    printf("Ano de ingresso? "); scanf("%u", &um_aluno.ano_ingresso);

    // Copia de um registro para outro
    outro_aluno = um_aluno; // todos os campos sao copiados

    // Impressao da copia
    printf("RA: %d\n", outro_aluno.ra);
    printf("Nome: %s\n", outro_aluno.nome);
    printf("Curso e turno: %d, %c\n", outro_aluno.curso, outro_aluno.turno);
    printf("Ano de ingresso: %d\n", outro_aluno.ano_ingresso);

    // Leitura das informacoes de um aluno especifico da turma
    printf("Digite o RA do 10o. aluno da turma: "); // de indice 9
    scanf("%d", &turma[9].ra);

    return EXIT_SUCCESS;
}

