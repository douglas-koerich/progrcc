#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "mygets.h"

void tROCAlETRAS(char [*]);

#define MAX_STRING  20

int main(void) {
    char string[MAX_STRING+1];
    printf("Digite uma palavra ou frase: ");
    Gets(string, sizeof(string));

    tROCAlETRAS(string);
    printf("String invertida: %s.\n", string);

    return EXIT_SUCCESS;
}

void tROCAlETRAS(char s[]) {
    int i;
    for (i=0; s[i]!='\0'; ++i) {    // for (i=0; s[i]; ++i)
        s[i] = isalpha(s[i])? isupper(s[i])? tolower(s[i]): toupper(s[i]): s[i];
        /*
        if (isalpha(s[i])) {
            if (isupper(s[i])) {
                s[i] = tolower(s[i]);
            }
            else {
                s[i] = toupper(s[i]);
            }
        }
        */
    }
}
