#include <stdlib.h>
#include <stdio.h>

int main(void) {
    int linhas, colunas;
    printf("Quantas linhas terah a tabela? "); scanf("%d", &linhas);
    printf("Quantas colunas? "); scanf("%d", &colunas);

    int matriz[linhas][colunas];
    int l, c;
    for (l=0; l<linhas; ++l) {
        for(c=0; c<colunas; ++c) {
            printf("Digite o valor a ser armazenado na posicao [%d][%d]: ", l, c);
            scanf("%d", &matriz[l][c]);
        }
    }

    // Ao mesmo tempo, salvo a matriz em disco e imprimo na tela
    printf("Digite o nome do arquivo para salvar a tabela: ");
    char nomearq[128];
    __fpurge(stdin);
    gets(nomearq);

    FILE* arqtab = fopen(nomearq, "w");
    if (arqtab == NULL) {
        perror("Nao foi possivel criar o arquivo para a tabela");
        return EXIT_FAILURE;
    }
    /* No caso do disco, como vou gravar um arquivo-texto, eh mais razoavel
     * comecar o conteudo do arquivo com uma indicacao do numero de linhas e
     * colunas que tem a matriz gravada; assim, quando recuperar do arquivo,
     * consigo criar/alocar/declarar a matriz em memoria para ler desse arquivo
     * com o tamanho certo... */
    fprintf(arqtab, "%d %d\n", linhas, colunas);

    puts("Tabela gerada:");
    for (l=0; l<linhas; ++l) {
        for (c=0; c<colunas; ++c) {
            printf("%3d ", matriz[l][c]);
            if (fprintf(arqtab, "%3d ", matriz[l][c]) < 0) { // numero em formato texto!
                perror("Nao pude escrever o numero no arquivo");
                fclose(arqtab);
                return EXIT_FAILURE;
            }
        }
        putchar('\n');
        if (fputc('\n', arqtab) == EOF) {
            // No caso do fputc, retornar EOF nao eh fim de arquivo, eh ERRO mesmo!
            perror("Nao pude escrever nova linha no arquivo");
            fclose(arqtab);
            return EXIT_FAILURE;
        }
    }
    // Salvamento com sucesso, fecha o arquivo
    fclose(arqtab);

    return EXIT_SUCCESS;
}
