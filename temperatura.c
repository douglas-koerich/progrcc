#include <stdio.h>

/*
float converteKelvin(float);
float converteFahrenheit(float);
*/
void converte(float, float*, float*);

int main() {
	float celsius, kelvin, fahrenheit;

	printf("Digite a temperatura (oC): ");
	scanf("%f", &celsius);

	/*
	kelvin = converteKelvin(celsius);
	fahrenheit = converteFahrenheit(celsius);
	*/
	converte(celsius, &kelvin, &fahrenheit);

	printf("Conversao: %.1f oF, %.1f K.\n", fahrenheit, kelvin);
	return 0;
}

/*
float converteKelvin(float celsius) {
	return celsius + 273;
}

float converteFahrenheit(float celsius) {
	int fah;
	fah = 9*celsius/5 + 32;
	return fah;
}
*/

void converte(float c, float* k, float* f) {
	*k = c + 273;
	*f = 9*c/5 + 32;
	printf("k = %.1f, f = %.1f\n", *k, *f);
}

