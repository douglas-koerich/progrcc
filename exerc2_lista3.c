#include <stdlib.h>
#include <stdio.h>

int main() {
    unsigned num, menor, maior;
    float soma = 0.0, media;
    int cont;
    const int NUM_VALORES = 5; // declaracao de uma variavel com valor inicial
                               // imutavel (uma variavel "constante")

    // para cont de 1 ateh NUM_VALORES faca
    for (cont = 1; cont <= NUM_VALORES; ++cont) {
        printf("Digite o (proximo) numero: ");
        scanf("%u", &num);

        if (num == 0) {
            // EXTRA: Comando para interrupcao FORCADA do laco
            break; // interrompe e sai do laco para a PROXIMA operacao
        }

        if (cont == 1) {
            menor = maior = num; // ambas recebem o valor de num
        } else {
            if (num > maior) {
                maior = num;    // "lembra" qual foi o maior ateh agora
            }
            if (num < menor) {
                menor = num;    // "lembra" qual foi o menor ateh agora
            }
        }
        soma += num;
    }

    media = soma / NUM_VALORES;

    printf("Maior numero: %u\n", maior);
    printf("Menor numero: %u\n", menor);
    printf("Media dos numeros: %f\n", media);

    return EXIT_SUCCESS;
}

