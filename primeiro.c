/* Este eh um comentario que descreve o proposito deste programa
em algumas linhas:
- Ele imprime uma mensagem no console (terminal);
- Termina retornando indicacao de "sucesso" para o sistema operacional. */

// Este eh um comentario que se resume a uma linha apenas (nao continua na proxima)

#include <stdlib.h> // Inclui a biblioteca-padrao que define 'EXIT_SUCCESS'
#include <stdio.h> // Inclui a biblioteca-padrao necessaria para uso de 'puts'

int main() { // o { marca o inicio de um bloco de codigo
    puts("Meu primeiro programa em C na UTP!"); // puts imprime no console
    return EXIT_SUCCESS; // EXIT_SUCCESS (=0) indica que o programa estah terminando OK
}

