#include <stdio.h>
#include <stdlib.h>  //exit, atoi
#include <unistd.h>  //getpid

int main(int argc, char *argv[]) {
	if (argc != 2) {
		printf("usage: memory-user <memory>\n");
		exit(1);
	}

	printf("pid: %d\n", getpid());

	int memory = atoi(argv[1]) * 1048576;
	int length = memory / sizeof(int);
	int *arr = malloc(memory);	

	while (1) {
		for (int i = 0; i < length; i++) {
			arr[i] += 1;
		}	
	}

	free(arr);
	return 0;
}
