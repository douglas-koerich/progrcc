#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define TAM_DESCR 20

/* Excepcionalmente neste programa vamos definir a struct
 * no arquivo-fonte (.c), e nao num arquivo-cabecalho (.h)
 */
struct exemplo {
    char descricao[TAM_DESCR];
    unsigned codigo;
    bool disponivel;
};
typedef struct exemplo exemplo;

int main(void) {
    /*
    exemplo algo; // variavel do tipo-estrutura
    */

    exemplo* algo; // ponteiro para uma estrutura na memoria
    algo = malloc(sizeof(exemplo)); // reserva uma estrutura inteira
                                    // na memoria

    printf("Digite a descricao: ");
    gets(algo->descricao);

    printf("Digite o codigo: ");
    scanf("%u", &algo->codigo);

    char resposta;
    do {
        printf("Disponivel (S/N)? ");
        scanf(" %c", &resposta);
        resposta = toupper(resposta);
    } while (resposta != 'S' && resposta != 'N');

    algo->disponivel = resposta; // (*algo).disponivel = resposta;

    if (algo->disponivel) {
        printf("Voce pode ter acesso a %s!\n", algo->descricao);
    }

    free(algo);

    return EXIT_SUCCESS;
}

