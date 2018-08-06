#include <stdlib.h>
#include <stdio.h>
#include <stdio_ext.h>
#include <ctype.h>
#include <string.h>
#include "ex5l7.h"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        puts("Numero insuficiente de parametros na linha de comando do programa");
        printf("Use: %s <nome-do-arquivo>\n", argv[0]);
        return EXIT_FAILURE;
    }
    // Crio o arquivo de cadastro, em modo binario pra gravar estruturas
    FILE* arquivo = fopen(argv[1], "wb");
    if (arquivo == NULL) {
        perror("Nao pude criar o arquivo de cadastro");
        return EXIT_FAILURE;
    }
    unsigned num_pacientes;
    printf("Quantos pacientes serao cadastrados? ");
    scanf("%u", &num_pacientes);

    // Cadastro em memoria eh um vetor (a ser salvo depois no arquivo),
    // pode ser alocado estaticamente...
    // struct paciente vetor[num_pacientes];
    // ... ou dinamicamente:
    paciente* vetor = (paciente*) malloc(sizeof(paciente) * num_pacientes);

    unsigned n;
    for (n=0; n<num_pacientes; ++n) {
        printf(">>> Dados do paciente #%u >>>\n", n+1);
        printf("Nome? ");
        __fpurge(stdin);
        gets(vetor[n].nome);
        do {
            printf("Idade? ");
            scanf("%hu", &vetor[n].idade);
        } while (vetor[n].idade > 100);
        do {
            printf("Sexo (M/F)? ");
            __fpurge(stdin);
            vetor[n].sexo = toupper(getchar());
        } while (vetor[n].sexo != 'M' && vetor[n].sexo != 'F');
        do {
            printf("Altura? ");
            scanf("%f", &vetor[n].altura);
        } while (vetor[n].altura < 0.2 || vetor[n].altura > 2.5);
        do {
            printf("Peso? ");
            scanf("%f", &vetor[n].peso);
        } while (vetor[n].peso < 0.5 || vetor[n].peso > 400.0);
    }
    // Vou gravar no arquivo todo o vetor de uma vez!! :-)
    if (fwrite(vetor, sizeof(paciente), num_pacientes, arquivo) < num_pacientes) {
        perror("Nao pude salvar o cadastro no arquivo");
        fclose(arquivo);
        free(vetor);    // nao esqueca da memoria alocada dinamicamente!
        return EXIT_FAILURE;
    }
    fclose(arquivo);

    // Como o enunciado pede, as proximas alteracoes serao a partir da leitura
    // do arquivo, entao posso liberar o vetor alocado dinamicamente!...
    free(vetor);

    // Para a leitura do arquivo, preciso apenas de um registro de rascunho
    paciente rascunho;
    arquivo = fopen(argv[1], "rb");
    if (arquivo == NULL) {
        perror("Nao pude abrir o arquivo de cadastro");
        return EXIT_FAILURE;
    }
    // Ler todo o arquivo (todos os registros)
    float maior_peso = 0.0;
    char nome_mais_pesada[MAX_NOME] = "Anonimo";    // nao sei ainda quem eh
    while (!feof(arquivo)) {
        if (fread(&rascunho, sizeof(paciente), 1, arquivo) < 1) {
            if (ferror(arquivo)) {
                perror("Nao pude ler um registro do arquivo");
                fclose(arquivo);
                return EXIT_FAILURE;
            }
        }
        else {
            if (rascunho.peso > maior_peso) {
                maior_peso = rascunho.peso;
                strcpy(nome_mais_pesada, rascunho.nome);
            }
            float peso_ideal;
            if (rascunho.sexo == 'M') {
                peso_ideal = 72.7 * rascunho.altura - 58;
            }
            else {
                peso_ideal = 62.1 * rascunho.altura - 44.7;
            }
            if (rascunho.peso > peso_ideal) {
                printf("%s estah com %.1f kg, acima do seu peso ideal de %.1f kg\n",
                       rascunho.nome, rascunho.peso, peso_ideal);
            }
            else if (rascunho.peso < peso_ideal) {
                printf("%s precisa conseguir %.1f kg para chegar ao seu peso ideal\n",
                       rascunho.nome, peso_ideal - rascunho.peso);
            }
        }
    }
    printf("A pessoa mais pesada eh %s\n", nome_mais_pesada);
    fclose(arquivo);
    return EXIT_SUCCESS;
}
