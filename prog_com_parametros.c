#include <stdlib.h>
#include <stdio.h>

#define MAX_NOME 30

// int main(void) { (sem argumentos na linha de comando)
int main(int num_params, char* lista_params[]) { // os nomes usuais sao argc e argv
    // char nome[MAX_NOME]; (dispensavel pq jah tem a string na linha de comando)

    // DEBUG (inspecao dos parametros)
    printf("num_params: %d\n", num_params);
    int i;
    for (i=0; i<num_params; ++i) { // para cada um dos valores no vetor recebido por main()
        printf("param[%d] = %s\n", i, lista_params[i]); // imprime a string da vez no vetor
    }

    // Eh boa pratica verificar se ao menos o numero de parametros eh o esperado
    if (num_params < 3) { // lembre-se que o nome do programa na linha de comando CONTA!
        puts("Numero insuficiente de parametros");
        // Tambem eh recomendavel que se instrua o usuario a entrar com a linha correta
        printf("Uso: %s nome-do-usuario ano-de-nascimento\n", lista_params[0]);
        return EXIT_FAILURE;
    }

    int ano, idade;

    /* Com os parametros na linha de comando estas linhas tambem sao removidas
    printf("Digite seu nome: ");
    gets(nome);
    printf("Digite seu ano de nascimento: ");
    scanf("%d", &ano);
    */

    // Jah que os parametros da linha de comando sao todos strings, pra fazer calculo com
    // um deles preciso converte-lo pra um tipo numerico

    // As duas linhas a seguir fazem a mesma coisa, sao alternativas entre si
    ano = atoi(lista_params[2]); // Ascii-TO-Integer: converte de string pra inteiro
    sscanf(lista_params[2], "%d", &ano); // usando um mecanismo similar ao scanf, mas de string

    idade = 2019 - ano;

    // printf("Ola, %s! Em 2019 voce fez (ou farah) %d anos.\n", nome, idade);
    printf("Ola, %s! Em 2019 voce fez (ou farah) %d anos.\n", lista_params[1], idade);

    return EXIT_SUCCESS;
}

