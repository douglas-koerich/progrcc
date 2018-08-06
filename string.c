#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#ifndef WINDOWS // diretiva de compilacao condicional: se nao for Windows...
#include <stdio_ext.h> // inclui esse cabecalho por causa de __fpurge()
#endif
#include <string.h>

#define MAX_NOME 100

// bool procura(char [*], int, char); STRINGS NAO PRECISAM DO TAMANHO NA CHAMADA
bool procura(char [*], char);

int main(void) {
    // Declaracao de um vetor de caracteres
    char vogais[6] = { 'a', 'e', 'i', 'o', 'u', 'y' }; // ISTO NAO EH UMA STRING!
    /* Este eh um jeito horroroso (e inutil, portanto nao usado) de inicializar
     * uma string (palavra, frase, paragrafo, etc.):
    char string[7] = { 'c', 'a', 'n', 'e', 't', 'a', 0 }; // ISTO EH UMA STRING!
    */
    char string[7] = "caneta";
    /* Observacoes:
     * A variavel nao vai poder conter nenhuma string (palavra) com mais de 6
     * simbolos;
     * A CONSTANTE "caneta" eh do tipo string (margeada com aspas duplas) e jah
     * contem em si o terminador nulo (\0)
     */

    // Impressao de uma string na tela
    printf("A variavel string contem %s\n", string);

    // Outras funcoes de impressao para string e caractere
    puts("A variavel string contem ");  // imprimir constante string (com \n automatico)
    puts(string);                       // imprimir variavel string (idem)

    putchar('@');                       // imprimir constante caractere
    char c = 'A';
    putchar(c);                         // imprimir variavel caractere
    putchar('\n');

    // Leitura de uma string do teclado
    char nome[MAX_NOME];
    printf("Bem-vindo(a), digite o seu nome: ");
    scanf(" %s", nome); // sem o & na frente da variavel porque eh um vetor!
    printf("Eh um prazer inenarravel executar-me para voce, %s!\n", nome);
    printf("Digite novamente, prometo usar o nome completo: ");
#ifdef WINDOWS
    fflush(stdin);
#else
    __fpurge(stdin); // limpeza manual do que ficou deixado pra tras pelo scanf
#endif
    gets(nome); // sem %s, sem &, somente o nome da variavel (sem colchetes)
    printf("Agora sim, %s!\n", nome);
    printf("Digite a primeira inicial do seu nome: ");
    c = getchar();
    printf("Sua inicial eh %c.\n", c);

    /* Nao existe copia de vetor com o operador de atribuicao (=)
    char copia[MAX_NOME] = nome;
    */
    char copia[MAX_NOME];
    strcpy(copia, nome); // copia = nome;

    printf("A string nome tem inicialmente %zd caracteres.\n", strlen(nome));

    if (strcmp(nome, copia) == 0)  { // strcmp() retorna zero se as strings forem
                                     // lexicograficamente iguais
        puts("Backup bem-sucedido");
    } else {
        puts("Backup errado");
    }

    printf("Fiz backup do nome em outra variavel (%s).\n", copia);

    printf("Digite o apelido pelo qual voce eh conhecido(a): ");
    char apelido[MAX_NOME];
#ifdef WINDOWS
    fflush(stdin);
#else
    __fpurge(stdin); // limpeza manual do que ficou deixado pra tras pelo gets (ou getchar)
#endif
    gets(apelido);
    // Concatena (poe no fim) o apelido no nome
    strcat(nome, " "); // para ter um espaco entre as palavras, sou obrigado a concatenar um
                       // espaco (note que usei " " e nao ' ' porque a concatenacao eh entre strings)
    strcat(nome, apelido); // nome += apelido;
    printf("Nome concatenado com apelido fica %s.\n", nome);
    if (strcmp(nome, copia) == 0)  { // strcmp() retorna zero se as strings forem
                                     // lexicograficamente iguais
        puts("Backup bem-sucedido");
    } else {
        puts("Backup errado");
    }

    printf("A string nome tem agora %zd caracteres.\n", strlen(nome));

    char x;
    printf("Digite uma letra qualquer: ");
#ifdef WINDOWS
    fflush(stdin);
#else
    __fpurge(stdin); // limpeza manual do que ficou deixado pra tras pelo gets (ou getchar)
#endif
    x = getchar();

    bool achei = procura(copia, x);
    if (achei == true) {
        puts("Achei no seu nome!");
    } else {
        puts("Nao achei no seu nome...");
    }   

    return EXIT_SUCCESS;
}

bool procura(char s[], char c) {
    int i = 0;
    while (s[i] != '\0') { // enquanto nao acha o terminador nulo...
        if (s[i] == c) {
            return true;
        }
        ++i;
    }
    return false; // nao encontrou dentro do while() {...}
}

