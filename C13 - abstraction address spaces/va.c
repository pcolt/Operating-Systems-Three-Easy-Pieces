//print location of code, heap and stack
//normally first comes code, then heap and stack all the way down
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	printf("location of code: %p\n", main);
	printf("location of heap: %p\n", malloc(100));
	int x = 3;
	printf("location of stack: %p\n", &x);
	return x;
}
