/* Escreva um programa que calcule a area e o perimetro de um circulo,
 * dado o seu raio.
 *
 * Recordando:	A = PI.raio²	(area)
 * 				C = 2.PI.raio	(perimetro)
 */

#include <stdio.h>	// por causa do printf e do scanf
#include <math.h>	// por causa do pow
#include <stdlib.h>	// por causa do EXIT_SUCCESS (=0)

#define PI 3.1416	// sem tipo, igual nem ponto-e-virgula!!!

int main() {
	float A, C;	// variaveis de saida
	float raio;	// variavel de entrada (poderia ser int, mas eh melhor float)
	// const float PI = 3.1416;	// "variavel" que nao muda de valor

	// Precisa iniciar pela leitura do raio
	printf("Digite o raio do circulo: ");
	scanf("%f", &raio);	// NAO esquecer do &!!!

	// Efetua o processamento/calculo
	A = PI * pow(raio, 2);
	C = 2 * PI * raio;

	// Exibe os resultados
	printf("Area = %.3f m², perimetro = %.3f m.\n", A, C);

	return EXIT_SUCCESS;
}

