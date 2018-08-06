#ifndef EXERC6REG_H
#define EXERC6REG_H

#include <stdlib.h>	// size_t

#define MAX_PROP 50
#define MAX_PLACA 7
#define MAX_MODELO 20
#define MAX_CHASSI 16
#define MAX_COR 15

struct renavam {
	char proprietario[MAX_PROP+1];	// +1 para o terminador nulo
	char placa[MAX_PLACA+1];		// idem
	char modelo[MAX_MODELO+1];		// ibidem
	unsigned ano;
	char chassi[MAX_CHASSI+1];		// ibidem
	char cor[MAX_COR+1];			// ibidem
	char combustivel;				// Alcool, Diesel, Gasolina, glV, Flex
};
typedef struct renavam renavam;

unsigned pos2000(struct renavam [], size_t);	// letra (a)
void gravaArq(char*, struct renavam*, size_t);	// letra (b)
struct renavam* buscaAdult(struct renavam*, size_t, size_t*);	// letra (c)

#endif

