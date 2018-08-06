#include <stdlib.h>
#include <stdio.h>

// Este programa vai imprimir na tela a tabuada de um numero escolhido pelo usuario

int main()
// inicio
{
    // declare numero : inteiro
    int numero, fator, total;

    // leia numero
    printf("Digite um numero: ");
    scanf("%d", &numero);

    // para fator de 1 ate 10 passo 1 faca
    for (fator = 1; fator <= 10; ++fator) {
        // total <- numero * fator
        total = numero * fator;

        // escreva numero "x" fator "=" total
        printf("%10d x %2d = %20d\n", numero, fator, total);

        // Exemplificando como um laco pode ser interrompido a forca, por conta
        // de uma condicao particular (poderia ser uma condicao de erro)
        if (total % 12 == 0) {
            printf("PEGADINHA! Nao aceito multiplos de duzia!!!\n");
            break;  // interrompe o laco, sem repetir
        }
    }
    // fim-para
    return EXIT_SUCCESS;
// fim
}
