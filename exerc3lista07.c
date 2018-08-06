#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#ifndef WIN32
#include <stdio_ext.h>  // soh existe pra Linux
#endif
#include <ctype.h>
#include "exerc3lista07.h"
#include "mygets.h" // Gets()

int main(void) {
    struct cliente movimento_do_dia[MAX_CARROS];

    // Primeira parte: operacao do dia
    // Note que se passa o tamanho MAXIMO do vetor que pode ser preenchido
    size_t num_veiculos = operacao_portaria(movimento_do_dia, MAX_CARROS);

    // Segunda parte: levantamento/estatistica (etc.) do movimento do dia
    // Note que agora se passa o tamanho UTIL (ocupado) do vetor de acordo com o movimento
    relatorio_final(movimento_do_dia, num_veiculos);

    return EXIT_SUCCESS;
}

void limpa_teclado(void) {
#ifndef WIN32   // nao estou compilando pra Windows?
    __fpurge(stdin);
#else           // estou compilando pra Windows
    fflush(stdin);
#endif
}

size_t operacao_portaria(struct cliente vetor[], size_t maximo) {
    size_t numero = 0;

    // Nao deixa "estourar" a capacidade do vetor
    while (numero < maximo) {
        printf("Digite as informacoes do novo veiculo (indice %zd):\n", numero);

        printf("PLACA (XXX-0000)? ");
        char letras[4], numeros[5]; // 3+1 e 4+1 para reservar espaco ao '\0'
        limpa_teclado();
        scanf("%3[A-Z]-%4[0-9]", letras, numeros);  // uso de "scancodes"

        // Usa snprintf para compor a string final/campo do registro com uma
        // juncao formatada das strings lidas separadamente
        snprintf(vetor[numero].placa, MAX_PLACA, "%s-%s", letras, numeros);

        if (strcmp(vetor[numero].placa, ULTIMA_PLACA) == 0) { // igual a ZZZ-9999?
            // Essa nao eh uma placa valida, encerra a operacao do dia aqui mesmo
            return numero;  // retorna o numero de registros armazenados ateh aqui
        }

        printf("MODELO? ");
        limpa_teclado();
        Gets(vetor[numero].modelo, MAX_NOME_MODELO);

        char tamanho;
        do {
            printf("TAMANHO (P/M/G)? ");
            limpa_teclado();
            tamanho = toupper(getchar());
        } while (tamanho != 'P' && tamanho != 'M' && tamanho != 'G');
        vetor[numero].tamanho = tamanho;

        printf("Hora de ENTRADA (HH:MM)? ");
        // Note que "hora" eh um (sub-)campo do campo "entrada" do registro que esta
        // no indice "numero" do vetor "vetor"
        scanf("%2d:%2d", &vetor[numero].entrada.hora, &vetor[numero].entrada.minuto);

        printf("Hora de SAIDA (HH:MM)? ");
        scanf("%2d:%2d", &vetor[numero].saida.hora, &vetor[numero].saida.minuto);

        ++numero;   // mais um veiculo cadastrado...
    }
    return maximo;  // saiu por ter esgotado o vetor (numero = maximo)
}

void relatorio_final(const struct cliente* vetor, size_t tamanho) {
    printf("Relatorio diario (%zd veiculos)\n", tamanho);
    int i = 0;
    const struct cliente* cursor = vetor;   // ponteiro de navegacao/percurso no vetor
    while (i<tamanho) {
        if (cursor->tamanho == 'G') {
            printf("Placa: %s, modelo: %s, ", cursor->placa, cursor->modelo);

            // Calculo da duracao: converte tudo pra minutos
            // Repare a "mistura" entre os operadores: antes do -> tem um ponteiro (cursor)
            // mas antes do . tem uma estrutura (saida)
            int hora_saida = cursor->saida.hora * 60 + cursor->saida.minuto;
            int hora_entrada = cursor->entrada.hora * 60 + cursor->entrada.minuto;
            int duracao_min = hora_saida - hora_entrada;

            // Completa a impressao do registro:
            printf("%02d:%02d\n", duracao_min / 60 /* horas cheias */, duracao_min % 60 /* minutos restantes */);
        }
        ++i, ++cursor;  // vai para o proximo registro no vetor
    }
}
