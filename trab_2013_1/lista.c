#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include "lista.h"

void criaIndice(struct indice_remissivo* indice) {
	if (indice == NULL) {
		return;
	}
	if (indice->cabeca == NULL) {
		return;
	}
	destroiIndice(indice);
	indice->cabeca = indice->cauda = NULL;
}

void destroiIndice(struct indice_remissivo* indice) {
	if (indice == NULL) {
		return;
	}
	while (indice->cabeca != NULL) {
		struct palavra_chave* p = indice->cabeca;
		indice->cabeca = p->proximo;

		if (p->palavra != NULL) {
			free(p->palavra);
		}
		while (p->cabeca != NULL) {
			struct linha* l = p->cabeca;
			p->cabeca = l->proximo;
			free(l);
		}
		free(p);
	}
	indice->cauda = NULL;
}

void inserePalavra(struct indice_remissivo* indice, const char* chave) {
	if (indice == NULL || chave == NULL) {
		return;
	}
	struct palavra_chave* p = indice->cabeca;
	while (p != NULL && strcasecmp(p->palavra, chave) < 0) {
		p = p->proximo;
	}
	if (p != NULL && strcasecmp(p->palavra, chave) == 0) {
		return;
	}
	char* dup = strdup(chave);
	if (dup == NULL) {
		return;
	}
	struct palavra_chave* n = (struct palavra_chave*) malloc(sizeof(struct palavra_chave));
	if (n == NULL) {
		free(dup);
		return;
	}
	n->palavra = dup;
	n->cabeca = n->cauda = NULL;
	n->proximo = p;
	if (indice->cabeca == NULL) {
		n->anterior = NULL;
		indice->cabeca = indice->cauda = n;
	}
	else {
		if (p == NULL) {
			n->anterior = indice->cauda;
			indice->cauda = n;
		}
		else {
			n->anterior = p->anterior;
			p->anterior = n;
		}
		if (n->anterior == NULL) {
			indice->cabeca = n;
		}
		else {
			n->anterior->proximo = n;
		}
	}
}

void insereLinha(const struct indice_remissivo* indice, const char* chave, int num) {
	if (indice == NULL || chave == NULL || num <= 0) {
		return;
	}
	struct palavra_chave* p = indice->cabeca;
	while (p != NULL && strcasecmp(p->palavra, chave) < 0) {
		p = p->proximo;
	}
	if (p == NULL || strcasecmp(p->palavra, chave) > 0) {
		return;
	}
	struct linha* l = p->cabeca;
	while (l != NULL && l->numero < num) {
		l = l->proximo;
	}
	if (l != NULL && l->numero == num) {
		return;
	}
	struct linha* n = (struct linha*) malloc(sizeof(struct linha));
	if (n == NULL) {
		return;
	}
	n->numero = num;
	n->proximo = l;
	if (p->cabeca == NULL) {
		n->anterior = NULL;
		p->cabeca = p->cauda = n;
	}
	else {
		if (l == NULL) {
			n->anterior = p->cauda;
			p->cauda = n;
		}
		else {
			n->anterior = l->anterior;
			l->anterior = n;
		}
		if (n->anterior == NULL) {
			p->cabeca = n;
		}
		else {
			n->anterior->proximo = n;
		}
	}
}

int gravaIndice(const struct indice_remissivo* indice, FILE* arquivo) {
	if (indice == NULL || arquivo == NULL) {
		return EXIT_SUCCESS;
	}
	struct palavra_chave* p = indice->cabeca;
	while (p != NULL) {
		if (p->cabeca == NULL) {
			p = p->proximo;
			continue;
		}
		if (fprintf(arquivo, "%-30s", p->palavra) < 0) {
			perror("Nao pude escrever no arquivo:");
			return EXIT_FAILURE;
		}
		struct linha* l = p->cabeca;
		while (l != NULL) {
			if (fprintf(arquivo, "%6d", l->numero) < 0) {
				perror("Nao pude escrever no arquivo:");
				return EXIT_FAILURE;
			}
			l = l->proximo;
		}
		if (fputc('\n', arquivo) == EOF) {
			perror("Nao pude escrever no arquivo:");
			return EXIT_FAILURE;
		}
		p = p->proximo;
	}
	return EXIT_SUCCESS;
}

