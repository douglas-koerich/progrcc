#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int* funcao_auxiliar(const int*, int, int*);
void imprime_vetor_i(const int[], int);

int main(int argc, char* argv[]) {
    if (argc < 3) {
        // Sao necessarios ao menos 3 argumentos:
        // 1) nome do programa (automatico e obrigatorio);
        // 2) valor de X
        // 3) valor de Y
        puts("Numero insuficiente de parametros/argumentos");
        printf("Use: %s <X> <Y>\n", argv[0]);
        return EXIT_FAILURE;
    }
    int X = atoi(argv[1]);
    int Y = atoi(argv[2]);
    // sscanf(argv[2], "%d", &Y);
    if (Y >= X) {
        puts("Parametros invalidos\nSegundo valor deve ser menor que o primeiro!");
        return EXIT_FAILURE;
    }
    srand(time(NULL));  // Inicializa semente de numeros pseudo-randomicos

    // Vetores declarados estaticamente: int primeiro[X], segundo[Y];
    int* primeiro = malloc(sizeof(int) * X); // bloco de X "inteiros"
    int* segundo = malloc(sizeof(int) * Y); // a multiplicacao eh necessaria
                                            // porque malloc recebe numero de
                                            // BYTES a serem alocados
    // Vamos alocar jah o segundo vetor resultante
    int* quarto = malloc(sizeof(int) * X); // considerando a hipotese de que
                                           // todos os numeros do primeiro vetor
                                           // sejam impares...
    
    // Percurso sobre os vetores alocados para preenche-los
    int i;
    for (i=0; i<X; ++i) {
        // primeiro[i] = rand() % 1000 + 1;
        printf("Digite o %do. valor do primeiro vetor: ", i+1);
        scanf("%d", &primeiro[i]);
    }
    for (i=0; i<Y; ++i) {
        // *(segundo+i) = rand() % 1000 + 1;
        printf("Digite o %do. valor do segundo vetor: ", i+1);
        scanf("%d", segundo + i);
    }
    printf("Primeiro vetor: "); imprime_vetor_i(primeiro, X); putchar('\n');
    printf("Segundo vetor: "); imprime_vetor_i(segundo, Y); putchar('\n');

    // Vamos pedir a uma funcao que verifique o numero de pares existentes
    // no primeiro vetor de entrada e aloque o primeiro vetor resultante para
    // nos
    int tamanho_terceiro;
    int* terceiro = funcao_auxiliar(primeiro, X, &tamanho_terceiro);

    int j, k = 0;
    for (i=0; i<X; ++i) {
        if (primeiro[i] % 2 == 0) {
            int soma = primeiro[i];
            for (j=0; j<Y; ++j) {
                soma += segundo[j];
            }
            terceiro[k++] = soma; // incrementa k apos escrever no indice
        }
    }
    printf("Terceiro vetor: "); imprime_vetor_i(terceiro, tamanho_terceiro); putchar('\n');
    
    for (i=k=0; i<X; ++i) {
        if (primeiro[i] % 2 != 0) {
            int divisores = 0;
            for (j=0; j<Y; ++j) {
                if (primeiro[i] % segundo[j] == 0) {
                    ++divisores;
                }
            }
            quarto[k++] = divisores;
        }
    }
    printf("Quarto vetor: "); imprime_vetor_i(quarto, k); putchar('\n');

    free(primeiro);
    free(segundo);
    free(terceiro);
    free(quarto);

    return EXIT_SUCCESS;
}

int* funcao_auxiliar(const int* vetor_entrada, int tamanho_entrada, int* tamanho_saida) {
    int i;
    *tamanho_saida = 0;
    for (i=0; i<tamanho_entrada; ++i) {
        if (vetor_entrada[i] % 2 == 0) {
            (*tamanho_saida)++; // precisa do parenteses pq o ++ deve ser aplicado
                                // ao conteudo (resultado do *), e nao ao ponteiro
        }
    }
    int* novo_vetor = malloc(sizeof(int) * *tamanho_saida); // notem que os *'s tem
                                                            // funcoes diferentes
    return novo_vetor;
}

void imprime_vetor_i(const int vetor[], int tamanho) {
    int i;
    for (i=0; i<tamanho; ++i) {
        printf("%d ", vetor[i]);
    }
}

