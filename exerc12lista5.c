#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include <math.h>

#define TAM_ENTRADA 15
#define TAM_CONTA   5

int main() {
    char num_conta[TAM_ENTRADA];
    int inum_conta;
    do {
        printf("Digite o numero da conta: ");
        __fpurge(stdin);
        gets(num_conta);
        inum_conta = atoi(num_conta);
    } while (strlen(num_conta) != TAM_CONTA || inum_conta < 10000);

    // Letra (a)
    // Encontra o numero inverso da conta; pra isso, percorro a string no sentido
    // contrario
    int i = TAM_CONTA-1;  // TAM_CONTA eh o indice do terminador nulo
    int rnum_conta = 0; // variavel para o numero de conta invertido
    while (i >= 0) {
        int digito = num_conta[i] - '0';    // Xunxo deslavado! Subtrai o codigo
                                            // ASCII do algarismo 0, obtendo assim
                                            // a "distancia" para o codigo desse
                                            // algarismo em num_conta[i], que eh
                                            // o numero procurado
        rnum_conta = rnum_conta*10 + digito; // acrescento o digito no final do
                                             // numero de conta calculado ateh agora
        --i;    // vai para tras na string
    }
    int soma_contas = inum_conta + rnum_conta;

    // Letra (b)
    int num_digitos = log10(soma_contas) + 1;   // determina se soma tem 5 ou 6 digitos
    int soma_digitos = 0;
    for (i=num_digitos; i>0; --i) {
        int digito = soma_contas % 10;  // ultimo digito da direita
        soma_digitos += digito * i;
        soma_contas /= 10;  // elimina ultimo digito da direita que ja foi somado
    }

    // Letra (c)
    int digito_verificador = soma_digitos % 10;

    printf("A conta com digito verificador eh %s-%c\n", num_conta,
           digito_verificador + '0');
    return 0;
}
