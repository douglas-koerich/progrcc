#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int main() {
    printf("Tamanho de short int: %ld bytes\n", sizeof(short int)); // 2
    printf("Tamanho de long long int: %ld bytes\n", sizeof(long long int)); // 8
    printf("Tamanho de unsigned long int: %ld bytes\n", sizeof(unsigned long)); // 8
    printf("Tamanho de unsigned: %ld bytes\n", sizeof(unsigned));   // 4

    printf("Tamanho de float: %ld bytes\n", sizeof(float));
    printf("Tamanho de double: %ld bytes\n", sizeof(double));

    printf("Tamanho de _Bool: %ld bytes\n", sizeof(_Bool));
    printf("Tamanho de bool: %ld bytes\n", sizeof(bool));

    return EXIT_SUCCESS;
}
