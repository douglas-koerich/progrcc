#include "arranjo.h"

unsigned arranjo(unsigned x, unsigned y) {
	return fatorial(x) / fatorial(x - y);
}
