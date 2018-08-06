#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#if !defined WIN32 || !defined WIN64
#define ESTOU_COMPILANDO_EM_LINUX
#include <stdio_ext.h>  // soh existe pra Linux
#endif

int main(void) {
    bool eh_vogal = false;
    char c;
    do {
        printf("Digite uma letra: ");
        
        // scanf(" %c", &c);    // como aprendemos antes...

// #if defined ESTOU_COMPILANDO_EM_LINUX
#ifdef ESTOU_COMPILANDO_EM_LINUX
        __fpurge(stdin);        // soh existe em Linux
#else
        fflush(stdin);          // soh funciona para o proposito em Windows
#endif

        scanf("%c", &c);

        c = toupper(c); // converte 'c' pra maiuscula correspondente
        if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' ||
            c == 'Y') {
            eh_vogal = true;
        }
    } while (!isalpha(c));
    if (eh_vogal) {
        printf("Voce digitou uma vogal!\n");
    } else {
        printf("Voce digitou uma consoante!\n");
    }
    return EXIT_SUCCESS;
}

