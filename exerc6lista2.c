#include <stdlib.h>
#include <stdio.h>

int main() {
    // Para simplificar a solucao, trabalharemos com angulos inteiros
    int angulo;

    printf("Digite o valor do angulo: ");
    scanf("%d", &angulo);

    // Iniciamos a analise fazendo a reducao do angulo ao intervalo (0 <= ang < 360)
    // Reduzir o angulo neste caso eh calcular o resto da divisao inteira por 360
    int reduzido = angulo % 360;
    printf("O angulo reduzido correspondente eh %d\n", reduzido);

    // Tambem aqui podemos determinar o numero de voltas, com o quociente da divisao inteira
    int voltas = angulo / 360;

    // Como o angulo pode ser negativo, o sinal de 'voltas' indica o sentido
    printf("O sentido do angulo eh ");
    if (reduzido < 0) {
        printf("horario\n");
        voltas = -voltas; // para imprimir o numero absoluto de voltas em seguida
    } else {
        printf("anti-horario\n");
    }
    printf("O angulo perfez %d voltas completas\n", voltas);

    // Enquadramento para angulo positivo
    printf("O angulo esta no quadrante ");
    if (reduzido >= 0) {
        if (reduzido < 90) { // desnecessario fazer if (reduzido >= 0 && reduzido < 90)
            printf("1\n");
        } else {
            if (reduzido < 180) { // nesse caso, ja eh maior ou igual a 90...
                printf("2\n");
            } else {
                if (reduzido < 270) {
                    printf("3\n");
                } else { // sendo reduzido, nao tem como ser maior ou igual a 360
                    printf("4\n");
                }
            }
        }
    } else {
        if (reduzido == 0 || reduzido < -270) { // 0 grau eh limite do primeiro quadrante
            printf("1\n");
        } else {
            if (reduzido >= -270 && reduzido < -180) {
                printf("2\n");
            } else {
                if (reduzido >= -180 && reduzido < -90) {
                    printf("3\n");
                } else {
                    printf("4\n");
                }
            }
        }
    }

    return EXIT_SUCCESS;
}

