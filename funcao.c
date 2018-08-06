/*
funcao CalculaMedia(a, b, c : real) : real  ; o tipo da funcao eh do seu retorno (resultado)
                                            ; os parametros (entradas) sao tambem do tipo real
inicio
    declare media : real        ; o retorno (resultado) da funcao eh do mesmo tipo que ela
                                ; nao existe 'leia' porque as entradas sao passadas pra funcao
    media <- (a + b + c) / 3    ; proposito da funcao (o que ela faz)
    CalculaMedia <- media       ; indicacao do retorno (repasse) do resultado para quem chamou a funcao
fim
*/

#include <stdlib.h>
#include <stdio.h>

// Funcao CalculaMedia em linguagem C:
float CalculaMedia(float a, float b, float c) // nao pode ser: (float a, b, c)
{
    float media;    // variavel local do bloco de codigo da funcao
    media = (a+b+c) / 3;
    return media;   // retorno (repasse) do resultado dessa variavel que serah entao DESTRUIDA
}

int main() {
    float nota_1bim, nota_2bim, nota_trab, media_parcial;

    printf("Digite a nota do 1o. bimestre: ");
    scanf("%f", &nota_1bim);
    printf("Digite a nota do 2o. bimestre: ");
    scanf("%f", &nota_2bim);
    printf("Digite a nota do trabalho: ");
    scanf("%f", &nota_trab);

    // Chamada da (desvio para) funcao; passa as notas como ARGUMENTOS da funcao (dados de entrada);
    // o retorno (resultado) da funcao eh copiado para a variavel 'media_parcial'
    media_parcial = CalculaMedia(nota_1bim, nota_2bim, nota_trab);

    printf("A media parcial do(a) aluno(a) eh %.1f.\n", media_parcial);

    return EXIT_SUCCESS;
}
