#include <stdio.h>

// inicio
int main()
{
    // Declaracao de variaveis em linguagem C
    // declare A, B, b, h : real
    float A, B, b, h;
    
    /* Aqui se fara a leitura
       de todas as variaveis
       de entrada do programa
    ; leia B
    ; leia b
    ; leia h
    leia B, b, h
    */
    printf("Digite o valor da base maior do trapezio: "); scanf("%f", &B);
    
    printf("Digite o valor da base menor: ");
    scanf("%f", &b);
    
    printf("Agora, digite a altura do trapezio: ");
    scanf("%f", &h);
    
    /* Calculo da area */
    // A <- (B+b)*h/2;
    A = (B+b)*h/2;

    // escreva A
    printf("A area calculada eh %.0f.\n", A);
    
    return 0;
} // fim