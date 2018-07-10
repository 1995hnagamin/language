#include <stdio.h>

int
main(int argc, char* argv[]) {
	int a[3][4] = {
		{1, 2, 3, 4},
		{1, 2, 3, 4},
		{1, 2, 3, 4},
	};
	printf("%lu\n", sizeof(a)); // 48 (= 4 * 3 * 4)
	printf("%lu\n", sizeof(a[1])); // 16 (= 4 * 4)
	printf("%lu\n", sizeof(a[1][1])); // 4
	printf("%lu\n", sizeof(*a)); // 16
	printf("%lu\n", sizeof(void));
	printf("%lu\n", sizeof(void*));
	return 0;
}
