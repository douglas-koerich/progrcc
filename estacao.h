#ifndef ESTACAO_H
#define ESTACAO_H

#define NUM_MEDICOES 24
#define NUM_ESTACOES 4
#define MAX_NOME_ESTACAO 50
#define NOME_ARQ_BINARIO "/tmp/medidas.bin"

struct data {
    int dia, mes, ano;
};
typedef struct data data;

struct estacao {
    char nome[MAX_NOME_ESTACAO];
    data quando;
    int medicoes[NUM_MEDICOES];
};
typedef struct estacao estacao;

#endif // ESTACAO_H
