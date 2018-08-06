#ifndef _LISTA_H_
#define _LISTA_H_

#include <stdio.h>

struct linha {
	int numero;
	struct linha* anterior;
	struct linha* proximo;
};

struct palavra_chave {
	char* palavra;
	struct linha* cabeca;
	struct linha* cauda;
	struct palavra_chave* anterior;
	struct palavra_chave* proximo;
};

struct indice_remissivo {
	struct palavra_chave* cabeca;
	struct palavra_chave* cauda;
};

void criaIndice(struct indice_remissivo*);
void destroiIndice(struct indice_remissivo*);
void inserePalavra(struct indice_remissivo*, const char*);
void insereLinha(const struct indice_remissivo*, const char*, int);
int gravaIndice(const struct indice_remissivo*, FILE*);

#endif

