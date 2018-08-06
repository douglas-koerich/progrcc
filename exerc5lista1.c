#include <stdio.h>
#include <math.h>

int main() {
    unsigned N; // inteiro positivo

    printf("Digite um numero inteiro positivo: ");
    scanf("%u", &N);

    float l = log10(N);
    int ll = l; // trunca o logaritmo (maior potencia de 10 menor que N)

    float q = pow(10, ll);  // q sera essa potencia

    unsigned MSD = N / (int) q;   // força uma divisao inteira (cast)

    printf("O digito mais significativo de N (%u) eh %u.\n", N, MSD);

    return 0;
}
