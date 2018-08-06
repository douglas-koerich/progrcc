#ifndef EXERC3LISTA07_H
#define EXERC3LISTA07_H

#include <stdlib.h> // uso do size_t

// Constantes (macros) do programa
#define MAX_CARROS      300
#define MAX_NOME_MODELO 15
#define MAX_PLACA       9   // 8 caracteres ("XXX-0000") + terminador nulo
#define ULTIMA_PLACA    "ZZZ-9999"

// Estrutura auxiliar que define um formato de hora e minuto
/*
struct horario {
    int hora;
    int minuto;
};
typedef struct horario horario; // pode ser usado o mesmo identificador
*/
typedef struct horario {
    int hora, minuto;
} horario;

// Definicao do registro de um cliente/veiculo
struct cliente {
    char placa[MAX_PLACA];
    char modelo[MAX_NOME_MODELO];
    char tamanho;   // P/M/G
    /*
    int hora_entrada, minuto_entrada;
    int hora_saida;
    int minuto_saida;
    */
    horario entrada;    // uma estrutura dentro de outra estrutura
    horario saida;      // o campo eh, ele mesmo, uma outra estrutura
};
typedef struct cliente veiculo;

// Prototipos das funcoes
size_t operacao_portaria(struct cliente vetor[], size_t maximo);
void relatorio_final(const struct cliente* vetor, size_t tamanho);  // 'const' pq nao vai alterar o vetor

#endif  // EXERC3LISTA07_H
