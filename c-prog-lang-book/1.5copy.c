//reads caracters from keyboard until end-of-file indicator
#include <stdio.h>

main() {
	int c;  //int to be big enough to store EOF
			//EOF is defined in stdio.h as int -1
			//look for stdio.h in prompt: 
			//find / -name stdio.h
	while ((c = getchar()) != EOF) {
		putchar(c);
	}
}
