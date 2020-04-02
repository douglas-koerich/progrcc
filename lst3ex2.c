#include <stdlib.h>
#include <stdio.h>

int main() {

    int contador = 1; // inicializa o contador de passagens com a primeira (1)
                      // a ser executada
    unsigned acumulador = 0; // inicializa com o elemento neutro da soma
    unsigned menor, maior;

    while (contador <= 5) {
        unsigned int numero;

        printf("Digite o proximo numero: ");
        scanf("%d", &numero);

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

        //contador = contador + 1;
        //contador += 1;
        ++contador; // contador++;

        acumulador += numero;
    }

    float media = acumulador / 5.0; // forca a constante ser real para a divisao
                                    // ser real tambem (e NAO inteira)

    printf("O maior valor digitado foi %u, o menor foi %u e a media eh %.2f\n",
           maior, menor, media);
    
    return EXIT_SUCCESS;
}

