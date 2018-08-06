#ifndef EXERC6LISTA7_H
#define EXERC6LISTA7_H

#define MAX_NUM_VEICULOS    100

#define MAX_PROPRIETARIO    120
#define MAX_MODELO          20
#define MAX_CHASSIS         16
#define MAX_COR             15

struct veiculo {
    char proprietario[MAX_PROPRIETARIO];
    char placa[8]; // "AAA0000" + terminador nulo
    char modelo[MAX_MODELO];
    int ano;
    char chassis[MAX_CHASSIS+1]; // XX000000000000XX
    char cor[MAX_COR];
    char combustivel;   // A, D, G, V, F
};

unsigned funcao_a(struct veiculo [*], size_t);  // passando um vetor de registros
void funcao_b(struct veiculo*, size_t);         // tambem passando um vetor de registros!

// Essa funcao eh interessante: ela vai criar por alocacao dinamica o vetor com os
// registros selecionados, devolvendo-o por retorno e seu tamanho serah "devolvido"
// atraves do ponteiro; a funcao main() terah que se encarregar de liberar a memoria
// alocada por essa funcao!
struct veiculo* funcao_c(const struct veiculo*, size_t, size_t*);

#endif  // EXERC6LISTA7_H
