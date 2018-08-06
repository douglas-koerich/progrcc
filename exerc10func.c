#include <stdio.h>

// Prototipo (assinatura/declaracao) da funcao
float calculaIR(float, unsigned);

int main() {
	// Variaveis locais da funcao main, nao sao as mesmas que os parametros
	// da funcao calculaIR()!!!
	float renda;
	unsigned dependentes;

	printf("Informe a sua renda bruta (R$): ");
	scanf("%f", &renda);

	printf("Quantos dependentes? ");
	scanf("%u", &dependentes);

	float imposto = calculaIR(renda, dependentes);

	printf("O imposto de renda a pagar serah de R$ %.2f (buah, buah!)\n",
		   imposto);

	return 0;
}

float calculaIR(float renda, unsigned dependentes) {
	float aliquota;

	// Desconto por dependentes
	renda -= dependentes * 1600;
	if (renda < 0) {	// Se o desconto for maior que a renda bruta
		return 0.0;
	}
	// Selecao da aliquota
	if (renda <= 20000) {
		aliquota = 0;	// Isento
	}
	else {
		if (renda <= 35000) { // subentendido que renda eh maior que 20k
		// if (renda > 20000 && renda <= 35000) {
			aliquota = 15;
		}
		else {
			if (renda <= 45000) {
				aliquota = 22.5;
			}
			else {	// soh pode ser maior que 45000!
				aliquota = 27.5;
			}
		}
	}
	float imposto = renda * aliquota/100;
	return imposto;
}

