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
		//redirect standard output to a file
		close(STDOUT_FILENO);
		printf("Child (pid:%d): Hello!\n",(int) getpid());
	} else {
		// parent
		int w = waitpid(0, NULL, WUNTRACED); 
		printf("Returned value from wait: %d. Parent(pid:%d): Goodbye!\n", w, (int) getpid());
	} 

	printf("After fork() (pid:%d)\n",(int) getpid());
	return 0;
}
