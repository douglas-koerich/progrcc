#include <stdio.h>  // fgets()
#include <stdio_ext.h>  // LINUX apenas: __fpurge()
#include <string.h> // strlen()
#include "mygets.h" // Gets()

void Gets(char string[], size_t max) {
    __fpurge(stdin); // remove "residuos" de entradas de caracteres/textos anteriores
    fgets(string, max, stdin);
    string[strlen(string)-1] = '\0'; // para "sumir" com o '\n' lido pelo fgets
}
