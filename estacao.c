#include <stdlib.h>
#include <stdio.h>
#include <stdio_ext.h> // somente Linux (__fpurge)
#include <time.h>
#include "estacao.h"

int main(void) {
    estacao estacoes[NUM_ESTACOES];

    // Ao inves de ler os valores de temperatura, vamos gerar randomicamente
    // dentro de uma faixa limitada de inteiros
    srand((unsigned) time(NULL));

    printf("Digite a data de hoje (d/m/aaaa): ");
    int d, m, a;
    scanf("%d/%d/%d", &d, &m, &a);

    int e, h;
    for (e = 0; e < NUM_ESTACOES; ++e) {
        estacoes[e].quando.dia = d;
        estacoes[e].quando.mes = m;
        estacoes[e].quando.ano = a;

        printf("Nome da estacao #%d? ", e + 1);
        __fpurge(stdin); // Linux (em Windows: fflush(stdin))
        gets(estacoes[e].nome);

        // "Leitura" das temperaturas
        for (h = 0; h < NUM_MEDICOES; ++h) {
            // Gera valor entre 15 e 20 graus
            estacoes[e].medicoes[h] = rand() % 6 + 15;
            printf("%d ", estacoes[e].medicoes[h]);
        }
        putchar('\n');
    }

    FILE* texto = fopen("/tmp/medidas.txt", "w");
    FILE* binario = fopen("/tmp/medidas.bin", "wb"); 
    if (texto == NULL || binario == NULL) {
        perror("Erro na criacao do arquivo de medidas");
        return EXIT_FAILURE;
    }
    fprintf(texto, "%02d/%02d/%04d\n", d, m, a);
    for (e = 0; e < NUM_ESTACOES; ++e) {
        fprintf(texto, "%s", estacoes[e].nome);
        for (h = 0; h < NUM_MEDICOES; ++h) {
            fprintf(texto, ";%d", estacoes[e].medicoes[h]);
        }
        fputc('\n', texto);

        // Uma estrutura por vez no arquivo binario
        // fwrite(&estacoes[e], sizeof(estacao), 1, binario);
    }
    fclose(texto);

    // Todas as estruturas de uma vez no arquivo binario
    fwrite(estacoes, sizeof(estacao), NUM_ESTACOES, binario);
    fclose(binario);

    return EXIT_SUCCESS;
}

