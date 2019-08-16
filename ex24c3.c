#include <stdlib.h>
#include <stdio.h>

int main() {
    float hora, m;
    int h, conversao;

    printf("Digite o horario na forma hora.minutos: ");
    scanf("%f", &hora);

    h = hora; // na variavel 'h' serah armazenada apenas a parte inteira de 'hora'
    m = hora - h; // 'm' eh float porque recebe a parte fracionaria de 'hora'

    conversao = h * 60 + m * 100;

    printf("O horario em minutos eh %d\n", conversao);

    return EXIT_SUCCESS;
}

