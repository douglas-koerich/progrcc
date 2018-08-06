#include <stdio.h>
#include <string.h> // para as funcoes que manipulam/analisam/etc. strings
#if !defined WIN32 && !defined WIN64
#include <stdio_ext.h>  // para __fpurge() usado em Linux
#endif

#define MAX_FRASE   500

// Prototipo de uma funcao que recebe string como parametro
int contaCaracter(char [*], /* size_t, nao precisa, porque tem o \0 */
                  char);

int main() {
    // Declaracao da variavel-string para a frase: um vetor de caracteres
    char frase[MAX_FRASE];

    // Leitura da frase digitada pelo usuario
    puts("Digite uma frase abaixo: ");  // puts() poe um \n automagicamente
    gets(frase); // ao inves de scanf(" %s", frase); (problemas com espacos)

    // Le o caracter que sera procurado na frase
    printf("Digite o caracter para busca: ");
#if defined WIN32 || defined WIN64
    fflush(stdin);  // para limpar o buffer do teclado em Windows
#else
    __fpurge(stdin); // para faze-lo em Linux (na verdade, em nao-Windows)
#endif
    char c = getchar();

    /*
    // Letra (a)
    int i = 0, contador = 0;
    while (frase[i] != '\0') {  // enquanto nao for o fim da string...
        if (frase[i] == c) {
            ++contador;
        }
        ++i;
    }
    */
    int cont = contaCaracter(frase, c);

    printf("O numero de ocorrencias de '%c' em \"%s\" eh %d\n",
           c, frase, cont);

    // Letra (b)
    int i;
    for (i = strlen(frase); // inicia no indice do ULTIMO caracter da string
         i >= 0;            // desloca-se em direcao ao inicio do vetor
         --i) {
        if (frase[i] == c) {
            break;  // vai interromper o laco com 'i' no indice do caracter
        }
    }
    printf("Caracter encontrado na posicao %d (-1 se nao achou)\n", i);

    return 0;
}

int contaCaracter(char str[], char ch) {
    // Letra (a)
    int i = 0, contador = 0;
    while (str[i] != '\0') {  // enquanto nao for o fim da string...
        if (str[i] == ch) {
            ++contador;
        }
        ++i;
    }
    return contador;
}

