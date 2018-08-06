#ifndef EXERC2LISTA7_H
#define EXERC2LISTA7_H

#define MAX_NOME    256

// Definicao da estrutura (do registro)
struct Habitante {
    char nome[MAX_NOME];
    unsigned idade;
    char sexo;
    float salario;
    unsigned filhos;
};
typedef struct Habitante Habitante;

// Prototipos das funcoes pedidas pelo exercicio
void censo(Habitante* pop, size_t num);                 // sem 'const' porque vai alterar
float media_salario(const Habitante* pop, size_t num);  // com 'const', nao pode alterar!
void mais_velho_mais_novo(const Habitante* pop, size_t num, unsigned* maior, unsigned* menor);
unsigned mulheres900filhos3(const Habitante* pop, size_t num);

// Prototipos das funcoes extras que manipulam o vetor de registros em um arquivo
void salva_arquivo(const Habitante* pop, size_t num, const char* nome_arq);
void le_imprime_arquivo(const char* nome_arq);

#endif

