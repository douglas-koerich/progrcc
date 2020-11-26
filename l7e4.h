#ifndef L7E4_H
#define L7E4_H

#include <stdlib.h>

// Definicao de data
typedef struct {
    int dia, mes, ano;
} Data;

#define TAMANHO_DESCRICAO 120
#define TAMANHO_CLIENTE 80

// Definicao do formato (tipo) da estrutura que representa a OS no problema
struct os_ {
    int numero;
    Data data;
    /* struct {
        int dia, mes, ano;
    } data; */
    float valor;
    char descricao[TAMANHO_DESCRICAO];
    char cliente[TAMANHO_CLIENTE];
};
typedef struct os_ OrdemServico;

// Prototipos de funcoes que utilizam o registro acima
void grava_banco_dados(const OrdemServico [*], size_t);
void calcula_estatisticas(void);

#endif