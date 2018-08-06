#ifndef PROFESSOR_H
#define PROFESSOR_H

#define MAX_PRENOME	20

struct professor {
	// Campos de entrada do problema/registro
	int codigo;
	char prenome[MAX_PRENOME];
	char sexo;
	int hrs_aulas;

	// Campos processados pelo programa (posso definir numa unica linha,
	// sendo do mesmo tipo)
	float sal_bruto, desconto, sal_liquido;
};
typedef struct professor professor;	// pode ser o mesmo nome

#endif

