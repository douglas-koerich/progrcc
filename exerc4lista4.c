#include <stdio.h>

float calculaTensao(float, float);

int main() {
    float diametro, carga, tensao;

    printf("Digite o diametro da barra: ");
    scanf("%f", &diametro);
    printf("Digite a carga da barra: ");
    scanf("%f", &carga);

    tensao = calculaTensao(diametro, carga);

    printf("A tensao aplicada sobre a barra eh %.3f\n", tensao);

    return 0;
}

float calculaTensao(float D, float Q) {
    // Embora nao pedido pelo exercicio (e nao seria avaliado numa questao),
    // eh IMPORTANTE prevenir-se quanto a parametros INVALIDOS numa funcao
    if (D == 0.0) {
        return 0.0; // do contrario, com denominador nulo na formula,
                    // seu programa ABORTARIA!
    }
    float S;
    int n;
    if (D > 100) {
        n = 2;
    }
    else {
        if (D < 50) {
            n = 6;
        }
        else {
            n = 4;
        }
    }
    /* Mais feio, nao use assim, embora esteja sintaticamente correto
    if (D > 100) n = 2;
    else if (D < 50) n = 6;
    else n = 4;
    */
    S = 4 * Q * n / (3.1416 * D * D);   // cuidado com os parenteses

    return S;
}

