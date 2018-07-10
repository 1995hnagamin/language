#include <stdio.h>

int
power(int a, int n) {
	if (!n) {
		return 1;
	} else if (n&1) {
		return a * power(a, n-1);
	} else {
		return power(a*a, n/2);
	}
}

int
main(void) {
	for (int i = 1; i <= 32; ++i) {
		int const mask = -power(2, 32-i);
		printf("%x\n", mask);
	}
	return 0;
}
