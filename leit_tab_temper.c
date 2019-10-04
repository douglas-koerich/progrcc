/* Este programa leh o conteudo do arquivo 'c2f.txt' e recupera
 * o valor de cada grau Celsius ("primeira coluna"), imprimindo
 * na tela uma tabela equivalente em Kelvin. */

#include <stdlib.h>
#include <stdio.h>

int main(void) {
    FILE* arqtab = fopen("c2f.txt", "r");
    if (arqtab == 0) {
        perror("Erro ao abrir arquivo");
        return EXIT_FAILURE;
    }
    /***
     * "Cenas dos proximos capitulos..."
     **/
    char cabecalho[1024];
    if (fgets(cabecalho, sizeof(cabecalho), arqtab) == 0) {
        perror("Erro ao ler a linha de cabecalho do arquivo");
        fclose(arqtab);
        return EXIT_FAILURE;
    }
    /***/

    FILE* arqbin = fopen("c2k.dat", "wb");
    if (arqbin == 0) {
        perror("Erro ao criar arquivo binario (Kelvin)");
        fclose(arqtab);
        return EXIT_FAILURE;
    }

    puts("Celsius --> Kelvin");
    float celsius, fahrenheit;
    while (!feof(arqtab)) {
        if (fscanf(arqtab, "%f,%f\n", // eh obrigatorio saber como
                                      // os valores estao separados
                                      // entre si no arquivo
                                      &celsius, &fahrenheit) == EOF) {
            if (ferror(arqtab)) {
                perror("Erro na leitura dos valores do arquivo");
                fclose(arqtab);
                fclose(arqbin);
                return EXIT_FAILURE;
            }
        } else { // nao eh fim nem erro
            float kelvin = celsius + 273;
            printf("C = %.0f <==> K = %.0f\n", celsius, kelvin);

            int c = celsius, // pega a parte inteira de celsius
                k = kelvin;  // idem de kelvin

            // Escreve no arquivo binario. Os parametros sao:
            // 1) origem do valor (a variavel);
            // 2) o tamanho em bytes que o valor ocupa na memoria
            // 3) quantos valores diferentes estao sendo gravados
            // 4) o arquivo de destino
            // O retorno tem que ser a mesma quantidade (3); se for
            // menor (ou zero), houve erro
            if (fwrite(&c, sizeof(int), 1, arqbin) < 1) {
                perror("Erro ao escrever Celsius no arquivo binario");
                fclose(arqtab);
                fclose(arqbin);
                return EXIT_FAILURE;
            }
            if (fwrite(&k, sizeof(k), 1, arqbin) < 1) {
                perror("Erro ao escrever Kelvin no arquivo binario");
                fclose(arqtab);
                fclose(arqbin);
                return EXIT_FAILURE;
            }
        }
    }
    fclose(arqtab);
    fclose(arqbin);

    return EXIT_SUCCESS;
}

