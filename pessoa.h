#ifndef PESSOA_H
#define PESSOA_H

#include <stdbool.h>

#define MAX_NOME 100

// DEFINICAO (modelo) da estrutura
struct pessoa {
    char nome[MAX_NOME];
    char sexo;
    unsigned idade;
    float peso, altura, ideal;
};
typedef struct pessoa Pessoa;

bool testa_peso_ideal(const Pessoa*);

#endif // PESSOA_H

