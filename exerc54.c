#include <stdio.h>
#include <ctype.h>

int main(void) {
	float altura, maior_h, menor_h, media_hf;
	char sexo, sexo_mais_alta;
	int contador, contador_f, contador_m;

	for (contador = 1, contador_f = contador_m = 0, media_hf = 0.0;
		 contador <= 15; ++contador) {
		printf("Digite a altura [m]: ");
		scanf("%f", &altura);

		do {
			printf("Digite o sexo (M/F): ");
			scanf(" %c", &sexo);
			sexo = toupper(sexo);
		} while (sexo != 'M' && sexo != 'F');

		// Letra (a)
		if (contador == 1) {
			maior_h = menor_h = altura;
			sexo_mais_alta = sexo;
		}
		else {
			if (altura > maior_h) {
				maior_h = altura;

				// Letra (d)
				sexo_mais_alta = sexo;
			}
			if (altura < menor_h) {
				menor_h = altura;
			}
		}

		// Letra (b)
		if (sexo == 'F') {
			++contador_f;
			media_hf += altura;
		}
		else {	// Letra (c)
			++contador_m;
		}
	}
	printf("Maior altura: %.2f\n", maior_h);
	printf("Menor altura: %.2f\n", menor_h);
	printf("Media das mulheres: %.2f\n", media_hf/contador_f);
	printf("Numero de homens: %d\n", contador_m);
	printf("Pessoa mais alta do sexo %c\n", sexo_mais_alta);

	return 0;
}

