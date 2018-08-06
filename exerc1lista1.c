#include <stdlib.h>
#include <stdio.h>

int main() {
    int segundos; // variavel de entrada
    int hrs, min, seg; // variaveis de saida

    printf("Digite o numero total de segundos: ");
    scanf("%d", &segundos); // nao esqueca do &!!!

    hrs = segundos / 3600; // divisao inteira (hora "cheia")
    /*
    segundos = segundos - hrs * 3600; // retira as horas cheias do total
    segundos = segundos % 3600; // resto da divisao tem a hora nao-cheia
    */
    segundos %= 3600; // forma aglutinada do operador % (mesma variavel nos dois lados da atribuicao)
    min = segundos / 60; // mesmo raciocinio, agora p/ obter minutos cheios
    seg = segundos % 60; // resto da nova divisao tem os segundos remanescentes

    printf("Os segundos equivalem a %02d:%02d:%02d\n", hrs, min, seg);

    return EXIT_SUCCESS;
}

