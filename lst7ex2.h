#ifndef LST7EX2_H
#define LST7EX2_H

struct habitante {
    unsigned idade;
    char genero;
    float salario;
    unsigned filhos;
};
typedef struct habitante habitante;

habitante* censo(size_t); // aloca um vetor e preenche com dados
float media_sal(const habitante [*], size_t);
void menor_maior_idade(const habitante [*], size_t, unsigned*, unsigned*);
size_t mulheres_3f_ateh_900(const habitante*, size_t);

#endif // LST7EX2_H
