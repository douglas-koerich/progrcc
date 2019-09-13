#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

bool eh_primo(unsigned); // testa apenas numeros positivos

/*
int main() {
    printf("Digite um numero: ");
    unsigned x;
    scanf("%u", &x);

    if (eh_primo(x)) { // retorno da funcao define se entra no 'if' ou no 'else'
        puts("Numero eh primo :-)");
    } else {
        puts("Numero nao eh primo :-(");
    }
    return EXIT_SUCCESS;
}
*/
int main() {
    printf("Digite um numero a ser decomposto em fatores primos: ");
    unsigned num;
    scanf("%u", &num);

    printf("%u = ", num);

    unsigned divisor = 2;
    while (num > 1) {
        while (!eh_primo(divisor)) { // enquanto divisor da vez nao eh primo...
            ++divisor; // ... vai para o proximo numero
        }
        // Divisor eh primo, continua...
        unsigned expoente = 0;
        while (num % divisor == 0) { // enquanto for divisivel pelo primo
            ++expoente;
            num /= divisor;
        }
        if (expoente > 0) {
            printf("%u^%u ", divisor, expoente);
        }
        ++divisor; // completou para o primo da vez, retorna ao inicio do laco
                   // com o proximo numero em teste pra ver se eh primo
    }
    putchar('\n'); // putchar() imprime no console apenas um caractere, neste
                   // caso o caractere de nova linha
    return EXIT_SUCCESS;
}

bool eh_primo(unsigned numero) {
    unsigned n;
    for (n=2; n<=numero/2; ++n) {
        if (numero % n == 0) {
            return false; // sai da funcao no meio do laco (nao precisa continuar)
        }
    }
    return true; // se cheguei ateh aqui eh porque o numero eh primo
}

