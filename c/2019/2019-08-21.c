#include <stdio.h>

int main(void) {
	(  &printf)("  &printf = %p\n", &printf);
	printf ("   printf = %p\n", printf);
	(  *printf)("  *printf = %p\n", *printf);
	( **printf)(" **printf = %p\n", **printf);
	(***printf)("***printf = %p\n", ***printf);
}
