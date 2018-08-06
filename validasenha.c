#include <stdio.h>
#include <string.h>

#define	SENHA	"admin"
#define MAX		15

main() {
	char senha_usuario[MAX];

	do {
		puts("Digite a senha (max. 15):");
		scanf(" %s", senha_usuario);
	}
	while (strcmp(senha_usuario, SENHA) != 0);
}

