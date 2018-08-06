#include <stdio.h>
#include <ctype.h>
// inicio
int main() {
	// declare idade: inteiro
	int idade;
	// declare sexo: caractere
	char sexo;
	// repita
	// Repeat
	do {
		// leia idade
		printf("Digite sua idade: ");
		scanf("%d", &idade);	
	// ate idade >= 0 e idade <= 120
	// Until (idade >= 0 And idade <= 120)
	} while (idade < 0 || idade > 120);
	// repita
	do {
		// leia sexo
		printf("Digite sexo (M/F): ");
		scanf(" %c", &sexo);
		sexo = toupper(sexo);	// conv. para maius.
	// ate sexo = 'F' ou sexo = 'M'
	} while (sexo != 'F' && sexo != 'M');
	// se sexo = 'F' entao
	if (sexo == 'F') {
		// escreva "Bem-vinda, "
		printf("Bem-vinda, ");
	}
	// senao
	else {
		// escreva "Bem-vindo, "
		printf("Bem-vindo, ");
	}
	// fim-se
	// se idade < 20 entao
	if (idade < 20) {
		// escreva "jovem!"
		printf("jovem!\n");
	}
	// senao
	else {
		// escreva "colega!"
		printf("colega!\n");
	}
	// fim-se
	return 0;
// fim
}
