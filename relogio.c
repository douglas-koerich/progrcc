#include <stdio.h>
#include <time.h>
#ifdef WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

int main(void) {
	while (1) {
		time_t agora = time(0);
		struct tm relogio = *localtime(&agora);
		printf("\r%02d:%02d:%02d", relogio.tm_hour, relogio.tm_min, relogio.tm_sec);
		fflush(stdout);
#ifdef WIN32
		Sleep(1);
#else
		usleep(250000);
#endif
	}
	return 0;
}


