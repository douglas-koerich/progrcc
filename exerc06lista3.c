#include <stdlib.h>
#include <stdio.h>

int main() {
    int n;
    do {
        printf("Digite o numero de ordem (primeiro, segundo, ...) do numero de Fibonacci: ");
        scanf("%d", &n);
    } while (n <= 0);
    if (n == 1 || n == 2) {
        printf("O numero de Fibonacci eh %d.\n", n-1);
    }
    else {
        int fn,         // Numero de Fibonacci que serah gerado pelo passo da vez
            // Como nao tive passos anteriores, preciso inicializar essas variaveis
            // com os valores que geram o primeiro numero a partir da formula
            fn_1 = 1,   // Numero que foi gerado no passo anterior (usado agora na soma)
            fn_2 = 0,   // Numero que foi gerado ha dois passos atras (tambem usado na soma)
            m;          // Controle do numero de Fibonacci que estah sendo gerado no momento
        for (m=3; m<=n; ++m) { // Comeca com m=3 porque eh o terceiro numero quem comeca a ser calculado
            fn = fn_1 + fn_2;   // Determina/calcula o numero da vez
            // Agora, prepara os anteriores para o proximo passo (se houver)
            fn_2 = fn_1;
            fn_1 = fn;
        }
        printf("O numero de Fibonacci eh %d.\n", fn);
    }
    return EXIT_SUCCESS;
}
