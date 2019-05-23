/* Escreva um programa em linguagem C que, para um arquivo-texto cujo caminho e
 * nome sao informados ao programa pelo usuario, SUBSTITUA todas as letras
 * Maiusculas por minusculas e todos os espacos em branco (caractere ' ' da
 * tabela ASCII) por sublinhados (caractere '_').
 * Exemplo:
 * (ANTES)  UTP - Universidade Tuiuti do Parana
 * (DEPOIS) utp_-_universidade_tuiuti_do_parana
 */

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define MAX_NOME_CAMINHO_ARQUIVO 128

int main(void) {
    char nome_caminho[MAX_NOME_CAMINHO_ARQUIVO];
    puts("Digite abaixo o nome (e caminho, se necessario) do arquivo");
    gets(nome_caminho); // Le o nome (e caminho) do arquivo

    // Abre o arquivo (ele jah deve existir!)
    FILE* arquivo = fopen(nome_caminho, "r+"); // para leitura E escrita
    if (arquivo == 0) { // sempre teste o resultado do fopen!!!
        perror("Nao foi possivel abrir o arquivo");
        return EXIT_FAILURE;
    }
    // Na falta de um "contador" relativo ao tamanho, lemos o arquivo
    // ateh o seu final (ou, no caso, enquanto nao atingimos esse final)
    while (!feof(arquivo)) {
        char c = fgetc(arquivo); // Le o proximo byte/caractere do arquivo
        if (c == EOF) { // Nao eh um caractere valido? Pode ser erro ou o fim mesmo...
            if (ferror(arquivo)) { // Ultima operacao retornou EOF por causa de erro?
                perror("Nao foi possivel ler o arquivo");
                fclose(arquivo);
                return EXIT_FAILURE;
            }
        } else {
            if (c == ' ' || isupper(c)) {
                // Volta no arquivo um caractere para tras (ou seja, sobre aquele
                // que acabou de ser lido)
                if (fseek(arquivo, -sizeof(char), SEEK_CUR) < 0) { // erro?
                    perror("Erro ao voltar no arquivo");
                    fclose(arquivo);
                    return EXIT_FAILURE;
                }
                /*
                if (c == ' ') {
                    c = '_';
                } else {
                    c = tolower(c);
                }
                */
                c = c == ' '? '_' : tolower(c);
                if (fputc(c, arquivo) == EOF) {
                    perror("Nao foi possivel atualizar o arquivo");
                    fclose(arquivo);
                    return EXIT_FAILURE;
                }
            }
        }
    }
    fclose(arquivo);
    return EXIT_SUCCESS;
}

