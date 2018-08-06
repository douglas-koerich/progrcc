#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include "trabalho.h"

int placa_jogo[TAMANHO][TAMANHO];
int placa_inicial[TAMANHO][TAMANHO];
const int placa_final[TAMANHO][TAMANHO] = {
    {  1,  2,  3,  4 },
    {  5,  6,  7,  8 },
    {  9, 10, 11, 12 },
    { 13, 14, 15,  0 }
};
unsigned contador_movimentos;
unsigned movimentos_iniciais = 50;

enum Direcao { ACIMA, ABAIXO, ESQUERDA, DIREITA, MAX };

void inicia_placa(void) {
    int l, c;
    for (l=0; l<TAMANHO; ++l) {
        for (c=0; c<TAMANHO; ++c) {
            placa_jogo[l][c] = placa_final[l][c];
        }
    }
    srand((unsigned) time(0));
    l = c = TAMANHO-1;  // posicao inicial do 0
    int i = 1;
    while (i <= movimentos_iniciais) {
        enum Direcao direcao = rand() % MAX;
        switch (direcao) {
            case ABAIXO:
                if (c < TAMANHO-1) {
                    placa_jogo[l][c] = placa_jogo[l][c+1];
                    placa_jogo[l][c+1] = 0;
                    ++c, ++i;
                }
                break;

            case ACIMA:
                if (c > 0) {
                    placa_jogo[l][c] = placa_jogo[l][c-1];
                    placa_jogo[l][c-1] = 0;
                    --c, ++i;
                }
                break;

            case ESQUERDA:
                if (l > 0) {
                    placa_jogo[l][c] = placa_jogo[l-1][c];
                    placa_jogo[l-1][c] = 0;
                    --l, ++i;
                }
                break;

            case DIREITA:
                if (l < TAMANHO-1) {
                    placa_jogo[l][c] = placa_jogo[l+1][c];
                    placa_jogo[l+1][c] = 0;
                    ++l, ++i;
                }
                break;
        }
    }
    for (l=0; l<TAMANHO; ++l) {
        for (c=0; c<TAMANHO; ++c) {
            placa_inicial[l][c] = placa_jogo[l][c];
        }
    }
    contador_movimentos = 0;
}

bool fim_jogo(void) {
    int l, c;
    for (l=0; l<TAMANHO; ++l) {
        for (c=0; c<TAMANHO; ++c) {
            if (placa_jogo[l][c] != placa_final[l][c]) {
                return false;
            }
        }
    }
    return true;
}

void reinicia_jogo(void) {
    char c;
    do {
        printf("Tem certeza que deseja reiniciar este jogo (S/N)? ");
        scanf(" %c", &c);
        c = toupper(c);
    } while (c != 'S' && c != 'N');
    if (c == 'S') {
        int l, c;
        for (l=0; l<TAMANHO; ++l) {
            for (c=0; c<TAMANHO; ++c) {
                placa_jogo[l][c] = placa_inicial[l][c];
            }
        }
    }
}

void novo_jogo(void) {
    char c;
    do {
        printf("Tem certeza que deseja iniciar um novo jogo (S/N)? ");
        scanf(" %c", &c);
        c = toupper(c);
    } while (c != 'S' && c != 'N');
    if (c == 'S') {
        inicia_placa();
    }
}

void salva_jogo(void) {
    char nome[128];
    printf("Digite o nome do arquivo a ser criado: ");
    scanf(" %s", nome);
    FILE* arquivo = fopen(nome, "wb");
    if (arquivo == NULL) {
        perror("Erro ao criar o arquivo");
        puts("Pressione <Enter> para continuar...");
        getchar();
        return;
    }
    size_t total = TAMANHO * TAMANHO;
    if (fwrite(&placa_jogo[0][0], sizeof(int), total, arquivo) < total) {
        perror("Erro ao escrever o jogo atual no arquivo");
        puts("Pressione <Enter> para continuar...");
        getchar();
    }
    if (fwrite(&placa_inicial[0][0], sizeof(int), total, arquivo) < total) {
        perror("Erro ao escrever o jogo inicial no arquivo");
        puts("Pressione <Enter> para continuar...");
        getchar();
    }
    if (fwrite(&contador_movimentos, sizeof(unsigned), 1, arquivo) < 1) {
        perror("Erro ao escrever o contador de movimentos no arquivo");
        puts("Pressione <Enter> para continuar...");
        getchar();
    }
    fclose(arquivo);
}

void le_jogo(void) {
    char nome[128];
    printf("Digite o nome do arquivo a ser lido: ");
    scanf(" %s", nome);
    FILE* arquivo = fopen(nome, "rb");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        puts("Pressione <Enter> para continuar...");
        getchar();
        return;
    }
    size_t total = TAMANHO * TAMANHO;
    if (fread(&placa_jogo[0][0], sizeof(int), total, arquivo) < total) {
        perror("Erro ao ler o jogo do arquivo");
        puts("Pressione <Enter> para continuar...");
        getchar();
    }
    if (fread(&placa_inicial[0][0], sizeof(int), total, arquivo) < total) {
        perror("Erro ao ler o jogo inicial do arquivo");
        puts("Pressione <Enter> para continuar...");
        getchar();
    }
    if (fread(&contador_movimentos, sizeof(unsigned), 1, arquivo) < 1) {
        perror("Erro ao ler o contador de movimentos do arquivo");
        puts("Pressione <Enter> para continuar...");
        getchar();
    }
    fclose(arquivo);
}
