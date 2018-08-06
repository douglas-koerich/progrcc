#include <stdio.h>
#include <math.h>

void tabula(void);

int main(void) {
	tabula();
	return 0;
}

void tabula(void) {
	for (int n = 1; n <= 10; ++n) {
		float x = pow(n, 2);
		for (int y = 0; y <= 5; ++y) {
			float f = (pow(x, 2) + 3*x + pow(y, 2)) /
					  (x*y - 5*y - 3*x + 15);
			printf("f(%.0f, %d) = %.3f\n", x, y, f);
		}
	}
}

