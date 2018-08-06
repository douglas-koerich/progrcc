#ifndef EX5L7_H
#define EX5L7_H

#define MAX_NOME    80

struct paciente {
    char nome[MAX_NOME];
    unsigned short idade;
    char sexo;
    float altura;
    float peso;
};
typedef struct paciente paciente;

#endif

