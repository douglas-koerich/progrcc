#include <stdlib.h>
#include <stdio.h>
#include <string.h>
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

    /***
     * ESCRITA DO ARQUIVO
     ***/

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

    /***
     * LEITURA DO ARQUIVO
     ***/

    arquivo = fopen("/tmp/fichas.bin", "rb");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo de fichas dos pacientes");
        return EXIT_FAILURE;
    }

    char nome_mais_pesada[TAM_NOME];
    float maior_peso = 0.0;

    while (!feof(arquivo)) {
        if (fread(&fulano, sizeof(Paciente), 1, arquivo) < 1) {
            if (ferror(arquivo)) {
                perror("Erro ao ler o arquivo de fichas dos pacientes");
                fclose(arquivo);
                return EXIT_FAILURE;
            }
        } else {
            if (fulano.peso > maior_peso) {
                maior_peso = fulano.peso;
                strcpy(nome_mais_pesada, fulano.nome);
            }
            float peso_ideal = calcula_peso_ideal(fulano.sexo, fulano.altura);
            if (fulano.peso > peso_ideal) {
                printf("%s, %u, acima do peso ideal\n", fulano.nome, fulano.idade);
            } else if (fulano.peso < peso_ideal) {
                printf("%s precisa adquirir %.1f kg para atingir o peso ideal\n",
                       fulano.nome, peso_ideal - fulano.peso);
            }
        }
    }

    fclose(arquivo);

    printf("O(A) paciente mais pesado(a) eh %s\n", nome_mais_pesada);

    return EXIT_SUCCESS;
}

float calcula_peso_ideal(char sexo, float altura) {
    switch (toupper(sexo)) {
        case 'M':
            return 72.7 * altura - 58;

        case 'F':
            return 62.1 * altura - 44.7;
    }
    return 0;
}

