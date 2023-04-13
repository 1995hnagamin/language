#include <stdio.h>
#include <time.h>

int tarai(int x, int y, int z) {
	if (x > y) {
		return tarai(tarai(x-1, y, z), tarai(y-1, z, x), tarai(z-1, x, y));
	} else {
		return y;
	}
}

double measure(int x, int y, int z, int ntimes) {
	double total = 0;
	for (int i = 0; i < ntimes; ++i) {
		clock_t const start = clock();
		int const v = tarai(x, y, z);
		clock_t const end = clock();

		double const time = (double)(end - start) / CLOCKS_PER_SEC;
		printf("%f (%d)\n", time, v);
		total += time;
	}
	return total / ntimes;
}

int main(void) {
	int params[6][2] = {
		{10, 5},
		{11, 5},
		{12, 6},
		{13, 6},
		{13, 7},
		{14, 7},
	};
	for (int i = 0; i < 6; ++i) {
		int const x = params[i][0], y = params[i][1];
		printf("x = %d, y = %d\n", x, y);
		double time = measure(x, y, 0, 10);
		printf("average: %f sec\n\n", time);
	}
	return 0;
}
