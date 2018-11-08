#ifndef EDEL11_3_H
#define EDEL11_3_H

#define MAX_STRING 30

// Se a definicao de 'interna' fosse feita antes
// struct interna { ... };

// Definicao do registro "principal"
struct externa {
    char campo_string[MAX_STRING];
    // Como struct interna eh definida DENTRO da struct externa,
    // soh vai ser visivel a partir/pela estrutura externa
    struct interna {
        int i1;
        int i2;
        int i3;
    } campo_inteiros;
    // struct interna campo_inteiros; -> se a definicao fosse feita antes
};

#endif // "fecha" o #ifndef EDEL11_3_H

