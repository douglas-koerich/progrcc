#include <stdlib.h>
#include <stdio.h>

float tensao_barra(float, float);
imprime_tensao(float);

int main(void) { // a funcao main nao tem parametros
    float diametro, carga;
    printf("Digite o diametro da barra: ");
    scanf("%f", &diametro);
    printf("Digite a carga imposta sobre a barra: ");
    scanf("%f", &carga);

    //float tensao = tensao_barra(diametro, carga);
    //printf("A tensao sobre a barra eh %f\n", tensao);
    
    //printf("A tensao sobre a barra eh %f\n", tensao_barra(diametro, carga));
    
    imprime_tensao(tensao_barra(diametro, carga));

    return EXIT_SUCCESS;
}

void imprime_tensao(float t) {
    if (t < 0) {
        return; // sai da funcao sem fazer nada (nem retornar, eh obvio)
    }
    printf("A tensao sobre a barra eh %f\n", t);
}

float tensao_barra(float D, float Q) {
    if (D == 0) {
        return 0; // nao eh possivel dividir por zero na formula
    }
    float S, PI = 3.14159;
    int n;
    if (D > 100) {
        n = 2;
    } else {
        if (D < 50) {
            n = 6;
        } else {
            n = 4;
        }
    }
    S = 4 * Q * n / (PI * D * D); // ao inves de pow(D, 2)
    return S;
}

