#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "mygets.h"

#define TAM_MAX_STRING  50

int main(void) {
    // Variavel do tipo texto-string
    char texto[TAM_MAX_STRING+1] = "Exemplo";   // declaracao + inicializacao com espaco extra para o terminador nulo

    // printf(texto);
    puts(texto);
    puts("Uma string constante");

    printf("A variavel contem %s\n", texto);
    puts("A variavel contem %s\n"); // isso eh inutil, mas mostra o que eh feito (NADA!) com %algo

    printf("Digite uma palavra: "); // se eu usar puts, o cursor passa para a proxima linha (porque puts poe um \n)
    /* Comentado por conta das limitacoes de scanf() com texto separado por espacos...
    scanf(" %s", texto); // nao tem & na frente do nome da variavel aqui (porque eh vetor!)
                         // (espaco em branco antes do %s limpa a entrada do teclado de outros separadores (ex. Enter))

    printf("A nova string eh %s\n", texto);

    printf("Agora, digite outra: ");
    scanf(" %s", texto);
    printf("A string tornou-se %s\n", texto);
    */

    /* Usando gets(), o que nao eh atualmente recomendavel...
    gets(texto);
    printf("A nova string eh %s\n", texto);
    printf("Agora, digite outra: ");
    gets(texto);
    printf("A string tornou-se %s\n", texto);
    */

    // Usando Gets() do professor, que internamente simplesmente chama:
    // fgets(variavel, tamanho, stdin)
    Gets(texto, TAM_MAX_STRING+1);
    printf("A nova string eh %s\n", texto);
    printf("Agora, digite outra: ");
    Gets(texto, TAM_MAX_STRING+1);
    printf("A string tornou-se %s\n", texto);

    /* Outras funcoes de E/S de caracteres
#ifdef WIN32
    fflush(stdin);
#else
    __fpurge(stdin);
#endif
    char c = getchar();
    putchar(c);
    putchar('X');
    */

    char outra[TAM_MAX_STRING];
    // outra = texto;
    strcpy(outra, texto);
    printf("Agora a outra variavel tambem tem o conteudo: %s\n", outra);

    char mais_uma[] = "qualquer coisa";
    strcat(outra, mais_uma);
    printf("Agora a outra variavel tem: %s\n", outra);

    char teste1[] = "primeira";
    char teste2[] = "segunda";
    char teste3[] = "primeira";

    if (strcmp(teste1, teste2) == 0) {
        puts("teste1 e teste2 sao iguais");
    } else {
        puts("teste1 e teste2 sao diferentes");
    }
    if (strcmp(teste1, teste3) == 0) {
        puts("teste1 e teste3 sao iguais");
    } else {
        puts("teste1 e teste3 sao diferentes");
    }

    printf("O numero de caracteres uteis em 'texto' eh %zd\n", strlen(texto));  // nao conta o '\0'

    return EXIT_SUCCESS;
}
