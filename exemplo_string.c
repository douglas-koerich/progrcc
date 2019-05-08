#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h> // para as funcoes str***() da biblioteca-padrao de C

#define MAX_NOME 100 // lembrar que esse tamanho deve considerar o espaco
                     // ocupado pelo proprio terminador nulo ('\0')

int main(void) {
    char nome[MAX_NOME]; // declaracao da "variavel string"
    char vip[MAX_NOME] // = { 'N', 'e', 'y', 'm', 'a', 'r' };
                       = "Neymar"; // inicializacao com um "vetor constante" 
    do {
        // printf("Digite o seu nome, usuario(a): ");
        puts("Digite o seu nome, usuario(a)");

        /* Esta linha soh serve para ler uma string sem separadores (espacos)
        scanf("%s", nome); // sem o & na frente da variavel!...
        */
        gets(nome); // le uma string ateh o \n

    } while (!isalpha(nome[0])); // pede novamente se nao inicia com letra

    printf("Bem-vindo(a) ah programacao em C, %s!\n", nome);

    if (strcmp(nome, vip) == 0) {
        puts("Voce eh o cara! X-P");
    } else {
        puts("Reduza-se ah sua mediocridade...");
    }
    // Vamos alterar a segunda letra do nome
    printf("Digite uma letra qualquer: ");
    nome[1] = getchar(); // leitura de caracter isolado
    puts(nome);

    return EXIT_SUCCESS;
}

