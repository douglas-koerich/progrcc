#include <stdio.h>

// Use um identificador associado pra poder alterar somente
// aqui o tamanho do vetor sem ter que alterar em varias partes
// do programa
#define TAMANHO 3

int main() {
    // Declaracao da variavel-vetor
    int y[TAMANHO]; // lembre-se que todos as posicoes tem 'lixo' nesse momento

    printf("Digite um valor: ");
    int v;
    scanf("%d", &v);
    int pos;
    do {
        // Da ao usuario o poder de escolher onde armazenar o valor...
        printf("Digite uma posicao: ");
        scanf("%d", &pos);
    // ... mas como ele pode usar mal esse poder, estourando o limite do vetor,
    // temos que testar
    } while (pos < 0 || pos > TAMANHO-1);

    // Armazena o valor, indexando o vetor (definindo a posicao)
    y[pos] = v;
    printf("y[%d] = %d\n", pos, y[pos]);

    return 0;
}

