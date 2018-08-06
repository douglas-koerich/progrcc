#ifndef EXERC2LISTA7_H
#define EXERC2LISTA7_H

// Definicao da estrutura/registro do exercicio
struct habitante {
    unsigned idade;
    char sexo;
    float salario;
    unsigned filhos;
};
typedef struct habitante habitante;

// Prototipos das funcoes usadas no programa
// void censo(habitante [*], size_t); (1a. forma valida)
void censo(habitante*, size_t); // size_t eh similar a int
float media_salarial(const habitante*, size_t);
void maior_menor_idade(const habitante*, size_t, unsigned*, unsigned*); // serao "retornados" dois valores
unsigned num_mulheres_3filhos_ateh900(const habitante*, size_t);

// Outras definicoes poderiam vir aqui tambem...
// #define ...

#endif // EXERC2LISTA7_H
