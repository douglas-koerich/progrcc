#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#ifndef WIN32
#include <stdio_ext.h>
#endif
#include "registro.h"   // contem a DEFINICAO do registro 'pessoa'

void imprime_pessoa(struct pessoa*);    // passagem de struct pra funcao eh por ponteiro

int main(int argc, char* argv[]) {
    float media = 0.0;
    unsigned contador = 0;
    size_t num_individuos;
    struct data hoje;

    printf("Digite a data de hoje (D/M/A): ");
    scanf("%d/%d/%d", &hoje.dia, &hoje.mes, &hoje.ano);

    // char nome[MAX_NOME+1];
    
    /*
    // DECLARACAO do registro (variavel que ocupa memoria com seus campos)
    Pessoa individuo;   // 'individuo' eh uma variavel do tipo 'Pessoa'
    */
    printf("Digite o numero de individuos: ");
    scanf("%zd", &num_individuos);
    Pessoa populacao[num_individuos];   // VETOR de registros ("banco de dados")

    // do {
    int i;
    for (i = 0; i < num_individuos; ++i) {
        // printf("Digite o nome ('nonono' para encerrar): ");
        printf("Digite o nome do individuo #%d: ", i + 1);
#ifdef WIN32
        fflush(stdin);
#else
        __fpurge(stdin);
#endif
        // gets(nome);
        // gets(individuo.nome);   // operador "ponto" (.) leva ao campo especifico da variavel
        gets(populacao[i].nome);

        // if (strcmp(individuo.nome, "nonono") != 0) {
        printf("Digite a idade: ");
        // unsigned idade;
        // scanf("%u", &idade);
        // scanf("%u", &individuo.idade);
        scanf("%u", &populacao[i].idade);

        // char sexo;
        do {
            printf("Digite o sexo (M/F): ");
#ifdef WIN32
            fflush(stdin);
#else
            __fpurge(stdin);
#endif
            // sexo = toupper(getchar());
            // individuo.sexo = toupper(getchar());
            populacao[i].sexo = toupper(getchar());
        // } while (individuo.sexo != 'M' && individuo.sexo != 'F');
        } while (populacao[i].sexo != 'M' && populacao[i].sexo != 'F');

        printf("Digite a renda (R$): ");
        // float renda;
        // scanf("%f", &renda);
        // scanf("%f", &individuo.renda);
        scanf("%f", &populacao[i].renda);

        printf("Digite a data de nascimento (D/M/A): ");
        scanf("%d/%d/%d", &populacao[i].nasc.dia, &populacao[i].nasc.mes, &populacao[i].nasc.ano);
        /*
        if (sexo == 'M' && idade >= 30 && idade <= 40) {
            media += renda;
            ++contador;
        }
        if (individuo.sexo == 'M' && individuo.idade >= 30 && individuo.idade <= 40) {
            media += individuo.renda;
            ++contador;
        }
        */
        if (populacao[i].sexo == 'M' && populacao[i].idade >= 30 && populacao[i].idade <= 40) {
            media += populacao[i].renda;
            ++contador;
        }
        //}
    //} while (strcmp(individuo.nome, "nonono") != 0);
    }

    if (contador != 0) {
        media /= contador;
    }
    printf("A media de renda dos homens entre 30 e 40 anos eh %.2f\n", media);

    // Impressao de todos os registros cadastrados
    printf("*** CADASTRO NO DIA %02d/%02d/%d ***\n", hoje.dia, hoje.mes, hoje.ano);
    /*
    for (i = 0; i < num_individuos; ++i) {
        printf("%s, %u anos, sexo %c, renda R$ %.2f;\n",
               populacao[i].nome, populacao[i].idade, populacao[i].sexo,
               populacao[i].renda);
    }
    */
    // Pessoa* ponteiro = &individuo;  // se a variavel for "escalar" (unitaria)
    for (i = 0; i < num_individuos; ++i) {
        imprime_pessoa(&populacao[i]);  // ou imprime_pessoa(populacao+i)
    }

    // Salvar o cadastro em arquivo
    FILE* f = fopen("/tmp/cadastro.txt", "w");
    if (f == NULL) {
        perror("Erro ao criar arquivo-texto");
        return EXIT_FAILURE;
    }
    Pessoa* p = populacao;  // nome do vetor eh o endereco do seu primeiro elemento
    for (i = 0; i < num_individuos; ++i, ++p) { // ++p salta para proximo registro no vetor
        // Se for arquivo-texto, soh posso fazer isso campo a campo do registro
        /*
        printf("%s, nascido(a) em %02d/%02d/%d, %u anos, sexo %c, renda R$ %.2f;\n",
               p->nome, p->nasc.dia, p->nasc.mes, p->nasc.ano, p->idade, p->sexo, p->renda);   // operador '->' para atingir o campo usando o endereco (no ponteiro)
        */
        if (fprintf(f, "%s;%02d/%02d/%d;%u;%c;%.2f\n", p->nome,
                    p->nasc.dia, p->nasc.mes, p->nasc.ano, p->idade, p->sexo, p->renda)
            < 0) {
            perror("Erro ao escrever no arquivo-texto");
            return EXIT_FAILURE;
        }
    }
    fclose(f);
    f = fopen("/tmp/cadastro.bin", "wb");
    if (f == NULL) {
        perror("Erro ao criar arquivo-binario");
        return EXIT_FAILURE;
    }
    // Eh possivel, como visto abaixo, gravar um vetor completo numa unica chamada de fwrite
    if (fwrite(populacao, sizeof(struct pessoa), num_individuos, f) < num_individuos) {
        perror("Erro ao escrever no arquivo-binario");
        return EXIT_FAILURE;
    }
    fclose(f);

    return EXIT_SUCCESS;
}

void imprime_pessoa(struct pessoa* p) {
    printf("%s, nascido(a) em %02d/%02d/%d, %u anos, sexo %c, renda R$ %.2f;\n",
           p->nome, p->nasc.dia, p->nasc.mes, p->nasc.ano, p->idade, p->sexo, p->renda);   // operador '->' para atingir o campo usando o endereco (no ponteiro)
}
