#include <stdio.h>

void trocaMinMai(char [*]);

#define TAM 200

int main() {
    char teste[TAM];

    printf("Digite uma frase para inverter: ");
    gets(teste);

    trocaMinMai(teste);

    // Imprime a string invertida
    puts(teste);

    return 0;
}

void trocaMinMai(char frase[]) {
    int i=0;
    while (frase[i] != '\0') {
        // Eh letra?
        if (isalpha(frase[i])) {
            // Eh maiuscula?
            if (isupper(frase[i])) {
                // Substitui o caracter pela minuscula do proprio caracter
                frase[i] = tolower(frase[i]);
            }
            // Caso contrario (eh minuscula)
            else {
                frase[i] = toupper(frase[i]);
            }
        }
        // Proximo caracter na string...
        ++i;
    }
}

