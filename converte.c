/* Escreva uma funcao que converte uma temperatura dada em Celsius para
 * Fahrenheit e Kelvin. Entao, chame essa funcao de um programa que imprime
 * uma tabela de temperaturas variando de -20 a +20 graus Celsius.
 */

#include <stdio.h>

// Como uma funcao nao consegue devolver dois valores de uma soh vez atraves
// de um return, a devolucao deve ser feita escrevendo numa posicao de memoria
// fornecida para a funcao (onde ela deve escrever os valores)
void converte(float, float*, float*);

int main() {
    float celsius, kelvin, fahrenheit;
    puts("### TABELA DE TEMPERATURAS ###");
    puts("Celsius Kelvin Fahrenheit");
    for (celsius = -20.0; celsius <= 20.0; ++celsius) {
        converte(celsius, &kelvin, &fahrenheit);    // funcao preenche os valores
                                                    // nos enderecos fornecidos
        printf("%7.1f %6.1f %10.1f\n", celsius, kelvin, fahrenheit);
    }
    return 0;
}

void converte(float c, float* k, float* f) {
    *k = c + 273.0;
    *f = 9*c/5 + 32;
}

