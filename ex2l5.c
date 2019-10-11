#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define QTDE_VALORES 20

int main(void) {
    int vetor[QTDE_VALORES], i;

    for (i = 0; i < QTDE_VALORES; ++i) { // percorre desde i=0 a i=QTDE_VALORES-1
        printf("Digite um novo valor inteiro (+/-): ");
        scanf("%d", &vetor[i]); // leh para a posicao i do vetor
    }

    int valores_unicos[QTDE_VALORES]; // mesmo tamanho pensando que pode nao haver
                                      // repetidos
    unsigned contadores[QTDE_VALORES] = {}; // conjunto de contadores, um para
                                            // cada valor unico, zerados no inicio
    unsigned n = 0; // vai medir a ocupacao nos vetores acima

    for (i = 0; i < QTDE_VALORES; ++i) {
        int referencia = vetor[i], j;
        bool repetido = false;

        // Procura por ocorrencias que jah foram vistas na porcao jah percorrida
        // do vetor (pra nao considerar o valor mais de uma vez)
        for (j = i-1; j >= 0; --j) { // percorre o vetor no sentido para tras!
            if (vetor[j] == referencia) {
                repetido = true;
                break; // nem precisa continuar, jah sei que eh repetido
            }
        }
        if (repetido == true) {
            continue; // aborta o passo!, vai para o proximo 'i' no 'for' externo
        }

        // Se chego nesta linha entao repetido == false :-)
        // Eh a primeira vez que encontrou o valor, poe no vetor de unicos
        // (OBS: Note que 'n' eh ao mesmo tempo um contador de ocupacao do
        // vetor 'valores_unicos' e o proximo indice livre dentro dele)
        valores_unicos[n] = referencia;
        contadores[n] = 1; // conta a ocorrencia da posicao 'i'

        // Agora, procura novas ocorrencias nas posicoes ah frente
        for (j = i+1; j < QTDE_VALORES; ++j) {
            if (vetor[j] == referencia) {
                ++contadores[n]; // conta essa outra ocorrencia da posicao 'j'
            }
        }
        // Conta essa nova posicao ocupada no vetor 'valores_unicos'
        ++n;
    }

    for (i = 0; i < n; ++i) { // note que **nao eh** i < QTDE_VALORES
        if (contadores[i] > 1) {
            printf("O numero %d ocorre %u vezes no vetor original.\n",
                   valores_unicos[i], contadores[i]);
        }
    }

    return EXIT_SUCCESS;
}

