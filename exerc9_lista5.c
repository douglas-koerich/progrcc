#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_FRASE 200

void criptografa(char [*]);
char troca_letra(char);

int main(void) {
    char frase[MAX_FRASE];

    puts("Digite uma frase qualquer na linha abaixo:"); // puts poe nova linha (\n) no final
    gets(frase);

    criptografa(frase);

    puts("A frase criptografada ficou:");
    puts(frase);
    // puts("A frase criptografada ficou:\n" frase); INVALIDO!!!
    // printf("A frase criptografada ficou:\n%s\n", frase); Isso funciona com o mesmo efeito...

    return EXIT_SUCCESS;
}

void criptografa(char s[]) {
    size_t tamanho = strlen(s); // DICA: strlen() sempre retorna "por tabela" o indice do '\0'
    int esq, dir;
    for (esq = 0, dir = tamanho-1; esq <= dir; ++esq, --dir) { // comeca percursos simultaneos
                                                               // e em sentidos contrarios
                                                               // iniciando do primeiro e do
                                                               // ultimo caractere valido
        char troca = s[esq]; // troca entre os elementos/caracteres
        s[esq] = s[dir];
        s[dir] = troca;

        s[esq] = troca_letra(s[esq]);
        s[dir] = troca_letra(s[dir]);
    }
}

char troca_letra(char ch) {
    if (isalpha(ch)) { // soh vai trocar por # se for letra
        switch (toupper(ch)) { // verifica a versao maiscula
            case 'A': case 'E': case 'I': case 'O': case 'U': case 'Y':
                break; // nao faz nada com as vogais

            default: // todas as outras letras (consoantes)
                ch = '#'; // substitui pelo caractere
        }
    }
    return ch;
}

