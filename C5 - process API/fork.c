#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char*argv[]) {
	int x = 100;
	printf("Before fork() (pid:%d), x = %d\n",(int) getpid(),  x);
	int rc = fork();
	if (rc <0) {
		// fork failed
		printf("fork failed\n");
		exit(1);
	} else if (rc == 0) {
		//child 
		x = 50;
		printf("Child (pid:%d), x = %d\n",(int) getpid(),  x);
	} else {
		// parent
		x++;
		printf("Parent (pid:%d), x = %d\n",(int) getpid(), x);
	} 
	printf("After fork() (pid:%d), x = %d\n",(int) getpid(),  x);
	return 0;
}
