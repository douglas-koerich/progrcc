#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

bool testa_palindromo(int);

int main(void) {
    int numero;

    printf("Digite o numero para teste: ");
    scanf("%d", &numero);

    bool resultado = testa_palindromo(numero);

    if (resultado) { // (resultado == true)
        printf("O numero eh palindromo.\n");
    } else {
        printf("O numero nao eh palindromo.\n");
    }

    return EXIT_SUCCESS;
}

bool testa_palindromo(int N) {
    // Usando a experiencia do exercicio da lista 1...
    int num_algarismos_N = log10(N) + 1;

    int N_recebido = N, N_invertido = 0;
    int grandeza;

    // Para cada algarismo de N, comecando na unidade (grandeza=1),
    // indo pela dezena (grandeza=2), centena (grandeza=3), etc...
    for (grandeza = 1; grandeza <= num_algarismos_N; ++grandeza) {
        int algarismo = N % 10;
        N_invertido = N_invertido * 10 + algarismo;
        N = N / 10;
    }
    // Ao final do laco, N_invertido tem os mesmos algarismos que
    // N_recebido (N original), no sentido da direita para esquerda
    return N_invertido == N_recebido;
}
