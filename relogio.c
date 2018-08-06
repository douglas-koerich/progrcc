#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#ifndef WIN32           // Se o pre-processador NAO encontrar (ndef) a definicao de WIN32...
#include <unistd.h>     // ... vai incluir para o compilador os prototipos do sistema Unix
#else                   // Senao...
#include <windows.h>    // ... vai incluir para o compilador os prototipos do sistema Windows
#endif

int main(void) {
    while (1) {  // laco infinito (nunca termina)
    // for (;;) {}  // outra maneira de fazer o mesmo...
        time_t agora = time(0);
        // printf("%d\n", (int) agora);
        // printf("%s", ctime(&agora));
        struct tm tempo = *localtime(&agora);   // struct e */& sao assuntos do 2o. bimestre
        printf("%02d:%02d:%02d\r", tempo.tm_hour, tempo.tm_min, tempo.tm_sec);   // \r volta a imprimir na mesma linha, ao contrario do \n
        fflush(stdout); // printf soh aparece na tela com \n ou com uma "descarga" (flush) para o console (stdout)
#ifndef WIN32
        // Em Unix/Linux:
        sleep(1);   // O compilador em Windows "nao ve" esta linha (porque ele tem a definicao de WIN32)
#else
        // Em Windows:
        Sleep(1000);    // O compilador em Unix "nao ve" esta linha
#endif
    }
    return EXIT_SUCCESS;
}
