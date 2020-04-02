#include <stdlib.h>
#include <stdio.h>

int main() {

    int contador;

    unsigned acumulador = 0; // inicializa com o elemento neutro da soma
    unsigned menor, maior;

    // while (contador <= 5) {
    for (contador = 1; contador <= 5; ++contador) {
        unsigned int numero;

        printf("Digite o proximo numero, ou 0 para interromper: ");
        scanf("%d", &numero);

        if (numero == 0) {
            break; // interrompe a execucao do passo e sai do laco
                   // (mesmo assim o ++contador lah em cima eh executado)
        }

        if (contador == 1) { // eh a primeira passagem do laco?
            menor = maior = numero; // inicia a "memoria" do menor/maior
        } else {
            if (numero < menor) {
                menor = numero;
            }
            if (numero > maior) {
                maior = numero;
            }
        }

        /*
        //contador = contador + 1;
        //contador += 1;
        ++contador; // contador++;
        */

        acumulador += numero;
    }

    /*
    float media = acumulador / 5.0; // forca a constante ser real para a divisao
                                    // ser real tambem (e NAO inteira)
    */
    // Com a introducao do 'break' no laco, a media tem que ser calculada com
    // base no contador; mas como a contagem considerou a digitacao do '0', que
    // foi usado soh pra interromper o laco, vamos usar o valor do contador-1
    float media = (float) acumulador / (contador-1); // a variavel 'acumulador' eh
                                                     // usada na expressao como se
                                                     // fosse um 'float'

    printf("O maior valor digitado foi %u, o menor foi %u e a media eh %.2f\n",
           maior, menor, media);
    
    return EXIT_SUCCESS;
}

