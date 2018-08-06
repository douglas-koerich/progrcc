#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// Definicao das dimensoes da matriz
#define DIAS_SEMANA 7   // numero de linhas
#define HORAS_DIA   24  // numero de colunas

#define MAX_TEMP    40  // temperatura maxima esperada para Curitiba

int main(void) {
    // Inicializacao do gerador de numeros aleatorios
    srand((unsigned) time(0));  // usa o relogio do PC como semente

    // Matriz 7 x 24 (linhas x colunas) - tabela de temperaturas inteiras
    int temp_cwb[DIAS_SEMANA][HORAS_DIA];

    float media_dia[DIAS_SEMANA];   // 7 medias diarias (media das temperaturas tomadas no dia, em horas diferentes)
    float media_hora[HORAS_DIA];    // 24 medias horarias (media das temperaturas tomadas na hora, em dias diferentes)

    // Preenche os valores da primeira linha da matriz (indice=dia=0)
    int hora;
    for (hora = 0; hora < HORAS_DIA; ++hora) {
        temp_cwb[0][hora] = rand() % (MAX_TEMP+1);  // gera entre 0 e 40
    }
    /* Ao inves de repetir o mesmo algoritmo para os demais dias da semana...
    for (hora = 0; hora < HORAS_DIA; ++hora) {
        temp_cwb[1][hora] = rand() % (MAX_TEMP+1);
    }
    for (hora = 0; hora < HORAS_DIA; ++hora) {
        temp_cwb[2][hora] = rand() % (MAX_TEMP+1);
    }
    ...
    */
    // ... repito o laco 'for' que preenche um dia dentro de um laco externo
    // 'for' (ou 'while')  que repete para cada novo dia da semana
    int dia = 1;    // ja fiz a linha 0 no for anterior, poderia move-lo pra ca...
    while (dia < DIAS_SEMANA) { // a ultima linha eh de indice DIAS_SEMANA-1
        for (hora = 0; hora < HORAS_DIA; ++hora) {
            temp_cwb[dia][hora] = rand() % (MAX_TEMP+1);  // repare o uso de [dia]
        }
        ++dia;
    }

    // Para imprimir as temperaturas aleatorias de Curitiba, vamos usar novamente
    // um par de lacos aninhados que percorrem a matriz
    for (dia = 0; dia < DIAS_SEMANA; ++dia) {
        for (hora = 0; hora < HORAS_DIA; ++hora) {
            printf("%d ", temp_cwb[dia][hora]);
        }
    }

    // Melhorando o aspecto da tabela/matriz na tela...
    printf("\n\n  "); // canto superior esquerdo (vazio)...
    for (hora = 0; hora < HORAS_DIA; ++hora) {
        printf("%2d ", hora);   // numeros das horas sobre a tabela...
    }
    for (dia = 0; dia < DIAS_SEMANA; ++dia) {
        printf("\n%d ", dia);   // numero do dia no lado esquerdo da linha...
        for (hora = 0; hora < HORAS_DIA; ++hora) {
            printf("%2d ", temp_cwb[dia][hora]);
        }
    }
    putchar('\n');  // termina a ultima linha com um salto para a proxima

    // O calculo das medias diarias se faz percorrendo a matriz linha apos linha
    // (dia apos dia), como se faz normalmente
    for (dia = 0; dia < DIAS_SEMANA; ++dia) {
        media_dia[dia] = 0.0;   // inicializa o somatorio desse dia
        for (hora = 0; hora < HORAS_DIA; ++hora) {
            media_dia[dia] += temp_cwb[dia][hora];
        }
        media_dia[dia] /= HORAS_DIA;
    }

    // O calculo das medias horarias se faz percorrendo a matriz coluna por coluna
    // (hora apos hora), analisando cada linha (dia) para uma determinada coluna (hora)
    for (hora = 0; hora < HORAS_DIA; ++hora) {  // repare na inversao da ordem dos lacos!!!
        media_hora[hora] = 0.0; // inicializa o somatorio dessa hora
        for (dia = 0; dia < DIAS_SEMANA; ++dia) {
            media_hora[hora] += temp_cwb[dia][hora];
        }
        media_hora[hora] /= DIAS_SEMANA;
    }

    // Impressao das medias
    printf("Medias das temperaturas, por dia: ");
    for (dia = 0; dia < DIAS_SEMANA; ++dia) {
        printf("%.1f ", media_dia[dia]);
    }
    printf("\nMedias das temperaturas, por hora: ");
    for (hora = 0; hora < HORAS_DIA; ++hora) {
        printf("%.1f ", media_hora[hora]);
    }
    putchar('\n');

    // Versao final da tabela
    printf("\n\n              "); // canto superior esquerdo (vazio)...
    for (hora = 0; hora < HORAS_DIA; ++hora) {
        printf("%4d ", hora);   // numeros das horas sobre a tabela...
    }
    printf("| Media do dia\n");
    for (dia = 0; dia < DIAS_SEMANA; ++dia) {
        printf("%13d ", dia);   // numero do dia no lado esquerdo da linha...
        for (hora = 0; hora < HORAS_DIA; ++hora) {
            printf("%4d ", temp_cwb[dia][hora]);
        }
        // Imprime a media desse dia
        printf("| %3.1f\n", media_dia[dia]);
    }
    printf("Media da hora ");
    for (hora = 0; hora < HORAS_DIA; ++hora) {
        printf("%3.1f ", media_hora[hora]);
    }
    putchar('\n');

    return EXIT_SUCCESS;
}

