#ifndef EXERC2_LISTA7_H_
#define EXERC2_LISTA7_H_

#include <stdlib.h> // para conhecer size_t

// Definicao da estrutura que caracteriza um habitante no problema
struct habitante {
    unsigned idade;
    char sexo;
    float salario;
    unsigned filhos;
};
typedef struct habitante habitante; // pode ser o mesmo nome para o typedef
// typedef struct habitante cidadao; // outro nome possivel, diferente do original

// Prototipos das funcoes envolvidas
void faz_recenseamento(habitante [*], size_t); // sem const, para alterar
float media_salario(const habitante [*], size_t); // com const, para NAO alterar
unsigned menor_idade(const habitante [*], size_t);
unsigned maior_idade(const habitante [*], size_t);
size_t num_mulheres_3filhos_ate900reais(const habitante [*], size_t);

#endif // EXERC2_LISTA7_H_
