#include <stdlib.h>
#include <stdio.h>

// "Declaracao" da funcao - prototipo em C
double calcula_fatorial(double);

int main() {
    double total, conjunto, combinacoes;

    printf("Digite o numero total de valores a escolher: ");
    scanf("%lf", &total);
    printf("Digite o tamanho de um conjunto de escolha: ");
    scanf("%lf", &conjunto);

    // combinacoes = total! / ((total-conjunto)! * conjunto!)

    /*
    double diferenca = total - conjunto;
    double fatorial_diferenca = 1.0;
    while (diferenca >= 1.0) {
        fatorial_diferenca *= diferenca--;
    }

    double fatorial_total = 1.0;
    while (total >= 1.0) {
        // fatorial_total *= total;
        // --total;
        fatorial_total *= total--;
    }

    double fatorial_conjunto = 1.0;
    while (conjunto >= 1.0) {
        fatorial_conjunto *= conjunto--;
    }
    */
    double fatorial_total, fatorial_diferenca, fatorial_conjunto;

    // As linhas abaixo sao CHAMADAS da funcao calcula_fatorial
    fatorial_total = calcula_fatorial(total);   // cada variavel recebe o retorno/resultado da funcao
    fatorial_conjunto = calcula_fatorial(conjunto);
    fatorial_diferenca = calcula_fatorial(total-conjunto);

    combinacoes = fatorial_total / (fatorial_diferenca * fatorial_conjunto);

    printf("A sua chance de acertar uma combinacao eh de 1 em %.0lf.\n", combinacoes);

    return EXIT_SUCCESS;
}

double calcula_fatorial(double numero) {
    double fatorial = 1.0;  // variavel LOCAL da funcao (existe APENAS dentro dela)
    while (numero >= 1.0) {
        fatorial *= numero--;
    }
    return fatorial;    // devolve/retorna/produz o resultado que estah na variavel local
}

