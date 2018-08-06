#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include <ctype.h>
#include "exerc5lista7.h"   // definicao da estrutura

#define MAX_PACIENTES   10

int main() {
    // "Banco de dados" de pacientes
    // (em memoria)
    Paciente lista[MAX_PACIENTES];  // um vetor do TIPO-comum 'Paciente'
    unsigned num_pacientes = 0;

    // Cadastro do banco de dados
    int i;
    for (i=0; i<MAX_PACIENTES; ++i) {
        printf("Digite o nome do paciente (<Enter> para interromper): ");
        __fpurge(stdin);    // limpa o teclado
        gets(lista[i].nome);    // A esquerda do ponto fica a variavel ([])
        if (strlen(lista[i].nome) > 0) {
            ++num_pacientes;
            printf("Digite a idade dele(a): ");
            scanf("%u", &lista[i].idade);
            do {
                printf("Digite o seu sexo (M/F): ");
                __fpurge(stdin);
                lista[i].sexo = toupper(getchar());
            } while (lista[i].sexo != 'M' && lista[i].sexo != 'F'); 
            printf("Digite a altura [m]: ");
            scanf("%f", &lista[i].altura);
            printf("Digite o peso [kg]: ");
            scanf("%f", &lista[i].peso);
        }
        else {
            break;
        }
    }
    char nome_mais_pesada[MAX_NOME];
    float maior_peso;
    for (i=0; i<num_pacientes; ++i) {   // pode ter interrompido, portanto
                                        // nao faz para todo o vetor
        // Levantamento de dados para a letra (a) do exercicio
        if (i==0) {
            strcpy(nome_mais_pesada, lista[i].nome);
            maior_peso = lista[i].peso;
        }
        else if (lista[i].peso > maior_peso) {
            maior_peso = lista[i].peso;
        }
        // Letra (b)
        float ideal;
        if (lista[i].sexo == 'M') {
            ideal = 72.7 * lista[i].altura - 58;
        }
        else {
            ideal = 62.1 * lista[i].altura - 44.7;
        }
        if (lista[i].peso > ideal) {
            printf("%s, com %u anos, esta acima do peso ideal de %.1f kg (atual = %.1f kg)\n", lista[i].nome, lista[i].idade, ideal, lista[i].peso);
        }
        // Letra (c)
        if (lista[i].peso < ideal) {
            printf("%s precisa adquirir %.1f kg para chegar ao seu peso ideal de %.1f kg (atual = %.1f kg)\n", lista[i].nome, ideal-lista[i].peso, ideal, lista[i].peso);
        }
    }
    printf("A pessoa mais pesada eh %s\n", nome_mais_pesada);

    return 0;
}

