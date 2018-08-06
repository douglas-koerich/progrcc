#include <stdio.h>

int main() {
	int f1 = 1, f2 = 2, tmp, n, i;
	printf("Quantos termos? ");
	scanf("%d", &n);
	for (i=1; i<=n; ++i) {
		if (i == 1) {
			printf("%d ", f1);
		}
		else if (i == 2) {
			printf("%d ", f2);
		}
		else {
			printf("%d ", f2+f1);
			tmp = f1;
			f1 = f2;
			f2 = tmp+f2;
		}
	}
	printf("\n");
	return 0;
}

