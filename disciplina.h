#ifndef DISCIPLINA_H
#define DISCIPLINA_H

#define TAM_COD_DISCIPLINA 8 // "PRGESTR\0"

struct disciplina {
    char codigo[TAM_COD_DISCIPLINA];
    float notas[3]; // AV1, AV2, ED
    unsigned faltas;
};
typedef struct disciplina Disciplina;

#endif // DISCIPLINA_H
