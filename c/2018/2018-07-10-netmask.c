#include <stdio.h>

int
main(void) {
	for (int i = 1; i <= 32; ++i) {
		int const mask = -1 << (32-i);
		printf("%x\n", mask);
	}
	return 0;
}
