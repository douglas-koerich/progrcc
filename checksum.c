#include <stdlib.h>
#include <stdio.h>

// typedef cria um "novo tipo" que nada mais eh do que um novo nome para um tipo
// que ja existe
typedef unsigned char byte;

// O valor EOF eh igual a -1; como -1 nao existe numa representacao sem sinal,
// EOF seria equivalente a 255, mas a comparacao b == EOF nao vai resultar em
// verdadeiro porque o EOF comparado eh -1, enquanto o b, mesmo tendo EOF, eh visto
// como 255; entao, temos que "criar" uma variavel (global) do "tipo-byte" com um EOF "sem sinal"
const byte UEOF = 255;

// Vou criar um programa que calcula o checksum de um arquivo qualquer e salva
// esse checksum em outro arquivo
// Na linha de comando do programa devem vir indicados:
// 1) o nome do arquivo que vai ser lido e do qual vou calcular o checksum;
// 2) o nome do arquivo que vai ser criado com esse checksum armazenado.
int main(int numero_argumentos_linha, char* lista_strings_argumentos[]) {
    if (numero_argumentos_linha < 3) {  // nome do programa na linha de comando conta
        puts("Numero insuficiente de argumentos");
        printf("Digite: %s <nome-arq-entrada> <nome-arq-saida>\n",
               lista_strings_argumentos[0]);    // o nome do programa eh o primeiro argumento [0]
        return EXIT_FAILURE;
    }
    // Vou abrir o arquivo considerando-o uma sequencia de codigos binarios, i.e.,
    // sem tentar "traduzir" para o simbolo ASCII correspondente ao valor binario
    // (e eh sempre binario o que esta gravado em qualquer arquivo)
    FILE* arq_entrada = fopen(lista_strings_argumentos[1], "rb");
    if (arq_entrada == NULL) {
        perror("Nao pude abrir o arquivo indicado");
        return EXIT_FAILURE;
    }
    // O checksum nada mais eh do que a soma dos codigos binarios lidos do arquivo
    long checksum = 0;
    while (!feof(arq_entrada)) {
        // Vou usar o novo tipo criado para declarar uma variavel (local) do "tipo-byte"
        byte b; // na pratica, eh um unsigned char...
        b = fgetc(arq_entrada); // note que posso usar fgetc() mesmo para arquivos binarios,
                                // afinal toda informacao gravada em arquivo eh binaria!...
        if (b == UEOF) {        // comparar (b == EOF) resulta falso mesmo se for fim do arquivo :-(
            if (ferror(arq_entrada)) {
                perror("Erro na leitura do arquivo");
                fclose(arq_entrada);
                return EXIT_FAILURE;
            }
        }
        else {
            checksum += b;  // soma ao checksum o valor binario lido do arquivo
                            // (por exemplo, se tivesse lido um A maiusculo, estaria
                            // somando o valor 65 (codigo ASCII de 'A') ao checksum)
            printf("Byte lido: %hhu\n", b);
        }
    }
    // Nao preciso mais do arquivo de entrada (ja li tudo!), posso (e devo) fecha-lo
    fclose(arq_entrada);

    // Vou criar um arquivo texto com o valor do checksum calculado
    FILE* arq_saida = fopen(lista_strings_argumentos[2], "w");
    if (arq_saida == NULL) {
        perror("Nao pude criar o arquivo indicado");
        return EXIT_FAILURE;
    }
    if (fprintf(arq_saida, "%ld\n", checksum) < 0) {
        perror("Nao pude escrever o checksum no arquivo");
        fclose(arq_saida);
        return EXIT_FAILURE;
    }
    fclose(arq_saida);
    return EXIT_SUCCESS;
}
