#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "exerc3lista7.h"

int main(void) {
    // Arquivo binario para conter os registros dos veiculos
    const char* nome_arquivo = "/tmp/Boas_Compras.bin";
    FILE* arquivo = fopen(nome_arquivo, "wb"); 
    if (arquivo == NULL) {
        perror("Nao foi possivel criar o arquivo");
        return EXIT_FAILURE;
    }
    // Cadastro dos registros de entrada e saida
    veiculo ficha;
    size_t contador = 0;
    do { // Laco para ler cada ficha de veiculo...
        printf("PLACA (ZZZ-9999 para sair)? ");
        scanf(" %s", ficha.placa); // nao tem & pois 'placa' eh vetor/string
        if (strcmp(ficha.placa, PLACA_TESTE) == 0) { // foi digitada a placa de teste?
            break; // interrompe o laco de leitura
        }
        printf("Modelo? ");
        scanf(" %s", ficha.modelo);
        char auxiliar;
        do {
            printf("Tamanho (P/M/G)? ");
            scanf(" %c", &auxiliar);
            auxiliar = toupper(auxiliar);
        } while (auxiliar != 'P' && auxiliar != 'M' && auxiliar != 'G');
        ficha.tamanho = auxiliar;
        printf("Hora de entrada (hh:mm)? ");
        scanf("%u:%u", &ficha.horario_entrada.hora, &ficha.horario_entrada.minuto);
        // Vamos considerar que o cadastro da ficha eh feito depois da saida
        // do veiculo...
        printf("Hora de saida (hh:mm)? ");
        scanf("%u:%u", &ficha.horario_saida.hora, &ficha.horario_saida.minuto);

        // Salva a ficha no arquivo
        fwrite(&ficha, sizeof(veiculo), 1, arquivo);
    } while (++contador <= MAX_VEICULOS); // leitura limitada a 300 veiculos
    fclose(arquivo);

    // Percorre o arquivo pra fazer a contabilidade :-)
    arquivo = fopen(nome_arquivo, "rb");
    if (arquivo == NULL) {
        perror("Nao foi possivel reabrir o arquivo");
        return EXIT_FAILURE;
    }
    contador = 0;
    puts("*** Lista de carros grandes ***");
    while (!feof(arquivo)) { // enquanto nao chega ao fim do arquivo...
        if (fread(&ficha, sizeof(veiculo), 1, arquivo) < 1) { // leitura deve ser testada
            if (ferror(arquivo)) {
                perror("Nao foi possivel ler o arquivo");
                return EXIT_FAILURE;
            }
        } else {
            ++contador;
            if (ficha.tamanho == 'G') {
                struct hh_mm permanencia = ficha.horario_saida;
                if (permanencia.minuto < ficha.horario_entrada.minuto) {
                    permanencia.minuto += 60;
                    --permanencia.hora; // hora 'empresta' 60 minutos para subtracao
                }
                permanencia.minuto -= ficha.horario_entrada.minuto;
                permanencia.hora -= ficha.horario_entrada.hora;
                printf("%s-%s-%u:%u\n", ficha.placa, ficha.modelo,
                       permanencia.hora, permanencia.minuto);
            }
        }
    }
    puts("*** Fim da lista ***");
    printf("Total de registros/veiculos: %zd.\n", contador);
    fclose(arquivo);
    return EXIT_SUCCESS;
}

