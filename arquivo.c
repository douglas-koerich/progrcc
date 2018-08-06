#include <stdlib.h>
#include <stdio.h>  // para printf e scanf, e agora tambem para as funcoes fxxx
#include <ctype.h>  // isgraph

int main(void) {
    /*
    // Cria e escreve num novo arquivo-texto
    FILE* texto = fopen("/tmp/arquivo.txt", "w"); // cria (w) o arquivo "arquivo.txt" no diretorio /tmp
    if (!texto) {   // recebeu um "token" invalido do sistema operacional
        perror("Erro ao criar o arquivo-texto");    // imprime a razao da falha na operacao
        return EXIT_FAILURE;
    }
    char simbolo;
    do {
        printf("Digite um simbolo grafico da tabela ASCII (* para terminar): ");
        scanf(" %c", &simbolo);
        if (isgraph(simbolo)) {
            if (fputc(simbolo, texto) == EOF) {
                perror("Erro ao escrever no arquivo-texto");
                break;  // para de pedir novos simbolos (interrompe o laco)
            }
        }
    } while (simbolo != '*');
    fclose(texto);

    // Agora, abre e le um arquivo-texto jah existente
    texto = fopen("/tmp/outro.txt", "r");   // arquivo tem que existir para ser aberto para leitura
    if (!texto) {
        perror("Erro ao abrir o outro arquivo");
        return EXIT_FAILURE;
    }
    while (!feof(texto)) {  // enquanto nao encontra/le a marca de fim de arquivo
        simbolo = fgetc(texto);
        if (simbolo == EOF) {   // leitura "invalida"?
            if (ferror(texto)) {    // nao leu a marca de fim (EOF), e sim houve um erro de fato
                perror("Nao pude ler o outro arquivo");
                break;
            }
            else {
                // Nao faz nada, porque foi feita a leitura da marca de fim
            }
        }
        else {  // leitura valida, vou imprimir na tela o que eu li do arquivo
            printf("%c", simbolo);
        }
    }
    printf("\n");   // para nao misturar com o prompt do terminal na saida do programa
    fclose(texto);
    */

    // Gerando um arquivo binario
    FILE* binario = fopen("arquivo.bin", "wb");
    if (!binario) {
        perror("Erro ao criar arquivo-binario");
        return EXIT_FAILURE;
    }
    unsigned char byte;
    unsigned short num;
    do {
        printf("Digite um numero entre 0 e 255 (capacidade numerica do byte): ");
        scanf("%hu", &num);
        if (num <= 0xFF) {
            byte = num;
            if (fputc(byte, binario) == EOF) {
                perror("Erro ao escrever no arquivo-binario");
                break;
            }
        }
    } while (num <= 255);
    fclose(binario);

    // Lendo desse mesmo arquivo binario
    binario = fopen("arquivo.bin", "rb");
    if (!binario) {
        perror("Erro ao ler arquivo-binario");
        return EXIT_FAILURE;
    }
    while (!feof(binario)) {
        byte = fgetc(binario);
        if (byte == EOF) {   // leitura "invalida"?
            if (ferror(binario)) {    // nao leu a marca de fim (EOF), e sim houve um erro de fato
                perror("Nao pude ler o arquivo-binario");
                break;
            }
        }
        else {
            printf("%#x ", byte);
        }
    }
    printf("\n");
    fclose(binario);

    return EXIT_SUCCESS;
}

/** EXERCICIO DE FIXACAO DOS CONTEUDOS: Operadores binarios e funcoes de arquivos
 * Escreva um programa em linguagem C que, lendo pares de bytes digitados na forma
 * hexadecimal pelo usuario (use scanf() com %x), grave esse par de bytes num arquivo
 * mesclando os bits da seguinte maneira:
 * Bits de ordem par (0, 2, 4 e 6) do primeiro byte sao agrupados com os bits de
 * ordem impar (1, 3, 5, 7) do segundo byte e o byte resultante eh gravado no arquivo
 * A gravacao do segundo byte no arquivo faz a mesclagem complementar (bits de ordem
 * impar do primeiro byte com os de ordem par do segundo byte);
 * Na leitura desse arquivo, os bytes originais devem ser recuperados (desfazendo a
 * mesclagem) e impressos na tela.
 **/
