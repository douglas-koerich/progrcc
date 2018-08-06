#ifndef _EXERC103_H_
#define _EXERC103_H_

struct habitante {
	unsigned short idade;
	char sexo;
	float salario;
	unsigned short filhos;
};
typedef /* nome original: */ struct habitante /* apelido: */ pessoa;

/* Modo alternativo: define o tipo junto com o apelido
typedef struct {
	unsigned short idade;
	char sexo;
	float salario;
	unsigned short filhos;
} pessoa;
*/

void ler(pessoa [*], size_t);
float media(pessoa*, size_t);
void minmax(pessoa*, size_t, unsigned short*, unsigned short*);
unsigned mulheres(pessoa [*], size_t);

#endif

