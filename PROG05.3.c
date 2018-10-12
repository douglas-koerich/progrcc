#include <stdlib.h>
#include <stdio.h>

int main(void) {
    int m, n;
    printf("Qual o tamanho do vetor? ");
    scanf("%d", &n);

    // O vetor pode agora ser declarado com tamanho relativo
    // a escolha do usuario (valor de n)
    int v[n];

    int i;
    for (i=0; i<n; ++i) {
        printf("Digite o %do. elemento do vetor: ", i+1);
        scanf("%d", &v[i]);
    }

    printf("Antes do deslocamento: ");
    for (i=0; i<n; ++i) {
        printf("%d ", v[i]);
    }

    printf("\nQuantos deslocamentos a fazer no vetor? ");
    scanf("%d", &m);

    int rot;
    // Repete o "escravos de joh, jogavam..." m vezes
    for (rot=1; rot<=m; ++rot) {
        // Salva o primeiro elemento
        int primeiro = v[0];

        // A partir do segundo, move para a posicao anterior
        for (i=1; i<n; ++i) {
            v[i-1] = v[i];
        }
        // Recupera o primeiro elemento para a ultima posicao
        v[n-1] = primeiro;
    }

    printf("Depois do deslocamento: ");
    for (i=0; i<n; ++i) {
        printf("%d ", v[i]);
    }
    putchar('\n');

    return EXIT_SUCCESS;
}

