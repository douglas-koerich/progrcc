#ifndef TRABALHO_H
#define TRABALHO_H

#include <stdbool.h>

// Numero de linhas e colunas da placa/matriz do jogo
#define TAMANHO 4

// Disposicao inicial das pecas na placa apos geracao de um novo jogo
extern int placa_inicial[TAMANHO][TAMANHO];

// Disposicao final das pecas em um jogo finalizado
extern const int placa_final[TAMANHO][TAMANHO];

// Placa/matriz do jogo
extern int placa_jogo[TAMANHO][TAMANHO];

// Contador de movimentos do jogo
extern unsigned contador_movimentos;

// DEBUG: Movimentos iniciais
extern unsigned movimentos_iniciais;

// Prototipos das funcoes do programa
void imprime_placa(void);
bool movimento_ok_executa(int);
void inicia_placa(void);
void reinicia_jogo(void);
void novo_jogo(void);
void salva_jogo(void);
void le_jogo(void);
bool fim_jogo(void);

#endif
