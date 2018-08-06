/* Este eh o meu primeiro programa em C */
// Esta eh uma segunda forma de incluir comentario

/*
   inicio ; algoritmo para calculo da area do trapezio
    declare B, b, h, A : real
    leia B, b, h
    A <- (B+b)*h/2
    escreva A
   fim
 */

#include <stdio.h>  // referencia para a biblioteca-padrao de E/S

int main() {    // programa para calculo da area do trapezio
	float B, b, h, A;
	printf("Digite a base MAIOR do trapezio: ");
	scanf("%f", &B); // nao esquecer o & no scanf!
	printf("Digite a base menor: ");
	scanf("%f", &b);
	printf("Digite a altura do trapezio: ");
	scanf("%f", &h);
	A = (B + b) * h / 2;
	printf("A area total eh %f\n", A); // aqui NAO tem o & na frente da variavel!
	return 0;
}
