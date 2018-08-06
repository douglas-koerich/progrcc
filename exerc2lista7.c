#include <stdlib.h>
#include <stdio.h>
#include <ctype.h> // para o toupper()
#include "exerc2lista7.h"

int main(int argc, char* argv[]) {
    // O numero de registros que serao lidos deve ter sido
    // passado por argumento na linha de comando (nao eh o que
    // o enunciado exigiu, mas vamos faze-lo a titulo de revisao)
    if (argc < 2) {
        puts("Numero insuficiente de parametros");
        printf("Use: %s <num-registros>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Converte a string que contem o numero de registros numa
    // variavel inteira, que pode ser usada como quantidade em
    // calculos no programa
    int registros = atoi(argv[1]);
    if (registros <= 0) { // Bonus da implementacao (nao obrigatorio)
        puts("Parametro incorreto");
        puts("Numero de registros deve ser maior que 0");
        return EXIT_FAILURE;
    }
    // Ha duas opcoes para criar o vetor de registros, aloca-lo
    // estaticamente assim:
    // habitante populacao[registros];
    // ou, dinamicamente, usando a funcao malloc():
    habitante* populacao = malloc(registros * sizeof(habitante));

    // Chama a funcao que faz o recenseamento
    censo(populacao, registros);

    // Uma vez que o vetor foi preenchido, calcula a media salarial
    float media = media_salarial(populacao, registros);

    // Agora, a proxima funcao precisa me "devolver"/"retornar" dois valores;
    // pra isso, vou passar pra ela os enderecos de duas variaveis locais
    // para que ela preencha essas posicoes de memoria atraves dos
    // ponteiros dela
    unsigned menor_idade, maior_idade;
    maior_menor_idade(populacao, registros, &maior_idade, &menor_idade);

    unsigned mulheres = num_mulheres_3filhos_ateh900(populacao, registros);

    printf("Media salarial: R$ %.2f\n", media);
    printf("Pessoa mais velha tem %u anos\n", maior_idade);
    printf("Pessoa mais jovem tem %u anos\n", menor_idade);
    printf("Mulheres segundo o criterio sao em %u\n", mulheres);

    // Ao fim do programa, deve certificar-se de liberar a memoria
    // que foi alocada para o "vetor" (bloco de registros)
    free(populacao);

    return EXIT_SUCCESS;
}

void censo(habitante* pop, size_t num) {
    // Um ponteiro/vetor eh recebido como parametro
    int i;
    puts("RECENSEAMENTO:");
    for (i=0; i<num; ++i) {
        printf("Digite os dados do habitante (%d de %zd)\n", i+1, num);
        printf("Idade: "); scanf("%u", &pop[i].idade);
        printf("Sexo: "); scanf(" %c", &((pop+i)->sexo)); // \o/
        printf("Salario: "); scanf("%f", &pop[i].salario);
        printf("Filhos: "); scanf("%u", &pop[i].filhos);
        puts("*****");
    }
}

float media_salarial(const habitante* pop, size_t num) {
    float soma = 0.0;
    int i;
    for (i=0; i<num; ++i) {
        soma += (pop+i)->salario;
    }
    return soma / num;
}

void maior_menor_idade(const habitante* pop, size_t num, unsigned* pmaior, unsigned* pmenor) {
    int i;
    for (i=0; i<num; ++i) {
        if (i == 0) {
            *pmaior = *pmenor = (pop+i)->idade;
        } else {
            if (pop[i].idade > *pmaior) {
                *pmaior = pop[i].idade;
            } else if (pop[i].idade < *pmenor) {
                *pmenor = pop[i].idade;
            }
        }
    }
}

unsigned num_mulheres_3filhos_ateh900(const habitante* pop, size_t num) {
    unsigned contador = 0;
    int i;
    for (i=0; i<num; ++i) {
        if (toupper((pop+i)->sexo) == 'F' &&
            (pop+i)->filhos == 3 && (pop+i)->salario <= 900.0) {
            ++contador;
        }
    }
    return contador;
}

