#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRING  100

bool ehPalindroma(const char*); // const impede que ehPalindroma use o
                                // ponteiro para alterar o conteudo

int main() {
    char string[MAX_STRING];

    puts("Digite uma palavra: ");
    gets(string);

    if (ehPalindroma(string)) {
        puts("A palavra eh palindroma :-)");
    }
    else {
        puts("A palavra NAO eh palindroma :-(");
    }
    return 0;
}

bool ehPalindroma(const char* s) {
    const char* pesq = s;
    const char* pdir = s + strlen(s) - 1;   // s+strlen(s) cai no '\0'!!
    while (pesq < pdir) {
        if (toupper(*pesq) != toupper(*pdir)) {
            return false;
        }
        else {
            ++pesq, --pdir;
        }
    }
    return true;
}

