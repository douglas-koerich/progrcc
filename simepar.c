#include <stdio.h>

#define MEDIDAS	3

int main() {
	float media;

	/* Solucao mais que "orelhuda"...
	float t1, t2, t3, t4, t5, t6, t7;
	printf("Digite a temperatura do 1o. dia: ");
	scanf("%f", &t1);
	printf("Digite a temperatura do 2o. dia: ");
	scanf("%f", &t2);
	printf("Digite a temperatura do 3o. dia: ");
	scanf("%f", &t3);
	printf("Digite a temperatura do 4o. dia: ");
	scanf("%f", &t4);
	printf("Digite a temperatura do 5o. dia: ");
	scanf("%f", &t5);
	printf("Digite a temperatura do 6o. dia: ");
	scanf("%f", &t6);
	printf("Digite a temperatura do 7o. dia: ");
	scanf("%f", &t7);
	media = (t1+t2+t3+t4+t5+t6+t7) / 7;
	*/

	float t;
	
	/* Solucao menos "orelhuda"...
	media = 0.0;
	printf("Digite a temperatura do 1o. dia: ");
	scanf("%f", &t);
	media += t;
	printf("Digite a temperatura do 2o. dia: ");
	scanf("%f", &t);
	media += t;
	printf("Digite a temperatura do 3o. dia: ");
	scanf("%f", &t);
	media += t;
	printf("Digite a temperatura do 4o. dia: ");
	scanf("%f", &t);
	media += t;
	printf("Digite a temperatura do 5o. dia: ");
	scanf("%f", &t);
	media += t;
	printf("Digite a temperatura do 6o. dia: ");
	scanf("%f", &t);
	media += t;
	printf("Digite a temperatura do 7o. dia: ");
	scanf("%f", &t);
	media += t;
	*/

	int dias;
	printf("Qual o numero de dias a serem monitorados? ");
	scanf("%d", &dias);

	int contador, medida;
	float media_dia;

	for (contador=1, media=0.0; contador<=dias; ++contador) {
		// for (medida=1, media_dia=0.0; medida<=MEDIDAS; ++medida) {
		medida = 1, media_dia = 0.0;
		while (medida <= MEDIDAS) {
			do {
				printf("Digite a %da. medida de temperatura do %do. dia: ", medida, contador);
				scanf("%f", &t);
			} while (t < -20 || t > 50);
			media_dia += t;
			++medida;
		}
		media_dia /= MEDIDAS;
		media += media_dia;
	}
	media /= dias; // media = media / dias;

	printf("A media do periodo foi %.1f.\n", media);

	return 0;
}

