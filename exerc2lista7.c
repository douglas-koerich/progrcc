#include <stdlib.h>
#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include <ctype.h>
#include "exerc2lista7.h"

int main() {
    unsigned num_habitantes;
    printf("Digite o numero de habitantes: ");
    scanf("%u", &num_habitantes);

    // Ao inves de declarar um vetor de registros de maneira estatica, assim...
    // Habitante populacao[num_habitantes];
    // ... vamos, ao inves, alocar o vetor dinamicamente!
    Habitante* populacao = (Habitante*) malloc(sizeof(Habitante)*num_habitantes);

    // Passa para a funcao que preenche o vetor
    censo(populacao, num_habitantes);

    // Antes de fazer os calculos pedidos pelo exercicio, vamos salvar o vetor no
    // arquivo
    char arquivo[80];
    printf("Digite o nome do arquivo para salvar o censo: ");
    scanf(" %s", arquivo);
    salva_arquivo(populacao, num_habitantes, arquivo);
/*
    // Calcula a media salarial da populacao
    float media = media_salario(populacao, num_habitantes);
    printf("A media salarial eh $%.2f\n", media);

    // Encontra a maior e menor idade da populacao
    unsigned velho, novo;
    mais_velho_mais_novo(populacao, num_habitantes, &velho, &novo);
    printf("A pessoa mais velha tem %u anos e a mais nova %u anos\n", velho, novo);

    // Estatistica das mulheres
    unsigned mulheres = mulheres900filhos3(populacao, num_habitantes);
    printf("O numero de mulheres com 3 filhos e salario ateh $900 eh %u\n", mulheres);
*/
    // Nao esqueca de liberar a memoria
    free(populacao);

    // Ao final, recupera o conteudo do arquivo para imprimir na tela
    le_imprime_arquivo(arquivo);

    return 0;
}

void censo(Habitante* pop, size_t num) {
    int h;
    puts("### INICIO DO CENSO ###");
    for (h=0; h<num; ++h) {
        printf("Dados do habitante #%d:\n", h+1);
        printf("Nome? "); __fpurge(stdin); gets(pop[h].nome);   // sem & porque eh string/vetor/"ponteiro"
        printf("Idade? "); scanf("%u", &pop[h].idade);
        do {
            printf("Sexo (M/F)? ");
            __fpurge(stdin);
            (pop+h)->sexo = toupper(getchar()); // pop+h eh um salto de h estruturas a partir do inicio em pop
        } while (pop[h].sexo != 'M' && (pop+h)->sexo != 'F');   // repare os dois modos...
        printf("Salario? "); scanf("%f", &(pop+h)->salario);
        printf("Filhos? "); scanf("%u", &(pop+h)->filhos);
    }
    puts("### FIM DO CENSO ###");
}

float media_salario(const Habitante* pop, size_t num) {
    float soma = 0.0;
    const Habitante* h = pop;
    int i = 0;
    while (i < num) {
        soma += h->salario;
        ++i, ++h;   // h pula uma estrutura inteira na memoria!!!
    }
    return soma/num;
}

void mais_velho_mais_novo(const Habitante* pop, size_t num, unsigned* maior, unsigned* menor) {
    int i = 0;
    while (i < num) {
        if (i == 0) {
            *maior = *menor = (pop+i)->idade;
        }
        else {
            if ((pop+i)->idade > *maior) {
                *maior = (pop+i)->idade;
            }
            if ((pop+i)->idade < *menor) {
                *menor = (pop+i)->idade;
            }
        }
        ++i;
    }
}

unsigned mulheres900filhos3(const Habitante* pop, size_t num) {
    int i;
    unsigned contador = 0;
    for (i=0; i<num; ++i) {
        if (pop[i].sexo == 'M') {
            continue;   // pula para proxima iteracao do laco
        }
        if (pop[i].filhos == 3 && pop[i].salario <= 900.0) {
            ++contador;
        }
    }
    return contador;
}

void salva_arquivo(const Habitante* pop, size_t num, const char* nome_arq) {
    FILE* arq = fopen(nome_arq, "w");
    if (arq == NULL) {
        perror("Erro ao criar arquivo");
        return;
    }
    fputs("Nome;Idade;Sexo;Salario;Filhos\n", arq);
    int i = 0;
    while (i < num) {
        fprintf(arq, "%s;%u;%c;%.2f;%u\n", pop[i].nome, pop[i].idade,
            pop[i].sexo, (pop+i)->salario, (pop+i)->filhos);
        ++i;
    }
    fclose(arq);

    // Vou salvar tambem no formato binario (para acesso aleatorio)
    char nome_arq2[100];
    strcpy(nome_arq2, nome_arq);
    strcat(nome_arq2, ".bin");
    arq = fopen(nome_arq2, "wb");
    if (arq == NULL) {
        perror("Erro ao criar arquivo");
        return;
    }
    /* Primeira versao: salva registro por registro
    // Em um arquivo binario nao faz sentido ter o cabecalho
    i = 0;
    while (i < num) {
        fwrite(pop+i, sizeof(Habitante), 1, arq);
        ++i;
    }
    */
    // Segunda versao: salva o vetor todo de um vez
    fwrite(pop, sizeof(Habitante), num, arq);
    fclose(arq);
}

void le_imprime_arquivo(const char* nome_arq) {
    char nome_arq2[256];
    strcpy(nome_arq2, nome_arq);
    strcat(nome_arq2, ".bin");
    // FILE* arq = fopen(nome_arq, "r");
    FILE* arq = fopen(nome_arq2, "rb");
    if (arq == NULL) {
        perror("Erro ao abrir arquivo");
        return;
    }
    /*
    // Primeira versao: le como um conjunto de linhas
    char str_registro[512];
    while (!feof(arq)) {
        if (fgets(str_registro, sizeof(str_registro), arq) == NULL) {
            if (ferror(arq)) {
                perror("Erro na leitura do arquivo");
                fclose(arq);
                return;
            }
            else {
                // Nao faz nada, encontrou o fim do arquivo ao ler uma proxima linha
            }
        }
        else {
            printf(str_registro);
        }
    }
    */
    /*
    // Segunda versao: le como um registro gravado em modo texto
    char cabecalho[512];
    if (fgets(cabecalho, sizeof(cabecalho), arq) == NULL) {
        if (ferror(arq)) {
            perror("Erro na leitura do cabecalho");
        }
        fclose(arq);
        return;
    }
    // Descarto a linha de cabecalho gravada no arquivo... (eu, Douglas, decidi fazer isso)
    */
    puts("|                 Nome | Idade | Sexo | Salario (R$) | Filhos |");
    Habitante registro;
    while (!feof(arq)) {
        /*
        // Usar %s nesse caso confunde o fscanf porque ele vai considerar TODA a linha como
        // sendo o primeiro campo (que eh uma string)
        //if (fscanf(arq, "%s;%u;%c;%f;%u\n", registro.nome, &registro.idade, &registro.sexo,

        // Solucao: usar o scancode do scanf (substituir o %s por %[<caracteres validos>])
        if (fscanf(arq, "%[A-Za-z ];%u;%c;%f;%u\n", registro.nome, &registro.idade, &registro.sexo,
            &registro.salario, &registro.filhos) == EOF) {
            if (ferror(arq)) {
                perror("Erro na leitura do arquivo");
                fclose(arq);
                return;
            }
            else {
                // Nao faz nada, encontrou o fim do arquivo ao ler um proximo registro
            }
        }
        */
        if (fread(&registro, sizeof(Habitante), 1, arq) < 1) {
            if (ferror(arq)) {
                perror("Erro na leitura do arquivo");
                fclose(arq);
                return;
            }
            else {
                // Nao faz nada, encontrou o fim do arquivo ao ler um proximo registro
            }
        }
        else {
            printf("| %20s | %5u |    %c | %12.2f | %6u |\n", registro.nome,
                registro.idade, registro.sexo, registro.salario, registro.filhos);
        }
    }
    fclose(arq);
}

