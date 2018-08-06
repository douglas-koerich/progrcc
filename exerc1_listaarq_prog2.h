#ifndef _EXERC1_H_
#define _EXERC1_H_

#define MAX_NOME		80
#define MAX_ENDERECO	200

typedef struct {
	int codigo;
	char nome[MAX_NOME];
	char endereco[MAX_ENDERECO];
	int ddd;
	int telefone;
} Cliente;

struct Data {
	int dia, mes, ano;
};
typedef struct Data Data;

typedef struct Documento {
	int numero;
	float valor;
	Data emissao;
	Data vencimento;
	int cliente;
} Documento;

#endif

