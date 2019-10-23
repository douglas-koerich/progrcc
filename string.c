#include <stdlib.h>
#include <stdio.h>
#include <string.h> // para as novas funcoes que operam com strings

#define TAMANHO 50

int main(void) {
    char nome[TAMANHO]; // capacidade MAXIMA do texto armazenado

    printf("Bem-vindo(a), digite o seu nome: ");
    /*
    scanf("%s", nome); // vetor passado pra uma funcao nao tem colchetes
                       // ATENCAO! nesse caso NAO usa & na frente de vetor
                       // scanf soh leh ateh o 1o. separador (espaco,
                       // tabulacao ou nova linha)

    gets(nome); // gets() NAO usa %s, pois soh serve pra ler string
    */

    // Como gets() eh inseguro, normalmente se substitui por fgets()
    fgets(nome, sizeof(nome), stdin); // stdin = "arquivo"/stream do console
    size_t tamanho_string = strlen(nome); // 'len'gth = comprimento
    printf("O numero de caracteres lidos eh %zd\n", tamanho_string);

    // Livrando-me do \n que fgets() leh sem que eu queira...
    nome[tamanho_string - 1] = '\0'; // substitui o ultimo (\n) pelo
                                     // terminador nulo

    // char copia[TAMANHO] = "Anonimo"; <-- Isso funciona!
    // char copia[TAMANHO] = nome; <-- Isso NAO funciona!!

    char copia[TAMANHO];
    strcpy(copia, nome); // pode ser uma constante no segundo parametro
                         // exemplo: strcpy(nome, "Desconhecido");

    char outra[TAMANHO] = "Sr(a)";
    strcat(outra, " "); // se nao inicializar com espaco, precisa fazer
                        // assim para inserir o branco entre palavras
    strcat(outra, nome); // concatenacao (juncao da segunda na primeira)

    puts(outra); // imprime a variavel-string isoladamente

    printf("Prazer em conhece-lo(a), %s!\n", nome);

    return EXIT_SUCCESS;
}

