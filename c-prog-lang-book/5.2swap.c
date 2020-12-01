#include <stdio.h>
// pointer arguments enable function to access and change objects in
// the function that called it

// paramteters of swap are declared pointers, and the operands are
// accessed directly through them
void swap(int *a, int *b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;	
}

int main() {
	int num1 = 2;
	int num2 = 0;
	
	printf("num1: %d, num2: %d\n", num1, num2);
	// since operator & produces the address of a variable,
	// &a is a pointer to a
	swap(&num1, &num2);
	printf("after swap is runned..\nnum1: %d, num2: %d\n", num1, num2);
}

