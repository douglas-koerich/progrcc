#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    unsigned n;
    printf("Digite um numero: ");
    scanf("%u", &n);
    
    bool eh_primo = true;
    unsigned divisor = n-1;
    while (divisor > 1) {
        if (n % divisor == 0) {
            eh_primo = false;
            break; // nao faz sentido continuar o teste
        }
        --divisor;
    }
    if (eh_primo) {
        printf("%u eh primo\n", n);
    } else {
        printf("%u nao eh primo (p.ex. divisivel por %u)\n", n, divisor);
    }
         
    return EXIT_SUCCESS;
}

