#include <stdlib.h> // EXIT_SUCCESS, etc.
#include <stdio.h>  // printf, getchar, etc.
#ifndef WIN32 // definicao WIN32 normalmente eh usada em ambiente WINDOWS
#include <stdio_ext.h> // exclusivo pra Linux
#endif
#include <ctype.h>  // toupper
#include "combinacao.h" // prototipo da funcao 'combinacao'

long probabilidade_de_acerto(char); // prototipo (declaracao) da funcao local

int main(void) {
    char jogo;
    do {
        printf("Qual eh o seu jogo favorito, a (Q)uina ou a Mega-(S)ena? ");
#ifdef WIN32 // Verifica se estah compilando em WINDOWS
        /* A funcao fflush funciona para WINDOWS na limpeza da entrada do console,
         * mas nao pra LINUX */
        fflush(stdin); // stdin = entrada de console
#else
        __fpurge(stdin); // funcao equivalente a fflush() em Linux
#endif
        jogo = toupper(getchar()); // getchar() le um caractere do teclado;
                                   // toupper() converte-o para maiuscula
    } while (jogo != 'Q' && jogo != 'S');

    long chance = probabilidade_de_acerto(jogo);
    printf("Voce tem 1 chance em %ld jogos possiveis para acertar.\n", chance);

    return EXIT_SUCCESS;
}

long probabilidade_de_acerto(char tipo) {
    long num_alternativas_possiveis, num_alternativas_escolhidas;
    if (tipo == 'Q') {
        num_alternativas_possiveis = 80;
        num_alternativas_escolhidas = 5;
    } else { // supondo a escolha por 'S' (mega-sena)
        num_alternativas_possiveis = 60;
        num_alternativas_escolhidas = 6;
    }
    long jogos_possiveis = combinacao(num_alternativas_possiveis,
                                      num_alternativas_escolhidas);
    return jogos_possiveis;
} 

