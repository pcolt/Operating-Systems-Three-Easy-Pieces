#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

int main(int argc, char*argv[]) {
	printf("Before fork() (pid:%d)\n",(int) getpid());

	int rc = fork();

	if (rc <0) {
		// fork failed
		printf("fork failed\n");
		exit(1);
	} else if (rc == 0) {
		//child 
		printf("Child (pid:%d)\n",(int) getpid());
		execl("/bin/ls", "ls", NULL);
	} else {
		// parent
		int w = wait(NULL);
		printf("Returned value from wait: %d\n", w);
		printf("Parent (pid:%d)\n",(int) getpid());
	} 

	printf("After fork() (pid:%d)\n",(int) getpid());
	return 0;
}
