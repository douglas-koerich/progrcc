#include <stdlib.h>
#include <stdio.h>

// O exercicio 1 eh um caso de "decomposicao" de um valor em suas
// partes componentes. Um outro caso similar a esse eh a divisao
// de um valor em dinheiro (p.ex., R$ 147,00) em cedulas da moeda
// (uma de 100, duas de 20, uma de 5 e uma de 2).

int main() {
    // Leitura do numero de segundos
    int segundos;
    printf("Quantos segundos se passaram desde a meia-noite? ");
    scanf("%d", &segundos);

    // Variaveis que armazenarao as partes decompostas
    int hrs, min, seg;

    // Calcula quantas "horas inteiras" se passaram no tempo em
    // segundos que foi informado
    hrs = segundos / 3600; // uma "hora inteira" tem 3600 segundos

    // O que nao "entrou como hora cheia" (isto eh, o resto dos
    // segundos totais) vai ser usado pra calcular os "minutos
    // inteiros" (v. a seguir)
    segundos = segundos % 3600; // troca o total pelo resto
                                // Comando alternativo: segundos %= 3600;

    // Calcula quantos "minutos cheios" sobraram das "horas cheias"
    min = segundos / 60; // um "minuto cheio" tem 60 segundos

    // O que restar do calculo anterior, sao os segundos finais
    seg = segundos % 60;

    // Repare nos formatos %... do printf abaixo, que garantem que
    // os valores tenham 2 digitos, com 0 ah esquerda se necessario
    printf("O total informado equivale a %02d:%02d:%02d\n",
           hrs, min, seg); // pode-se dividir o comando em 2+ linhas

    return EXIT_SUCCESS;
}
