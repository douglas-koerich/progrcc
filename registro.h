#ifndef REGISTRO_H
#define REGISTRO_H

#define MAX_NOME    50

struct data {
    int dia, mes, ano;      // tres campos do mesmo tipo em sequencia
};

// DEFINICAO do registro (especificacao para o compilador)
// AQUI **NAO** SE ESTAH CRIANDO/ALOCANDO QUALQUER ESPACO EM MEMORIA
// AO CONTRARIO, ESTAH SE DEFININDO APENAS UM MODELO, UM MOLDE PARA AS
// VERDADEIRAS VARIAVEIS ABAIXO
struct pessoa {
    // Lista de campos que compoem um registro na memoria
    char nome[MAX_NOME+1];  // campo-vetor-string
    unsigned idade;         // campo-unsigned
    char sexo;              // campo-char
    float renda;            // campo-float
    struct data nasc;       // campo-struct
};  // ponto-e-virgula no final

/* Ilustracao de typedef
typedef unsigned char byte; // 'byte' eh um "tipo" equivalente a unsigned char
*/

typedef struct pessoa Pessoa;   // poderia ser 'pessoa' tambem
/* Declaracoes de variaveis possiveis:
 * struct pessoa var_1;
 * Pessoa var_2;
 */

#endif

