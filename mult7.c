#include <stdlib.h>
#include <stdio.h>

int main()
// inicio
{
    // declare numero : inteiro
    int numero;

    // escreva "Enquanto vc nao digitar um multiplo de 7 nao terminaremos aqui..."
    printf("Enquanto vc nao digitar um multiplo de 7 nao terminaremos aqui...\n");

    // LACO COM TESTE NO FINAL (USADO QUANDO O VALOR DE TESTE EH GERADO DENTRO DO LACO)
    // repita   ; Em C, o "repita-ate" torna-se "faca-enquanto"
    do {
        // leia numero  ; comando de leitura serah repetido 1 ou mais vezes
        printf("Numero? ");
        scanf("%d", &numero);
    }
    // ate resto (numero, 7) = 0    ; ateh que o numero seja divisivel por 7
    // numero % 7 == 0 ; Em C, como a repeticao ocorre enquanto a condicao for VERDADEIRA,
    //                 ; eh necessario inverter a logica da expressao
    while (!(numero % 7 == 0)); // Normalmente, seria assim: while (numero %7 != 0);

    return EXIT_SUCCESS;
// fim
}
