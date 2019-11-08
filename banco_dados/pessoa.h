#ifndef PESSOA_H
#define PESSOA_H

// DEFINICAO de um novo tipo-registro
struct person {
    // Campos (propriedades) do registro
    float altura;
    char sexo;

    // Campos em sequencia que forem do mesmo tipo podem ser combinados
    // com virgula(s)
    float peso, peso_ideal, imc;
}; // Termina com ponto-e-virgula!

// DEFINICAO de um novo nome para um tipo conhecido
typedef unsigned char byte; // o tipo "byte" eh um "unsigned char"
typedef struct person pessoa; // "pessoa" eh um nome alternativo para a estrutura

/* Exemplo-extra:
typedef struct a { // neste caso poderia omitir o "a"
    int x; // o campo "x" eh do tipo int
    char y; // o campo "y" eh do tipo char
    struct s {
        int i;
        float j;
    } z; // o campo "z" eh do tipo struct s
} b; // define "b" como um nome para a estrutura
*/

// Em arquivos-cabecalhos tambem se definem prototipos de funcoes (associadas
// ao tipo, nesse caso)
float calcula_imc(float, float);
void imprime_dados(struct person);

#endif // PESSOA_H

