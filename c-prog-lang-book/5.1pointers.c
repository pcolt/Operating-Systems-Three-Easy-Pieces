#include <stdio.h>

// the unary operator & gives the address of an object, so the statment
// p = &c;
// assigns the address of c to the variable p, and p is said to "point
// to" c. 
// The unary operator * is the 'indirection' or 'deferencing' operator;
// when applied to a pointer, it accesses the object the pointer points
// to.

int main() {
	int x = 1, y = 2, z[10];
	int *ip;		/* ip is a pointer to int */
	
	ip = &x;		/* ip now points to x */
	y = *ip;		/* y is now 1 */
	*ip = 0;		// x is now 0 but y is still 1
	printf("x is 0: %d, y is 1: %d\n", x, y);
	ip = &z[0];		// ip now points to z[0]

// if ip points to the integer x, then *ip can occour in any contex where
// x could so

	ip = &y;		// ip points to y
	*ip = *ip + 10;	// increments *ip and y by 10
	printf("ip and y are now both 11: %d\n", y);
}

