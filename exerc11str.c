#include <ctype.h>
#include <stdio.h>

void inverteMAImin(char[*]);

#define MAX_STRING	100

int main() {
	char frase[MAX_STRING];

	printf("Digite uma frase: ");
	gets(frase);

	inverteMAImin(frase);

	puts(frase);

	return 0;
}

void inverteMAImin(char string[]) {
	int i = 0;
	while (string[i] != '\0') {
		if (isalpha(string[i])) {
			if (isupper(string[i])) {
				string[i] = tolower(string[i]);
			}
			else {
				string[i] = toupper(string[i]);
			}
		}
		++i;
	}
}

