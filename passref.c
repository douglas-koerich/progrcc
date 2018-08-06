#include <stdlib.h>
#include <stdio.h>

int menor_valor(int, int, int);
int maior_valor(int, int, int);
void menor_maior_valor(int, int, int, int*, int*);

int main(void) {
    int x, y, z;

    printf("Digite x: ");
    scanf("%d", &x);
    printf("Agora, digite y: ");
    scanf("%d", &y);
    printf("Finalmente, digite z: ");
    scanf("%d", &z);

    /*
    int menor = menor_valor(x, y, z);
    int maior = maior_valor(x, y, z);
    */
    int menor, maior;
    menor_maior_valor(x, y, z, &menor, &maior);

    printf("O menor valor entre os numeros eh %d e o maior eh %d.\n", menor, maior);

    return EXIT_SUCCESS;
}

// Os parametros x, y e z da funcao menor_valor() NAO sao as
// mesmas variaveis de mesmo nome da funcao main()
int menor_valor(int x, int y, int z) {
    if (x < y) {
        if (x < z) {
            return x;
        }
        if (y < z) {
            return y;
        } 
        return z;
    } else {
        if (y < z) {
            return y;
        }
        if (x < z) {
            return x;
        }
        return z;
    }
}

int maior_valor(int x, int y, int z) {
    if (x > y) {
        if (x > z) {
            return x;
        }
        if (y > z) {
            return y;
        } 
        return z;
    } else {
        if (y > z) {
            return y;
        }
        if (x > z) {
            return x;
        }
        return z;
    }
}

void menor_maior_valor(int x, int y, int z, int* pmenor, int* pmaior) {
    *pmenor = menor_valor(x, y, z); // altera o valor na posicao original da
                                    // variavel 'menor' lah da funcao main
    *pmaior = maior_valor(x, y, z);
}


