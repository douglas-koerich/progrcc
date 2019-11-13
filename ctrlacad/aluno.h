#ifndef ALUNO_H
#define ALUNO_H

#define MAX_NOME 128
#define NUM_NOTAS 4

struct data {
    unsigned dia, mes, ano;
};
typedef struct data data;

struct aluno {
    unsigned matricula;
    char nome_completo[MAX_NOME];
    struct data data_nasc;
    float notas[NUM_NOTAS];
    float media;
    unsigned faltas;
};
typedef struct aluno aluno;

#endif // ALUNO_H

