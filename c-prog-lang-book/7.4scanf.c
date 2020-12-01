#include <stdio.h>
// a rudimentary calculator

int main() {
	double sum, v;

	sum = 0;
	while (scanf("%lf", &v) == 1)		// l indicates a pointer to long
		printf("\t%.2f\n", sum += v);
	return 0;
}
