#include <stdlib.h>
#include <stdio.h>

#define NUM_QUESTOES 5

int main(void) {
    char gabarito[NUM_QUESTOES] = { 'd', 'e', 'a', 'a', 'b' };
    char* pc;

    pc = &gabarito[1];
    printf("Q2 = %c@%p\n", *pc, pc);

    /*
    pc = &gabarito[2];
    */
    ++pc;
    printf("Q3 = %c@%p\n", *pc, pc);

    pc -= 2; // &gabarito[0];
    printf("Q1 = %c@%p\n", *pc, pc);

    int gabarito_n[NUM_QUESTOES] = { 4, 5, 1, 1, 2 };
    int* pi;

    pi = &gabarito_n[1];
    printf("Q2 = %d@%p\n", *pi, pi);

    /*
    pi = &gabarito_n[2];
    */
    ++pi;
    printf("Q3 = %d@%p\n", *pi, pi);

    pi -= 2; // &gabarito_n[0];
    printf("Q1 = %d@%p\n", *pi, pi);

    return EXIT_SUCCESS;
}

