#ifndef EXERC5LISTA7_H
#define EXERC5LISTA7_H

#define MAX_NOME    80

struct paciente {
    char nome[MAX_NOME];
    unsigned idade;
    char sexo;  // M ou F
    float peso, altura;
};

float calcula_peso_ideal(float, char);

#endif  // EXERC5LISTA7_H
