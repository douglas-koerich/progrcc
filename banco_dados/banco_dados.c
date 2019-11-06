#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "pessoa.h"

/* Crie um programa que armazene num banco de dados as alturas e o sexos de
 * varias pessoas. Devem ser calculados e armazenados no mesmo banco seus pesos
 * ideias e IMCs (indices de massa corporal). Ao final, o programa deve imprimir
 * uma listagem dos registros e uma estatistica da saude dessa populacao.
 *
 * Para homens, deverah calcular o peso ideal usando a formula:
 * peso ideal = 72,7 x alt - 58; para mulheres: peso ideal = 62,1 x alt - 44,7.
 *
 * O IMC eh calculado pela formula: IMC = peso / (altura * altura) */

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("%s: parametros insuficientes\n", argv[0]);
        puts("Informe o numero de registros na linha de comando");
        return EXIT_FAILURE;
    }

    int num_pessoas = atoi(argv[1]);
    struct person populacao[num_pessoas]; // vetor de registros --> banco de dados

    int p;
    for (p = 0; p < num_pessoas; ++p) { // laco para percorrer o vetor (como antes)
        printf("Digite sua altura, em metros: ");
        scanf("%f", &populacao[p].altura); // nome-do-vetor[indice].nome-do-campo

        printf("Digite seu peso, em kg: ");
        scanf("%f", &populacao[p].peso);

        char sexo;
        do {
            printf("Digite seu sexo (M/F): ");
            scanf(" %c", &sexo);
            sexo = toupper(sexo); 
        } while (sexo != 'M' && sexo != 'F');
        populacao[p].sexo = sexo;

        populacao[p].peso_ideal = populacao[p].sexo == 'M' ?
            (72.7 * populacao[p].altura - 58) : (62.1 * populacao[p].altura - 44.7);
        populacao[p].imc = calcula_imc(populacao[p].peso, populacao[p].altura);
    }

    for (p = 0; p < num_pessoas; ++p) {
        printf("%c %.2fm %.0fkg ", populacao[p].sexo, populacao[p].altura,
               populacao[p].peso);
        if (populacao[p].peso > populacao[p].peso_ideal) {
            printf("NOK ");
        } else {
            printf("Ok! ");
        }
        putchar('\n');
    }

    return EXIT_SUCCESS;
}

float calcula_imc(float p, float h) {
    return p / (h * h);
}

