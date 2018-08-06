#ifndef TIPOS_H     // para garantir que nao haja insercao aninhada, o que provocaria
#define TIPOS_H     // a redefinicao dos mesmos tipos, o que o compilador nao aceitaria

#define MAX 30
#define LOJAS 3

struct data {
    int dia;
    int mes;
    int ano;    // ou: int dia, mes, ano;
};
typedef struct data data;

// Vamos "modelar" uma entidade 'Produto', formado pelo codigo numerico, descricao
// (textual), valor de compra e de venda e quantidade em estoque
// Pra isso, "criamos" um tipo de dado novo e composto, isto eh, um REGISTRO
struct produto {        // ++DEFINICAO++ do registro (nao eh uma criacao de dados em memoria)
    int codigo;         // Lista de CAMPOS desse registro, ou seja, as informacoes individuais
    char descricao[MAX];
    float valor_compra;
    float valor_venda;  // Poderia ter definido assim: float valor_compra, valor_venda;
    unsigned qtde_estoque[LOJAS];   // Um vetor dentro da estrutura
    data vencimento;
};  // deve terminar com ponto-e-virgula apos o fecha-chaves

// Pode-se dar um outro nome para esse tipo, usando typedef
typedef struct produto Produto; // tipo 'Produto' = tipo 'struct produto'
typedef struct produto produto; // agora, nao precisa mais usar struct na frente...

// Outros fazem assim:
// typedef struct produto { ... (campos) ... } produto;

#endif  // TIPOS_H
