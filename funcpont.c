#include <stdlib.h>
#include <stdio.h>

/*
float polegadas_para_pes(float pol);
float polegadas_para_jardas(float pol);
float polegadas_para_milhas(float pol);
*/

// Uma unica funcao que converta polegadas para as tres outras unidades de medidas
void converte_para_todas(float pol, float* pes, float* jardas, float* milhas);

int main(void) {
    float polegadas;
    printf("Digite o comprimento em polegadas: ");
    scanf("%f", &polegadas);

    float p, j, m;  // variaveis LOCAIS de main(), desconhecidas para converte_para_todas
    /*
    pes = polegadas / 12;
    jardas = pes / 3;
    milhas = jardas / 1760;
    */
    converte_para_todas(polegadas,      // passagem de variavel por copia ("somente-leitura")
                        &p, &j, &m);    // passagens de variaveis por endereco ("referencia")

    printf("Esse comprimento vale %.5f pes, %.5f jardas e %.5f milhas.\n", p, j, m);

    return EXIT_SUCCESS;
}

void converte_para_todas(float pol, float* pes, float* jardas, float* milhas)
{
    // float pes, jardas, milhas;  // variaveis locais (destruidas no fim da funcao)
    *pes = pol / 12;
    *jardas = *pes / 3;
    *milhas = *jardas / 1760;
}
