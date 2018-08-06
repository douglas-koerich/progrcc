#include <stdlib.h>
#include <stdio.h>

#define TAMANHO 7   // SEM ponto-e-virgula!!!
#define OUTRO 5

int main(void) {
    int x;          // variavel escalar nao inicializada
    int y = 10;     // variavel escalar inicializada

    x = y;              // atribuicao de valor para a variavel escalar
    printf("Teste: digite y =>");
    scanf("%d", &y);    // leitura de valor para uma variavel escalar

    /* Resumindo: uma variavel tem seu valor modificado por um de tres modos:
     * a) Inicializacao (valor inicial na declaracao)
     * b) Atribuicao (copia de outro valor = )
     * c) Leitura/entrada de dados (valor oriundo do scanf)
     */

    // int lista[7];   // um vetor nao inicializado de numeros inteiros
    int lista[TAMANHO];
    int z = 2;

    // Para atribuir valores ao vetor, deve-se indicar qual elemento vai ser
    // alterado, usando um INDICE
    lista[0] = 10;  // valor do PRIMEIRO elemento do conjunto (0 eh o indice inicial)
    // lista[6] = 20;
    lista[TAMANHO-1] = 20;  // valor do ULTIMO elemento
    // lista[7] = 30;       // CUIDADO!!!! Provavel erro de execucao
    lista[TAMANHO] = 30;    // IDEM!!!

    printf("Digite um valor para a SEGUNDA posicao do vetor: ");
    scanf("%d", &lista[1]);

    int outro[OUTRO] = { 2, 4, 6, 8, 10 };  // vetor inicializado de inteiros
    int mais_um[OUTRO] = { 1, 3, 5 }; // as restantes sao zeradas (valor binario)
    int zerado[OUTRO] = { 0 };  // pelo menos um valor na inicializacao

    // Atencao para os riscos desta forma de inicializar:
    int reservado[] = { 10, 20, 30, 40 };   // vetor tera 4 posicoes apenas!
                                            // usado pra listas de constantes

    // A recuperacao de um valor do vetor eh feita pela mesma indexacao
    z = lista[0];
    /*
    printf("O 1o. valor da lista vale %d\n", lista[0]);
    printf("O 2o. valor da lista vale %d\n", lista[1]);
    printf("O 3o. valor da lista vale %d\n", lista[2]);
    printf("O 4o. valor da lista vale %d\n", lista[3]);
    printf("O 5o. valor da lista vale %d\n", lista[4]);
    printf("O 6o. valor da lista vale %d\n", lista[5]);
    printf("O 7o. valor da lista vale %d\n", lista[6]);
    */
    int posicao;
    for (posicao = 0; posicao < TAMANHO; ++posicao) {
        printf("O %do. valor da lista vale %d\n", posicao+1, lista[posicao]);
    }

    return EXIT_SUCCESS;
}

