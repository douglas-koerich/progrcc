#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define NUM_QUESTOES 5
#define TAM_PALAVRA 20
#define MAX_NOME 100

int main(void) {
    char respostas[NUM_QUESTOES] = { 'a', 'e', 'c', 'd', 'a' };
    int resp_num[] = { 10, 3, 1, 0, 34 };

    // Imprimindo o vetor de caracteres "isolados"
    int i;
    for (i = 0; i < NUM_QUESTOES; ++i) {
        printf("%c ", respostas[i]);
        /*
        putchar(respostas[i]);
        putchar(' ');
        */
    }
    // printf("\n");
    putchar('\n');
    
    /*
    char palavra[TAM_PALAVRA] = { 'T', 'u', 'i', 'u', 't', 'i' }; // "Tuiuti"
    */
    char palavra[TAM_PALAVRA] = "Tuiuti (UTP)";
    char algarismo = '1'; // um byte na memoria
    char algarismo_[] = "1"; // DOIS bytes na memoria (char algarismo_[2])

    // Imprimindo o vetor de caracteres que eh uma string
    // printf("%s\n", palavra);
    puts(palavra); // automaticamente adiciona um \n ao final da impressao
                   // no console

    // Altera o conteudo da string com outra palavra
    /*
    palavra = "(UTP) Tuiuti"; // nao existe atribuicao de vetor
    */
    strcpy(palavra, "(UTP) Tuiuti"); // copia destino para origem

    // Compara duas strings
    if (strcmp(palavra, "(UTP) TUIUTI") != 0) { // <0, se palavra for menor
                                                // =0, se palavra for igual
                                                // >0, se palavra for maior
        puts("As strings sao diferentes");
    } else {
        puts("As strings sao iguais");
    }

    /*
    puts("O conteudo da string eh ");
    puts(palavra);
    */
    printf("O conteudo da string eh %s\n", palavra);

    char nome[MAX_NOME];
    printf("Digite o seu nome: ");
    /*
    scanf("%s", nome); // NAO PONHA o & na frente da variavel!!
    printf("Bem-vindo(a), %s, ah programacao em C com strings!\n", nome);
    scanf("%s", nome);
    printf("O que tinha no buffer do teclado era %s\n", nome);
    */
    gets(nome);
    char sobrenome[MAX_NOME];
    printf("Digite o seu sobrenome: ");
    gets(sobrenome);

    printf("Bem-vindo(a), %s, ah programacao em C com strings!\n", nome);

    // Adiciona um sufixo ao nome
    // strcat(nome, ", brasileiro(a)"); // nome += " ,brasileiro(a)";
    strcat(nome, " "); // insere um espaco "na mao" ao final do nome
    strcat(nome, sobrenome);
    printf("%s, bem-vindo novamente!\n", nome);

    return EXIT_SUCCESS;
}

