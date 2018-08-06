#include <stdio.h>
#include <ctype.h>

int main() {
	float altura, maior, menor, soma_alturas;
	char sexo, sexo_maior;
	int pessoa, homens, mulheres;

	for (pessoa = 1, homens = mulheres = 0, soma_alturas = 0.0;
		 pessoa <= 15; ++pessoa) {
		printf("Digite a altura da pessoa n. %d: ", pessoa);
		scanf("%f", &altura);

		do {
			printf("Digite o sexo (M/F) da pessoa n. %d: ", pessoa);
			scanf(" %c", &sexo);
			sexo = toupper(sexo);	// pra comparar soh maiusculas
		} while (sexo != 'M' && sexo != 'F');

		if (pessoa == 1) {	// primeira leitura?
			maior = menor = altura;	// nao ha anterior com que comparar
			sexo_maior = sexo;
		}
		else {	// da segunda em diante, tenho que comparar pra mudar
			if (altura > maior) {
				maior = altura;
				sexo_maior = sexo;
			}
			if (altura < menor) {
				menor = altura;
			}
		}
		if (sexo == 'M') {
			++homens;
		}
		else {
			++mulheres;
			soma_alturas += altura;
		}
	}
	float media_alturas_mulheres = soma_alturas / mulheres;

	printf("Maior altura: %.2f m\n", maior);
	printf("Menor altura: %.2f m\n", menor);
	printf("Numero de homens: %d\n", homens);
	printf("Media de altura das mulheres: %.2f\n", media_alturas_mulheres);
	printf("Sexo da pessoa mais alta: %c\n", sexo_maior);

	return 0;
}

