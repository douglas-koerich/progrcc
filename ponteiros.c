#include <stdlib.h>
#include <stdio.h>

int main(void) {
    int* pend = NULL;
    unsigned char* porta_serial_COM1 = 0x3F8; // somente possivel para enderecos conhecidos de HW

    printf("O endereco inicial apontado por 'pend' eh %p (%u).\n", pend, pend);
    printf("O endereco armazenado em 'porta_serial_COM1' eh %p.\n", porta_serial_COM1);

    int x = 35;
    printf("O valor na variavel 'x' eh %d.\n", x);
    pend = &x;  // armazena em 'pend' o ENDERECO de 'x' (nao o valor 35!)
    printf("O novo endereco apontado por 'pend' eh %p (%u).\n", pend, pend);

    printf("Digite um novo valor para a variavel 'x': ");
    // scanf("%d", &x);
    scanf("%d", pend);
    printf("O novo valor de 'x' eh %d.\n", x);
    printf("Repetindo: o novo valor eh %d.\n", *pend);  // recupera o conteudo NO ENDERECO armazenado em 'pend'

    // Bugs possiveis:
    x = 10;
    // pend = x;   // Erro 1: esquecimento do &
    // pend = *x;  // Erro 2: operador incorreto
    pend = &x;
    printf("Novo 'x': ");
    // scanf("%d", &pend); // Erro 3: operador incorreto (desnecessario)
    // scanf("%d", *pend); // Erro 4: operador incorreto (idem)
    scanf("%d", pend);
    printf("'x' agora eh %d.\n", *pend); // Nao ter um operador ou usar & apenas imprimiria numeros "absurdos" (os enderecos!)

    char c = 'a';
    char* pc = &c;
    printf("O caractere %c estah no endereco %p.\n", *pc, pc);

    return EXIT_SUCCESS;
}

