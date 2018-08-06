#include "combinacao.h"

unsigned combinacao(unsigned x, unsigned y) {
	unsigned num = fatorial(x);
	unsigned den = fatorial(y) * fatorial(x - y);
	return num / den;
}
