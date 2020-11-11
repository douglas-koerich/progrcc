#include <stdlib.h>
#include <stdio.h>

int main(int num_params, char* lista_params[]) {
    /*
    printf("Digite o numero de parciais: ");
    size_t num_parciais;
    scanf("%zu", &num_parciais);

    float parciais[num_parciais]; // Soh eh possivel com C99 em diante
    */
    if (num_params < 2) { // 2 --> o nome do programa e o valor passado como argumento
        puts("Numero insuficiente de argumentos");
        printf("%s <numero-de-parciais>\n", lista_params[0]);
        return EXIT_FAILURE;
    }
    int num_parciais = atoi(lista_params[1]);

    float* parciais = malloc(sizeof(float) * num_parciais);
    float* backup = parciais;
    if (parciais == NULL) {
        return EXIT_FAILURE;
    }

    int p;
    for (p = 0; p < num_parciais; ++p, ++parciais) {
        printf("Digite a %da. parcial: ", p + 1);
        scanf("%f", parciais);
    }

    float s;
    for (p = 0, s = 0.0; p < num_parciais; ++p) {
        s += backup[p];
    }

    float ms = s / num_parciais;

    printf("A media do semestre eh %.1f\n", ms);

    free(backup); // deve passar o MESMO VALOR de endereco recebido do malloc()
    
    return EXIT_SUCCESS;
}