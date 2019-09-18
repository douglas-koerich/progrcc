#include <stdbool.h>    // definicao de bool
#include <stdlib.h>     // definicao de EXIT_SUCCESS, etc.
#include <stdio.h>      // prototipos de print(), scanf(), puts()
#include <math.h>       // prototipos de log10(), pow()

bool palindromo(unsigned); // prototipo (declaracao) da funcao

int main(void) {
    unsigned numero;
    printf("Digite um numero inteiro positivo: ");
    scanf("%u", &numero);

    bool eh_palindromo = palindromo(numero);
    if (eh_palindromo == true) {
        puts("O numero eh palindromo!");
    } else {
        puts("NAO eh palindromo!!!");
    }
    return EXIT_SUCCESS;
}

bool palindromo(unsigned N) {
    unsigned num_digitos = log10(N) + 1; // v. exercicio 4 da lista 1...
    unsigned pos_esq, pos_dir;
    for (pos_esq = 1, pos_dir = num_digitos; // percorre N a partir dos extremos
         pos_esq < pos_dir; // repete enquanto nao se cruzam no meio
         ++pos_esq, --pos_dir) // caminha com as posicoes em direcao ao centro
    {
        unsigned digito_esq, digito_dir;

        /* Se fosse pra extrair apenas os digitos menos significativo (LSD)
         * e o mais significativo (MSD), teriamos novamente o exercicio 4
         * da lista 1 como referencia:
         */
        digito_esq = N / pow(10, num_digitos-1);
        digito_dir = N % 10;

        if (digito_esq != digito_dir) {
            return false; // sao diferentes nas posicoes equidistantes de N
        }

        // Para o passo seguinte do laco, "descarta" esses digitos :-)
        N -= digito_esq * pow(10, num_digitos-1); // remove digito da esquerda
        N /= 10; // remove digito da direita
        num_digitos -= 2; // menos 2 digitos a considerar
    }
    return true;
}

