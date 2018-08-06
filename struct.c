#include <stdlib.h>
#include <stdio.h>
#include <stdio_ext.h>  // __fpurge
#include <ctype.h>      // toupper
#include "cabecalho.h"  // contem a DEFINICAO da estrutura
#include "mygets.h"     // leitura de strings

int main(int argc, char* argv[]) {
    // DECLARACAO de registros (aqui existe alocacao de memoria)
    Paciente fulano;
    struct paciente beltrano;   // fulano e beltrano sao do mesmo tipo de registro
    Paciente sicrano = {
        "Mao-Tse-Tung", 'M', 67, 115, 1.65, 'N'
    };
    // Isto funciona para compiladores C99 (inicializacao parcial)
    Paciente anonimo = {
        .genero = 'M',
        .hipertenso = 'N'
    };

    // Vetor de registros
    Paciente vetor_coluna_prestes[2];

    // Imprime o numero de bytes ocupados na memoria por um registro
    printf("O tamanho de cada registro eh %zd.\n", sizeof(Paciente));

    // Preenchimento do cadastro
    /*
    puts("Digite os dados:");
    printf("Nome? ");
    Gets(fulano.nome, MAX_NOME);    // minha propria funcao no lugar de fgets() para tirar o \n
    char genero;
    do {
        printf("Genero (M/F)? ");
        __fpurge(stdin);    // limpa o teclado antes de ler
        genero = toupper(getchar());
    } while (genero != 'F' && genero != 'M');
    fulano.genero = genero;
    printf("Idade? ");
    scanf("%u", &fulano.idade);
    printf("Peso? ");
    scanf("%f", &fulano.peso);
    printf("Altura? ");
    scanf("%f", &fulano.altura);
    char hiper;
    do {
        printf("Hipertenso(a) (S/N)? ");
        __fpurge(stdin);    // limpa o teclado antes de ler
        hiper = toupper(getchar());
    } while (hiper != 'S' && hiper != 'N');
    fulano.hipertenso = (hiper == 'S');
    */
    //preenche_registro(&fulano);
    //preenche_registro(&beltrano);

    int i;
    for (i=0; i<2; ++i) {
        preenche_registro(vetor_coluna_prestes + i);    // passa ponteiro obtido por aritmetica
    }
    // Ilustra a impressao de um campo de um dos elementos
    printf("O nome do segundo individuo eh %s.\n", vetor_coluna_prestes[1].nome);l

    return EXIT_SUCCESS;
}

void preenche_registro(Paciente* pac) {
    puts("Digite os dados:");
    printf("Nome? ");
    Gets((*pac).nome, MAX_NOME);    // minha propria funcao no lugar de fgets() para tirar o \n
    char genero;
    do {
        printf("Genero (M/F)? ");
        __fpurge(stdin);    // limpa o teclado antes de ler
        genero = toupper(getchar());
    } while (genero != 'F' && genero != 'M');
    pac->genero = genero;
    printf("Idade? ");
    scanf("%u", &pac->idade);
    printf("Peso? ");
    scanf("%f", &pac->peso);
    printf("Altura? ");
    scanf("%f", &pac->altura);
    char hiper;
    do {
        printf("Hipertenso(a) (S/N)? ");
        __fpurge(stdin);    // limpa o teclado antes de ler
        hiper = toupper(getchar());
    } while (hiper != 'S' && hiper != 'N');
    pac->hipertenso = (hiper == 'S');
}
