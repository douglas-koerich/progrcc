#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

int main() {
    char opcao;
    do {
        printf("Deseja sair do programa (S/N)? ");
        scanf(" %c", &opcao);
        opcao = toupper(opcao); // retorna a maiuscula do argumento 'opcao'
    //} while (opcao != 'S' && opcao != 's');
    } while (opcao != 'S'); 
    return EXIT_SUCCESS;
}
