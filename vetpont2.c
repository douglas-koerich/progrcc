#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define NUM_STRINGS 10
#define TAM_MAX_STRING 30

void inverte(char* str);

int main(void) {
    // Um 'vetor' de strings eh, na verdade, uma matriz de caracteres, lembra-se?
    // Cada linha da matriz eh uma string individualmente
    char vetor_s[NUM_STRINGS][TAM_MAX_STRING];
    int i;
    for (i=0; i<NUM_STRINGS; ++i) {
        // Um ponteiro para caractere pode apontar para o inicio de um vetor de
        // caracteres, certo? E um vetor de caracteres pode ser uma string, certo?
        // Entao, o comando abaixo faz pstr apontar para o inicio da i-esima string
        // no vetor (i-esima linha da matriz)
        char* pstr = &vetor_s[i][0];
        printf("Digite uma string para armazenar no vetor (endereco=%p): ", pstr);
        gets(pstr);
        
        // Pra nao forcar a digitar todas as 10 strings, se for vazia pahra o laco
        if (strlen(pstr) == 0) {
            break;
        }
    }
    int j;
    puts("Strings digitadas:");
    for (j=0; j<i; ++j) {
        char* pstr = &vetor_s[j][0];
        puts(pstr);

        // Aproveita e inverte a string
        inverte(pstr);
    }
    puts("Strings invertidas:");
    for (j=0; j<i; ++j) {
        char* pstr = &vetor_s[j][0];
        puts(pstr);
    }
    return EXIT_SUCCESS;
}

void inverte(char* str) {
    // Usa a funcao strlen() pra descobrir a posicao do fim da string
    int esq = 0, dir = strlen(str)-1;
    while (esq < dir) {
        char aux = str[esq];
        str[esq] = str[dir];
        str[dir] = aux;
        ++esq, --dir;
    }
}

