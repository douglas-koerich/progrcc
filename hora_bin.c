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
    FILE* arqlog = fopen(argv[1], "wb");    // cria no formato (b)inario
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

        // Ao inves de imprimir uma string, vou gravar de forma binaria os diferentes campos
        // da estrutura
        /* Ao inves de gravar no arquivo cada campo separadamente, posso gravar a estrutura
           inteira de uma vez...
        if (fwrite(&agora_hora.hora, sizeof(int), 1, arqlog) < 1 ||
            fwrite(&agora_hora.minuto, sizeof(int), 1, arqlog) < 1 ||
            fwrite(&agora_hora.segundo, sizeof(int), 1, arqlog) < 1) {
        */
        if (fwrite(&agora_hora, sizeof(struct hora), 1, arqlog) < 1) {
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
    arqlog = fopen(argv[1], "rb");  // novamente, abertura para ler de um arquivo (b)inario
    if (arqlog == NULL) {
        perror("Nao pude reabrir o arquivo gerado");
        return EXIT_FAILURE;
    }
    // "Salta" a primeira hora, ou seja, os primeiros tres campos gravados
    fseek(arqlog, 3*sizeof(int), SEEK_SET); // pula 3*sizeof(int) bytes a partir do inicio (SEEK_SET)
    // Ou poderia ter saltado a struct inteira: fseek(arqlog, sizeof(struct hora), SEEK_SET);
    Hora hora2;
    /* Idem para a leitura, ao inves de ler cada campo separadamente, leio a estrutura
       completa do arquivo
    if (fread(&hora2.hora, sizeof(int), 1, arqlog) < 1 ||
        fread(&hora2.minuto, sizeof(int), 1, arqlog) < 1 ||
        fread(&hora2.segundo, sizeof(int), 1, arqlog) < 1) {
    */
    if (fread(&hora2, sizeof(Hora), 1, arqlog) < 1) {
        if (ferror(arqlog)) {
            perror("Nao pude ler o segundo registro do arquivo");
            fclose(arqlog);
            return EXIT_FAILURE;
        }
    }
    else {
        printf("A segunda hora informada pelo arquivo foi %02d:%02d:%02d\n",
               hora2.hora, hora2.minuto, hora2.segundo);
    }
    // Para recuperar a ultima hora, basta "saltar para tras" a partir do fim do arquivo
    fseek(arqlog, -sizeof(struct hora), SEEK_END);  // numero negativo significa um deslocamento
                                                    // pra tras a partir do fim do arquivo (SEEK_END)
    // Agora, posicionado sobre o ultimo registro, posso fazer a leitura do mesmo
    if (fread(&hora2, sizeof(struct hora), 1, arqlog) < 1) {
        if (ferror(arqlog)) {
            perror("Nao pude ler o ultimo registro do arquivo");
            fclose(arqlog);
            return EXIT_FAILURE;
        }
    }
    else {
        printf("A ultima hora informada pelo arquivo foi %02d:%02d:%02d\n",
               hora2.hora, hora2.minuto, hora2.segundo);
    }
    fclose(arqlog);
    return EXIT_SUCCESS;
}
