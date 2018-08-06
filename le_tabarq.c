#include <stdlib.h>
#include <stdio.h>

int main(void) {
    printf("Digite o nome do arquivo que contem a tabela: ");
    char nomearq[128];
    gets(nomearq);

    FILE* arqtab = fopen(nomearq, "r");
    if (arqtab == NULL) {
        perror("Nao foi possivel abrir o arquivo da tabela");
        return EXIT_FAILURE;
    }
    // Sabendo que o "formato" do arquivo estabelece que a primeira linha dele
    // tem a dimensao da matriz gravada, vou fazer essa leitura para alocar a
    // matriz adequadamente
    int linhas, colunas;
    if (fscanf(arqtab, "%d %d\n", &linhas, &colunas) == EOF) {
        perror("Nao pude ler as dimensoes da matriz");
        fclose(arqtab);
        return EXIT_FAILURE;
    }
    int matriz[linhas][colunas];
    int l, c;
    for (l=0; l<linhas; ++l) {
        for(c=0; c<colunas; ++c) {
            // Como os valores da tabela estao armazenados por linha e separados
            // com espacos e nova-linha (\n), cada fscanf faz a leitura correta
            // do proximo numero a ser posto na matriz (porque fscanf, igual ao scanf,
            // considera separadores os espacos e novas-linhas)
            if (fscanf(arqtab, "%d", &matriz[l][c]) == EOF) {
                perror("Nao pude ler o proximo numero no arquivo");
                fclose(arqtab);
                return EXIT_FAILURE;
            }
        }
    }
    puts("Tabela lida do arquivo:");
    for (l=0; l<linhas; ++l) {
        for (c=0; c<colunas; ++c) {
            printf("%3d ", matriz[l][c]);
        }
        putchar('\n');
    }
    // Salvamento com sucesso, fecha o arquivo
    fclose(arqtab);

    return EXIT_SUCCESS;
}
