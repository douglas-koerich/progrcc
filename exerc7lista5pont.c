#include <stdio.h>
#include <string.h> // para as funcoes que manipulam/analisam/etc. strings
#if !defined WIN32 && !defined WIN64
#include <stdio_ext.h>  // para __fpurge() usado em Linux
#endif

#define MAX_FRASE   500

// Prototipo de uma funcao que recebe string como parametro
int contaCaracter(char [*], /* size_t, nao precisa, porque tem o \0 */
                  char);

int main() {
    // Declaracao da variavel-string para a frase: um vetor de caracteres
    // ISSO NAO MUDA! MESMO SE VAMOS OPERAR SOBRE A STRING USANDO PONTEIRO,
    // AINDA EH NECESSARIO DECLARAR UM VETOR/UMA STRING PARA ARMAZENAR A
    // INFORMACAO NA MEMORIA!!!
    char frase[MAX_FRASE];

    // Leitura da frase digitada pelo usuario
    puts("Digite uma frase abaixo: ");  // puts() poe um \n automagicamente
    gets(frase); // recebendo apenas o nome do vetor, estah recebendo o ponteiro
                 // agora faz sentido o motivo de nao antepor o & na variavel

    // Le o caracter que sera procurado na frase
    printf("Digite o caracter para busca: ");
#if defined WIN32 || defined WIN64
    fflush(stdin);  // para limpar o buffer do teclado em Windows
#else
    __fpurge(stdin); // para faze-lo em Linux (na verdade, em nao-Windows)
#endif
    char c = getchar();

    // Letra (a)
    int cont = contaCaracter(frase, c); // de novo, passando o ponteiro-vetor

    printf("O numero de ocorrencias de '%c' em \"%s\" eh %d\n",
           c, frase, cont);

    // Letra (b)
    int i;
    char *pc = frase; // equivale a pc = &frase[0];
    /*
    for (i = strlen(pc), pc += i;   // mudo (desloco) o ponteiro para o ultimo caracter
         i >= 0; --i, --pc) {       // caminha com o ponteiro para tras
        if (*pc == c) {
    */
    for (i = strlen(pc), pc += i; i >= 0; --i) {
        if (*pc-- == c) {   // pega o conteudo, testa e DEPOIS decrementa (vai para tras)
            break;
        }
    }
    printf("Caracter encontrado na posicao %d (-1 se nao achou)\n", i);

    return 0;
}

int contaCaracter(char* str, char ch) {
    // Letra (a)
    int contador = 0;
    /* Esta versao, trazida da anterior com vetor-string, ainda seria
     * valida porque podemos usar [] em ponteiro ("indexacao do ponteiro")
    int i = 0;
    while (str[i] != '\0') {  // enquanto nao for o fim da string...
        if (str[i] == ch) {
            ++contador;
        }
        ++i;
    }
    */
    // Como 'str' eh um ponteiro comum que recebe uma COPIA do endereco representado
    // por 'frase' na linha de chamada da funcao (v. linha 35), entao posso incrementa-lo
    // sem problemas (nao poderia fazer isso com o "ponteiro" 'frase')
    while (*str != '\0') {
        if (*str++ == ch) { // se fosse para incrementar o conteudo, deveria ser (*str)++
            ++contador;
        }
        // ++str; (se usei o ++ acima, comento aqui)
    }
    return contador;
}

