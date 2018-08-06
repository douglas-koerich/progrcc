/* Cria e depois le um banco de dados formado pelo prenome
 * de uma pessoa e seu ano de nascimento. Quando da leitura
 * desse cadastro, o programa informa a idade de cada pessoa.
 */

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_PRENOME     20
#define ARQ_CADASTRO    "/tmp/cadastro.txt"

int main(int argc, char* argv[]) {
    unsigned ano_nasc;
    char prenome[MAX_PRENOME];

    // Abre o arquivo
    FILE* cadastro = fopen(ARQ_CADASTRO, "a+"); // para acrescentar se ja existe
    if (cadastro == NULL) {
        perror("Erro ao abrir/criar o cadastro");
        return EXIT_FAILURE;
    }

    bool fim;
    do {
        puts("Digite o nome de uma pessoa para cadastrar,");
        printf("(<nonono> para encerrar): ");
        scanf(" %s", prenome);
        fim = (strcmp(prenome, "nonono") == 0);
        if (!fim) { // if (fim == false)
            do {
                printf("Digite o ano de nascimento (AAAA): ");
                scanf("%u", &ano_nasc);
            } while (ano_nasc < 1900 || ano_nasc > 2017);
            // Saida formatada (transforma variaveis nao-texto em caracteres)
            if (fprintf(cadastro, "%s,%u\n", prenome, ano_nasc) < 0) {
                perror("Erro ao escrever no arquivo");
                return EXIT_FAILURE;
            }
        }
    } while (!fim); // while (fim == false);

    // Ter aberto o arquivo com "a+" significa que a leitura comeca no
    // inicio do arquivo
    puts("\n*** CALCULO DAS IDADES DO CADASTRO ***");
    while (!feof(cadastro)) {
        // fscanf vai fazer leitura da linha do arquivo em partes:
        // %[A-Za-z] significa: o primeiro campo deve ser considerado pela sequencia
        // de caracteres no intervalo A-Z ou a-z, o que exclui a virgula e os algarismos
        // que vem na sequencia (nao serao considerados parte da string inicial);
        // %u significa: ja tendo considerado a virgula como o separador das partes, o
        // fscanf vai ler os algarismos seguintes para a variavel inteira (sem sinal)
        if (fscanf(cadastro,"%[A-Za-z],%u\n", prenome, &ano_nasc) == EOF) {
            if (ferror(cadastro)) {
                perror("Erro ao recuperar o conteudo do arquivo");
                return EXIT_FAILURE;
            }
        } else {
            printf("%s farah neste ano %u anos de idade.\n", prenome, 2017-ano_nasc);
        }
    }

    fclose(cadastro);

    return EXIT_SUCCESS;
}

