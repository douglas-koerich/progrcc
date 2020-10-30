#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

char calcula_verificador(const char [*]);

// Define como variavel global porque tanto main() quanto calcula_verificador() vao criar
// vetores com essa dimensao
const size_t NUM_DIGITOS_CONTA = 5;

int main(void) {
    char num_conta_corrente[NUM_DIGITOS_CONTA + 1];

    printf("Digite o numero da conta-corrente: ");
    scanf(" %s", num_conta_corrente); // NAO DEVE ANTEPOR o & antes da variavel

    char digito_verificador = calcula_verificador(num_conta_corrente);

    printf("O numero da conta com digito eh %s-%c\n", num_conta_corrente, digito_verificador);

    return EXIT_SUCCESS;
}

char calcula_verificador(const char numero_conta[]) {
    char num_conta_invertida[NUM_DIGITOS_CONTA + 1];
    int n = strlen(numero_conta) - 1; // indice do ultimo caractere valido na string 'numero_conta'
    int i = 0;
    while (n >= 0) {
        num_conta_invertida[i] = numero_conta[n];
        --n, ++i;
    }
    num_conta_invertida[i] = '\0'; // ao terminar o laco acima, 'i' vai estar na posicao seguinte ao
                                   // ultimo caractere copiado da string original; eh necessario "marcar"
                                   // o fim da string invertida manualmente neste caso

    int num_conta, num_invertido;
    num_conta = atoi(numero_conta); // converte de string (supostamente numerica) para o inteiro correspondente
    num_invertido = atoi(num_conta_invertida);

    // Letra (a) do algoritmo
    int soma = num_conta + num_invertido;

    // Letra (b)
    int num_algarismos = log10(soma) + 1; // v. exercicio da primeira lista da Disciplina
    int acumulado_multiplicacoes = 0;
    while (soma > 0) {
        int menos_significativo = soma % 10;
        acumulado_multiplicacoes += menos_significativo * num_algarismos;

        // Para o proximo passo elimina o menos significativo da vez, diminuindo tambem o numero de algarismos
        soma /= 10; // removeu o LSD
        --num_algarismos;
    }

    // Letra (c)
    char digito = (acumulado_multiplicacoes % 10) + '0'; // converte o digito inteiro em caractere

    return digito;
}