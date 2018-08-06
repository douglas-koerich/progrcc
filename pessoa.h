#ifndef PESSOA_H
#define PESSOA_H

// DEFINICAO da estrutura (registro), nao cria variaveis!
// (eh como um "gabarito" que define os componentes e seus tipos)
struct pessoa { // em C, o nome do novo tipo "pessoa" precisa vir com "struct" antes
    unsigned idade;     // 
    char sexo;          // } *campos* da estrutura
    float peso, altura; //
    float ideal;        // optou por nao definir junto aos campos acima
    float imc;
};
typedef struct pessoa pessoa;   // dah um nome simplificado sem "struct" para o tipo acima

/*
 * typedef struct pessoa { // uso do nome "pessoa" aqui eh opcional
 *     ... //
 * } pessoa; // nome simplificado
 */

#endif // PESSOA_H

