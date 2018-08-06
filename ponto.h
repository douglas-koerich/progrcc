#ifndef PONTO_H
#define PONTO_H

// DEFINICAO (nao eh declaracao) do registro/entidade/"coisa" 'Ponto'
struct Ponto {  // 'Ponto' passa a ser um novo TIPO de dado da linguagem C
    double x;   // 'x' e 'y' sao CAMPOS (partes) do registro
    double y;   // neste caso, poderia escrever: double x, y;
};  // termina definicao da estrutura com ponto-e-virgula apos fecha-chaves!

typedef struct Ponto Pto;   // 'Pto' eh um "apelido" para o tipo 'Ponto'

/***** Ate este ponto NAO se fez nenhuma reserva de memoria/variavel *****/

#endif  // PONTO_H

