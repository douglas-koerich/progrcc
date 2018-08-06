#include <stdlib.h>
#include <stdio.h>

int main() {
    int n, Y;  // n da formula do produtorio eh digitado pelo usuario
    float P;    // produto das fracoes provavelmente serah um numero real

    printf("Digite o numero de termos (N) do produtorio: ");
    scanf("%d", &n);
    printf("Digite o valor de Y usado no produtorio: ");
    scanf("%d", &Y);

    // A variavel 'i' eh ao mesmo tempo o valor usado no denominador de cada vez
    // e o contador (controle de repeticoes) do laco
    int i;
    for (i=1, P=1; i<=n; ++i) { // inicializa o produtorio na entrada do laco
                                // (poderia ser tambem assim: i=P=1)
        // Dentro do laco que repete os termos, faz-se o calculo do termo da vez

        // Para calcular o fatorial, lembramos que ele tambem eh um produtorio,
        // entao o mecanismo eh o mesmo (usar um laco)
        int f, x;
        for (x=i-1, f=1; x>=1; --x) {
            f = f * x;  // "acumula" no fatorial o termo 'x' da vez
        }
        float p = (float) Y / f;    // sem cast, a divisao eh inteira
                                    // (entre Y e f que sao inteiros)
        P *= p;  // "acrescenta" o novo termo no produtorio
    }
    printf("O resultado do produtorio (P) eh igual a %.3f\n", P);
    return EXIT_SUCCESS;
}
