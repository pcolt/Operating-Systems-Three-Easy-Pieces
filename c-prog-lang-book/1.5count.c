#include <stdio.h>

//count characters in input
//usage: ./1.5count.c <filename

main () {
	int nc;
	for (nc=0; getchar() != EOF; nc++)
		;
	printf("%d\n", nc);

	return(0);
}
