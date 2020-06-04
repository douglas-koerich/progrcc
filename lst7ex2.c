#include <stdlib.h>
#include <stdio.h>
#include <stdio_ext.h>
#include <ctype.h>
#include "lst7ex2.h"

int main(void) {
    size_t num_habitantes;
    printf("Digite o numero de habitantes: ");
    scanf("%zu", &num_habitantes);

    habitante* populacao = censo(num_habitantes);
    float media = media_sal(populacao, num_habitantes);
    unsigned menor, maior;
    menor_maior_idade(populacao, num_habitantes, &menor, &maior);
    size_t mulheres = mulheres_3f_ateh_900(populacao, num_habitantes);

    puts("Estatisticas finais:");
    printf("Media salarial = R$ %.2f\n", media);
    printf("Menor idade = %u\n", menor);
    printf("Maior idade = %u\n", maior);
    printf("Mulheres c/ 3 filhos e ateh R$900 = %zu\n", mulheres);

    free(populacao); // censo() aloca, main() libera

    return EXIT_SUCCESS;
}

habitante* censo(size_t num) {
    habitante* vet = malloc(num * sizeof(habitante));

    // Execucao do censo
    int h;
    for (h = 0; h < num; ++h) {
        printf("Dados do habitante no. %d:\n", h+1);
        printf("Idade [anos]? "); scanf("%u", &vet[h].idade);
        __fpurge(stdin); // em Linux (em Windows: fflush(stdin))
        printf("Genero (M/F/...)? "); vet[h].genero = toupper(getchar());
        printf("Salario [R$]? "); scanf("%f", &vet[h].salario);
        printf("Num. de filhos? "); scanf("%u", &vet[h].filhos);
        puts("----------");
    }

    return vet;
}

float media_sal(const habitante populacao[], size_t num_habitantes) {
    if (num_habitantes == 0) {
        return 0.0;
    }
    float soma_sal;
    int h;
    for (h = 0, soma_sal = 0.0; h < num_habitantes; ++h) {
        soma_sal += populacao[h].salario;
    }
    return soma_sal / num_habitantes;
}

void menor_maior_idade(const habitante populacao[], size_t num_habitantes,
                       unsigned* p_menor, unsigned* p_maior) {
    *p_menor = *p_maior = 0; // preenche com 0 os dois conteudos (variaveis 'menor' e 'maior' da
                             // funcao main() )
    int h;
    const habitante* individuo;
    for (h = 0, individuo = populacao; h < num_habitantes; ++h, ++individuo) {
        if (h == 0) { // primeiro individuo do vetor-populacao?
            *p_menor = *p_maior = individuo->idade;
        } else {
            if (individuo->idade > *p_maior) {
                *p_maior = individuo->idade;
            }
            if (individuo->idade < *p_menor) {
                *p_menor = individuo->idade;
            }
        }
    }
}

size_t mulheres_3f_ateh_900(const habitante* populacao, size_t num_habitantes) {
    int h;
    size_t contador;
    for (h = 0, contador = 0; h < num_habitantes; ++h) {
        if ((populacao + h)->genero == 'F' &&
            (populacao + h)->filhos == 3 &&
            (populacao + h)->salario <= 900) {
            ++contador;
        }
    }
    return contador; 
}

