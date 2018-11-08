#include <stdlib.h>
#include <stdio.h>
#include "EDEL11.3.h"

int main(void) {
    struct externa var_ext;

    // Letra a: "preencha cada um dos campos por leitura"
    printf("Digite o valor de 'campo_string': ");
    gets(var_ext.campo_string);

    printf("Digite o primeiro dos inteiros de 'campo_inteiros': ");
    scanf("%d", &var_ext.campo_inteiros.i1);
    printf("Segundo inteiro: ");
    scanf("%d", &var_ext.campo_inteiros.i2);
    printf("Terceiro: ");
    scanf("%d", &var_ext.campo_inteiros.i3);

    // Grava o registro no arquivo texto
    FILE* arqtexto = fopen("/tmp/EDEL11_3.txt", "wt");
    if (arqtexto == 0) {
        perror("Nao foi possivel criar o arquivo texto");
        return EXIT_FAILURE;
    }
    // A presenca dos campos inteiros (binarios) exige o uso de escrita
    // formatada (fprintf) no arquivo
    fprintf(arqtexto, "%s;", var_ext.campo_string);
    fprintf(arqtexto, "%d;%d;%d", var_ext.campo_inteiros.i1, var_ext.campo_inteiros.i2,
            var_ext.campo_inteiros.i3);
    fclose(arqtexto);

    // Grava o registro no arquivo binario
    FILE* arqbinario = fopen("/tmp/EDEL11_3.bin", "wb");
    if (arqbinario == 0) {
        perror("Nao foi possivel criar o arquivo binario");
        return EXIT_FAILURE;
    }
    fwrite(&var_ext, sizeof(struct externa), 1, arqbinario); // 1 = num. de estruturas
    fclose(arqbinario);

    struct externa recupera;
    arqbinario = fopen("/tmp/EDEL11_3.bin", "rb");
    if (arqbinario == 0) {
        perror("Nao foi possivel abrir o arquivo binario");
        return EXIT_FAILURE;
    }
    fread(&recupera, sizeof(recupera), 1, arqbinario);
    fclose(arqbinario);

    // Letra b: Imprime o conteudo do registro
    puts("CONTEUDO DO REGISTRO:");
    printf("String: %s\n", recupera.campo_string);
    printf("Int #1: %d\n", recupera.campo_inteiros.i1);
    printf("Int #2: %d\n", recupera.campo_inteiros.i2);
    printf("Int #3: %d\n", recupera.campo_inteiros.i3);

    arqtexto = fopen("/tmp/EDEL11_3.txt", "rt");
    if (arqtexto == 0) {
        perror("Nao foi possivel abrir o arquivo texto");
        return EXIT_FAILURE;
    }
    struct externa rec2;
    /* Isto NAO funciona porque tudo serah visto como parte da string (primeiro campo),
     * afinal, o arquivo eh uma grande string (texto)
    fscanf(arqtexto, "%s;%d;%d;%d", rec2.campo_string,
           &rec2.campo_inteiros.i1, &rec2.campo_inteiros.i2, &rec2.campo_inteiros.i3);
    */
    // Eh necessario delimitar o conjunto de caracteres validos para o campo string inicial
    fscanf(arqtexto, "%[A-Za-z0-9];%d;%d;%d", rec2.campo_string,
           &rec2.campo_inteiros.i1, &rec2.campo_inteiros.i2, &rec2.campo_inteiros.i3);
    fclose(arqtexto);

    puts("CONTEUDO DO REGISTRO:");
    printf("String: %s\n", rec2.campo_string);
    printf("Int #1: %d\n", rec2.campo_inteiros.i1);
    printf("Int #2: %d\n", rec2.campo_inteiros.i2);
    printf("Int #3: %d\n", rec2.campo_inteiros.i3);

    return EXIT_SUCCESS;
}

