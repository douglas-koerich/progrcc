/* PROBLEMA: Escrever uma funcao UNICA que faca a conversao de unidades de
 * temperatura conforme selecionado:
 * 1: Celsius para Fahrenheit E Kelvin ("duplo retorno")
 * 2: Fahrenheit para Celsius E Kelvin (idem)
 * 3: Kelvin para Celsius E Fahrenheit (ibidem)
 *
 * Se fosse possivel escrever uma funcao para cada tipo de conversao, elas
 * seriam assim:
 * float c2f(float c);	// 1
 * float c2k(float c);	// 1
 * float f2c(float f);	// 2
 * float f2k(float f);	// 2
 * float k2c(float k);	// 3
 * float k2f(float c);	// 3
 */

#include <stdio.h>
 
// Passagem de parametro por referencia (ou endereco): recebe um ponteiro/endereco
// para atraves dele alterar o valor original da variavel que pertence a funcao que
// chama (no caso, main)
void convtemp(float in, float* out1, float* out2, int opcao);

int main() {
	int origem;
	float temp_entrada;				// lido do teclado
	float temp_saida1, temp_saida2;	// resultante ("retornadas") da funcao
	
	do {
		printf("Qual a unidade de temperatura digitada (1:C, 2:F, 3:K)? ");
		scanf("%d", &origem);
	} while (origem < 1 || origem > 3);
	
	printf("Digite a temperatura: ");
	scanf("%f", &temp_entrada);
	
	// Para que convtemp possa alterar o valor das variaveis LOCAIS temp_saida1
	// e temp_saida2 eh necessario que a funcao receba os ENDERECOS (onde na
	// memoria) dessas variaveis - por isso o operador & na frente das variaveis
	// que vao ser alteradas!
	convtemp(temp_entrada, &temp_saida1, &temp_saida2, origem);
	
	printf("Temperatura informada: %f\n", temp_entrada);
	printf("Convertida para: %f; e\n", temp_saida1);
	printf("Tambem convertida para: %f\n", temp_saida2);
	
	return 0;
}

void convtemp(float in, float* out1, float* out2, int opcao) {
	switch (opcao) {
		case 1:	// origem eh Celsius?
			*out1 = in + 273;		// Celsius para Kelvin (c2k)
			*out2 = 9*in/5 + 32;	// Celsius para Fahrenheit (c2f)
			break;
			
		case 2:	// origem eh Fahrenheit?
			*out1 = 5*(in - 32)/9;	// Fahrenheit para Celsius (f2c)
			*out2 = *out1 + 273;		// Fahrenheit para Kelvin (f2k) usando Celsius
			break;
			
		case 3:	// origem eh Kelvin?
			*out1 = in - 273;			// Kelvin para Celsius (k2c)
			*out2 = 9*(*out1)/5 + 32;	// Kelvin para Fahrenheit (k2f) usando Celsius
			break;
			
		default:
			puts("Opcao invalida!");
			*out1 = *out2 = 0;	// Sem o operador * teriamos atribuido o endereco NULO
								// aos ponteiros
	}
}
