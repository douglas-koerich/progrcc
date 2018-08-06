#include <stdlib.h>
#include <stdio.h>
#ifndef WIN32
#include <stdio_ext.h>  // so vale pra Linux
#endif
#include <string.h> // para uso do strchr()
#include <time.h>   // funcoes de data e hora, incluindo leitura do relogio do PC
#include "hora.h"

#define MAX_DIGITADOS   10000

/* Este programa registra num arquivo cada instante em que o usuario pressionou
 * a tecla <Enter>, o que permite o retorno de funcoes como scanf/getchar/gets, etc.
 */
int main(int argc, char* argv[]) {  // Vou receber o nome do arquivo por linha de comando
    if (argc < 2) {
        puts("Numero insuficiente de parametros");
        printf("Uso do programa: %s <nome-do-arquivo>\n", argv[0]);
        return EXIT_FAILURE;
    }
    FILE* arqlog = fopen(argv[1], "w");
    if (arqlog == NULL) {
        perror("Erro ao criar o arquivo de registros");
        return EXIT_FAILURE;
    }
    puts("Voce pode teclar o que quiser, cada vez que teclar um <Enter> vou");
    puts("mostrar e registrar a hora e limpar a tela, e continuar aceitando");
    puts("sua digitacao ate que entre os caracteres digitados esteja um C (maiusculo)");

    char caracteres_entrada[MAX_DIGITADOS];
    do {
        puts("Esperando...");
#ifdef WIN32
        fflush(stdin);
#else
        __fpurge(stdin);    // limpa eventual sujeira no teclado entre uma string e outra...
#endif
        gets(caracteres_entrada);

        // Tanto time_t quanto struct tm sao definidos pelo cabecalho time.h
        time_t agora = time(NULL); // le o relogio do PC na forma de segundos desde 1/Jan/1970
        struct tm agora_hms = *localtime(&agora);    // converte para formato legivel
        Hora agora_hora;

        // Copia/converte para minha propria estrutura
        agora_hora.hora = agora_hms.tm_hour;
        agora_hora.minuto = agora_hms.tm_min;
        agora_hora.segundo = agora_hms.tm_sec;

        if (fprintf(arqlog, "%02d:%02d:%02d\n",
                    agora_hora.hora, agora_hora.minuto, agora_hora.segundo) < 0) {
            perror("Nao pude registrar o evento no arquivo");
            fclose(arqlog);
            return EXIT_FAILURE;
        }
        else {
            fflush(arqlog); // Forca a gravacao dos dados no arquivo, mesmo se ainda sao poucos...
        }
#ifdef WIN32
        system("cls");
#else
        system("clear");    // comando para limpar a tela no Linux
#endif
    } while (strchr(caracteres_entrada, 'C') == NULL);
    fclose(arqlog);

    // Para recuperar a segunda hora registrada, sou obrigado a ler a mesma do arquivo
    arqlog = fopen(argv[1], "r");
    if (arqlog == NULL) {
        perror("Nao pude reabrir o arquivo gerado");
        return EXIT_FAILURE;
    }
    // Como o arquivo estah em modo texto, um registro por linha, basta fazer um fgets()
    // "falso" pra chegar na segunda linha e ler a hora registrada
    if (fgets(caracteres_entrada, MAX_DIGITADOS, arqlog) == NULL) { // reaproveitei a variavel string
        if (ferror(arqlog)) {
            perror("Nao pude ler o arquivo");
            fclose(arqlog);
            return EXIT_FAILURE;
        }
    }
    else {
        // Nao faco nada com o conteudo da primeira linha, mas agora estou
        // posicionado sobre a segunda
    }
    Hora hora2;
    if (fscanf(arqlog, "%d:%d:%d\n", &hora2.hora, &hora2.minuto, &hora2.segundo) == EOF) {
        if (ferror(arqlog)) {
            perror("Nao pude ler o arquivo");
            fclose(arqlog);
            return EXIT_FAILURE;
        }
    }
    else {
        printf("A segunda hora informada pelo arquivo foi %02d:%02d:%02d\n",
               hora2.hora, hora2.minuto, hora2.segundo);
    }
    fclose(arqlog);
    return EXIT_SUCCESS;
}
