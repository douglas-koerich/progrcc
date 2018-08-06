#include <stdlib.h>
#include <stdio.h>

int main() {
    // Variaveis locais do bloco da funcao main()
    // Quando sai da funcao main(), as variaveis e seus valores
    // sao destruidos
    int dividendo, divisor;
    printf("Digite o valor do dividendo: ");
    scanf("%d", &dividendo);
    printf("Digite o valor do divisor: ");
    scanf("%d", &divisor);
    if (divisor == 0) {
        printf("A divisao nao pode ser feita!\n");
    }
    else {
        /*
        if (divisor > 100)
            printf("Nao aceito ...");   // com um comando dentro do if() pode-se
                                        // (mas nao eh recomendavel) abrir mao do {}
        else {
        */
        if (divisor > 100) {
            printf("Nao aceito divisores maiores que 100!\n");
        }
        else {
            // Variavel local do bloco else
            // Quando sai do else, a variavel e seu valor
            // sao destruidos
            int quociente;

            /* Repare que se eu declarasse:
            int divisor = 2;
            dentro deste bloco, essa variavel 'divisor' "esconderia"
            a variavel 'divisor' declarada no inicio de main() - esta
            que seria usada no lugar daquela */

            quociente = dividendo / divisor;
            printf("O quociente resultante eh %d.\n", quociente);
        }
    }
    return EXIT_SUCCESS;
}
