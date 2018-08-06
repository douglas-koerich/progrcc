#ifndef EXERC5LISTA7_H
#define EXERC5LISTA7_H

#define MAX_NOME    200

struct Paciente {
    char nome[MAX_NOME];
    unsigned idade;
    char sexo;
    float altura, peso; // sendo do mesmo tipo e consecutivos na definicao,
                        // podem ser declarados na mesma linha
};
typedef struct Paciente Paciente;   // nao tem problema ser o mesmo nome

/* Outra alternativa de definicao eh a seguinte:
typedef struct {
    ... campos ...
} Paciente;
*/

#endif  // EXERC5LISTA7_H

