#include <stdio.h>

int main() {
	int var1, var2;
	printf("var1? "); scanf("%d", &var1);
	printf("var2? "); scanf("%d", &var2);
	printf("Antes da troca: var1=%d, var2=%d\n", var1, var2);
	int var3 = var2;
	var2 = var1;
	var1 = var3;
	printf("Depois da troca: var1=%d, var2=%d\n", var1, var2);
	return 0;
}

