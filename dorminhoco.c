#include <stdlib.h>
#include <stdio.h>
#include <unistd.h> // em Windows: windows.h

// Uma funcao que nao tem retorno de resultado eh um "procedimento", e tem como
// tipo: 'void'
void durma(int);    // prototipo

// Uma funcao que nao tem parametros (ou seja, faz sempre a mesma coisa com os
// mesmos dados) tem uma lista vazia, que eh void
void limpa(void);   // nem recebe parametros, nem devolve resultados

int main(void) {    // main() nesse caso tambem nao recebe parametros (do sistema)
    int segundos;
    printf("Digite o numero de segundos em espera: ");
    scanf("%d", &segundos);

    printf("Dormindo por %d segundos...", segundos);
    fflush(stdout); // descarrega o buffer do console pra aparecer antes do sleep
                    // jah que esse printf nao tem um \n (que descarrega automaticamente)
    durma(segundos);
    limpa();
    printf("Acordei!\n");

    return EXIT_SUCCESS;
}

void durma(int tempo) {
    sleep(tempo);
}

void limpa(void) {
    // Em Linux; se fosse Windows, seria system("cls")
    system("clear");
}
