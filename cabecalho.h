#ifndef CABECALHO_H
#define CABECALHO_H

#include <stdbool.h>

// Em arquivos-cabecalhos incluimos:

// a) Definicoes de constantes
#define MAX_NOME    50

// b) Definicoes (nao declaracoes!) de registros
struct paciente {   // NOVO tipo de dado conhecido pelo compilador
    char nome[MAX_NOME];    // campos do registro...
    char genero;
    unsigned idade;
    float peso;
    float altura;
    bool hipertenso;
};  // aqui termina com ponto-e-virgula!!

// Novo nome para a estrutura
typedef struct paciente Paciente;   // Paciente eh um nome de tipo alternativo a struct paciente
/* typedef struct {
    ...
} Paciente; */

// c) Prototipos de funcao
void preenche_registro(Paciente*);

#endif  // CABECALHO_H
