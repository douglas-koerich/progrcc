#include <math.h>

float somatorio(unsigned N) {
	unsigned n;
	float S;
	for (n=1, S=0.0; n<=N; ++n) {
		S += (pow(n, 2) + 1) / (n + 3);
	}
	return S;
}


