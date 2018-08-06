#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h> // para as novas funcoes str*****()
#include <stdio_ext.h>  // __fpurge()
#include "mygets.h"

#define NUM_QUESTOES 10
#define MAX_NOME 15 // maior comprimento de nome esperado pelo programa

unsigned conta_letras(char [*], char);  // com string no vetor, nao eh necessario passar o tamanho
                                        // (o fim da string eh determinado pelo terminador nulo '\0')

int main(void) {
    /*
    //
    // ESTE EH UM EXEMPLO DE ALGO QUE **NAO** EH UMA STRING!
    //
    char gabarito[NUM_QUESTOES] = { 0 };    // vetor de caracteres desconexos (sem relacao entre si)
                                            // eh uma lista de letras avulsas (inicializado com zeros binarios)
    int i;
    for (i=0; i<NUM_QUESTOES; ++i) {
        do {
            printf("Digite a resposta da questao %d: ", i+1);
            scanf(" %c", &gabarito[i]);
            gabarito[i] = toupper(gabarito[i]); // converte pra maiuscula
        } while (gabarito[i] < 'A' || gabarito[i] > 'E'); // aproveitando que sao codigos numericos consecutivos na tabela
    }
    */
    /*
     * AQUI VAMOS TRABALHAR COM UMA VARIAVEL-STRING
     */
    // char prenome[MAX_NOME+1] = { 'A', 'n', 'o', 'n', 'i', 'm', 'o', '\0' };  // ninguem inicializa assim!!!
    char prenome[MAX_NOME+1] = "Anonimo"; // eh o unico momento em que se pode usar o operador =
                                          // +1 eh uma reserva adicional para o caso de ocuparmos as MAX_NOME posicoes com letras
                                          // e ainda termos o espaco para o terminador nulo ('\0')
    // prenome = "desconhecido";          // nao funciona em C (apenas em C++ com std::string)

    /*
    printf("Digite o seu primeiro nome: ");
    scanf(" %s", prenome);  // SEM o e-comercial (&) na frente!!!
    printf("Prazer em conhece-lo(a), %s!\n", prenome);

    char sobrenome[MAX_NOME+1];
    printf("Digite agora o seu sobrenome: ");   // "esqueci" o espaco antes do %s
    scanf("%s", sobrenome); // sem o espaco anterior, acaba lendo um possivel "residuo" de digitacao anterior
    printf("Voce pertence a familia %s.\n", sobrenome);
    */
    puts("Digite o seu primeiro nome: ");
    //fgets(prenome, MAX_NOME+1, stdin);
    //fgets(prenome, sizeof(prenome), stdin); // tamanho do vetor eh conhecido de antemao
    //prenome[strlen(prenome)-1] = '\0';      // para "sumir" com o \n lido pelo fgets
    Gets(prenome, sizeof(prenome));
    /*
    puts("Voce pertence a familia ");   // Imprime uma string de cada vez
    puts(prenome);
    putchar('\n');
    */
    // Nesse caso eh melhor um printf mesmo...
    printf("Prazer em conhece-lo(a), %s!\n", prenome);

    char sobrenome[MAX_NOME+1];
    puts("Digite o seu sobrenome");
    Gets(sobrenome, sizeof(sobrenome));
    printf("Voce pertence a familia %s.\n", sobrenome);

    // Nome completo, juntando as duas variaveis numa soh
    char completo[2*MAX_NOME+1];    // tamanho igual ao dobro das partes
    strcpy(completo, prenome);      // completo = prenome;
    strcat(completo, " ");          // strcat() nao coloca espacos de separacao automaticamente
    strcat(completo, sobrenome);    // completo += sobrenome; /*(CONCATENACAO)*/
    printf("O nome completo eh %s.\n", completo);

    // Comparacao entre strings
    if (strcmp(prenome, sobrenome) == 0) // comparacao lexicografica (pela ordem do dicionario/da tabela ASCII,
                                         // com maiusculas antes das minusculas)
    {
        puts("Prenome e sobrenome sao iguais!");
    }
    else {
        puts("Prenome e sobrenome sao diferentes.");
    }

    // Funcao para determinar quantas vezes uma letra aparece numa string
    printf("Digite uma letra para contar no nome completo: ");
    __fpurge(stdin);
    char letra = getchar(); // le um caracter do teclado
    // scanf(" %c", &letra);
    unsigned contador = conta_letras(completo, letra);
    printf("O numero de ocorrencias da letra %c eh %u.\n", letra, contador);

    return EXIT_SUCCESS;
}

unsigned conta_letras(char string[], char caracter) {
    int i = 0;
    unsigned contador = 0;
    while (string[i] != '\0') {
        if (string[i] == caracter) {
            ++contador;
        }
        ++i;
    }
    return contador;
}
