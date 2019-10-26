#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define NUM_DIGITOS_CONTA 5

char calcula_digito_verificador(const char [*]);

int main(void) {
    char numconta[NUM_DIGITOS_CONTA+2]; // espacos adicionais para:
                                        // 1. digito verificador;
                                        // 2. terminador nulo
    unsigned num;
    do {
        printf("Digite o numero da conta: ");
        scanf("%d", &num);
    } while (num > 99999);

    sprintf(numconta, "%05u", num); // converte pra string formatada

    char digito_verificador = calcula_digito_verificador(numconta);
    
    printf("A conta com digito eh %s-%c\n", numconta, digito_verificador);

    return EXIT_SUCCESS;
}

char calcula_digito_verificador(const char num_conta[]) {
    char conta_inv[NUM_DIGITOS_CONTA+2] = {};
    int i, j;
    for (i = 0, j = strlen(num_conta)-1; j >= 0; ++i, --j) {
        conta_inv[i] = num_conta[j];
    }
    int soma = atoi(num_conta) + atoi(conta_inv);
    int soma_digitos = 0, num_digitos_soma = log10(soma) + 1;
    while (num_digitos_soma > 0) {
        soma_digitos += soma % 10 * num_digitos_soma;
        soma /= 10;
        --num_digitos_soma;
    }
    return soma_digitos % 10 + '0';
}

