#ifndef REGISTRO_H_
#define REGISTRO_H_

#define TAM_NOME 100

// Definicao de uma estrutura em C, i.e., um novo tipo
// agregado de informacoes
struct aluno {
    int ra;                 // RA (registro do aluno)
    char nome[TAM_NOME];    // Nome
    int curso;              // Codigo do curso
    char turno;             // M, V ou N
    unsigned ano_ingresso;  // Ano de ingresso
}; // aqui vai um ponto-e-virgula!

// Novo nome ("apelido") para a estrutura recem-definida
typedef struct aluno estudante;

#endif // REGISTRO_H_

