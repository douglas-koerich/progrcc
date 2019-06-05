#include <stdlib.h>
#include <stdio.h>

int main(void) {
    int i;  // declaracao de uma variavel do tipo inteiro
    int* p; // declaracao de um ponteior para um inteiro

    char *pc, c; // declaracao de um ponteiro para um caractere
                 // e (CUIDADO!) de uma variavel do tipo char
    
    float *pf1, *pf2; // dois ponteiros declarados para float's
    
    printf("Digite o valor de i: ");
    scanf("%d", &i);
    printf("Digite o caractere para armazenar em c: ");
    scanf(" %c", &c);

    p = &i; // o & eh o operador de enderecamento
    pc = &c; // armazena em pc o endereco da variavel c

    int* pi = &i; // inicializacao com o endereco de uma variavel
    int* pi2 = pi; // copia o endereco salvo em outro ponteiro
    int* pi3 = NULL; // ponteiro zerado (INVALIDO)

    // Eh possivel armazenar o endereco de um ponteiro (jah que
    // ele tambem eh uma variavel) --> ponteiro para ponteiro
    int** pp = &pi; // agora sim, existe o & antes do ponteiro

    /* Nos casos a seguir as posicoes de memoria seriam vistas
     * com valores diferentes dos originais, dependendo de como
     * sao vistas pelos respectivos tipos de ponteiros
     * p = &c;
     * pc = &i;
     */

    printf("Voce armazenou %d na variavel i e %c em c\n", i, c);
    printf("A variavel i estah no endereco %p\n", p); // pi, pi2
    printf("c estah em %p\n", &c);
    
    printf("Agora, imprimindo com os ponteiros: i=%d, c=%c\n", *p, *pc);

    return EXIT_SUCCESS;
}

