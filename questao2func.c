#include <stdio.h>

int questao2(void);

// Variavel GLOBAL, visivel e acessivel por todas as funcoes a seguir
float S;	// Toda variavel global nao inicializada tem valor inicial 0
			// (permanece na memoria durante toda a execucao do programa)

int main(void) {
	int termos = questao2(); // Esta variavel 'termos' eh diferente e estah
							 // em outro lugar da memoria daquela variavel
							 // 'termos' que eh local a questao2()
	printf("O valor final de S eh %.10f, com %d termos.\n", S, termos);
	return 0;
}

int questao2(void) {
	// Variaveis LOCAIS da funcao questao2()
	// (destruidas na saida da funcao)
	float S_anterior = 0.0, precisao, numerador = 63.0;
	int denominador = 0, termos = 0;
	do {
		// Variavel 'fatorial' eh LOCAL ao laco, fora dele nao existe
		// (e eh criada no inicio e destruida no final de cada passo)
		int fatorial = 1;
		for (int i=1; i<=denominador; ++i) {	// com C99+ (nao VC++)
			fatorial *= i;
		}
		S += numerador / fatorial;
		precisao = S - S_anterior;
		numerador -= 2;
		++denominador;
		++termos;
		printf("S = %.10f, S_anterior = %.10f\n", S, S_anterior);
		S_anterior = S;
	} while (precisao >= 0.0000001);

	return termos;
}
