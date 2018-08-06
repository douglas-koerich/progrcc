#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "mygets.h"
#include "exerc6lista7.h"

int main(int argc, char* argv[]) {
    // Apesar do exercicio nao solicitar, o nome do arquivo
    // contendo o banco de dados eh esperado como o parametro
    // da linha de chamada do programa
    if (argc < 2) {
        puts("Numero insuficiente de parametros");
        printf("Use: %s nome-do-arquivo\n", argv[0]);
        return EXIT_FAILURE;
    }
    FILE* cadastro = fopen(argv[1], "rt");
    if (cadastro == NULL) {
        perror("Nao pude abrir o arquivo");
        return EXIT_FAILURE;
    }
    // Copia o banco de dados para um vetor de registros em memoria,
    // onde eh mais facil e agil efetuar a varredura e as verificacoes
    struct veiculo conjunto_registros[MAX_NUM_VEICULOS];
    int indice = 0;
    while (!feof(cadastro)) {
        if (fscanf(cadastro,
            "%[A-Za-z ],%[A-Z0-9],%[A-Za-z],%d,%[A-Z0-9],%[A-Za-z],%c\n",
            conjunto_registros[indice].proprietario,
            conjunto_registros[indice].placa,
            conjunto_registros[indice].modelo,
            &conjunto_registros[indice].ano,
            conjunto_registros[indice].chassis,
            conjunto_registros[indice].cor,
            &conjunto_registros[indice].combustivel) == EOF) {
            if (ferror(cadastro)) {
                perror("Nao pude ler do arquivo");
                return EXIT_FAILURE;
            }
        } else {
            ++indice;
        }
    }
    // Fecha o arquivo assim que o mesmo nao eh mais necessario!!
    fclose(cadastro);

    // Note que o valor de 'indice' que sai do laco acima eh
    // igual ao contador de registros lidos do arquivo (< MAX_NUM_VEICULOS)
    size_t contador = indice;

    printf("Numero de veiculos a diesel do ano 2000 ou mais: %u.\n",
           funcao_a(conjunto_registros, contador));
    puts("Placas (AB)..-...(0247): consulte arquivo 'especiais.txt'");
    funcao_b(conjunto_registros, contador);

    size_t num_suspeitos;
    struct veiculo* suspeitos = funcao_c(conjunto_registros, contador, &num_suspeitos);
    puts("Proprietarios com suspeita de adulteracao:");
    for (indice = 0; indice < num_suspeitos; ++indice) {
        puts(suspeitos[indice].proprietario);
    }
    free(suspeitos);
    return EXIT_SUCCESS;
}

unsigned funcao_a(struct veiculo vetor[], size_t tamanho) {
    unsigned contador = 0;
    int indice;
    for (indice = 0; indice < tamanho; ++indice) {
        if (vetor[indice].ano >= 2000 && vetor[indice].combustivel == 'D') {
            ++contador;
        }
    }
    return contador;
}

void funcao_b(struct veiculo* vetor, size_t tamanho) {
    FILE* arq = fopen("especiais.txt", "wt");
    if (arq == NULL) {
        perror("Erro ao criar arquivo de placas especiais");
        return;
    }
    int indice = 0;
    while (indice < tamanho) {
        char inicial = vetor[indice].placa[0],
             final = vetor[indice].placa[6];

        // Repare que os numeros testados sao na verdade algarismos em ASCII
        // (caracteres que estao na string de placa)
        if ((inicial == 'A' || inicial == 'B') &&
            (final == '0' || final == '2' || final == '4' || final == '7')) {
            fprintf(arq, "%s:%s\n", vetor[indice].proprietario, vetor[indice].placa);
        }
        ++indice;
    }
    fclose(arq);
}

struct veiculo* funcao_c(const struct veiculo* vetor, size_t tamanho, size_t* contador) {
    *contador = 0;
    struct veiculo* suspeitos = NULL;
    int indice;
    for (indice = 0; indice < tamanho; ++indice) {
        bool chassis_ok;
        
        // Inicia a inspecao verificando se o comprimento estah ok
        chassis_ok = strlen(vetor[indice].chassis) == MAX_CHASSIS;
        if (chassis_ok == true) {
            int posicao;
            for (posicao = 0; posicao < MAX_CHASSIS; ++posicao) {
                // Para as posicoes 1, 2, penultima e ultima, tem que ser letra
                if (posicao == 0 || posicao == 1 || posicao == MAX_CHASSIS-2 || posicao == MAX_CHASSIS-1) {
                    if (!isalpha(vetor[indice].chassis[posicao])) {
                        chassis_ok = false;
                        break;  // nao faz sentido continuar varrendo esse chassis, ja estah NOK
                    }
                } else {
                    if (!isdigit(vetor[indice].chassis[posicao])) {
                        chassis_ok = false;
                        break;  // idem
                    }
                }
            }
        }
        if (chassis_ok == false) {
            // Eh o primeiro suspeito encontrado?
            ++(*contador);
            if (suspeitos == NULL) {
                suspeitos = (struct veiculo*) malloc(sizeof(struct veiculo));

                // Para copiar de um registro que contem campos-string para outro, faz a
                // copia campo a campo...
                strcpy(suspeitos->proprietario, vetor[indice].proprietario);
                strcpy(suspeitos->placa, vetor[indice].placa);
                strcpy(suspeitos->modelo, vetor[indice].modelo);
                suspeitos->ano = vetor[indice].ano;
                strcpy(suspeitos->chassis, vetor[indice].chassis);
                strcpy(suspeitos->cor, vetor[indice].cor);
                suspeitos->combustivel = vetor[indice].combustivel;
            } else {
                // NOVIDADE: pra aumentar o tamanho de uma area ja alocada, use realloc()
                // (procure saber mais na bibliografia)
                suspeitos = (struct veiculo*) realloc(suspeitos, sizeof(struct veiculo)*(*contador));

                // ... (continuando as reticencias de cima) ou copia toda a area de memoria
                // do registro usando memcpy() (outra NOVIDADE, consulte os livros!)
                memcpy(&suspeitos[*contador - 1], &vetor[indice], sizeof(struct veiculo));
            }
        }
    }
    return suspeitos;
}

