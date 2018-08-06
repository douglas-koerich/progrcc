#include <stdio.h>
#ifndef WIN32
	#include <stdbool.h>
	#include <stdio_ext.h>
#else
	typedef int bool;
	#define false 0
	#define true 1
#endif

bool mystrcmp(char[*], char[*]);

#define MAX	20

int main() {
	char str1[MAX], str2[MAX];

	printf("Primeira string: ");
	gets(str1);

#ifdef WIN32
	fflush(stdin);
#else
	__fpurge(stdin);
#endif

	printf("Segunda string: ");
	gets(str2);

	printf("As strings sao %s\n", mystrcmp(str1, str2)? "iguais": "diferentes");

	return 0;
}

bool mystrcmp(char s1[], char s2[]) {
	int b = 0;
	do {
		// Ate o terminador nulo entra na comparacao (para strings de
		// tamanhos diferentes, vai resultar falso)
		if (s1[b] != s2[b]) {
			return false;
		}
	} while (s1[b++] != '\0');
	return true;
}

