#include <stdlib.h>
#include <stdio.h>
#ifndef WIN32
#include <stdio_ext.h>
#endif
#include <ctype.h>
#include "trabalho.h"

int main(int argc, char* argv[]) {
    if (argc > 1) {
        movimentos_iniciais = atoi(argv[1]);
    }
    inicia_placa();
    do {
        imprime_placa();
        printf("Movimentos: %u.\n\n", contador_movimentos);
        puts("** MENU **");
        puts("(1-15) Peca para mover");
        puts("(A) Iniciar outro jogo");
        puts("(B) Reiniciar este jogo");
        puts("(C) Salvar este jogo");
        puts("(D) Ler um jogo salvo");
        puts("(E) Sair sem salvar");
        printf("Escolha sua opcao ==> ");
        char opcao[8];
        scanf(" %s", opcao);
        #ifdef WIN32
        fflush(stdin);
        #else
        __fpurge(stdin);
        #endif
        switch (toupper(opcao[0])) {
            case 'A':
                novo_jogo();
                break;

            case 'B':
                reinicia_jogo();
                break;

            case 'C':
                salva_jogo();
                break;

            case 'D':
                le_jogo();
                break;

            case 'E': {
                char c;
                do {
                    printf("Tem certeza que deseja sair (S/N)? ");
                    scanf(" %c", &c);
                    c = toupper(c);
                } while (c != 'S' && c != 'N');
                if (c == 'S') {
                    return EXIT_SUCCESS;
                }
            }

            default: {
                int numero = atoi(opcao);
                if (numero < 1 || numero > 15) {
                    puts("(((Opcao invalida!)))\nPressione <Enter> para continuar...");
                    getchar();
                }
                else if (movimento_ok_executa(numero) == false) {
                    puts("(((Movimento invalido!)))\nPressione <Enter> para continuar...");
                    getchar();
                }
            }
        }
    } while (fim_jogo() == false);
    imprime_placa();
    printf("\nFIM DO JOGO COM %u MOVIMENTOS :-)\n", contador_movimentos);
    return EXIT_SUCCESS;
}
