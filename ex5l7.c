#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#ifdef __unix__ // se estiver executando em UNIX/Linux
#include <stdio_ext.h>
#endif
#include "ex5l7.h" // para conhecer o novo tipo

int main(void) {
    size_t pacientes;
    printf("Digite o numero de pacientes: ");
    scanf("%zu", &pacientes);

    Paciente fulano;
    int i;

    FILE* arquivo = fopen("/tmp/fichas.bin", "wb");
    if (arquivo == NULL) {
        perror("Erro ao criar o arquivo de fichas dos pacientes");
        return EXIT_FAILURE;
    }

    for (i = 1; i <= pacientes; ++i) {
        printf(">>> DADOS DO(A) PACIENTE N.%d <<<\n", i);
#ifdef __unix__
        __fpurge(stdin); // para limpar o teclado em UNIX/Linux
#else // Windows
        fflush(stdin); // para limpar o teclado em Windows
#endif
        printf("Nome? "); gets(fulano.nome);
        printf("Idade? "); scanf("%u", &fulano.idade);
        do {
            printf("Sexo (M/F)? "); scanf(" %c", &fulano.sexo);
            fulano.sexo = toupper(fulano.sexo);
        } while (fulano.sexo != 'M' && fulano.sexo != 'F');
        printf("Peso? "); scanf("%f", &fulano.peso);
        printf("Altura? "); scanf("%f", &fulano.altura);

        fwrite(&fulano, sizeof(Paciente), 1, arquivo);
    }

    fclose(arquivo);

    return EXIT_SUCCESS;
}

