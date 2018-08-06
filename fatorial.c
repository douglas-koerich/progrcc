#include "fatorial.h"

unsigned fatorial(unsigned x) {
	unsigned f = 1, i = 1;
	while (i <= x) {
		f *= i++;
	}
	return f;
}
