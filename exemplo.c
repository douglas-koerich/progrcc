// Referencias para a biblioteca-padrao
#include <stdlib.h>
#include <stdio.h>

int main()
/* inicio */
{ // comeco do bloco de codigo da funcao main

    // declare idade, ano : inteiro
    int idade, ano;
    
    // escreva "Digite..."
    printf("Digite a sua idade: ");

    // leia idade
    scanf("%d", &idade);
    
    // Esse calculo pode nao refletir a realidade...
    // Em portugol: ano <- 2018 - idade
    ano = 2018-idade;
    
    // escreva ano
    printf("Voce nasceu em %d...\n", ano);
    
    return 0;
} // fim

