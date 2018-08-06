#include <stdbool.h>
#include <stdio.h>

int main() {
	int ano;
	bool ehBissexto;

	printf("Digite o ano: ");
	scanf("%d", &ano);

	/*
	if (ano % 4 == 0) {
		if (ano % 100 == 0) {
			if (ano % 400 == 0) {
				ehBissexto = true;
			}
			else {	
				ehBissexto = false;
			}
		}
		else {
			ehBissexto = true;
		}
	}
	else {
		ehBissexto = false;
	}
	*/
	bool A = ano % 4 == 0;	// expressao do lado direito eh relacional, que retorna um logico (true/false)
	bool B = ano % 100 == 0;
	bool C = ano % 400 == 0;
	ehBissexto = A && ((!B && !C) || (B && C));
	if (ehBissexto) {
		printf("O ano eh bissexto.\n");
	}
	else {
		printf("O ano NAO eh bissexto.\n");
	}

	return 0;
}

