#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main() {
    int N;
    printf("Digite o numero: ");
    scanf("%d", &N);

    // Vamos determinar a "grandeza" do numero na base decimal
    // usando logaritmo
    int grandeza = log10(N);    // copiar de double (vindo da funcao log10)
                                // pra int vai truncar a parte fracionaria,
                                // mas eh o que eu quero!

    // Para obter o algarismo mais significativo, divido o numero
    // pela potencia de 10 que eh a grandeza
    int multiplo_10 = pow(10, grandeza);
    int mais_significativo = N / multiplo_10; // divisao inteira!

    printf("O algarismo mais significativo eh %d.\n", mais_significativo);

    return EXIT_SUCCESS;
}
