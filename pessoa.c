#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "pessoa.h"

#define NUM_HABITANTES 30

// typedef unsigned char byte;

/*
 * typedef struct {
 *    (... campos ...)
 * } nome-do-tipo;
 */

int main(void) {
    /*
    char nome[MAX_NOME], sexo;
    unsigned idade;
    float peso, altura, ideal;
    */

    // DECLARACAO de variaveis-estruturas
    struct pessoa sujeito;
    Pessoa outro = {
        "Anonimo", // .nome
        '?', // .sexo
        /*
        0,
        0.0,
        0.0,
        0.0
        */
    };
    outro = sujeito; // copia binaria de todos os campos

    struct pessoa populacao[NUM_HABITANTES];

    // PONTEIRO para (que guarda o endereco de) uma estrutura
    Pessoa* p = &sujeito;
    // struct pessoa* p = populacao; (aponta para o primeiro elemento)

    printf("Digite o seu nome: ");
    gets(sujeito.nome);
    // gets(populacao[indice].nome);
    printf("Ola, %s, preciso de algumas informacoes adicionais:\n", sujeito.nome);
    do {
        printf("Sexo (M/F)? ");
        scanf(" %c", &sujeito.sexo);
        p->sexo = toupper((*p).sexo);
    } while (p->sexo != 'F' && p->sexo != 'M');
    printf("Idade? "); scanf("%u", &sujeito.idade);
    printf("Peso [kg]? "); scanf("%f", &sujeito.peso);
    printf("Altura [m]? "); scanf("%f", &sujeito.altura);

    if (sujeito.sexo == 'M') {
        p->ideal = 72.7 * p->altura - 58;
    } else {
        p->ideal = 62.1 * p->altura - 44.7;
    }

    if (testa_peso_ideal(&sujeito)) {
        puts("Voce estah dentro do peso ideal.");
    } else {
        puts("Voce estah com excesso de peso, cuidado!");
    }
    return EXIT_SUCCESS;
}

bool testa_peso_ideal(const Pessoa* p) {
    if (p->peso > p->ideal) {
        return false;
    } else {
        return true;
    }
}
