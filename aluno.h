#ifndef ALUNO_H
#define ALUNO_H

#include <stdbool.h>

// Arquivos-cabecalhos sao o lugar ideal para definicao de
// constantes e estruturas
#define TAM_NOME 100

// DEFINICAO de um novo tipo estruturado ("registro") utiliza
// a palavra 'struct' na frente do nome do tipo
struct aluno {
    // Membros-campos da estrutura
    char nome[TAM_NOME];
    int matricula;
    int ano_ingresso;
    // Poderia ser: int matricula, ano_ingresso;
    char genero;
    int codigo_curso;
    bool cursando;
    float coeficiente_rendimento;
};  // termina com ponto-e-virgula!

// Define um "apelido" para o tipo 'struct aluno'
typedef struct aluno Aluno; // poderia ser 'struct aluno aluno;'

// Outros exemplos:
/* typedef struct aluno {
 * ...
 * } Aluno;
 *
 * typedef struct { // nesse caso a 'struct' eh "anonima"
 * ...              // e portanto soh pode ser declarada
 * } Aluno;         // atraves do apelido dado a ela
 */
#endif // ALUNO_H

