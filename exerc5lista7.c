#include <stdlib.h>
#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include <ctype.h>
#include "exerc5lista7.h"
#include "mygets.h"

int main(void) {
    FILE* arquivo = fopen("exerc5.txt", "wt");
    if (arquivo == NULL) {
        perror("Nao foi possivel criar o arquivo");
        return EXIT_FAILURE;
    }
    FILE* planilha = fopen("plan5.txt", "wt");
    if (planilha == NULL) {
        perror("Nao foi possivel criar a planilha");
        return EXIT_FAILURE;
    }
    fprintf(planilha, "NOME;IDADE;GENERO;PESO;ALTURA\n");
    FILE* banco_dados = fopen("banco.bin", "wb");
    if (banco_dados == NULL) {
        perror("Nao foi possivel criar o banco de dados");
        return EXIT_FAILURE;
    }

    printf("Quantos pacientes vai cadastrar? ");
    int num_pacientes;
    scanf("%d", &num_pacientes);

    // Alocacao dinamica do vetor contendo o conjunto/lista de pacientes
    struct paciente* lista;
    lista = (struct paciente*) malloc(sizeof(struct paciente) * num_pacientes);

    int i = 0;

    float maior_peso = 0.0;
    char nome_mais_pesado[MAX_NOME];

    while (i < num_pacientes) {
        __fpurge(stdin);
        printf("Digite o nome do paciente: ");
        Gets((lista+i)->nome, MAX_NOME);

        char genero;
        do {
            printf("Digite o sexo (M/F): ");
            __fpurge(stdin);
            genero = toupper(getchar());
        } while (genero != 'M' && genero != 'F');
        (lista+i)->sexo = genero;

        printf("Digite a idade (anos): ");
        scanf("%u", &(lista+i)->idade);

        printf("Digite o peso (kg): ");
        scanf("%f", &(lista+i)->peso);

        if ((lista+i)->peso > maior_peso) {
            maior_peso = (lista+i)->peso;
            strcpy(nome_mais_pesado, (lista+i)->nome);
        }

        printf("Digite a altura (m): ");
        scanf("%f", &(lista+i)->altura);

        float ideal = calcula_peso_ideal((lista+i)->altura, (lista+i)->sexo);
        if ((lista+i)->peso > ideal) {
            printf("%s, voce estah acima do peso (ideal: %.1f).\n", (lista+i)->nome, ideal);
        } else if ((lista+i)->peso < ideal) {
            printf("%s, voce estah abaixo do peso, precisa engordar %.1f kg.\n", (lista+i)->nome, ideal-(lista+i)->peso);
        }

        // Salva/grava no arquivo o nome desse paciente
        if (fputs((lista+i)->nome, arquivo) == EOF) {
            perror("Nao foi possivel escrever no arquivo");
            return EXIT_FAILURE;
        }
        if (fputc('\n', arquivo) == EOF) {
            perror("Nao foi possivel escrever no arquivo");
            return EXIT_FAILURE;
        }

        // Salva na planilha todos os dados do paciente
        fprintf(planilha, "%s;%u;%c;%.1f;%.2f\n", (lista+i)->nome, (lista+i)->idade,
                (lista+i)->sexo, (lista+i)->peso, (lista+i)->altura);

        // Salva o registro na sua forma binaria original no banco de dados
        fwrite(lista+i, sizeof(struct paciente), 1, banco_dados);

        ++i;
    }
    printf("A pessoa mais pesada chama-se %s.\n", nome_mais_pesado);

    // Antes de sair do programa, nao esquece de liberar a memoria alocada
    free(lista);

    fclose(arquivo);
    fclose(planilha);
    fclose(banco_dados);

    // Faz a impressao na tela de cada uma das strings armazenadas no arquivo
    arquivo = fopen("exerc5.txt", "rt");
    if (arquivo == NULL) {
        perror("Nao foi possivel abrir o arquivo");
        return EXIT_FAILURE;
    }
    while (!feof(arquivo)) {
        char nome[MAX_NOME];
        if (fgets(nome, MAX_NOME, arquivo) == NULL) {
            if (ferror(arquivo)) {
                perror("Nao foi possivel ler do arquivo");
                return EXIT_FAILURE;
            }
        } else {
            printf("Nome lido: %s", nome);  // vai ler o \n do arquivo
        }
    }
    fclose(arquivo);

    // Le o primeiro registro do arquivo
    planilha = fopen("plan5.txt", "rt");
    if (planilha == NULL) {
        perror("Nao foi possivel abrir a planilha");
        return EXIT_FAILURE;
    }
    // Descarta a linha de cabecalho ("NOME;IDADE;...")
    char temp[MAX_NOME];
    fgets(temp, sizeof(temp), planilha);

    // Agora sim, le o registro
    struct paciente rascunho;
    fscanf(planilha, "%[A-Za-z];%u;%c;%f;%f\n", rascunho.nome, &rascunho.idade,
           &rascunho.sexo, &rascunho.peso, &rascunho.altura);

    fclose(planilha);

    // Le e imprime o conteudo do PENULTIMO registro do banco de dados
    banco_dados = fopen("banco.bin", "rb");
    if (banco_dados == NULL) {
        perror("Nao foi possivel abrir o banco de dados");
        return EXIT_FAILURE;
    }
    // Ao abrir um arquivo, o ponteiro de leitura encontra-se no inicio do mesmo
    /*
    // Para ler o penultimo precisa se posicionar no fim...
    fseek(banco_dados, 0, SEEK_END);
    // ... e em seguida, voltar para o comeco do penultimo registro a fim de le-lo
    fseek(banco_dados, -2*sizeof(struct paciente), SEEK_CUR);
    */
    fseek(banco_dados, -2*sizeof(struct paciente), SEEK_END);

    // Uma vez posicionado sobre o inicio dos bytes do penultimo registro, leio-o
    fread(&rascunho, sizeof(struct paciente), 1, banco_dados);
    printf("Conteudo do registro: %s; %u; %c; %f; %f\n", rascunho.nome,
           rascunho.idade, rascunho.sexo, rascunho.peso, rascunho.altura);
    fclose(banco_dados);

    return EXIT_SUCCESS;
}

float calcula_peso_ideal(float altura, char sexo) {
    float ideal;
    if (sexo == 'M') {
        ideal = 72.7 * altura - 58;
    } else {
        ideal = 62.1 * altura - 44.7;
    }
    return ideal;
}
