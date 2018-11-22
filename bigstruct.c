#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "bigstruct.h"

// Passa estrutura por endereco para funcao; como a funcao
// nao deve alterar o conteudo do registro, define o ponteiro
// como 'const'
void salva_registro(const Big*);
void zera_inteiros(Big*);

int main(void) {
    Big mac;
    strcpy(mac.string, "McDonald's is nice (and fat)!");
    srand((unsigned) time(NULL)); // antes usavamos time(0)
    int i;
    for (i=0; i<NUM_INTS; ++i) {
        mac.vetor_i[i] = rand() % 100000;
    }
    for (i=0; i<NUM_DOUB; ++i) {
        mac.vetor_d[i] = (double) rand() / rand();
    }
    salva_registro(&mac); // passa o endereco do registro
    return EXIT_SUCCESS;
}

void salva_registro(const Big* pb) {
    FILE* arquivo = fopen("/tmp/registro.txt", "w");
    if (arquivo == NULL) { // antes faziamos arquivo == 0 :-)
        perror("Nao foi possivel criar o arquivo");
        return; // sai da funcao aqui
    }
    fprintf(arquivo, "%s\n", (*pb).string);
    int i;
    for (i=0; i<NUM_INTS; ++i) {
        // fprintf(arquivo, "%d ", (*pb).vetor_i[i]);
        fprintf(arquivo, "%d ", pb->vetor_i[i]);
    }
    fputc('\n', arquivo);
    for (i=0; i<NUM_DOUB; ++i) {
        fprintf(arquivo, "%lf ", pb->vetor_d[i]);
    }
    fputc('\n', arquivo);
    fclose(arquivo);
}

void zera_inteiros(Big* pb) {
    int i;
    for (i=0; i<NUM_INTS; ++i) {
        pb->vetor_i[i] = 0;
    }
}

