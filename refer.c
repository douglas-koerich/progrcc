/*
Sabe-se que:
a) 1 peh = 12 polegadas
b) 1 jarda = 3 pehs
c) 1 milha = 1760 jardas
Faca uma funcao que receba uma medida em jardas, faca as conversoes e retorne
os resultados: (a) em polegadas; (b) em milhas.
*/

#include <stdlib.h>
#include <stdio.h>

float converte_pol(float);
float converte_mil(float);
void converte_pol_mil(float, float*, float*);

int main(void) {
    float jardas, polegadas, milhas;

    puts("Programa-exemplo para conversao de jardas em polegadas e milhas");
    printf("Digite a dimensao em jardas: ");
    scanf("%f", &jardas);

    /*
    polegadas = converte_pol(jardas);
    milhas = converte_mil(jardas);
    */
    converte_pol_mil(jardas, &polegadas, &milhas);

    printf("A conversao resultou: %.2f polegadas / %.2f milhas.\n", polegadas, milhas);

    return EXIT_SUCCESS;
}

float converte_pol(float j) {
    float p = j * 3 * 12;   // altera o valor da variavel p
    return p;
}

float converte_mil(float j) {
    float m = j / 1760;
    return m;
}

void converte_pol_mil(float j, float* p, float* m) {
    *p = j * 3 * 12;    // altera o conteudo do endereco (apontado por) p
    *m = j / 1760;
}

