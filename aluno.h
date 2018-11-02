#ifndef ALUNO_H
#define ALUNO_H

#include "data.h"
#include "disciplina.h"

// Eh possivel definir um novo tipo a partir de outro
typedef unsigned char byte;
typedef unsigned short word;
// byte b; <-- uma variavel do novo tipo 'byte'
// word w; <-- uma variavel de 16 bits

#define MAX_NOME_ALUNO 50

// Para registros, eh necessario defini-los antes
struct aluno {
    // Campos/elementos do registro
    unsigned matricula;
    char nome[MAX_NOME_ALUNO];
    struct data nascimento; // usando o nome original
    float mensalidade;
    Disciplina disc_em_curso[6]; // usando o apelido
};
typedef struct aluno aluno;

/* Modo alternativo (e muito comum):
 * typedef struct nome_do_tipo { // citar nome_do_tipo aqui eh opcional
 *     // ... campos da struct ...
 * } apelido_do_tipo;
 * Exemplo:
 * typedef struct {
 *     unsigned matricula;
 *     ...
 * } aluno;
 */

#endif // ALUNO_H

