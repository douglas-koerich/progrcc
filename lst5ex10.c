#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

bool palindroma(const char [*]); // nao eh necessario passar o tamanho
                                 // como parametro, pois o vetor tem
                                 // um marcador de "fim", que eh o
                                 // terminador nulo
                                 // 'const' eh usado pra restringir o
                                 // acesso ao vetor (string) pela
                                 // funcao a apenas-leitura (nao pode
                                 // alterar o conteudo do vetor)

#define MAX_STRING 50

int main(void) {
    char entrada[MAX_STRING]; // "variavel" string

    puts("Digite abaixo uma palavra/frase para teste:");
    gets(entrada);

    bool resultado = palindroma(entrada);

    if (resultado == true) { // if (resultado)
        puts("A palavra/frase eh palindroma");
    } else {
        puts("A palavra/frase NAO eh palindroma");
    }
    return EXIT_SUCCESS;
}

bool palindroma(const char string[]) {
    // Exemplos
    // { 'a', 'r', 'a', 'r', 'a', '\0' } "arara" (eh palindroma)
    // { 'b', 'r', 'a', 'b', 'a', '\0' } "braba" (NAO eh palindroma)
    //    0    1    2    3    4    5 <-- indices do vetor string

    /*
    size_t num_validos = 0;
    int i = 0;
    while (string[i] != '\0') { // while(string[i] != 0)
                                // while(string[i]) <-- !=0 eh true
        ++num_validos, ++i; // consulte o operador virgula nos livros
    }
    */
    size_t num_validos = strlen(string);
    int j = num_validos-1; // inicia na posicao anterior ah do '\0'
    i = 0;
    while (j > i) {
        if (string[i] != string[j]) {
            return false; // encontrou diferenca entre os percursos
                          // esq->dir (i) e esq<-dir (j)
        }
        ++i, --j;
    }
    return true;
}

