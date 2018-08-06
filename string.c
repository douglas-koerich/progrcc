#include <stdlib.h>
#include <stdio.h>
#ifndef WIN32           // se nao estiver compilando em Windows 32-bits...
#include <stdio_ext.h>  // __fpurge()
#endif
#include <string.h>     // funcoes strXXX()

#define MAX 120

// Procedimento (funcao sem retorno) que nao recebe parametros, apenas para limpar
// qualquer entrada pendente de leitura do teclado ("lixo" de uma entrada anterior)
void limpa_teclado(void);

// Funcao que recebe uma string como parametro
unsigned contaOcorrenciasCh(char, char [*] /* com o terminador nulo nao preciso mais passar o tamanho do vetor (size_t) */);

int main(void) {
    // Inicializacao com uma string inicial
    char senha[] = "password1234";  // serao reservados 13 posicoes para a variavel-vetor senha (1 a mais para o \0)
    char nome[MAX] = "(vazio)";     // serao reservados 120 posicoes, como definido dentro dos colchetes
    char login[MAX];

    // Leitura de uma string do teclado
    printf("Vamos nos apresentar, digite o seu nome: ");
    /* Para uma variavel-string, SCANF termina a leitura ao encontrar
     * um salto-de-linha (o que ja fazia para outros tipos), um espaco ou
     * um sinal de tabulacao
     * Assim, esta linha nao aceita nomes com espacos (ex. "Dilma Roussef").
     */
    //scanf(" %s", nome); // ATENCAO!!! Nao usa & na frente da variavel com %s no scanf!
    limpa_teclado();
    gets(nome); // Nao usa %s no gets...

    printf("Muito prazer, %s!\n", nome);    // Trata a string como uma variavel comum
                                            // sem colchetes nem laco pra imprimir

    puts("Abaixo, o nome que foi digitado:");   // Impressao de uma CONSTANTE string
    puts(nome);                                 // Impressao de uma VARIAVEL string
                                                // Obs: puts() SEMPRE poe um nova-linha ao fim da string

    printf("Digite a senha: "); // Continuo usando printf para CONSTANTE string se nao quero nova-linha
    limpa_teclado();
    gets(login);

    // Comparacao entre strings
    // if (login == senha) {   // Comparacao entre strings nao eh feita usando o sinal == ou !=
    if (strcmp(login, senha) == 0) {    // Se strcmp() retorna 0, as strings sao iguais!
        puts("Senha CORRETA!");
    }
    else {
        puts("Senha INCORRETA!");
    }

    char copia[MAX];
    
    // Outras operacoes com string
    strcpy(copia, nome);    // equivalente a fazer copia = nome;
    printf("Copia apos a atribuicao: %s\n", copia);
    strcat(copia, login);   // equivalente a fazer copia += login;
    printf("Copia apos a concatenacao: %s\n", copia);

    printf("O comprimento da string 'copia' eh %u caracteres.\n", strlen(copia));   // nao conta o \0!!!

    // Versao em "funcao" da letra (a) do exercicio 7 da lista
    printf("Digite um caractere para procurar no nome informado: ");
    /*
    char ch;
    scanf(" %c", &ch);
    */
    limpa_teclado();        // Tambem pra getchar() eu preciso remover entradas pendentes ("presas")
    char ch = getchar();    // Le um caracter do teclado e armazena na variavel ch
    printf("O numero de ocorrencias de %c na string %s eh %u.\n", ch, nome, contaOcorrenciasCh(ch, nome));

    return EXIT_SUCCESS;
}

void limpa_teclado(void) {
#ifndef WIN32           // se eu nao estiver num compilador Windows 32-bits...
//#if !defined WIN32    // outra maneira de escrever a linha do PRE-PROCESSADOR acima
    __fpurge(stdin);    // "limpa" entradas pendentes no teclado ("lixo")
#else                   // caso contrario, estou num compilador Windows 32-bits
    fflush(stdin);
#endif
}

unsigned contaOcorrenciasCh(char ch, char string[]) {
    unsigned contador = 0;
    int posicao = 0;
    while (string[posicao] != '\0') {   // fazer ateh o fim da string
        if (string[posicao] == ch) {    // comparacao de caracteres usa ==, nao strcmp()!!!
            ++contador;
        }
        ++posicao;  // vai para o proximo caracter, se houver...
    }
    return contador;
}

