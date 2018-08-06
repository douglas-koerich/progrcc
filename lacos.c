#include <stdlib.h>
#include <stdio.h>

int main() {
    int a, b;
    printf("Digite o numerador (a): ");
    scanf("%d", &a);
    // Vou fazer como o Barth Simpson de castigo, escrever repetidamente
    // no quadro: "nao vou esquecer como funciona um laco" pelo numero de
    // vezes igual ao valor de a
    int contador = 1;   // variavel de controle dos lacos a seguir (while e for)

    // Teste no inicio: "enquanto-faca" (0 ou mais repeticoes)
    while (contador <= a) {
        printf("Nao vou esquecer como funciona um laco!\n");
        if (contador % 7 == 0) {    // Se contador chegar a um multiplo de 7...
            // Interromper o laco antes do fim da contagem
            printf("\"Saida pela esquerda...\" (Leao da Montanha)\n");
            break; // nao executa ++contador, vai direto para o do {...}
        }
        ++contador;
    }
    // Para lacos contados (com um numero determinado de repeticoes), eh mais
    // comum utilizar o laco 'for': "para-de-ate-passo-faca"
    for (contador = 1; contador <= a; ++contador) {
        printf("Juro!, nao vou esquecer mesmo (contador=%d)!!!\n", contador);
    }

    // Teste no fim: "faca-enquanto" (1 ou mais repeticoes)
    do {
        printf("Digite o denominador (b): ");
        scanf("%d", &b);
    } while (b == 0);
    int c = a / b;
    printf("A divisao inteira resulta %d.\n", c);
    return EXIT_SUCCESS;
}

/* Programa que nunca termina (ex. servidor Web)
int main() {
    while (true) {  // for (;;) {}
        // Faca o que deve ser feito continuamente...
    }
}
*/
