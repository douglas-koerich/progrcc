#include <stdlib.h>
#include <stdio.h>

// O numero de jogos diferentes na mega-sena eh a combinacao de 60 numeros em
// grupos de 6 valores, ou seja, eh a velha amiga analise combinatoria

// Um prototipo eh uma "declaracao" da funcao como se faz com uma variavel
double fatorial(int);
int combinacao(double, double, double);

int main() {
    int n, p, C;
    printf("Quantos numeros tem o jogo no total? ");
    scanf("%d", &n);
    printf("Qual eh o tamanho do grupo formado? ");
    scanf("%d", &p);

    double fat_n, fat_p, fat_n_menos_p;
    fat_n = fatorial(n);
    fat_p = fatorial(p);
    fat_n_menos_p = fatorial(n-p);  // como argumento eh valido o resultado de uma expressao (como n-p)

    C = combinacao(fat_n, fat_p, fat_n_menos_p);
    printf("O numero de combinacoes eh %d.\n", C);

    return EXIT_SUCCESS;
}

// "Definicao" da funcao
int combinacao(double fat_n, double fat_p, double fat_n_menos_p) {
    int C;
    C = fat_n / (fat_p * fat_n_menos_p);
    return C;
}

double fatorial(int n) {    // o parametro 'n' aqui eh outra variavel diferente de 'n' da main()
    double fat_n;           // variaveis locais da funcao
    int i;
    for (fat_n = 1.0, i = 1; i <= n; ++i) {
        fat_n *= i;
    }
    return fat_n;
}
