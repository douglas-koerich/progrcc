#include <time.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>		// so funciona pra Linux
//#include <windows.h>	// funcao Sleep no Windows

int main(void) {
	// Programa sem fim!...
	while (true) {
		time_t agora = time(0);
		struct tm* relogio = localtime(&agora);
		printf("%02d:%02d:%02d\r", relogio->tm_hour, relogio->tm_min,
			   relogio->tm_sec);
		if (relogio->tm_sec % 10 == 0) {
			putchar('\a');
		}
		fflush(stdout);
		usleep(500000);	// dorme por 0.5 segundo = 500000 microsegundos
	}
	return 0;
}
