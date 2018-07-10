#include <stdio.h>

struct S1 {
	char c1;
	char c2;
	char c3;
};

int
main(void) {
	struct S1 a[5];
	printf("a+i:\n");
	for (int i = 0; i < 5; ++i) {
		printf("%p\n", a+i);
	}
	printf("(int *)(a+i):\n");
	for (int i = 0; i < 5; ++i) {
		printf("%p\n", (int *)(a+i));
	}
	printf("((int *)(a+i))+j:\n");
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 3; ++j) {
			printf("%p\n", ((int *)(a+i))+j);
		}
		printf("\n");
	}
	return 0;
}
