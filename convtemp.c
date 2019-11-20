#include <stdlib.h>
#include <stdio.h>

float c2k(float);
float c2f(float);

void c2kf(float, float*, float*); // passa enderecos de variaveis que podem
                                  // ser assim alteradas pela funcao c2kf

int main(int argc, char* argv[]) {
    if (argc < 2) {
        puts("Numero insuficiente de parametros");
        printf("Uso: %s <celsius>\n", argv[0]);
        return EXIT_FAILURE;
    }
    float celsius = atof(argv[1]); // converte string (com PONTO decimal, se
                                   // houver) para um numero real

    float kelvin, fahrenheit;

    /*
    kelvin = c2k(celsius);
    fahrenheit = c2f(celsius);
    */
    c2kf(celsius, &kelvin, &fahrenheit); // c2kf pode alterar kelvin e fahrenheit

    printf("Kelvin = %.1f\n", kelvin);
    printf("Fahrenheit = %.1f\n", fahrenheit);

    return EXIT_SUCCESS;
}

float c2k(float c) {
    float k = c + 273;
    return k;
}

float c2f(float c) {
    float f = 9 * c / 5 + 32;
    return f;
}

void c2kf(float c, float* k, float* f) {
    *k = c + 273; // o conteudo (*) no endereco (k) recebe a soma
    *f = 9 * c / 5 + 32;
    // nao eh mais necessario (nem pode, pois eh void) retornar valores; jah
    // "retornam" em seus enderecos cujos conteudos foram alterados
}

