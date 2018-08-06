#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include "pessoa.h"

void salva_cadastro(const struct pessoa*, size_t);

int main(void) {
    size_t num_pessoas;
    printf("Digite o numero de pessoas a cadastrar: ");
    scanf("%zd", &num_pessoas);

    /*
    // DECLARACAO de uma variavel-estrutura, com seus campos internos!
    struct pessoa individuo;
    struct pessoa conhecido = { 99, 'F', 56.0, 1.45, .imc=1.0 }; // inicializacao (parcial)

    do {
        printf("Digite o sexo da pessoa: ");
        scanf(" %c", &individuo.sexo);  // operador . usado com variavel-estrutura
        individuo.sexo = toupper(individuo.sexo); // transforma para maiusc.
    } while (individuo.sexo != 'M' && individuo.sexo != 'F');

    struct pessoa* pIndividuo = &individuo; // ponteiro para a estrutura
    printf("Digite a idade da pessoa: ");
    scanf("%d", &pIndividuo->idade); // operador -> usado com ponteiro-para-estrutura

    pessoa* pOutroPonteiro = &individuo;    // usando o tipo do typedef
    printf("Digite o peso [kg]: ");
    scanf("%f", &pOutroPonteiro->peso);

    printf("Finalmente, digite a altura dele(a) [m]: ");
    scanf("%f", &individuo.altura);

    float peso_ideal = individuo.sexo == 'M'? 72.7*individuo.altura - 58:
                                              62.1*individuo.altura - 44.7;
    printf("O peso ideal eh %f ", peso_ideal);

    float imc = individuo.peso / pow(individuo.altura, 2);
    if (imc < 18.5) {
        puts("(estah abaixo do peso)");
    } else if (imc < 25) {
        puts("(normal)");
    } else if (imc < 30) {
        puts("(estah acima do peso)");
    } else {
        puts("(obeso(a))");
    }
    individuo.ideal = peso_ideal;
    individuo.imc = imc;
    */

    // DECLARACAO de um vetor de estruturas
    struct pessoa populacao[num_pessoas];
    struct pessoa* pPopulacao = populacao;  // nome do vetor eh seu endereco inicial
    int i;
    for (i=0; i<num_pessoas; ++i) {
        do {
            printf("Digite o sexo da %da. pessoa: ", i+1);
            scanf(" %c", &populacao[i].sexo);
            populacao[i].sexo = toupper(populacao[i].sexo);
        } while (populacao[i].sexo != 'M' && populacao[i].sexo != 'F');

        printf("Digite a idade da pessoa: ");
        scanf("%d", &(pPopulacao+i)->idade); // aritmetica nos faz chegar ao
                                             // i-esimo registro no vetor

        printf("Digite o peso [kg]: ");
        scanf("%f", &(pPopulacao+i)->peso);

        printf("Finalmente, digite a altura dele(a) [m]: ");
        scanf("%f", &populacao[i].altura);

        float peso_ideal = populacao[i].sexo == 'M'? 72.7*populacao[i].altura - 58:
                                                  62.1*populacao[i].altura - 44.7;
        printf("O peso ideal eh %f ", peso_ideal);

        float imc = populacao[i].peso / pow(populacao[i].altura, 2);
        if (imc < 18.5) {
            puts("(estah abaixo do peso)");
        } else if (imc < 25) {
            puts("(normal)");
        } else if (imc < 30) {
            puts("(estah acima do peso)");
        } else {
            puts("(obeso(a))");
        }

        populacao[i].ideal = peso_ideal;
        populacao[i].imc = imc;
    }
    salva_cadastro(populacao, num_pessoas);

    // Imprime o segundo registro do arquivo
    FILE* arq = fopen("/tmp/pessoa.bin", "rb");
    if (arq == NULL) {
        perror("Erro ao abrir o arquivo de cadastro");
        return EXIT_FAILURE;
    }
    fseek(arq, sizeof(struct pessoa), SEEK_SET); // pula o primeiro
    struct pessoa rascunho;
    if (fread(&rascunho, sizeof(pessoa), 1, arq) < 1) {
        perror("Erro ao ler o individuo");
        return EXIT_FAILURE;
    }
    fclose(arq);
    printf("Sexo: %c,\nPeso: %.1f,\nAltura: %.2f\n", rascunho.sexo,
           rascunho.peso, rascunho.altura);

    return EXIT_SUCCESS;
}

void salva_cadastro(const struct pessoa* vetor, size_t tamanho) {
    FILE* binario = fopen("/tmp/pessoa.bin", "wb");
    if (binario == NULL) {
        perror("Nao pude criar o arquivo binario");
        exit(EXIT_FAILURE); // posso sair por aqui pois nao ha alocacao dinamica no main()
    }
    if (fwrite(vetor, sizeof(struct pessoa), tamanho, binario) < tamanho) {
        perror("Erro ao escrever no arquivo binario");
        exit(EXIT_FAILURE);
    }
    fclose(binario);

    FILE* texto = fopen("/tmp/pessoa.txt", "w");
    if (texto == NULL) {
        perror("Nao pude criar o arquivo texto");
        exit(EXIT_FAILURE);
    }
    int i = 0;
    while (i < tamanho) {
        fprintf(texto, "%u, %c, %f, %f, %f, %f\n", vetor[i].idade, vetor[i].sexo,
            vetor[i].peso, vetor[i].altura, vetor[i].ideal, vetor[i].imc);
        ++i;
    }
    fclose(texto);
}

