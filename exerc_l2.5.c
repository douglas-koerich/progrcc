#include <stdlib.h>
#include <stdio.h>

int main() {
    float salario_base;
    unsigned tempo_trabalho;

    printf("Digite o salario-base do(a) funcionario(a): ");
    scanf("%f", &salario_base);
    printf("Informe o numero de anos trabalhados na empresa: ");
    scanf("%u", &tempo_trabalho);

    float bonus;

    if (salario_base <= 400.0) {
        // Bloco de codigo do resultado 'verdadeiro'
        bonus = salario_base * 0.15;
    } else {
        // Bloco de codigo do resultado 'falso' (para o teste acima)
        if (400.0 < salario_base && salario_base <= 1000.0) {
            bonus = salario_base * 0.12;
        } else {    // sempre do 'if' mais proximo!
            bonus = salario_base * 0.05;
        }
    }

    /* ISSO EH VALIDO MAS POUCO RECOMENDAVEL
    if (salario_base <= 400.0)
        bonus = salario_base * 0.15;
        // uma linha aqui sem chaves faria o compilador reportar um erro
        // porque o if() acima se tornaria "simples" e o else abaixo nao
        // teria mais o seu if() correspondente
    else if (400.0 < salario_base && salario_base <= 1000.0)
        bonus = salario_base * 0.12;
    else
        bonus = salario_base * 0.05;
    */

    float extra = 0.0;

    // Estrutura de decisao simples (apenas o caso verdadeiro)
    if (tempo_trabalho >= 3) {
        extra = salario_base * 0.1; // extra = salario_base*10/100;
    }
    float salario_final;
    salario_final = salario_base + bonus + extra;

    printf("O salario final serah R$ %.2f.\n", salario_final);

    return EXIT_SUCCESS;
}

