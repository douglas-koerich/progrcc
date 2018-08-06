#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

// inicio
int main() {
    // declare sexo : caracter
    char sexo;

    // leia sexo
    printf("Digite o seu sexo (genero M/F): ");
    scanf(" %c", &sexo);

    // se sexo = 'F' OU sexo = 'f' entao
    if (sexo == 'F' || sexo == 'f') {
    // if (toupper(sexo) == 'F') {     // toupper() converte o caracter para maiusculo
        // escreva "Parabens pelo seu dia!"
        printf("Parabens pelo seu dia!\n");
    }
    // senao
    else  {
        // se sexo = 'M' ou sexo = 'm' entao
        if (sexo == 'M' || sexo == 'm') {
            // escreva "Parabenize uma mulher hoje!"
            printf("Parabenize uma mulher hoje!\n");
        }
        // senao
        else {
            // se sexo = 'T' ou sexo = 't' entao
            if (sexo == 'T' || sexo == 't') {
                // escreva "Voce tambem merece os parabens!"
                printf("Voce tambem merece os parabens!\n");
            }
            // senao
            else {
                // escreva "Entrada invalida!"
                printf("Entrada invalida!\n");
            // fim-se
            }
        }
    // fim-se
    }
    return EXIT_SUCCESS;
// fim
}
