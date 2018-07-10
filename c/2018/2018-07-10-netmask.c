#include <stdio.h>

int
main(void) {
	for (int i = 0; i <= 32; ++i) {
		unsigned int const mask = ~0UL << (32-i);
		printf("%08x\n", mask);
	}
	return 0;
}
