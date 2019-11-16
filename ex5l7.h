#ifndef EX5L7_H
#define EX5L7_H

#define TAM_NOME 120

struct paciente {
    char nome[TAM_NOME]; // string
    unsigned idade;
    char sexo; // M/F
    float altura, peso;
};
typedef struct paciente Paciente;

float calcula_peso_ideal(char, float);

#endif // EX5L7_H

