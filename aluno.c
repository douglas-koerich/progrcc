#include <stdlib.h>
#include <stdio.h>
#include <stdio_ext.h>
#include <time.h>
#include "aluno.h"

#define TAM_TURMA 10

int calcula_tempo_curso(const Aluno*); // funcao nao consegue alterar o registro passado como parametro
void zera_coeficiente(Aluno*); // essa funcao vai conseguir mudar o conteudo do(s) campo(s) do registro

int main(void) {
    // Alocacao estatica de variaveis:
    struct aluno aluno1; // 'aluno1' eh uma variavel do tipo 'aluno'
    Aluno aluno2; // 'aluno2' eh uma variavel do mesmo tipo-base
    Aluno turma[TAM_TURMA]; // vetor de registros/estruturas

    Aluno fisico = {
        "Albert Einstein", // nome
        10, // matricula
        1905, // ano_ingresso
        'M', // ...
        999,
        false,
        1000.0,
    };
    Aluno fisica = {
        "Marie Curie",
        90,
        .genero = 'F', // pulei o ano_ingresso (fica 0)
        // demais campos ficam zerados tambem
    };

    Aluno mini_turma[2] = {
        // primeiro aluno da turma
        {
            "Juquinha",
            12,
            2012,
            'M',
            24,
            true,
            8.9
        },
        // segundo aluno da turma
        {
            "Mariazinha",
            20,
            2013,
            'F',
            18,
            false,
            6.1
        }
    };

    // Alocacao dinamica
    Aluno* aluno3 = malloc(sizeof(Aluno));  // alocacao de 1 aluno na heap
    Aluno* outra_turma = malloc(sizeof(Aluno) * TAM_TURMA); // alocacao de outro vetor de alunos

    printf("O tamanho da variavel unitaria eh %zd.\n", sizeof(aluno1));
    printf("O tamanho da variavel composta (vetor) eh %zd.\n", sizeof(turma));

    puts("Digite as informacoes do aluno 1 abaixo:");
    printf("Nome? "); gets(aluno1.nome); // operador '.' acessa o campo
    printf("Matricula? "); scanf("%d", &aluno1.matricula);
    aluno1.ano_ingresso = 2017;
    printf("Sexo? "); scanf(" %c", &aluno1.genero);
    // ... o mesmo para os demais ...
    printf("A letra inicial do nome digitado eh %c.\n", aluno1.nome[0]);
    
    puts("Digite as informacoes do primeiro aluno da turma:");
    printf("Nome? "); __fpurge(stdin); gets(turma[0].nome);
    printf("Matricula? "); scanf("%d", &turma[0].matricula);
    turma[0].ano_ingresso = 2017;
    printf("Sexo? "); scanf(" %c", &turma[0].genero);
    // ... o mesmo para os demais ...
    printf("A letra inicial do nome digitado para o primeiro aluno eh %c.\n", turma[0].nome[0]);

    aluno2 = aluno1; // copia membro a membro

    puts("Digite as informacoes do aluno 3 abaixo:");
    printf("Nome? "); __fpurge(stdin); gets(aluno3->nome); // operador '->' acessa o campo atraves do ponteiro/endereco para o registro
    printf("Matricula? "); scanf("%d", &aluno3->matricula);
    aluno3->ano_ingresso = 2017;
    printf("Sexo? "); scanf(" %c", &aluno3->genero);
    // ... o mesmo para os demais ...
    printf("A letra inicial do nome digitado eh %c.\n", aluno3->nome[0]);

    int tempo_aluno1 = calcula_tempo_curso(&aluno1); // aluno1 eh uma variavel declarada estaticamente
    int tempo_aluno3 = calcula_tempo_curso(aluno3);  // aluno3 eh um ponteiro para a "variavel" alocada dinamicamente

    zera_coeficiente(&aluno1);
    zera_coeficiente(aluno3);

    free(outra_turma);
    free(aluno3);

    FILE* texto = fopen("/tmp/aluno.txt", "w");
    if (texto == NULL) {
        perror("Erro ao criar arquivo texto");
        return EXIT_FAILURE;
    }
    fprintf(texto, "%s;%d;%d;%c;%d;%d;%.1f\n",
            aluno1.nome, aluno1.matricula, aluno1.ano_ingresso, aluno1.genero,
            aluno1.codigo_curso, aluno1.cursando, aluno1.coeficiente_rendimento);
    fclose(texto);
    
    FILE* binario = fopen("/tmp/aluno.bin", "wb");
    if (binario == NULL) {
        perror("Erro ao criar arquivo binario");
        return EXIT_FAILURE;
    }
    fwrite(&aluno1, sizeof(Aluno), 1, binario);
    fwrite(turma, sizeof(Aluno), TAM_TURMA, binario);

    fclose(binario);
    binario = fopen("/tmp/aluno.bin", "rb");
    fseek(binario, sizeof(Aluno), SEEK_SET); // pula o primeiro registro gravado (aluno1)
    fread(&aluno2, sizeof(Aluno), 1, binario);

    printf("Conferencia do nome lido do arquivo: %s\n", aluno2.nome);

    fclose(binario);

    return EXIT_SUCCESS;
}

int calcula_tempo_curso(const Aluno* a) {
    time_t agora = time(NULL);
    struct tm* data_e_hora = localtime(&agora);
    int ano_atual = data_e_hora->tm_year + 1900; // v. 'man localtime'
    printf("Curiosidade: agora sao %d:%02d\n", data_e_hora->tm_hour, data_e_hora->tm_min);
    puts(asctime(data_e_hora));
    return ano_atual - a->ano_ingresso;
}

void zera_coeficiente(Aluno* a) {
    a->coeficiente_rendimento = 0.0;
}

