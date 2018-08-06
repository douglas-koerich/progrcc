/* Este eh um exemplo
   ilustrativo da traducao de um algoritmo
   para o programa correspondente em linguagem C */
#include <stdlib.h> // definicao de EXIT_SUCCESS
#include <stdio.h>  // definicoes de scanf e printf
#include <math.h>   // definicoes de pow e sqrt

int main()
// inicio
{
    // declare cateto1, cateto2, soma, hipotenusa : real
    float cateto1, cateto2, soma, hipotenusa;

    // leia cateto1, cateto2
    printf("Digite o primeiro cateto do triangulo: "); scanf("%f", &cateto1);
    printf("Digite o segundo cateto do triangulo: \n"); scanf("%f", &cateto2);

    // soma <- cateto1 ^ 2 + cateto2 ** 2    ; comentario: ambas notacoes de potencia
    soma = cateto1 * cateto1 + pow(cateto2, 2);

    // hipotenusa <- raiz(soma)
    hipotenusa = sqrt(soma);    // hipotenusa = pow(soma, 0.5);

    // escreva hipotenusa
    printf("A hipotenusa do triangulo vale %f\n", hipotenusa);

    return EXIT_SUCCESS;
// fim
}
