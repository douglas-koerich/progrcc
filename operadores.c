#include <stdio.h>
#include <math.h>

int main() {
	short int i1, i2, i3;
	long int l1, l2, l3;
	float f1, f2, f3;

	printf("Digite o valor de i1: "); scanf("%hd", &i1);
	printf("Digite o valor de i2: "); scanf("%hd", &i2);
/*
	printf("Digite o valor de l1: "); scanf("%ld", &l1);
	printf("Digite o valor de l2: "); scanf("%ld", &l2);
*/
	printf("Digite o valor de f1: "); scanf("%f", &f1);
	printf("Digite o valor de f2: "); scanf("%f", &f2);

	i3 = i1 + i2;
	printf("1. i3 = %d\n", i3);
	i3 = i1 + l2;
	printf("2. i3 = %d\n", i3);

	i3 = i1 / i2;
	printf("3. i3 = %d\n", i3);
	i3 = i1 % i2;
	printf("3,5. i3 = %d\n", i3);
	f3 = f1 / f2;
	printf("4. f3 = %.3f\n", f3);
	f3 = (float) i1 / i2 ;
	printf("5. f3 = %.3f\n", f3);

	i3 = pow(i1, i2);
	printf("6. i3 = %d\n", i3);
	f3 = sqrt(f1);
	printf("7. f3 = %.3f\n", f3);
	f3 = pow(f1, 1.0/3);
	printf("8. f3 = %.3f\n", f3);

	l3 = i1 + i2 * i3;
	printf("9. l2 = %ld\n", l3);
	l3 = (i1 + i2) * i3;
	printf("10. l2 = %ld\n", l3);

	return 0;
}

