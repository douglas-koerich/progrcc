#include <stdlib.h>
#include <stdio.h>

float conv_k(float);
float conv_f(float);
void conv_kf(float, float*, float*);

int main(void) {
    float celsius;
    printf("%10s %10s %10s\n", "Celsius", "Kelvin", "Fahrenheit");
    for (celsius = -50.0; celsius <= +50.0; ++celsius) {
        float kelvin, fahrenheit;
        /*
        kelvin = conv_k(celsius);
        fahrenheit = conv_f(celsius);
        */
        conv_kf(celsius, &kelvin, &fahrenheit); // passa os enderecos para alterar o conteudo
        printf("%10.1f %10.1f %10.1f\n", celsius, kelvin, fahrenheit);
    }
    return EXIT_SUCCESS;
}

float conv_k(float c) {
    float k = c + 273;
    return k;
}

float conv_f(float c) {
    float f = 9 * c / 5 + 32;
    return f;
}

void conv_kf(float c, float* pk, float* pf) {
    *pk = c + 273;
    *pf = 9 * c / 5 + 32;
}

